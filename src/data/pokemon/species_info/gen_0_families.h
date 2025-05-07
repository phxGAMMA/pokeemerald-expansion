#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen0[] =
{
#endif

#if P_FAMILY_AGUMON
    [SPECIES_AGUMON] =
    {
        .baseHP        = 120,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_VACCINE, TYPE_FIRE),
        .catchRate = 1,
        .expYield = 255,
        .evYield_HP        = 1,
        .evYield_Attack    = 1,
        .evYield_Defense   = 1,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 5,
        .friendship = 0,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SIMPLE, ABILITY_STAMINA, ABILITY_WELL_BAKED_BODY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Agu"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_AGUMON,
        .categoryName = _("Reptile"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Despite how weak this fledging is,\n"
            "it boasts a ferocious attitude.\n"
            "Sharp, solid claws grow from each limb,\n"
            "offering some power in a fight."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 512,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Agumon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .backPic = gMonBackPic_Agumon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Agumon,
        .shinyPalette = gMonShinyPalette_Agumon,
        .iconSprite = gMonIcon_Agumon,
        .iconPalIndex = 0,
        SHADOW(0, 0, SHADOW_SIZE_M)
        FOOTPRINT(Agumon)
        OVERWORLD(
            sPicTable_Agumon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Agumon,
            gShinyOverworldPalette_Agumon
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sAgumonLevelUpLearnset,
        .teachableLearnset = sAgumonTeachableLearnset,
    },
#endif //P_FAMILY_AGUMON

#if P_FAMILY_GABUMON
    [SPECIES_GABUMON] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 120,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_VACCINE, TYPE_ICE),
        .catchRate = 1,
        .expYield = 255,
        .evYield_HP        = 1,
        .evYield_Attack    = 1,
        .evYield_Defense   = 1,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 5,
        .friendship = 0,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_GUTS, ABILITY_FUR_COAT, ABILITY_QUICK_FEET },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Gabu"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_GABUMON,
        .categoryName = _("Reptile"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Although it is covered by a fur pelt,\n"
            "this is a genuine reptile Digimon.\n"
            "When it is wearing its fur pelt,\n"
            "its personality completely shifts."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 512,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gabumon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Gabumon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Gabumon,
        .shinyPalette = gMonShinyPalette_Gabumon,
        .iconSprite = gMonIcon_Gabumon,
        .iconPalIndex = 0,
        SHADOW(0, 0, SHADOW_SIZE_M)
        FOOTPRINT(Gabumon)
        OVERWORLD(
            sPicTable_Gabumon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gabumon,
            gShinyOverworldPalette_Gabumon
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sGabumonLevelUpLearnset,
        .teachableLearnset = sGabumonTeachableLearnset,
    },
#endif //P_FAMILY_GABUMON

#ifdef __INTELLISENSE__
};
#endif
