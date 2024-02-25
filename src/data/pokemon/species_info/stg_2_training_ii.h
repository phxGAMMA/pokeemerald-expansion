#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_KOROMON
#define KOROMON_MISC_INFO                                                                        \
        .baseHP        = 60,                                                                     \
        .baseAttack    = 40,                                                                     \
        .baseDefense   = 40,                                                                     \
        .baseSpeed     = 20,                                                                     \
        .baseSpAttack  = 20,                                                                     \
        .baseSpDefense = 20,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 120,                                                                        \
        .expYield = 200,                                                                         \
        .evYield_HP        = 1,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 55,                                                                         \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_BALL_FETCH, ABILITY_NONE, ABILITY_NONE },                         \
        .bodyColor = BODY_COLOR_RED,                                                             \
        .speciesName = _("Koro"),                                                                \
        .cryId = CRY_KOROMON,                                                                    \
        .natDexNum = NATIONAL_DEX_KOROMON,                                                       \
        .categoryName = _("Lesser"),                                                             \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Koromon, 64, 64),                                                              \
        /*FRONT_PIC_FEMALE(Koromon, 64, 64),*/                                                   \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Koromon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Koromon, 64, 64),                                                               \
        /*BACK_PIC_FEMALE(Koromon, 64, 64),*/                                                    \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,                                                  \
        PALETTES(Koromon),                                                                       \
        /*PALETTE_FEMALE(Koromon),*/                                                             \
        ICON(Koromon, 0),                                                                        \
        /*ICON_FEMALE(Koromon, 0),*/                                                             \
        LEARNSETS(Koromon),                                                                      \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   20, SPECIES_AGUMON},                \
                                {EVO_FRIENDSHIP_NO_HEARTS,   20, SPECIES_AGUMON_BLACK},          \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 20, SPECIES_AGUMON_X}),             \
        /*.formSpeciesIdTable = sKoromonFormSpeciesIdTable,*/                                    \
        /*.formChangeTable = sKoromonFormChangeTable,*/                                          \
        .isLegendary = FALSE
    [SPECIES_KOROMON] =
    {
        KOROMON_MISC_INFO,
    },
#endif //D_FAMILY_KOROMON

#if D_FAMILY_TSUNOMON
#define TSUNOMON_MISC_INFO                                                                       \
        .baseHP        = 20,                                                                     \
        .baseAttack    = 20,                                                                     \
        .baseDefense   = 20,                                                                     \
        .baseSpeed     = 60,                                                                     \
        .baseSpAttack  = 40,                                                                     \
        .baseSpDefense = 40,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 120,                                                                        \
        .expYield = 200,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 1,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 55,                                                                         \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_BALL_FETCH, ABILITY_NONE, ABILITY_NONE },                         \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Tsuno"),                                                               \
        .cryId = CRY_TSUNOMON,                                                                   \
        .natDexNum = NATIONAL_DEX_TSUNOMON,                                                      \
        .categoryName = _("Lesser"),                                                             \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Tsunomon, 64, 64),                                                             \
        /*FRONT_PIC_FEMALE(Tsunomon, 64, 64),*/                                                  \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Tsunomon,                                                      \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Tsunomon, 64, 56),                                                              \
        /*BACK_PIC_FEMALE(Tsunomon, 64, 64),*/                                                   \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Tsunomon),                                                                      \
        /*PALETTE_FEMALE(Tsunomon),*/                                                            \
        ICON(Tsunomon, 0),                                                                       \
        /*ICON_FEMALE(Tsunomon, 0),*/                                                            \
        LEARNSETS(Tsunomon),                                                                     \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   20, SPECIES_GABUMON},               \
                                {EVO_FRIENDSHIP_NO_HEARTS,   20, SPECIES_GABUMON_BLACK},         \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 20, SPECIES_GABUMON_X}),            \
        /*.formSpeciesIdTable = sTsunomonFormSpeciesIdTable,*/                                   \
        /*.formChangeTable = sTsunomonFormChangeTable,*/                                         \
        .isLegendary = FALSE
    [SPECIES_TSUNOMON] =
    {
        TSUNOMON_MISC_INFO,
    },
#endif //D_FAMILY_TSUNOMON

#if D_FAMILY_DEMI_VEEMON
#define DEMI_VEEMON_MISC_INFO                                                                    \
        .baseHP        = 40,                                                                     \
        .baseAttack    = 60,                                                                     \
        .baseDefense   = 40,                                                                     \
        .baseSpeed     = 20,                                                                     \
        .baseSpAttack  = 20,                                                                     \
        .baseSpDefense = 20,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 120,                                                                        \
        .expYield = 200,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 1,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 55,                                                                         \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_BALL_FETCH, ABILITY_NONE, ABILITY_NONE },                         \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("D.Vee"),                                                               \
        .cryId = CRY_DEMI_VEEMON,                                                                \
        .natDexNum = NATIONAL_DEX_DEMI_VEEMON,                                                   \
        .categoryName = _("B.Dragon"),                                                           \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(DemiVeemon, 64, 64),                                                           \
        /*FRONT_PIC_FEMALE(DemiVeemon, 64, 64),*/                                                \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_DemiVeemon,                                                    \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(DemiVeemon, 64, 56),                                                            \
        /*BACK_PIC_FEMALE(DemiVeemon, 64, 64),*/                                                 \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(DemiVeemon),                                                                    \
        /*PALETTE_FEMALE(DemiVeemon),*/                                                          \
        ICON(DemiVeemon, 0),                                                                     \
        /*ICON_FEMALE(DemiVeemon, 0),*/                                                          \
        LEARNSETS(DemiVeemon),                                                                   \
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_VEEMON}),                                \
        /*.formSpeciesIdTable = sDemiVeemonFormSpeciesIdTable,*/                                 \
        /*.formChangeTable = sDemiVeemonFormChangeTable,*/                                       \
        .isLegendary = FALSE
    [SPECIES_DEMI_VEEMON] =
    {
        DEMI_VEEMON_MISC_INFO,
    },
#endif //D_FAMILY_DEMI_VEEMON

#if D_FAMILY_MINOMON
#define MINOMON_MISC_INFO                                                                        \
        .baseHP        = 20,                                                                     \
        .baseAttack    = 20,                                                                     \
        .baseDefense   = 20,                                                                     \
        .baseSpeed     = 40,                                                                     \
        .baseSpAttack  = 60,                                                                     \
        .baseSpDefense = 40,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 120,                                                                        \
        .expYield = 200,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 1,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 55,                                                                         \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_BALL_FETCH, ABILITY_NONE, ABILITY_NONE },                         \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Mino"),                                                                \
        .cryId = CRY_MINOMON,                                                                    \
        .natDexNum = NATIONAL_DEX_MINOMON,                                                       \
        .categoryName = _("Larva"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Minomon, 64, 64),                                                              \
        /*FRONT_PIC_FEMALE(Minomon, 64, 64),*/                                                   \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Minomon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Minomon, 64, 56),                                                               \
        /*BACK_PIC_FEMALE(Minomon, 64, 64),*/                                                    \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Minomon),                                                                       \
        /*PALETTE_FEMALE(Minomon),*/                                                             \
        ICON(Minomon, 0),                                                                        \
        /*ICON_FEMALE(Minomon, 0),*/                                                             \
        LEARNSETS(Minomon),                                                                      \
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_WORMMON}),                               \
        /*.formSpeciesIdTable = sMinomonFormSpeciesIdTable,*/                                    \
        /*.formChangeTable = sMinomonFormChangeTable,*/                                          \
        .isLegendary = FALSE
    [SPECIES_MINOMON] =
    {
        MINOMON_MISC_INFO,
    },
#endif //D_FAMILY_MINOMON

#ifdef __INTELLISENSE__
};
#endif