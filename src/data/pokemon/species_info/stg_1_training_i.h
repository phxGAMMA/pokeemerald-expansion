#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_BOTAMON
#define BOTAMON_MISC_INFO                                                                        \
        .baseHP        = 30,                                                                     \
        .baseAttack    = 20,                                                                     \
        .baseDefense   = 20,                                                                     \
        .baseSpeed     = 10,                                                                     \
        .baseSpAttack  = 10,                                                                     \
        .baseSpDefense = 10,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 150,                                                                        \
        .expYield = 100,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 5,                                                                          \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_NONE },                             \
        .bodyColor = BODY_COLOR_RED,                                                             \
        .speciesName = _("Bota"),                                                                \
        .cryId = CRY_BOTAMON,                                                                    \
        .natDexNum = NATIONAL_DEX_BOTAMON,                                                       \
        .categoryName = _("Slime"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Botamon, 64, 64),                                                              \
        /*FRONT_PIC_FEMALE(Botamon, 64, 64),*/                                                   \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Botamon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Botamon, 64, 64),                                                               \
        /*BACK_PIC_FEMALE(Botamon, 64, 64),*/                                                    \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,                                                  \
        PALETTES(Botamon),                                                                       \
        /*PALETTE_FEMALE(Botamon),*/                                                             \
        ICON(Botamon, 0),                                                                        \
        /*ICON_FEMALE(Botamon, 0),*/                                                             \
        LEARNSETS(Botamon),                                                                      \
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_KOROMON}),                               \
        /*.formSpeciesIdTable = sBotamonFormSpeciesIdTable,*/                                    \
        /*.formChangeTable = sBotamonFormChangeTable,*/                                          \
        .isLegendary = FALSE
    [SPECIES_BOTAMON] =
    {
        BOTAMON_MISC_INFO,
    },
#endif //D_FAMILY_BOTAMON

#if D_FAMILY_PUNIMON
#define PUNIMON_MISC_INFO                                                                        \
        .baseHP        = 10,                                                                     \
        .baseAttack    = 10,                                                                     \
        .baseDefense   = 10,                                                                     \
        .baseSpeed     = 30,                                                                     \
        .baseSpAttack  = 20,                                                                     \
        .baseSpDefense = 20,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 150,                                                                        \
        .expYield = 100,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 5,                                                                          \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_NONE },                             \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Puni"),                                                                \
        .cryId = CRY_PUNIMON,                                                                    \
        .natDexNum = NATIONAL_DEX_PUNIMON,                                                       \
        .categoryName = _("Slime"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Punimon, 64, 64),                                                              \
        /*FRONT_PIC_FEMALE(Punimon, 64, 64),*/                                                   \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Punimon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Punimon, 64, 56),                                                               \
        /*BACK_PIC_FEMALE(Punimon, 64, 64),*/                                                    \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Punimon),                                                                       \
        /*PALETTE_FEMALE(Punimon),*/                                                             \
        ICON(Punimon, 0),                                                                        \
        /*ICON_FEMALE(Punimon, 0),*/                                                             \
        LEARNSETS(Punimon),                                                                      \
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_TSUNOMON}),                              \
        /*.formSpeciesIdTable = sPunimonFormSpeciesIdTable,*/                                    \
        /*.formChangeTable = sPunimonFormChangeTable,*/                                          \
        .isLegendary = FALSE
    [SPECIES_PUNIMON] =
    {
        PUNIMON_MISC_INFO,
    },
#endif //D_FAMILY_PUNIMON

#if D_FAMILY_CHIBOMON
#define CHIBOMON_MISC_INFO                                                                       \
        .baseHP        = 20,                                                                     \
        .baseAttack    = 30,                                                                     \
        .baseDefense   = 20,                                                                     \
        .baseSpeed     = 10,                                                                     \
        .baseSpAttack  = 10,                                                                     \
        .baseSpDefense = 10,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 150,                                                                        \
        .expYield = 100,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 5,                                                                          \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_NONE },                             \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Chibo"),                                                               \
        .cryId = CRY_CHIBOMON,                                                                   \
        .natDexNum = NATIONAL_DEX_CHIBOMON,                                                      \
        .categoryName = _("Slime"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Chibomon, 64, 64),                                                             \
        /*FRONT_PIC_FEMALE(Chibomon, 64, 64),*/                                                  \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Chibomon,                                                      \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Chibomon, 64, 56),                                                              \
        /*BACK_PIC_FEMALE(Chibomon, 64, 64),*/                                                   \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Chibomon),                                                                      \
        /*PALETTE_FEMALE(Chibomon),*/                                                            \
        ICON(Chibomon, 0),                                                                       \
        /*ICON_FEMALE(Chibomon, 0),*/                                                            \
        LEARNSETS(Chibomon),                                                                     \
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_DEMI_VEEMON}),                           \
        /*.formSpeciesIdTable = sChibomonFormSpeciesIdTable,*/                                   \
        /*.formChangeTable = sChibomonFormChangeTable,*/                                         \
        .isLegendary = FALSE
    [SPECIES_CHIBOMON] =
    {
        CHIBOMON_MISC_INFO,
    },
#endif //D_FAMILY_CHIBOMON

#if D_FAMILY_LEAFMON
#define LEAFMON_MISC_INFO                                                                        \
        .baseHP        = 10,                                                                     \
        .baseAttack    = 10,                                                                     \
        .baseDefense   = 10,                                                                     \
        .baseSpeed     = 20,                                                                     \
        .baseSpAttack  = 30,                                                                     \
        .baseSpDefense = 20,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 150,                                                                        \
        .expYield = 100,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 5,                                                                          \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_NONE },                             \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Leaf"),                                                                \
        .cryId = CRY_LEAFMON,                                                                    \
        .natDexNum = NATIONAL_DEX_LEAFMON,                                                       \
        .categoryName = _("Slime"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Leafmon, 64, 64),                                                              \
        /*FRONT_PIC_FEMALE(Leafmon, 64, 64),*/                                                   \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Leafmon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Leafmon, 64, 56),                                                               \
        /*BACK_PIC_FEMALE(Leafmon, 64, 64),*/                                                    \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Leafmon),                                                                       \
        /*PALETTE_FEMALE(Leafmon),*/                                                             \
        ICON(Leafmon, 0),                                                                        \
        /*ICON_FEMALE(Leafmon, 0),*/                                                             \
        LEARNSETS(Leafmon),                                                                      \
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_MINOMON}),                               \
        /*.formSpeciesIdTable = sLeafmonFormSpeciesIdTable,*/                                    \
        /*.formChangeTable = sLeafmonFormChangeTable,*/                                          \
        .isLegendary = FALSE
    [SPECIES_LEAFMON] =
    {
        LEAFMON_MISC_INFO,
    },
#endif //D_FAMILY_LEAFMON

#ifdef __INTELLISENSE__
};
#endif