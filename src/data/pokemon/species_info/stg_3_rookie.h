#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_AGUMON
#define AGUMON_MISC_INFO                                                                         \
        .baseHP        = 90,                                                                     \
        .baseAttack    = 60,                                                                     \
        .baseDefense   = 60,                                                                     \
        .baseSpeed     = 30,                                                                     \
        .baseSpAttack  = 30,                                                                     \
        .baseSpDefense = 30,                                                                     \
        .catchRate = 90,                                                                         \
        .expYield = 300,                                                                         \
        .evYield_HP        = 1,                                                                  \
        .evYield_Attack    = 1,                                                                  \
        .evYield_Defense   = 1,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 105,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_RED,                                                             \
        .speciesName = _("Agu"),                                                                 \
        .cryId = CRY_AGUMON,                                                                     \
        .natDexNum = NATIONAL_DEX_AGUMON,                                                        \
        .categoryName = _("Reptile"),                                                            \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Agumon,                                                        \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,                                                  \
        LEARNSETS(Agumon),                                                                       \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   30, SPECIES_GREYMON},               \
                                {EVO_FRIENDSHIP_NO_HEARTS,   30, SPECIES_GREYMON_BLACK},         \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 30, SPECIES_GREYMON_X}),            \
        .formSpeciesIdTable = sAgumonFormSpeciesIdTable,                                         \
        .formChangeTable = sAgumonFormChangeTable,                                               \
        .isLegendary = FALSE
    [SPECIES_AGUMON] =
    {
        AGUMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        FRONT_PIC(Agumon, 64, 64),
        //FRONT_PIC_FEMALE(Agumon, 64, 64),
        BACK_PIC(Agumon, 64, 64),
        //BACK_PIC_FEMALE(Agumon, 64, 64),
        PALETTES(Agumon),
        //PALETTE_FEMALE(Agumon),
        ICON(Agumon, 0),
        //ICON_FEMALE(Agumon, 0),
    },
    [SPECIES_AGUMON_BLACK] =
    {
        AGUMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(AgumonBlack, 64, 64),
        //FRONT_PIC_FEMALE(AgumonBlack, 64, 64),
        BACK_PIC(AgumonBlack, 64, 64),
        //BACK_PIC_FEMALE(AgumonBlack, 64, 64),
        PALETTES(AgumonBlack),
        //PALETTE_FEMALE(AgumonBlack),
        ICON(AgumonBlack, 0),
        //ICON_FEMALE(AgumonBlack, 0),
    },
    [SPECIES_AGUMON_X] =
    {
        AGUMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(AgumonX, 64, 64),
        //FRONT_PIC_FEMALE(AgumonX, 64, 64),
        BACK_PIC(AgumonX, 64, 64),
        //BACK_PIC_FEMALE(AgumonX, 64, 64),
        PALETTES(AgumonX),
        //PALETTE_FEMALE(AgumonX),
        ICON(AgumonX, 0),
        //ICON_FEMALE(AgumonX, 0),
    },
#endif //D_FAMILY_AGUMON

#if D_FAMILY_GABUMON
#define GABUMON_MISC_INFO                                                                        \
        .baseHP        = 30,                                                                     \
        .baseAttack    = 30,                                                                     \
        .baseDefense   = 30,                                                                     \
        .baseSpeed     = 90,                                                                     \
        .baseSpAttack  = 60,                                                                     \
        .baseSpDefense = 60,                                                                     \
        .catchRate = 90,                                                                         \
        .expYield = 300,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 1,                                                                  \
        .evYield_SpAttack  = 1,                                                                  \
        .evYield_SpDefense = 1,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 105,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Gabu"),                                                                \
        .cryId = CRY_GABUMON,                                                                    \
        .natDexNum = NATIONAL_DEX_GABUMON,                                                       \
        .categoryName = _("Reptile"),                                                            \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Gabumon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        LEARNSETS(Gabumon),                                                                      \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   30, SPECIES_GARURUMON},             \
                                {EVO_FRIENDSHIP_NO_HEARTS,   30, SPECIES_GARURUMON_BLACK},       \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 30, SPECIES_GARURUMON_X}),          \
        .formSpeciesIdTable = sGabumonFormSpeciesIdTable,                                        \
        .formChangeTable = sGabumonFormChangeTable,                                              \
        .isLegendary = FALSE
    [SPECIES_GABUMON] =
    {
        GABUMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        FRONT_PIC(Gabumon, 64, 64),
        //FRONT_PIC_FEMALE(Gabumon, 64, 64),
        BACK_PIC(Gabumon, 64, 64),
        //BACK_PIC_FEMALE(Gabumon, 64, 64),
        PALETTES(Gabumon),
        //PALETTE_FEMALE(Gabumon),
        ICON(Gabumon, 0),
        //ICON_FEMALE(Gabumon, 0),
    },
    [SPECIES_GABUMON_BLACK] =
    {
        GABUMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(GabumonBlack, 64, 64),
        //FRONT_PIC_FEMALE(GabumonBlack, 64, 64),
        BACK_PIC(GabumonBlack, 64, 64),
        //BACK_PIC_FEMALE(GabumonBlack, 64, 64),
        PALETTES(GabumonBlack),
        //PALETTE_FEMALE(GabumonBlack),
        ICON(GabumonBlack, 0),
        //ICON_FEMALE(GabumonBlack, 0),
    },
    [SPECIES_GABUMON_X] =
    {
        GABUMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(GabumonX, 64, 64),
        //FRONT_PIC_FEMALE(GabumonX, 64, 64),
        BACK_PIC(GabumonX, 64, 64),
        //BACK_PIC_FEMALE(GabumonX, 64, 64),
        PALETTES(GabumonX),
        //PALETTE_FEMALE(GabumonX),
        ICON(GabumonX, 0),
        //ICON_FEMALE(GabumonX, 0),
    },
#endif //D_FAMILY_GABUMON

#if D_FAMILY_VEEMON
#define VEEMON_MISC_INFO                                                                         \
        .baseHP        = 60,                                                                     \
        .baseAttack    = 90,                                                                     \
        .baseDefense   = 60,                                                                     \
        .baseSpeed     = 30,                                                                     \
        .baseSpAttack  = 30,                                                                     \
        .baseSpDefense = 30,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 90,                                                                         \
        .expYield = 300,                                                                         \
        .evYield_HP        = 1,                                                                  \
        .evYield_Attack    = 1,                                                                  \
        .evYield_Defense   = 1,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 105,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE, ABILITY_NONE },                           \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Vee"),                                                                 \
        .cryId = CRY_VEEMON,                                                                     \
        .natDexNum = NATIONAL_DEX_VEEMON,                                                        \
        .categoryName = _("M.Dragon"),                                                           \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Veemon, 64, 64),                                                               \
        /*FRONT_PIC_FEMALE(Veemon, 64, 64),*/                                                    \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Veemon,                                                        \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Veemon, 64, 56),                                                                \
        /*BACK_PIC_FEMALE(Veemon, 64, 64),*/                                                     \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Veemon),                                                                        \
        /*PALETTE_FEMALE(Veemon),*/                                                              \
        ICON(Veemon, 0),                                                                         \
        /*ICON_FEMALE(Veemon, 0),*/                                                              \
        LEARNSETS(Veemon),                                                                       \
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_EX_VEEMON}),                             \
        /*.formSpeciesIdTable = sVeemonFormSpeciesIdTable,*/                                     \
        /*.formChangeTable = sVeemonFormChangeTable,*/                                           \
        .isLegendary = FALSE
    [SPECIES_VEEMON] =
    {
        VEEMON_MISC_INFO,
    },
#endif //D_FAMILY_VEEMON

#if D_FAMILY_WORMMON
#define WORMMON_MISC_INFO                                                                        \
        .baseHP        = 30,                                                                     \
        .baseAttack    = 30,                                                                     \
        .baseDefense   = 30,                                                                     \
        .baseSpeed     = 60,                                                                     \
        .baseSpAttack  = 90,                                                                     \
        .baseSpDefense = 60,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 90,                                                                         \
        .expYield = 300,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 1,                                                                  \
        .evYield_SpAttack  = 1,                                                                  \
        .evYield_SpDefense = 1,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 105,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE, ABILITY_NONE },                           \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Worm"),                                                                \
        .cryId = CRY_WORMMON,                                                                    \
        .natDexNum = NATIONAL_DEX_WORMMON,                                                       \
        .categoryName = _("Larva"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Wormmon, 64, 64),                                                              \
        /*FRONT_PIC_FEMALE(Wormmon, 64, 64),*/                                                   \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Wormmon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Wormmon, 64, 56),                                                               \
        /*BACK_PIC_FEMALE(Wormmon, 64, 64),*/                                                    \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Wormmon),                                                                       \
        /*PALETTE_FEMALE(Wormmon),*/                                                             \
        ICON(Wormmon, 0),                                                                        \
        /*ICON_FEMALE(Wormmon, 0),*/                                                             \
        LEARNSETS(Wormmon),                                                                      \
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_STINGMON}),                              \
        /*.formSpeciesIdTable = sWormmonFormSpeciesIdTable,*/                                    \
        /*.formChangeTable = sWormmonFormChangeTable,*/                                          \
        .isLegendary = FALSE
    [SPECIES_WORMMON] =
    {
        WORMMON_MISC_INFO,
    },
#endif //D_FAMILY_WORMMON

#ifdef __INTELLISENSE__
};
#endif