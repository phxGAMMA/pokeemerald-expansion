#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_METAL_GREYMON
#define METAL_GREYMON_MISC_INFO                                                                  \
        .baseHP        = 150,                                                                    \
        .baseAttack    = 100,                                                                    \
        .baseDefense   = 100,                                                                    \
        .baseSpeed     = 50,                                                                     \
        .baseSpAttack  = 50,                                                                     \
        .baseSpDefense = 50,                                                                     \
        .catchRate = 30,                                                                         \
        .expYield = 500,                                                                         \
        .evYield_HP        = 3,                                                                  \
        .evYield_Attack    = 2,                                                                  \
        .evYield_Defense   = 2,                                                                  \
        .evYield_Speed     = 1,                                                                  \
        .evYield_SpAttack  = 1,                                                                  \
        .evYield_SpDefense = 1,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 205,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_RED,                                                             \
        .speciesName = _("M.Grey"),                                                              \
        .cryId = CRY_METAL_GREYMON,                                                              \
        .natDexNum = NATIONAL_DEX_METAL_GREYMON,                                                 \
        .categoryName = _("Android"),                                                            \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_MetalGreymon,                                                  \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,                                                  \
        LEARNSETS(MetalGreymon),                                                                 \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   50, SPECIES_WAR_GREYMON},           \
                                {EVO_FRIENDSHIP_NO_HEARTS,   50, SPECIES_WAR_GREYMON_BLACK},     \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 50, SPECIES_WAR_GREYMON_X}),        \
        .formSpeciesIdTable = sMetalGreymonFormSpeciesIdTable,                                   \
        /*.formChangeTable = sMetalGreymonFormChangeTable,*/                                     \
        .isLegendary = FALSE
    [SPECIES_METAL_GREYMON] =
    {
        METAL_GREYMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        FRONT_PIC(MetalGreymon, 64, 64),
        //FRONT_PIC_FEMALE(MetalGreymon, 64, 64),
        BACK_PIC(MetalGreymon, 64, 64),
        //BACK_PIC_FEMALE(MetalGreymon, 64, 64),
        PALETTES(MetalGreymon),
        //PALETTE_FEMALE(MetalGreymon),
        ICON(MetalGreymon, 0),
        //ICON_FEMALE(MetalGreymon, 0),
    },
    [SPECIES_METAL_GREYMON_BLACK] =
    {
        METAL_GREYMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(MetalGreymonBlack, 64, 64),
        //FRONT_PIC_FEMALE(MetalGreymonBlack, 64, 64),
        BACK_PIC(MetalGreymonBlack, 64, 64),
        //BACK_PIC_FEMALE(MetalGreymonBlack, 64, 64),
        PALETTES(MetalGreymonBlack),
        //PALETTE_FEMALE(MetalGreymonBlack),
        ICON(MetalGreymonBlack, 0),
        //ICON_FEMALE(MetalGreymonBlack, 0),
    },
    [SPECIES_METAL_GREYMON_X] =
    {
        METAL_GREYMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(MetalGreymonX, 64, 64),
        //FRONT_PIC_FEMALE(MetalGreymonX, 64, 64),
        BACK_PIC(MetalGreymonX, 64, 64),
        //BACK_PIC_FEMALE(MetalGreymonX, 64, 64),
        PALETTES(MetalGreymonX),
        //PALETTE_FEMALE(MetalGreymonX),
        ICON(MetalGreymonX, 0),
        //ICON_FEMALE(MetalGreymonX, 0),
    },
#endif //D_FAMILY_METAL_GREYMON

#if D_FAMILY_WERE_GARURUMON
#define WERE_GARURUMON_MISC_INFO                                                                 \
        .baseHP        = 50,                                                                     \
        .baseAttack    = 50,                                                                     \
        .baseDefense   = 50,                                                                     \
        .baseSpeed     = 150,                                                                    \
        .baseSpAttack  = 100,                                                                    \
        .baseSpDefense = 100,                                                                    \
        .catchRate = 30,                                                                         \
        .expYield = 500,                                                                         \
        .evYield_HP        = 1,                                                                  \
        .evYield_Attack    = 1,                                                                  \
        .evYield_Defense   = 1,                                                                  \
        .evYield_Speed     = 3,                                                                  \
        .evYield_SpAttack  = 2,                                                                  \
        .evYield_SpDefense = 2,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 205,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("W.Garuru"),                                                            \
        .cryId = CRY_WERE_GARURUMON,                                                             \
        .natDexNum = NATIONAL_DEX_WERE_GARURUMON,                                                \
        .categoryName = _("B.Man"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_WereGarurumon,                                                 \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        LEARNSETS(WereGarurumon),                                                                \
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_ONE_HEART,   50, SPECIES_METAL_GARURUMON},       \
                                {EVO_FRIENDSHIP_NO_HEARTS,   50, SPECIES_METAL_GARURUMON_BLACK}, \
                                {EVO_FRIENDSHIP_FIVE_HEARTS, 50, SPECIES_METAL_GARURUMON_X}),    \
        .formSpeciesIdTable = sWereGarurumonFormSpeciesIdTable,                                  \
        /*.formChangeTable = sWereGarurumonFormChangeTable,*/                                    \
        .isLegendary = FALSE
    [SPECIES_WERE_GARURUMON] =
    {
        WERE_GARURUMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        FRONT_PIC(WereGarurumon, 64, 64),
        //FRONT_PIC_FEMALE(WereGarurumon, 64, 64),
        BACK_PIC(WereGarurumon, 64, 64),
        //BACK_PIC_FEMALE(WereGarurumon, 64, 64),
        PALETTES(WereGarurumon),
        //PALETTE_FEMALE(WereGarurumon),
        ICON(WereGarurumon, 0),
        //ICON_FEMALE(WereGarurumon, 0),
    },
    [SPECIES_WERE_GARURUMON_BLACK] =
    {
        WERE_GARURUMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(WereGarurumonBlack, 64, 64),
        //FRONT_PIC_FEMALE(WereGarurumonBlack, 64, 64),
        BACK_PIC(WereGarurumonBlack, 64, 64),
        //BACK_PIC_FEMALE(WereGarurumonBlack, 64, 64),
        PALETTES(WereGarurumonBlack),
        //PALETTE_FEMALE(WereGarurumonBlack),
        ICON(WereGarurumonBlack, 0),
        //ICON_FEMALE(WereGarurumonBlack, 0),
    },
    [SPECIES_WERE_GARURUMON_X] =
    {
        WERE_GARURUMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(WereGarurumonX, 64, 64),
        //FRONT_PIC_FEMALE(WereGarurumonX, 64, 64),
        BACK_PIC(WereGarurumonX, 64, 64),
        //BACK_PIC_FEMALE(WereGarurumonX, 64, 64),
        PALETTES(WereGarurumonX),
        //PALETTE_FEMALE(WereGarurumonX),
        ICON(WereGarurumonX, 0),
        //ICON_FEMALE(WereGarurumonX, 0),
    },
#endif //D_FAMILY_WERE_GARURUMON

#if D_FAMILY_PAILDRAMON
#define PAILDRAMON_MISC_INFO                                                                     \
        .baseHP        = 80,                                                                     \
        .baseAttack    = 120,                                                                    \
        .baseDefense   = 80,                                                                     \
        .baseSpeed     = 80,                                                                     \
        .baseSpAttack  = 120,                                                                    \
        .baseSpDefense = 80,                                                                     \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 30,                                                                         \
        .expYield = 500,                                                                         \
        .evYield_HP        = 1,                                                                  \
        .evYield_Attack    = 2,                                                                  \
        .evYield_Defense   = 1,                                                                  \
        .evYield_Speed     = 1,                                                                  \
        .evYield_SpAttack  = 2,                                                                  \
        .evYield_SpDefense = 1,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 205,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE, ABILITY_NONE },                        \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("Paildra"),                                                             \
        .cryId = CRY_PAILDRAMON,                                                                 \
        .natDexNum = NATIONAL_DEX_PAILDRAMON,                                                    \
        .categoryName = _("D.Man"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(Paildramon, 64, 64),                                                           \
        /*FRONT_PIC_FEMALE(Paildramon, 64, 64),*/                                                \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Paildramon,                                                    \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(Paildramon, 64, 56),                                                            \
        /*BACK_PIC_FEMALE(Paildramon, 64, 64),*/                                                 \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(Paildramon),                                                                    \
        /*PALETTE_FEMALE(Paildramon),*/                                                          \
        ICON(Paildramon, 0),                                                                     \
        /*ICON_FEMALE(Paildramon, 0),*/                                                          \
        LEARNSETS(Paildramon),                                                                   \
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_DRAGON_IMPERIALDRAMON}),                 \
        /*.formSpeciesIdTable = sPaildramonFormSpeciesIdTable,*/                                 \
        /*.formChangeTable = sPaildramonFormChangeTable,*/                                       \
        .isLegendary = FALSE
    [SPECIES_PAILDRAMON] =
    {
        PAILDRAMON_MISC_INFO,
    },
#endif //D_FAMILY_PAILDRAMON

#ifdef __INTELLISENSE__
};
#endif