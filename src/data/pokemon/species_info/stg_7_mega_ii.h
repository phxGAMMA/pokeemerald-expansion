#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_OMNIMON
#if P_FUSION_FORMS
#define OMNIMON_MISC_INFO                                                                        \
        .baseHP        = 180,                                                                    \
        .baseAttack    = 120,                                                                    \
        .baseDefense   = 120,                                                                    \
        .baseSpeed     = 180,                                                                    \
        .baseSpAttack  = 120,                                                                    \
        .baseSpDefense = 120,                                                                    \
        .catchRate = -1,                                                                         \
        .expYield = 700,                                                                         \
        .evYield_HP        = 3,                                                                  \
        .evYield_Attack    = 2,                                                                  \
        .evYield_Defense   = 2,                                                                  \
        .evYield_Speed     = 3,                                                                  \
        .evYield_SpAttack  = 2,                                                                  \
        .evYield_SpDefense = 2,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = -1,                                                                         \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_NEUROFORCE, ABILITY_NONE, ABILITY_NONE },                         \
        .bodyColor = BODY_COLOR_GREEN,                                                           \
        .speciesName = _("Omni"),                                                                \
        .cryId = CRY_OMNIMON,                                                                    \
        .natDexNum = NATIONAL_DEX_OMNIMON,                                                       \
        .categoryName = _("H.Knight"),                                                           \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_Omnimon,                                                       \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,                                                \
        LEARNSETS(Omnimon),                                                                      \
        .formSpeciesIdTable = sOmnimonFormSpeciesIdTable,                                        \
        /*.formChangeTable = sOmnimonFormChangeTable,*/                                          \
        .isLegendary = TRUE
    [SPECIES_OMNIMON] =
    {
        OMNIMON_MISC_INFO,
        .types = { TYPE_DATA, TYPE_DATA },
        FRONT_PIC(Omnimon, 64, 64),
        //FRONT_PIC_FEMALE(Omnimon, 64, 64),
        BACK_PIC(Omnimon, 64, 48),
        //BACK_PIC_FEMALE(Omnimon, 64, 64),
        PALETTES(Omnimon),
        //PALETTE_FEMALE(Omnimon),
        ICON(Omnimon, 0),
        //ICON_FEMALE(Omnimon, 0),
    },
    [SPECIES_OMNIMON_BLACK] =
    {
        OMNIMON_MISC_INFO,
        .types = { TYPE_VIRUS, TYPE_VIRUS },
        FRONT_PIC(OmnimonBlack, 64, 64),
        //FRONT_PIC_FEMALE(OmnimonBlack, 64, 64),
        BACK_PIC(OmnimonBlack, 64, 48),
        //BACK_PIC_FEMALE(OmnimonBlack, 64, 64),
        PALETTES(OmnimonBlack),
        //PALETTE_FEMALE(OmnimonBlack),
        ICON(OmnimonBlack, 0),
        //ICON_FEMALE(OmnimonBlack, 0),
    },
    [SPECIES_OMNIMON_X] =
    {
        OMNIMON_MISC_INFO,
        .types = { TYPE_VACCINE, TYPE_VACCINE },
        FRONT_PIC(OmnimonX, 64, 64),
        //FRONT_PIC_FEMALE(OmnimonX, 64, 64),
        BACK_PIC(OmnimonX, 64, 48),
        //BACK_PIC_FEMALE(OmnimonX, 64, 64),
        PALETTES(OmnimonX),
        //PALETTE_FEMALE(OmnimonX),
        ICON(OmnimonX, 0),
        //ICON_FEMALE(OmnimonX, 0),
    },
#endif //P_FUSION_FORMS
#endif //D_FAMILY_OMNIMON

#if D_FAMILY_FIGHTER_IMPERIALDRAMON
#define FIGHTER_IMPERIALDRAMON_MISC_INFO                                                         \
        .baseHP        = 120,                                                                    \
        .baseAttack    = 180,                                                                    \
        .baseDefense   = 120,                                                                    \
        .baseSpeed     = 120,                                                                    \
        .baseSpAttack  = 180,                                                                    \
        .baseSpDefense = 120,                                                                    \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = -1,                                                                         \
        .expYield = 700,                                                                         \
        .evYield_HP        = 2,                                                                  \
        .evYield_Attack    = 3,                                                                  \
        .evYield_Defense   = 2,                                                                  \
        .evYield_Speed     = 2,                                                                  \
        .evYield_SpAttack  = 3,                                                                  \
        .evYield_SpDefense = 2,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = -1,                                                                         \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE, ABILITY_NONE },                        \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("F.Imperial"),                                                          \
        .cryId = CRY_FIGHTER_IMPERIALDRAMON,                                                     \
        .natDexNum = NATIONAL_DEX_FIGHTER_IMPERIALDRAMON,                                        \
        .categoryName = _("A.D.Man"),                                                            \
        .height = 0,                                                                             \
        .weight = 0,                                                                             \
        .description = COMPOUND_STRING("Data under analysis."),                                  \
        .pokemonScale = 256,                                                                     \
        .pokemonOffset = 0,                                                                      \
        .trainerScale = 256,                                                                     \
        .trainerOffset = 0,                                                                      \
        FRONT_PIC(FighterImperialdramon, 64, 64),                                                \
        /*FRONT_PIC_FEMALE(FighterImperialdramon, 64, 64),*/                                     \
        .frontPicYOffset = 12,                                                                   \
        .frontAnimFrames = sAnims_FighterImperialdramon,                                         \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                                 \
        .enemyMonElevation = 0,                                                                  \
        BACK_PIC(FighterImperialdramon, 64, 56),                                                 \
        /*BACK_PIC_FEMALE(FighterImperialdramon, 64, 64),*/                                      \
        .backPicYOffset = 12,                                                                    \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                                 \
        PALETTES(FighterImperialdramon),                                                         \
        /*PALETTE_FEMALE(FighterImperialdramon),*/                                               \
        ICON(FighterImperialdramon, 0),                                                          \
        /*ICON_FEMALE(FighterImperialdramon, 0),*/                                               \
        LEARNSETS(FighterImperialdramon),                                                        \
        /*.formSpeciesIdTable = sFighterImperialdramonFormSpeciesIdTable,*/                      \
        /*.formChangeTable = sFighterImperialdramonFormChangeTable,*/                            \
        .isLegendary = FALSE
    [SPECIES_FIGHTER_IMPERIALDRAMON] =
    {
        FIGHTER_IMPERIALDRAMON_MISC_INFO,
    },
#endif //D_FAMILY_FIGHTER_IMPERIALDRAMON

#ifdef __INTELLISENSE__
};
#endif