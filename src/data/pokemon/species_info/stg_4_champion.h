#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_GREYMON
#define GREYMON_MISC_INFO                                                                        \
        .baseHP        = 120,                                                                    \
        .baseAttack    = 80,                                                                     \
        .baseDefense   = 80,                                                                     \
        .baseSpeed     = 40,                                                                     \
        .baseSpAttack  = 40,                                                                     \
        .baseSpDefense = 40,                                                                     \
        .catchRate = 60,                                                                         \
        .expYield = 400,                                                                         \
        .evYield_HP        = 2,                                                                  \
        .evYield_Attack    = 1,                                                                  \
        .evYield_Defense   = 1,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 155,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_RED,                                                             \
        .speciesName = _("Grey"),                                                                \
        .cryId = CRY_GREYMON,                                                                    \
        .natDexNum = NATIONAL_DEX_GREYMON,                                                       \
        .categoryName = _("Dinosaur"),                                                           \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Greymon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,                                                  \
        LEARNSETS(Greymon),                                                                      \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   40, SPECIES_METAL_GREYMON},         \
                                {EVO_FRIENDSHIP_NO_HEARTS,   40, SPECIES_METAL_GREYMON_BLACK},   \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 40, SPECIES_METAL_GREYMON_X}),      \
        .formSpeciesIdTable = sGreymonFormSpeciesIdTable,                                        \
        /*.formChangeTable = sGreymonFormChangeTable,*/                                          \
        .isLegendary = FALSE
    [SPECIES_GREYMON] =
    {
        GREYMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        FRONT_PIC(Greymon, 64, 64),
        //FRONT_PIC_FEMALE(Greymon, 64, 64),
        BACK_PIC(Greymon, 64, 64),
        //BACK_PIC_FEMALE(Greymon, 64, 64),
        PALETTES(Greymon),
        //PALETTE_FEMALE(Greymon),
        ICON(Greymon, 0),
        //ICON_FEMALE(Greymon, 0),
    },
    [SPECIES_GREYMON_BLACK] =
    {
        GREYMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(GreymonBlack, 64, 64),
        //FRONT_PIC_FEMALE(GreymonBlack, 64, 64),
        BACK_PIC(GreymonBlack, 64, 64),
        //BACK_PIC_FEMALE(GreymonBlack, 64, 64),
        PALETTES(GreymonBlack),
        //PALETTE_FEMALE(GreymonBlack),
        ICON(GreymonBlack, 0),
        //ICON_FEMALE(GreymonBlack, 0),
    },
    [SPECIES_GREYMON_X] =
    {
        GREYMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(GreymonX, 64, 64),
        //FRONT_PIC_FEMALE(GreymonX, 64, 64),
        BACK_PIC(GreymonX, 64, 64),
        //BACK_PIC_FEMALE(GreymonX, 64, 64),
        PALETTES(GreymonX),
        //PALETTE_FEMALE(GreymonX),
        ICON(GreymonX, 0),
        //ICON_FEMALE(GreymonX, 0),
    },
#endif //D_FAMILY_GREYMON

#if D_FAMILY_GARURUMON
#define GARURUMON_MISC_INFO                                                                      \
        .baseHP        = 40,                                                                     \
        .baseAttack    = 40,                                                                     \
        .baseDefense   = 40,                                                                     \
        .baseSpeed     = 120,                                                                    \
        .baseSpAttack  = 80,                                                                     \
        .baseSpDefense = 80,                                                                     \
        .catchRate = 60,                                                                         \
        .expYield = 400,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 2,                                                                  \
        .evYield_SpAttack  = 1,                                                                  \
        .evYield_SpDefense = 1,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 155,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Garuru"),                                                              \
        .cryId = CRY_GARURUMON,                                                                  \
        .natDexNum = NATIONAL_DEX_GARURUMON,                                                     \
        .categoryName = _("Beast"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Garurumon,                                                     \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        LEARNSETS(Garurumon),                                                                    \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   40, SPECIES_WERE_GARURUMON},        \
                                {EVO_FRIENDSHIP_NO_HEARTS,   40, SPECIES_WERE_GARURUMON_BLACK},  \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 40, SPECIES_WERE_GARURUMON_X}),     \
        .formSpeciesIdTable = sGarurumonFormSpeciesIdTable,                                      \
        /*.formChangeTable = sGarurumonFormChangeTable,*/                                        \
        .isLegendary = FALSE
    [SPECIES_GARURUMON] =
    {
        GARURUMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        FRONT_PIC(Garurumon, 64, 64),
        //FRONT_PIC_FEMALE(Garurumon, 64, 64),
        BACK_PIC(Garurumon, 64, 64),
        //BACK_PIC_FEMALE(Garurumon, 64, 64),
        PALETTES(Garurumon),
        //PALETTE_FEMALE(Garurumon),
        ICON(Garurumon, 0),
        //ICON_FEMALE(Garurumon, 0),
    },
    [SPECIES_GARURUMON_BLACK] =
    {
        GARURUMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(GarurumonBlack, 64, 64),
        //FRONT_PIC_FEMALE(GarurumonBlack, 64, 64),
        BACK_PIC(GarurumonBlack, 64, 64),
        //BACK_PIC_FEMALE(GarurumonBlack, 64, 64),
        PALETTES(GarurumonBlack),
        //PALETTE_FEMALE(GarurumonBlack),
        ICON(GarurumonBlack, 0),
        //ICON_FEMALE(GarurumonBlack, 0),
    },
    [SPECIES_GARURUMON_X] =
    {
        GARURUMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(GarurumonX, 64, 64),
        //FRONT_PIC_FEMALE(GarurumonX, 64, 64),
        BACK_PIC(GarurumonX, 64, 64),
        //BACK_PIC_FEMALE(GarurumonX, 64, 64),
        PALETTES(GarurumonX),
        //PALETTE_FEMALE(GarurumonX),
        ICON(GarurumonX, 0),
        //ICON_FEMALE(GarurumonX, 0),
    },
#endif //D_FAMILY_GARURUMON

#if D_FAMILY_EX_VEEMON
#define EX_VEEMON_MISC_INFO                                                                      \
        .baseHP        = 80,                                                                     \
        .baseAttack    = 120,                                                                    \
        .baseDefense   = 80,                                                                     \
        .baseSpeed     = 40,                                                                     \
        .baseSpAttack  = 40,                                                                     \
        .baseSpDefense = 40,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 60,                                                                         \
        .expYield = 400,                                                                         \
        .evYield_HP        = 1,                                                                  \
        .evYield_Attack    = 2,                                                                  \
        .evYield_Defense   = 1,                                                                  \
        .evYield_Speed     = 0,                                                                  \
        .evYield_SpAttack  = 0,                                                                  \
        .evYield_SpDefense = 0,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 155,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE, ABILITY_NONE },                           \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("E.Vee"),                                                               \
        .cryId = CRY_EX_VEEMON,                                                                  \
        .natDexNum = NATIONAL_DEX_EX_VEEMON,                                                     \
        .categoryName = _("M.Dragon"),                                                           \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(ExVeemon, 64, 64),                                                             \
        /*FRONT_PIC_FEMALE(ExVeemon, 64, 64),*/                                                  \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_ExVeemon,                                                      \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(ExVeemon, 64, 56),                                                              \
        /*BACK_PIC_FEMALE(ExVeemon, 64, 64),*/                                                   \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(ExVeemon),                                                                      \
        /*PALETTE_FEMALE(ExVeemon),*/                                                            \
        ICON(ExVeemon, 0),                                                                       \
        /*ICON_FEMALE(ExVeemon, 0),*/                                                            \
        LEARNSETS(ExVeemon),                                                                     \
        /*.formSpeciesIdTable = sExVeemonFormSpeciesIdTable,*/                                   \
        /*.formChangeTable = sExVeemonFormChangeTable,*/                                         \
        .isLegendary = FALSE
    [SPECIES_EX_VEEMON] =
    {
        EX_VEEMON_MISC_INFO,
    },
#endif //D_FAMILY_EX_VEEMON

#if D_FAMILY_STINGMON
#define STINGMON_MISC_INFO                                                                       \
        .baseHP        = 40,                                                                     \
        .baseAttack    = 40,                                                                     \
        .baseDefense   = 40,                                                                     \
        .baseSpeed     = 80,                                                                     \
        .baseSpAttack  = 120,                                                                    \
        .baseSpDefense = 80,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 60,                                                                         \
        .expYield = 400,                                                                         \
        .evYield_HP        = 0,                                                                  \
        .evYield_Attack    = 0,                                                                  \
        .evYield_Defense   = 0,                                                                  \
        .evYield_Speed     = 1,                                                                  \
        .evYield_SpAttack  = 2,                                                                  \
        .evYield_SpDefense = 1,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 155,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE, ABILITY_NONE },                           \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Sting"),                                                               \
        .cryId = CRY_STINGMON,                                                                   \
        .natDexNum = NATIONAL_DEX_STINGMON,                                                      \
        .categoryName = _("Insectoid"),                                                          \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Stingmon, 64, 64),                                                             \
        /*FRONT_PIC_FEMALE(Stingmon, 64, 64),*/                                                  \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Stingmon,                                                      \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Stingmon, 64, 56),                                                              \
        /*BACK_PIC_FEMALE(Stingmon, 64, 64),*/                                                   \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Stingmon),                                                                      \
        /*PALETTE_FEMALE(Stingmon),*/                                                            \
        ICON(Stingmon, 0),                                                                       \
        /*ICON_FEMALE(Stingmon, 0),*/                                                            \
        LEARNSETS(Stingmon),                                                                     \
        /*.formSpeciesIdTable = sStingmonFormSpeciesIdTable,*/                                   \
        /*.formChangeTable = sStingmonFormChangeTable,*/                                         \
        .isLegendary = FALSE
    [SPECIES_STINGMON] =
    {
        STINGMON_MISC_INFO,
    },
#endif //D_FAMILY_STINGMON

#ifdef __INTELLISENSE__
};
#endif