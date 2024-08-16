#include "global.h"
#include "rtc.h"
#include "wild_encounter.h"
#include "pokemon.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "random.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "safari_zone.h"
#include "overworld.h"
#include "pokeblock.h"
#include "battle_setup.h"
#include "roamer.h"
#include "tv.h"
#include "link.h"
#include "script.h"
#include "battle_debug.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "constants/abilities.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/weather.h"

extern const u8 EventScript_SprayWoreOff[];

#define MAX_ENCOUNTER_RATE 2880

#define NUM_FEEBAS_SPOTS 6

// Number of accessible fishing spots in each section of Route 119
// Each section is an area of the route between the y coordinates in sRoute119WaterTileData
#define NUM_FISHING_SPOTS_1 131
#define NUM_FISHING_SPOTS_2 167
#define NUM_FISHING_SPOTS_3 149
#define NUM_FISHING_SPOTS (NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2 + NUM_FISHING_SPOTS_3)

enum {
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

#define WILD_CHECK_REPEL    (1 << 0)
#define WILD_CHECK_KEEN_EYE (1 << 1)

#define HEADER_NONE 0xFFFF

static u16 FeebasRandom(void);
static void FeebasSeedRng(u16 seed);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *encRate);
static void ApplyCleanseTagEncounterRateMod(u32 *encRate);
//static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemon *wildMon, u16 species, u8 area);
#ifdef BUGFIX
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex, u32 size);
#else
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex);
#endif
static bool8 IsAbilityAllowingEncounter(u8 level);

EWRAM_DATA static u8 sWildEncountersDisabled = 0;
EWRAM_DATA static u32 sFeebasRngValue = 0;
EWRAM_DATA bool8 gIsFishingEncounter = 0;
EWRAM_DATA bool8 gIsSurfingEncounter = 0;

#include "data/wild_encounters.h"

static const struct WildPokemon sWildFeebas = {20, 25, SPECIES_FEEBAS};

static const u16 sRoute119WaterTileData[] =
{
//yMin, yMax, numSpots in previous sections
     0,  45,  0,
    46,  91,  NUM_FISHING_SPOTS_1,
    92, 139,  NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2,
};

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

// Each fishing spot on Route 119 is given a number between 1 and NUM_FISHING_SPOTS inclusive.
// The number is determined by counting the valid fishing spots left to right top to bottom.
// The map is divided into three sections, with each section having a pre-counted number of
// fishing spots to start from to avoid counting a large number of spots at the bottom of the map.
// Note that a spot is considered valid if it is surfable and not a waterfall. To exclude all
// of the inaccessible water metatiles (so that they can't be selected as a Feebas spot) they
// use a different metatile that isn't actually surfable because it has MB_NORMAL instead.
// This function is given the coordinates and section of a fishing spot and returns which number it is.
static u16 GetFeebasFishingSpotId(s16 targetX, s16 targetY, u8 section)
{
    u16 x, y;
    u16 yMin = sRoute119WaterTileData[section * 3 + 0];
    u16 yMax = sRoute119WaterTileData[section * 3 + 1];
    u16 spotId = sRoute119WaterTileData[section * 3 + 2];

    for (y = yMin; y <= yMax; y++)
    {
        for (x = 0; x < gMapHeader.mapLayout->width; x++)
        {
            u8 behavior = MapGridGetMetatileBehaviorAt(x + MAP_OFFSET, y + MAP_OFFSET);
            if (MetatileBehavior_IsSurfableAndNotWaterfall(behavior) == TRUE)
            {
                spotId++;
                if (targetX == x && targetY == y)
                    return spotId;
            }
        }
    }
    return spotId + 1;
}

static bool8 CheckFeebas(void)
{
    u8 i;
    u16 feebasSpots[NUM_FEEBAS_SPOTS];
    s16 x, y;
    u8 route119Section = 0;
    u16 spotId;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE119)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE119))
    {
        GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
        x -= MAP_OFFSET;
        y -= MAP_OFFSET;

        // Get which third of the map the player is in
        if (y >= sRoute119WaterTileData[3 * 0 + 0] && y <= sRoute119WaterTileData[3 * 0 + 1])
            route119Section = 0;
        if (y >= sRoute119WaterTileData[3 * 1 + 0] && y <= sRoute119WaterTileData[3 * 1 + 1])
            route119Section = 1;
        if (y >= sRoute119WaterTileData[3 * 2 + 0] && y <= sRoute119WaterTileData[3 * 2 + 1])
            route119Section = 2;

        // 50% chance of encountering Feebas (assuming this is a Feebas spot)
        if (Random() % 100 > 49)
            return FALSE;

        FeebasSeedRng(gSaveBlock1Ptr->dewfordTrends[0].rand);

        // Assign each Feebas spot to a random fishing spot.
        // Randomness is fixed depending on the seed above.
        for (i = 0; i != NUM_FEEBAS_SPOTS;)
        {
            feebasSpots[i] = FeebasRandom() % NUM_FISHING_SPOTS;
            if (feebasSpots[i] == 0)
                feebasSpots[i] = NUM_FISHING_SPOTS;

            // < 1 below is a pointless check, it will never be TRUE.
            // >= 4 to skip fishing spots 1-3, because these are inaccessible
            // spots at the top of the map, at (9,7), (7,13), and (15,16).
            // The first accessible fishing spot is spot 4 at (18,18).
            if (feebasSpots[i] < 1 || feebasSpots[i] >= 4)
                i++;
        }

        // Check which fishing spot the player is at, and see if
        // it matches any of the Feebas spots.
        spotId = GetFeebasFishingSpotId(x, y, route119Section);
        for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
        {
            if (spotId == feebasSpots[i])
                return TRUE;
        }
    }
    return FALSE;
}

static u16 FeebasRandom(void)
{
    sFeebasRngValue = ISO_RANDOMIZE2(sFeebasRngValue);
    return sFeebasRngValue >> 16;
}

static void FeebasSeedRng(u16 seed)
{
    sFeebasRngValue = seed;
}

// LAND_WILD_COUNT
static u8 ChooseWildMonIndex_Land(void)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        wildMonIndex = 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        wildMonIndex = 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        wildMonIndex = 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        wildMonIndex = 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        wildMonIndex = 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        wildMonIndex = 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        wildMonIndex = 9;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_10)
        wildMonIndex = 10;
    else
        wildMonIndex = 11;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 11 - wildMonIndex;

    return wildMonIndex;
}

// ROCK_WILD_COUNT / WATER_WILD_COUNT
static u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        wildMonIndex = 3;
    else
        wildMonIndex = 4;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 4 - wildMonIndex;

    return wildMonIndex;
}

// FISH_WILD_COUNT
static u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;

        if (swap)
            wildMonIndex = 1 - wildMonIndex;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;

        if (swap)
            wildMonIndex = 6 - wildMonIndex;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)
            wildMonIndex = 9;

        if (swap)
            wildMonIndex = 14 - wildMonIndex;
        break;
    }
    return wildMonIndex;
}
/*
static u8 ChooseWildMonLevel(const struct WildPokemon *wildPokemon, u8 wildMonIndex, u8 area)
{
    u8 min;
    u8 max;
    u8 range;
    u8 rand;

    if (LURE_STEP_COUNT == 0)
    {
        // Make sure minimum level is less than maximum level
        if (wildPokemon[wildMonIndex].maxLevel >= wildPokemon[wildMonIndex].minLevel)
        {
            min = wildPokemon[wildMonIndex].minLevel;
            max = wildPokemon[wildMonIndex].maxLevel;
        }
        else
        {
            min = wildPokemon[wildMonIndex].maxLevel;
            max = wildPokemon[wildMonIndex].minLevel;
        }
        range = max - min + 1;
        rand = Random() % range;

        // check ability for max level mon
        if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        {
            u16 ability = GetMonAbility(&gPlayerParty[0]);
            if (ability == ABILITY_HUSTLE || ability == ABILITY_VITAL_SPIRIT || ability == ABILITY_PRESSURE)
            {
                if (Random() % 2 == 0)
                    return max;

                if (rand != 0)
                    rand--;
            }
        }
        return min + rand;
    }
    else
    {
        // Looks for the max level of all slots that share the same species as the selected slot.
        max = GetMaxLevelOfSpeciesInWildTable(wildPokemon, wildPokemon[wildMonIndex].species, area);
        if (max > 0)
            return max + 1;
        else // Failsafe
            return wildPokemon[wildMonIndex].maxLevel + 1;
    }
}
*/
static u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == MAP_GROUP(UNDEFINED))
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId >= NUM_ALTERING_CAVE_TABLES)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }
            else
            {
                u16 rnd = Random() % 100 + 1;
                u16 mapTimeId = GetTimeOfDay();
                if (mapTimeId == TIME_MORNING)
                {
                    if (rnd > 50)
                        mapTimeId = TIME_MORNING;
                    else if (rnd > 30)
                        mapTimeId = TIME_DAY;
                    else if (rnd > 20)
                        mapTimeId = TIME_EVENING;
                    else // (rnd > 0)
                        mapTimeId = TIME_NIGHT;
                }
                else if (mapTimeId == TIME_DAY)
                {
                    if (rnd > 80)
                        mapTimeId = TIME_MORNING;
                    else if (rnd > 30)
                        mapTimeId = TIME_DAY;
                    else if (rnd > 10)
                        mapTimeId = TIME_EVENING;
                    else // (rnd > 0)
                        mapTimeId = TIME_NIGHT;
                }
                else if (mapTimeId == TIME_EVENING)
                {
                    if (rnd > 90)
                        mapTimeId = TIME_MORNING;
                    else if (rnd > 70)
                        mapTimeId = TIME_DAY;
                    else if (rnd > 20)
                        mapTimeId = TIME_EVENING;
                    else // (rnd > 0)
                        mapTimeId = TIME_NIGHT;
                }
                else // (mapTimeId == TIME_NIGHT)
                {
                    if (rnd > 80)
                        mapTimeId = TIME_MORNING;
                    else if (rnd > 70)
                        mapTimeId = TIME_DAY;
                    else if (rnd > 50)
                        mapTimeId = TIME_EVENING;
                    else // (rnd > 0)
                        mapTimeId = TIME_NIGHT;
                }

                if (mapTimeId >= TIMES_COUNT)
                    mapTimeId = 0;

                i += mapTimeId;
            }

            return i;
        }
    }

    return HEADER_NONE;
}

u8 PickWildMonNature(void)
{
    u8 i;
    u8 j;
    struct Pokeblock *safariPokeblock;
    u8 natures[NUM_NATURES];

    if (GetSafariZoneFlag() == TRUE && Random() % 100 < 80)
    {
        safariPokeblock = SafariZoneGetActivePokeblock();
        if (safariPokeblock != NULL)
        {
            for (i = 0; i < NUM_NATURES; i++)
                natures[i] = i;
            for (i = 0; i < NUM_NATURES - 1; i++)
            {
                for (j = i + 1; j < NUM_NATURES; j++)
                {
                    if (Random() & 1)
                    {
                        u8 temp;
                        SWAP(natures[i], natures[j], temp);
                    }
                }
            }
            for (i = 0; i < NUM_NATURES; i++)
            {
                if (PokeblockGetGain(natures[i], safariPokeblock) > 0)
                    return natures[i];
            }
        }
    }
    // check synchronize for a pokemon with the same ability
    if (OW_SYNCHRONIZE_NATURE < GEN_9
        && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_SYNCHRONIZE
        && (OW_SYNCHRONIZE_NATURE == GEN_8 || Random() % 2 == 0))
    {
        return GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY) % NUM_NATURES;
    }

    // random nature
    return Random() % NUM_NATURES;
}

static void CreateWildMon(u16 species, u8 level)
{
    bool32 checkCuteCharm;
    u8 abilityNum = Random() % 3;

    ZeroEnemyPartyMons();
    checkCuteCharm = OW_CUTE_CHARM < GEN_9;

    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        checkCuteCharm = FALSE;
        break;
    }

    if (checkCuteCharm
        && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_CUTE_CHARM
        && Random() % 3 != 0)
    {
        u16 leadingMonSpecies = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
        u32 leadingMonPersonality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
        u8 gender = GetGenderFromSpeciesAndPersonality(leadingMonSpecies, leadingMonPersonality);

        // misses mon is genderless check, although no genderless mon can have cute charm as ability
        if (gender == MON_FEMALE)
            gender = MON_MALE;
        else
            gender = MON_FEMALE;

        CreateMonWithGenderNatureLetter(&gEnemyParty[0], species, level, USE_RANDOM_IVS, gender, PickWildMonNature(), 0);
        return;
    }

    CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, PickWildMonNature());
    if (FlagGet(B_SMART_WILD_AI_FLAG | B_FLAG_DYNAMAX_BATTLE))
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityNum);
}
#ifdef BUGFIX
#define TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildPokemon, type, ability, ptr, count) TryGetAbilityInfluencedWildMonIndex(wildPokemon, type, ability, ptr, count)
#else
#define TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildPokemon, type, ability, ptr, count) TryGetAbilityInfluencedWildMonIndex(wildPokemon, type, ability, ptr)
#endif

static bool8 TryGenerateWildMon(const struct WildPokemonInfo *wildMonInfo, u8 area, u8 flags)
{
    u8 wildMonIndex = 0;
    u8 level;

    switch (area)
    {
    case WILD_AREA_LAND:
        if (OW_MAGNET_PULL < GEN_9 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_STEEL, ABILITY_MAGNET_PULL, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_STATIC < GEN_9 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_LIGHTNING_ROD == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_LIGHTNING_ROD, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_FLASH_FIRE == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_FIRE, ABILITY_FLASH_FIRE, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_HARVEST == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_GRASS, ABILITY_HARVEST, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_STORM_DRAIN == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_WATER, ABILITY_STORM_DRAIN, &wildMonIndex, LAND_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        if (OW_MAGNET_PULL < GEN_9 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_STEEL, ABILITY_MAGNET_PULL, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_STATIC < GEN_9 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_LIGHTNING_ROD == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_LIGHTNING_ROD, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_FLASH_FIRE == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_FIRE, ABILITY_FLASH_FIRE, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_HARVEST == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_GRASS, ABILITY_HARVEST, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_STORM_DRAIN == GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_WATER, ABILITY_STORM_DRAIN, &wildMonIndex, WATER_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    case WILD_AREA_ROCKS:
        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    }

    level = GetMonScaledLevel(FALSE);
    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
        return FALSE;
    if (gMapHeader.mapLayoutId != LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return TRUE;
}

static u16 GenerateFishingWildMon(const struct WildPokemonInfo *wildMonInfo, u8 rod)
{
    u8 wildMonIndex = ChooseWildMonIndex_Fishing(rod);

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, GetMonScaledLevel(FALSE));
    return wildMonInfo->wildPokemon[wildMonIndex].species;
}

static bool8 SetUpMassOutbreakEncounter(u8 flags)
{
    u16 i;
    u8 level = GetMonScaledLevel(FALSE);

    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
        return FALSE;

    CreateWildMon(gSaveBlock1Ptr->outbreakPokemonSpecies, level);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(&gEnemyParty[0], gSaveBlock1Ptr->outbreakPokemonMoves[i], i);

    return TRUE;
}

static bool8 DoMassOutbreakEncounterTest(void)
{
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE
     && gSaveBlock1Ptr->location.mapNum == gSaveBlock1Ptr->outbreakLocationMapNum
     && gSaveBlock1Ptr->location.mapGroup == gSaveBlock1Ptr->outbreakLocationMapGroup)
    {
        if (Random() % 100 < gSaveBlock1Ptr->outbreakPokemonProbability)
            return TRUE;
    }
    return FALSE;
}

static bool8 EncounterOddsCheck(u16 encounterRate)
{
    if (Random() % MAX_ENCOUNTER_RATE < encounterRate)
        return TRUE;
    else
        return FALSE;
}

// Returns true if it will try to create a wild encounter.
static bool8 WildEncounterCheck(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (LURE_STEP_COUNT != 0)
        encounterRate *= 2;
    if (!ignoreAbility && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u32 ability = GetMonAbility(&gPlayerParty[0]);

        if (ability == ABILITY_STENCH && gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            encounterRate = encounterRate * 3 / 4;
        else if (ability == ABILITY_STENCH)
            encounterRate /= 2;
        else if (ability == ABILITY_ILLUMINATE && OW_ILLUMINATE < GEN_9)
            encounterRate *= 2;
        else if (ability == ABILITY_WHITE_SMOKE)
            encounterRate /= 2;
        else if (ability == ABILITY_ARENA_TRAP)
            encounterRate *= 2;
        else if (ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == WEATHER_SANDSTORM)
            encounterRate /= 2;
        else if (ability == ABILITY_SNOW_CLOAK && gSaveBlock1Ptr->weather == WEATHER_SNOW)
            encounterRate /= 2;
        else if (ability == ABILITY_QUICK_FEET)
            encounterRate /= 2;
        else if (ability == ABILITY_INFILTRATOR && OW_INFILTRATOR == GEN_8)
            encounterRate /= 2;
        else if (ability == ABILITY_NO_GUARD)
            encounterRate *= 2;
    }
    if (encounterRate > MAX_ENCOUNTER_RATE)
        encounterRate = MAX_ENCOUNTER_RATE;
    return EncounterOddsCheck(encounterRate);
}

// When you first step on a different type of metatile, there's a 40% chance it
// skips the wild encounter check entirely.
static bool8 AllowWildCheckOnNewMetatile(void)
{
    if (Random() % 100 >= 60)
        return FALSE;
    else
        return TRUE;
}

static bool8 AreLegendariesInSootopolisPreventingEncounters(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(SOOTOPOLIS_CITY)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(SOOTOPOLIS_CITY))
    {
        return FALSE;
    }

    return FlagGet(FLAG_LEGENDARIES_IN_SOOTOPOLIS);
}

bool8 StandardWildEncounter(u16 curMetatileBehavior, u16 prevMetatileBehavior)
{
    u16 headerId;
    struct Roamer *roamer;

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePikeWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;
            else if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;

            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePyramidWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(curMetatileBehavior) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else
            {
                if (DoMassOutbreakEncounterTest() == TRUE && SetUpMassOutbreakEncounter(WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                // try a regular wild land encounter
                if (TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    if (TryDoDoubleWildBattle())
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                    {
                        BattleSetup_StartWildBattle();
                    }
                    return TRUE;
                }

                return FALSE;
            }
        }
        else if (MetatileBehavior_IsWaterWildEncounter(curMetatileBehavior) == TRUE
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridgeOverWater(curMetatileBehavior) == TRUE))
        {
            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            else if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].waterMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    gIsSurfingEncounter = TRUE;
                    if (TryDoDoubleWildBattle())
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                    {
                        BattleSetup_StartWildBattle();
                    }
                    return TRUE;
                }

                return FALSE;
            }
        }
    }

    return FALSE;
}

void RockSmashWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].rockSmashMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, WILD_AREA_ROCKS, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u16 headerId;

    PlayerGetDestCoords(&x, &y);
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            if (DoMassOutbreakEncounterTest() == TRUE)
                SetUpMassOutbreakEncounter(0);
            else
                TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0);

            BattleSetup_StartWildBattle();
            return TRUE;
        }
        else if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, 0);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE && gWildMonHeaders[headerId].fishingMonsInfo != NULL)
        return TRUE;
    else
        return FALSE;
}

void FishingWildEncounter(u8 rod)
{
    u16 species;

    if (CheckFeebas() == TRUE)
    {
        species = sWildFeebas.species;
        CreateWildMon(species, GetMonScaledLevel(FALSE));
    }
    else
    {
        species = GenerateFishingWildMon(gWildMonHeaders[GetCurrentMapWildMonHeaderId()].fishingMonsInfo, rod);
    }
    IncrementGameStat(GAME_STAT_FISHING_ENCOUNTERS);
    SetPokemonAnglerSpecies(species);
    gIsFishingEncounter = TRUE;
    BattleSetup_StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u16 headerId;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;

    *isWaterMon = FALSE;
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
        return SPECIES_NONE;
    landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
    // Land Pokemon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    // Water Pokemon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    // Either land or water Pokemon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 repelLureVar = VarGet(VAR_REPEL_STEP_COUNT);
    u16 steps = REPEL_LURE_STEPS(repelLureVar);
    bool32 isLure = IS_LAST_USED_LURE(repelLureVar);

    if (InBattlePike() || InBattlePyramid())
        return FALSE;
    if (InUnionRoom() == TRUE)
        return FALSE;

    if (steps != 0)
    {
        steps--;
        if (!isLure)
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }
        else
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps | REPEL_LURE_MASK);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }

    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!REPEL_STEP_COUNT)
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            u8 ourLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);

            if (wildLevel < ourLevel)
                return FALSE;
            else
                return TRUE;
        }
    }

    return FALSE;
}

static bool8 IsAbilityAllowingEncounter(u8 level)
{
    u16 ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, u8 type, u8 numMon, u8 *monIndex)
{
    u8 validIndexes[numMon]; // variable length array, an interesting feature
    u8 i, validMonCount;

    for (i = 0; i < numMon; i++)
        validIndexes[i] = 0;

    for (validMonCount = 0, i = 0; i < numMon; i++)
    {
        if (gSpeciesInfo[wildMon[i].species].types[0] == type || gSpeciesInfo[wildMon[i].species].types[1] == type)
            validIndexes[validMonCount++] = i;
    }

    if (validMonCount == 0 || validMonCount == numMon)
        return FALSE;

    *monIndex = validIndexes[Random() % validMonCount];
    return TRUE;
}

#include "data.h"
/*
static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemon *wildMon, u16 species, u8 area)
{
    u8 i, maxLevel = 0, numMon = 0;

    switch (area)
    {
    case WILD_AREA_LAND:
        numMon = LAND_WILD_COUNT;
        break;
    case WILD_AREA_WATER:
        numMon = WATER_WILD_COUNT;
        break;
    case WILD_AREA_ROCKS:
        numMon = ROCK_WILD_COUNT;
        break;
    }

    for (i = 0; i < numMon; i++)
    {
        if (wildMon[i].species == species && wildMon[i].maxLevel > maxLevel)
            maxLevel = wildMon[i].maxLevel;
    }

    return maxLevel;
}
*/
#ifdef BUGFIX
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex, u32 size)
#else
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex)
#endif
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return FALSE;
    else if (GetMonAbility(&gPlayerParty[0]) != ability)
        return FALSE;
    else if (Random() % 2 != 0)
        return FALSE;

#ifdef BUGFIX
    return TryGetRandomWildMonIndexByType(wildMon, type, size, monIndex);
#else
    return TryGetRandomWildMonIndexByType(wildMon, type, LAND_WILD_COUNT, monIndex);
#endif
}

static void ApplyFluteEncounterRateMod(u32 *encRate)
{
    if (FlagGet(FLAG_SYS_ENC_UP_ITEM) == TRUE)
        *encRate += *encRate / 2;
    else if (FlagGet(FLAG_SYS_ENC_DOWN_ITEM) == TRUE)
        *encRate = *encRate / 2;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encRate)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM) == ITEM_CLEANSE_TAG)
        *encRate = *encRate * 2 / 3;
}

bool8 TryDoDoubleWildBattle(void)
{
    if (GetSafariZoneFlag()
      || (B_DOUBLE_WILD_REQUIRE_2_MONS == TRUE && GetMonsStateToDoubles() != PLAYER_HAS_TWO_USABLE_MONS))
        return FALSE;
    else if (B_FLAG_FORCE_DOUBLE_WILD != 0 && FlagGet(B_FLAG_FORCE_DOUBLE_WILD))
        return TRUE;
    else if (B_DOUBLE_WILD_CHANCE != 0 && ((Random() % 100) + 1 <= B_DOUBLE_WILD_CHANCE))
        return TRUE;
    return FALSE;
}

bool8 StandardWildEncounter_Debug(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();
    if (TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
        return FALSE;

    DoStandardWildBattle_Debug();
    return TRUE;
}

static const u16 sSevenStarSpecies[] =
{
    SPECIES_MEW,
    SPECIES_CELEBI,
    SPECIES_JIRACHI,
    SPECIES_DEOXYS
};

static const u16 sSixStarSpecies[] =
{
    SPECIES_VENUSAUR,
    SPECIES_CHARIZARD,
    SPECIES_BLASTOISE,
    SPECIES_CROBAT,
    SPECIES_ANNIHILAPE,
    SPECIES_MAGNEZONE,
    SPECIES_RHYPERIOR,
    SPECIES_KINGDRA,
    SPECIES_DRAGONITE,
    SPECIES_MEWTWO,
    SPECIES_MEGANIUM,
    SPECIES_TYPHLOSION,
    SPECIES_FERALIGATR,
    SPECIES_URSALUNA,
    SPECIES_MAMOSWINE,
    SPECIES_TYRANITAR,
    SPECIES_LUGIA,
    SPECIES_HO_OH,
    SPECIES_SCEPTILE,
    SPECIES_BLAZIKEN,
    SPECIES_SWAMPERT,
    SPECIES_OBSTAGOON,
    SPECIES_DUSKNOIR,
    SPECIES_SALAMENCE,
    SPECIES_METAGROSS,
    SPECIES_KYOGRE,
    SPECIES_GROUDON
};

static const u16 sFiveStarSpecies[] =
{
    SPECIES_PIDGEOT,
    SPECIES_NIDOQUEEN,
    SPECIES_NIDOKING,
    SPECIES_VILEPLUME,
    SPECIES_BELLOSSOM,
    SPECIES_POLIWRATH,
    SPECIES_POLITOED,
    SPECIES_ALAKAZAM,
    SPECIES_MACHAMP,
    SPECIES_VICTREEBEL,
    SPECIES_GOLEM,
    SPECIES_SIRFETCHD,
    SPECIES_GENGAR,
    SPECIES_STEELIX,
    SPECIES_LICKILICKY,
    SPECIES_BLISSEY,
    SPECIES_TANGROWTH,
    SPECIES_MR_RIME,
    SPECIES_ELECTIVIRE,
    SPECIES_MAGMORTAR,
    SPECIES_PORYGON_Z,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_TOGEKISS,
    SPECIES_AMPHAROS,
    SPECIES_JUMPLUFF,
    SPECIES_AMBIPOM,
    SPECIES_YANMEGA,
    SPECIES_HONCHKROW,
    SPECIES_MISMAGIUS,
    SPECIES_FARIGIRAF,
    SPECIES_DUDUNSPARCE,
    SPECIES_GLISCOR,
    SPECIES_OVERQWIL,
    SPECIES_WEAVILE,
    SPECIES_SNEASLER,
    SPECIES_CURSOLA,
    SPECIES_WYRDEER,
    SPECIES_RAIKOU,
    SPECIES_ENTEI,
    SPECIES_SUICUNE,
    SPECIES_LUDICOLO,
    SPECIES_SHIFTRY,
    SPECIES_GARDEVOIR,
    SPECIES_GALLADE,
    SPECIES_SLAKING,
    SPECIES_EXPLOUD,
    SPECIES_PROBOPASS,
    SPECIES_AGGRON,
    SPECIES_ROSERADE,
    SPECIES_FLYGON,
    SPECIES_WALREIN,
    SPECIES_REGIROCK,
    SPECIES_REGICE,
    SPECIES_REGISTEEL,
    SPECIES_LATIAS,
    SPECIES_LATIOS
};

static const u16 sFourStarSpecies[] =
{
    SPECIES_IVYSAUR,
    SPECIES_CHARMELEON,
    SPECIES_WARTORTLE,
    SPECIES_RATICATE,
    SPECIES_FEAROW,
    SPECIES_ARBOK,
    SPECIES_RAICHU,
    SPECIES_SANDSLASH,
    SPECIES_CLEFABLE,
    SPECIES_NINETALES,
    SPECIES_WIGGLYTUFF,
    SPECIES_GOLBAT,
    SPECIES_PARASECT,
    SPECIES_VENOMOTH,
    SPECIES_DUGTRIO,
    SPECIES_PERSIAN,
    SPECIES_PERRSERKER,
    SPECIES_GOLDUCK,
    SPECIES_PRIMEAPE,
    SPECIES_ARCANINE,
    SPECIES_TENTACRUEL,
    SPECIES_RAPIDASH,
    SPECIES_SLOWBRO,
    SPECIES_SLOWKING,
    SPECIES_MAGNETON,
    SPECIES_DODRIO,
    SPECIES_DEWGONG,
    SPECIES_MUK,
    SPECIES_CLOYSTER,
    SPECIES_HYPNO,
    SPECIES_KINGLER,
    SPECIES_ELECTRODE,
    SPECIES_EXEGGUTOR,
    SPECIES_MAROWAK,
    SPECIES_WEEZING,
    SPECIES_RHYDON,
    SPECIES_SEADRA,
    SPECIES_SEAKING,
    SPECIES_STARMIE,
    SPECIES_GYARADOS,
    SPECIES_VAPOREON,
    SPECIES_JOLTEON,
    SPECIES_FLAREON,
    SPECIES_ESPEON,
    SPECIES_UMBREON,
    SPECIES_LEAFEON,
    SPECIES_GLACEON,
    SPECIES_SYLVEON,
    SPECIES_PORYGON2,
    SPECIES_OMASTAR,
    SPECIES_KABUTOPS,
    SPECIES_DRAGONAIR,
    SPECIES_BAYLEEF,
    SPECIES_QUILAVA,
    SPECIES_CROCONAW,
    SPECIES_FURRET,
    SPECIES_NOCTOWL,
    SPECIES_LEDIAN,
    SPECIES_ARIADOS,
    SPECIES_LANTURN,
    SPECIES_XATU,
    SPECIES_AZUMARILL,
    SPECIES_SUNFLORA,
    SPECIES_QUAGSIRE,
    SPECIES_FORRETRESS,
    SPECIES_GRANBULL,
    SPECIES_URSARING,
    SPECIES_MAGCARGO,
    SPECIES_PILOSWINE,
    SPECIES_OCTILLERY,
    SPECIES_HOUNDOOM,
    SPECIES_DONPHAN,
    SPECIES_PUPITAR,
    SPECIES_GROVYLE,
    SPECIES_COMBUSKEN,
    SPECIES_MARSHTOMP,
    SPECIES_MIGHTYENA,
    SPECIES_LINOONE,
    SPECIES_SWELLOW,
    SPECIES_PELIPPER,
    SPECIES_MASQUERAIN,
    SPECIES_BRELOOM,
    SPECIES_NINJASK,
    SPECIES_SHEDINJA,
    SPECIES_HARIYAMA,
    SPECIES_DELCATTY,
    SPECIES_MEDICHAM,
    SPECIES_MANECTRIC,
    SPECIES_SWALOT,
    SPECIES_SHARPEDO,
    SPECIES_WAILORD,
    SPECIES_CAMERUPT,
    SPECIES_GRUMPIG,
    SPECIES_CACTURNE,
    SPECIES_ALTARIA,
    SPECIES_WHISCASH,
    SPECIES_CRAWDAUNT,
    SPECIES_CLAYDOL,
    SPECIES_CRADILY,
    SPECIES_ARMALDO,
    SPECIES_MILOTIC,
    SPECIES_BANETTE,
    SPECIES_DUSCLOPS,
    SPECIES_GLALIE,
    SPECIES_FROSLASS,
    SPECIES_HUNTAIL,
    SPECIES_GOREBYSS,
    SPECIES_SHELGON,
    SPECIES_METANG
};

static const u16 sThreeStarSpecies[] =
{
    SPECIES_BUTTERFREE,
    SPECIES_BEEDRILL,
    SPECIES_PIDGEOTTO,
    SPECIES_NIDORINA,
    SPECIES_NIDORINO,
    SPECIES_GLOOM,
    SPECIES_POLIWHIRL,
    SPECIES_KADABRA,
    SPECIES_MACHOKE,
    SPECIES_WEEPINBELL,
    SPECIES_GRAVELER,
    SPECIES_FARFETCHD,
    SPECIES_HAUNTER,
    SPECIES_ONIX,
    SPECIES_HITMONLEE,
    SPECIES_HITMONCHAN,
    SPECIES_HITMONTOP,
    SPECIES_LICKITUNG,
    SPECIES_CHANSEY,
    SPECIES_TANGELA,
    SPECIES_KANGASKHAN,
    SPECIES_MR_MIME,
    SPECIES_SCYTHER,
    SPECIES_SCIZOR,
    SPECIES_KLEAVOR,
    SPECIES_JYNX,
    SPECIES_ELECTABUZZ,
    SPECIES_MAGMAR,
    SPECIES_PINSIR,
    SPECIES_TAUROS,
    SPECIES_LAPRAS,
    SPECIES_DITTO,
    SPECIES_PORYGON,
    SPECIES_AERODACTYL,
    SPECIES_SNORLAX,
    SPECIES_TOGETIC,
    SPECIES_FLAAFFY,
    SPECIES_SUDOWOODO,
    SPECIES_SKIPLOOM,
    SPECIES_AIPOM,
    SPECIES_YANMA,
    SPECIES_MURKROW,
    SPECIES_MISDREAVUS,
    SPECIES_UNOWN,
    SPECIES_WOBBUFFET,
    SPECIES_GIRAFARIG,
    SPECIES_DUNSPARCE,
    SPECIES_GLIGAR,
    SPECIES_QWILFISH,
    SPECIES_SHUCKLE,
    SPECIES_SNEASEL,
    SPECIES_CORSOLA,
    SPECIES_DELIBIRD,
    SPECIES_MANTINE,
    SPECIES_SKARMORY,
    SPECIES_STANTLER,
    SPECIES_SMEARGLE,
    SPECIES_MILTANK,
    SPECIES_BEAUTIFLY,
    SPECIES_DUSTOX,
    SPECIES_LOMBRE,
    SPECIES_NUZLEAF,
    SPECIES_KIRLIA,
    SPECIES_VIGOROTH,
    SPECIES_LOUDRED,
    SPECIES_NOSEPASS,
    SPECIES_SABLEYE,
    SPECIES_MAWILE,
    SPECIES_LAIRON,
    SPECIES_PLUSLE,
    SPECIES_MINUN,
    SPECIES_VOLBEAT,
    SPECIES_ILLUMISE,
    SPECIES_ROSELIA,
    SPECIES_TORKOAL,
    SPECIES_SPINDA,
    SPECIES_VIBRAVA,
    SPECIES_ZANGOOSE,
    SPECIES_SEVIPER,
    SPECIES_LUNATONE,
    SPECIES_SOLROCK,
    SPECIES_CASTFORM,
    SPECIES_KECLEON,
    SPECIES_TROPIUS,
    SPECIES_CHIMECHO,
    SPECIES_ABSOL,
    SPECIES_SEALEO,
    SPECIES_RELICANTH,
    SPECIES_LUVDISC
};

static const u16 sTwoStarSpecies[] =
{
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_METAPOD,
    SPECIES_KAKUNA,
    SPECIES_RATTATA,
    SPECIES_SPEAROW,
    SPECIES_EKANS,
    SPECIES_PIKACHU,
    SPECIES_SANDSHREW,
    SPECIES_CLEFAIRY,
    SPECIES_VULPIX,
    SPECIES_JIGGLYPUFF,
    SPECIES_ZUBAT,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_DIGLETT,
    SPECIES_MEOWTH,
    SPECIES_PSYDUCK,
    SPECIES_MANKEY,
    SPECIES_GROWLITHE,
    SPECIES_TENTACOOL,
    SPECIES_PONYTA,
    SPECIES_SLOWPOKE,
    SPECIES_MAGNEMITE,
    SPECIES_DODUO,
    SPECIES_SEEL,
    SPECIES_GRIMER,
    SPECIES_SHELLDER,
    SPECIES_DROWZEE,
    SPECIES_KRABBY,
    SPECIES_VOLTORB,
    SPECIES_EXEGGCUTE,
    SPECIES_CUBONE,
    SPECIES_KOFFING,
    SPECIES_RHYHORN,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_MAGIKARP,
    SPECIES_EEVEE,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_DRATINI,
    SPECIES_CHIKORITA,
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_SENTRET,
    SPECIES_HOOTHOOT,
    SPECIES_LEDYBA,
    SPECIES_SPINARAK,
    SPECIES_CHINCHOU,
    SPECIES_NATU,
    SPECIES_SUNKERN,
    SPECIES_WOOPER,
    SPECIES_PINECO,
    SPECIES_SNUBBULL,
    SPECIES_TEDDIURSA,
    SPECIES_SLUGMA,
    SPECIES_SWINUB,
    SPECIES_REMORAID,
    SPECIES_HOUNDOUR,
    SPECIES_PHANPY,
    SPECIES_LARVITAR,
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_POOCHYENA,
    SPECIES_ZIGZAGOON,
    SPECIES_SILCOON,
    SPECIES_CASCOON,
    SPECIES_TAILLOW,
    SPECIES_WINGULL,
    SPECIES_SURSKIT,
    SPECIES_SHROOMISH,
    SPECIES_NINCADA,
    SPECIES_MAKUHITA,
    SPECIES_SKITTY,
    SPECIES_MEDITITE,
    SPECIES_ELECTRIKE,
    SPECIES_GULPIN,
    SPECIES_CARVANHA,
    SPECIES_WAILMER,
    SPECIES_NUMEL,
    SPECIES_SPOINK,
    SPECIES_CACNEA,
    SPECIES_SWABLU,
    SPECIES_BARBOACH,
    SPECIES_CORPHISH,
    SPECIES_BALTOY,
    SPECIES_LILEEP,
    SPECIES_ANORITH,
    SPECIES_FEEBAS,
    SPECIES_SHUPPET,
    SPECIES_DUSKULL,
    SPECIES_SNORUNT,
    SPECIES_CLAMPERL,
    SPECIES_BAGON,
    SPECIES_BELDUM
};

static const u16 sOneStarSpecies[] =
{
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PIDGEY,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_ODDISH,
    SPECIES_POLIWAG,
    SPECIES_ABRA,
    SPECIES_MACHOP,
    SPECIES_BELLSPROUT,
    SPECIES_GEODUDE,
    SPECIES_GASTLY,
    SPECIES_MAREEP,
    SPECIES_HOPPIP,
    SPECIES_WURMPLE,
    SPECIES_LOTAD,
    SPECIES_SEEDOT,
    SPECIES_RALTS,
    SPECIES_SLAKOTH,
    SPECIES_WHISMUR,
    SPECIES_ARON,
    SPECIES_TRAPINCH,
    SPECIES_SPHEAL
};

static const u16 sNoStarSpecies[] =
{
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_TYROGUE,
    SPECIES_HAPPINY,
    SPECIES_MIME_JR,
    SPECIES_SMOOCHUM,
    SPECIES_ELEKID,
    SPECIES_MAGBY,
    SPECIES_MUNCHLAX,
    SPECIES_TOGEPI,
    SPECIES_AZURILL,
    SPECIES_BONSLY,
    SPECIES_WYNAUT,
    SPECIES_MANTYKE,
    SPECIES_BUDEW,
    SPECIES_CHINGLING
};

#define SEVEN_STAR 7
#define SIX_STAR   6
#define FIVE_STAR  5
#define FOUR_STAR  4
#define THREE_STAR 3
#define TWO_STAR   2
#define ONE_STAR   1
#define NO_STAR    0

static u16 PickRaidSpecies(void)
{
    u16 rnd = (Random() % 100) + 1;
    u8 raidStarLevel = NO_STAR;
    u16 species;
    u32 flag;
/*
    if (FlagGet(FLAG_SYS_POSTGAME_CLEAR))
    {
        if (rnd > 80)
            raidStarLevel = SEVEN_STAR;
        else if (rnd > 50)
            raidStarLevel = SIX_STAR;
        else if (rnd > 30)
            raidStarLevel = FIVE_STAR;
        else if (rnd > 15)
            raidStarLevel = FOUR_STAR;
        else // (rnd > 0)
            raidStarLevel = THREE_STAR;
    }
    else
*/
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        if (rnd > 70)
            raidStarLevel = SIX_STAR;
        else if (rnd > 40)
            raidStarLevel = FIVE_STAR;
        else if (rnd > 20)
            raidStarLevel = FOUR_STAR;
        else // (rnd > 0)
            raidStarLevel = THREE_STAR;
    }
    else if (FlagGet(FLAG_BADGE06_GET))
    {
        if (rnd > 70)
            raidStarLevel = FIVE_STAR;
        else if (rnd > 40)
            raidStarLevel = FOUR_STAR;
        else if (rnd > 20)
            raidStarLevel = THREE_STAR;
        else // (rnd > 0)
            raidStarLevel = TWO_STAR;
    }
    else if (FlagGet(FLAG_BADGE03_GET))
    {
        if (rnd > 60)
            raidStarLevel = THREE_STAR;
        else if (rnd > 20)
            raidStarLevel = TWO_STAR;
        else // (rnd > 0)
            raidStarLevel = ONE_STAR;
    }
    else
    {
        if (rnd > 80)
            raidStarLevel = ONE_STAR;
        else // (rnd > 0)
            raidStarLevel = NO_STAR;
    }

    switch (raidStarLevel)
    {
    case SEVEN_STAR:
        if (FlagGet(FLAG_DAILY_SEVEN_STAR_RAID))
            raidStarLevel--;
        species = sSevenStarSpecies[Random() % NELEMS(sSevenStarSpecies)];
        break;
    case SIX_STAR:
        if (FlagGet(FLAG_DAILY_SIX_STAR_RAID))
            raidStarLevel--;
        species = sSixStarSpecies[Random() % NELEMS(sSixStarSpecies)];
        break;
    case FIVE_STAR:
        if (FlagGet(FLAG_DAILY_FIVE_STAR_RAID))
            raidStarLevel--;
        species = sFiveStarSpecies[Random() % NELEMS(sFiveStarSpecies)];
        break;
    case FOUR_STAR:
        if (FlagGet(FLAG_DAILY_FOUR_STAR_RAID))
            raidStarLevel--;
        species = sFourStarSpecies[Random() % NELEMS(sFourStarSpecies)];
        break;
    case THREE_STAR:
        if (FlagGet(FLAG_DAILY_THREE_STAR_RAID))
            raidStarLevel--;
        species = sThreeStarSpecies[Random() % NELEMS(sThreeStarSpecies)];
        break;
    case TWO_STAR:
        if (FlagGet(FLAG_DAILY_TWO_STAR_RAID))
            raidStarLevel--;
        species = sTwoStarSpecies[Random() % NELEMS(sTwoStarSpecies)];
        break;
    case ONE_STAR:
        if (FlagGet(FLAG_DAILY_ONE_STAR_RAID))
            raidStarLevel--;
        species = sOneStarSpecies[Random() % NELEMS(sOneStarSpecies)];
        break;
    case NO_STAR:
        species = sNoStarSpecies[Random() % NELEMS(sNoStarSpecies)];
        break;
    }

    flag = (DAILY_FLAGS_START + 0x2) + raidStarLevel;
    if (flag > (DAILY_FLAGS_START + 0x2)
     && flag < (DAILY_FLAGS_START + 0xA))
        FlagSet(flag);
    return species;
}

void SetRaidFlags(void)
{
    FlagSet(B_SMART_WILD_AI_FLAG);
    FlagSet(B_FLAG_DYNAMAX_BATTLE);
}

void ClearRaidFlags(void)
{
    FlagClear(B_SMART_WILD_AI_FLAG);
    FlagClear(B_FLAG_DYNAMAX_BATTLE);
}

void CreateRaidMons(u16 species, u8 lvl1, u8 lvl2)
{
    CreateWildMon(species, lvl1);
    if (TryDoDoubleWildBattle())
    {
        struct Pokemon mon1 = gEnemyParty[0];
        CreateWildMon(species, lvl2);
        gEnemyParty[1] = mon1;
        BattleSetup_StartDoubleWildBattle();
    }
    else
    {
        BattleSetup_StartWildBattle();
    }
}

void StartRaidEncounter(void)
{
    u16 species = PickRaidSpecies();
    u8 lvl1 = GetMonScaledLevel(Random() % 2);
    u8 lvl2 = GetMonScaledLevel(Random() % 2);

    SetRaidFlags();
    CreateRaidMons(species, lvl1, lvl2);
    ClearRaidFlags();
}
