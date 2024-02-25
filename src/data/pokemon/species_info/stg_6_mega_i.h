#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_WAR_GREYMON
#define WAR_GREYMON_MISC_INFO                                                                    \
        .baseHP        = 180,                                                                    \
        .baseAttack    = 120,                                                                    \
        .baseDefense   = 120,                                                                    \
        .baseSpeed     = 60,                                                                     \
        .baseSpAttack  = 60,                                                                     \
        .baseSpDefense = 60,                                                                     \
        .catchRate = 3,                                                                          \
        .expYield = 600,                                                                         \
        .evYield_HP        = 3,                                                                  \
        .evYield_Attack    = 2,                                                                  \
        .evYield_Defense   = 2,                                                                  \
        .evYield_Speed     = 1,                                                                  \
        .evYield_SpAttack  = 1,                                                                  \
        .evYield_SpDefense = 1,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 255,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_RED,                                                             \
        .speciesName = _("W.Grey"),                                                              \
        .cryId = CRY_WAR_GREYMON,                                                                \
        .natDexNum = NATIONAL_DEX_WAR_GREYMON,                                                   \
        .categoryName = _("D.Man"),                                                              \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_WarGreymon,                                                    \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,                                                  \
        LEARNSETS(WarGreymon),                                                                   \
        .formSpeciesIdTable = sWarGreymonFormSpeciesIdTable,                                     \
        .formChangeTable = sWarGreymonFormChangeTable,                                           \
        .isLegendary = FALSE
#define WAR_GREYMON_SPRITE_INFO                                                                  \
        FRONT_PIC(WarGreymon, 64, 64),                                                           \
        /*FRONT_PIC_FEMALE(WarGreymon, 64, 64),*/                                                \
        BACK_PIC(WarGreymon, 64, 64),                                                            \
        /*BACK_PIC_FEMALE(WarGreymon, 64, 64),*/                                                 \
        PALETTES(WarGreymon),                                                                    \
        /*PALETTE_FEMALE(WarGreymon),*/                                                          \
        ICON(WarGreymon, 0)
        /*ICON_FEMALE(WarGreymon, 0),*/
    [SPECIES_WAR_GREYMON] =
    {
        WAR_GREYMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        WAR_GREYMON_SPRITE_INFO,
    },
    [SPECIES_WAR_GREYMON_BLACK] =
    {
        WAR_GREYMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(WarGreymonBlack, 64, 64),
        //FRONT_PIC_FEMALE(WarGreymonBlack, 64, 64),
        BACK_PIC(WarGreymonBlack, 64, 64),
        //BACK_PIC_FEMALE(WarGreymonBlack, 64, 64),
        PALETTES(WarGreymonBlack),
        //PALETTE_FEMALE(WarGreymonBlack),
        ICON(WarGreymonBlack, 0),
        //ICON_FEMALE(WarGreymonBlack, 0),
    },
    [SPECIES_WAR_GREYMON_X] =
    {
        WAR_GREYMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(WarGreymonX, 64, 64),
        //FRONT_PIC_FEMALE(WarGreymonX, 64, 64),
        BACK_PIC(WarGreymonX, 64, 64),
        //BACK_PIC_FEMALE(WarGreymonX, 64, 64),
        PALETTES(WarGreymonX),
        //PALETTE_FEMALE(WarGreymonX),
        ICON(WarGreymonX, 0),
        //ICON_FEMALE(WarGreymonX, 0),
    },
#if P_MEGA_EVOLUTIONS
    [SPECIES_WAR_GREYMON_WARP] =
    {
        WAR_GREYMON_MISC_INFO,
        .types = { TYPE_MYSTERY, TYPE_MYSTERY },
        WAR_GREYMON_SPRITE_INFO,
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //D_FAMILY_WAR_GREYMON

#if D_FAMILY_METAL_GARURUMON
#define METAL_GARURUMON_MISC_INFO                                                                \
        .baseHP        = 60,                                                                     \
        .baseAttack    = 60,                                                                     \
        .baseDefense   = 60,                                                                     \
        .baseSpeed     = 180,                                                                    \
        .baseSpAttack  = 120,                                                                    \
        .baseSpDefense = 120,                                                                    \
        .catchRate = 3,                                                                          \
        .expYield = 600,                                                                         \
        .evYield_HP        = 1,                                                                  \
        .evYield_Attack    = 1,                                                                  \
        .evYield_Defense   = 1,                                                                  \
        .evYield_Speed     = 3,                                                                  \
        .evYield_SpAttack  = 2,                                                                  \
        .evYield_SpDefense = 2,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 255,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("M.Garuru"),                                                            \
        .cryId = CRY_METAL_GARURUMON,                                                            \
        .natDexNum = NATIONAL_DEX_METAL_GARURUMON,                                               \
        .categoryName = _("Android"),                                                            \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_MetalGarurumon,                                                \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        LEARNSETS(MetalGarurumon),                                                               \
        .formSpeciesIdTable = sMetalGarurumonFormSpeciesIdTable,                                 \
        .formChangeTable = sMetalGarurumonFormChangeTable,                                       \
        .isLegendary = FALSE
#define METAL_GARURUMON_SPRITE_INFO                                                              \
        FRONT_PIC(MetalGarurumon, 64, 64),                                                       \
        /*FRONT_PIC_FEMALE(MetalGarurumon, 64, 64),*/                                            \
        BACK_PIC(MetalGarurumon, 64, 56),                                                        \
        /*BACK_PIC_FEMALE(MetalGarurumon, 64, 64),*/                                             \
        PALETTES(MetalGarurumon),                                                                \
        /*PALETTE_FEMALE(MetalGarurumon),*/                                                      \
        ICON(MetalGarurumon, 0)
        /*ICON_FEMALE(MetalGarurumon, 0),*/
    [SPECIES_METAL_GARURUMON] =
    {
        METAL_GARURUMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        METAL_GARURUMON_SPRITE_INFO,
    },
    [SPECIES_METAL_GARURUMON_BLACK] =
    {
        METAL_GARURUMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(MetalGarurumonBlack, 64, 64),
        //FRONT_PIC_FEMALE(MetalGarurumonBlack, 64, 64),
        BACK_PIC(MetalGarurumonBlack, 64, 64),
        //BACK_PIC_FEMALE(MetalGarurumonBlack, 64, 64),
        PALETTES(MetalGarurumonBlack),
        //PALETTE_FEMALE(MetalGarurumonBlack),
        ICON(MetalGarurumonBlack, 0),
        //ICON_FEMALE(MetalGarurumonBlack, 0),
    },
    [SPECIES_METAL_GARURUMON_X] =
    {
        METAL_GARURUMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(MetalGarurumonX, 64, 64),
        //FRONT_PIC_FEMALE(MetalGarurumonX, 64, 64),
        BACK_PIC(MetalGarurumonX, 64, 64),
        //BACK_PIC_FEMALE(MetalGarurumonX, 64, 64),
        PALETTES(MetalGarurumonX),
        //PALETTE_FEMALE(MetalGarurumonX),
        ICON(MetalGarurumonX, 0),
        //ICON_FEMALE(MetalGarurumonX, 0),
    },
#if P_MEGA_EVOLUTIONS
    [SPECIES_METAL_GARURUMON_WARP] =
    {
        METAL_GARURUMON_MISC_INFO,
        .types = { TYPE_MYSTERY, TYPE_MYSTERY },
        METAL_GARURUMON_SPRITE_INFO,
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //D_FAMILY_METAL_GARURUMON

#if D_FAMILY_DRAGON_IMPERIALDRAMON
#define DRAGON_IMPERIALDRAMON_MISC_INFO                                                          \
        .baseHP        = 100,                                                                    \
        .baseAttack    = 150,                                                                    \
        .baseDefense   = 100,                                                                    \
        .baseSpeed     = 100,                                                                    \
        .baseSpAttack  = 150,                                                                    \
        .baseSpDefense = 100,                                                                    \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = 3,                                                                          \
        .expYield = 600,                                                                         \
        .evYield_HP        = 2,                                                                  \
        .evYield_Attack    = 3,                                                                  \
        .evYield_Defense   = 2,                                                                  \
        .evYield_Speed     = 2,                                                                  \
        .evYield_SpAttack  = 3,                                                                  \
        .evYield_SpDefense = 2,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = 255,                                                                        \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE, ABILITY_NONE },                        \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("D.Imperial"),                                                          \
        .cryId = CRY_DRAGON_IMPERIALDRAMON,                                                      \
        .natDexNum = NATIONAL_DEX_DRAGON_IMPERIALDRAMON,                                         \
        .categoryName = _("A.Dragon"),                                                           \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(DragonImperialdramon, 64, 64),                                                 \
        /*FRONT_PIC_FEMALE(DragonImperialdramon, 64, 64),*/                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_DragonImperialdramon,                                          \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(DragonImperialdramon, 64, 56),                                                  \
        /*BACK_PIC_FEMALE(DragonImperialdramon, 64, 64),*/                                       \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(DragonImperialdramon),                                                          \
        /*PALETTE_FEMALE(DragonImperialdramon),*/                                                \
        ICON(DragonImperialdramon, 0),                                                           \
        /*ICON_FEMALE(DragonImperialdramon, 0),*/                                                \
        LEARNSETS(DragonImperialdramon),                                                         \
        .evolutions = EVOLUTION({EVO_LEVEL, 60, SPECIES_FIGHTER_IMPERIALDRAMON}),                \
        /*.formSpeciesIdTable = sDragonImperialdramonFormSpeciesIdTable,*/                       \
        /*.formChangeTable = sDragonImperialdramonFormChangeTable,*/                             \
        .isLegendary = FALSE
    [SPECIES_DRAGON_IMPERIALDRAMON] =
    {
        DRAGON_IMPERIALDRAMON_MISC_INFO,
    },
#endif //D_FAMILY_DRAGON_IMPERIALDRAMON

#ifdef __INTELLISENSE__
};
#endif