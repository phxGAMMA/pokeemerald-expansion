#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGenD[] =
{
#endif

#if D_FAMILY_PALADIN_IMPERIALDRAMON
#define PALADIN_IMPERIALDRAMON_MISC_INFO                                                         \
        .baseHP        = 180,                                                                    \
        .baseAttack    = 180,                                                                    \
        .baseDefense   = 120,                                                                    \
        .baseSpeed     = 180,                                                                    \
        .baseSpAttack  = 180,                                                                    \
        .baseSpDefense = 120,                                                                    \
        .types = { TYPE_DATA, TYPE_DATA },                                                       \
        .catchRate = -1,                                                                         \
        .expYield = 800,                                                                         \
        .evYield_HP        = 3,                                                                  \
        .evYield_Attack    = 3,                                                                  \
        .evYield_Defense   = 2,                                                                  \
        .evYield_Speed     = 3,                                                                  \
        .evYield_SpAttack  = 3,                                                                  \
        .evYield_SpDefense = 2,                                                                  \
        .genderRatio = MON_GENDERLESS,                                                           \
        .eggCycles = -1,                                                                         \
        .friendship = MAX_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_ERRATIC,                                                            \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },             \
        .abilities = { ABILITY_WONDER_GUARD, ABILITY_NONE, ABILITY_NONE },                       \
        .bodyColor = BODY_COLOR_BLUE,                                                            \
        .speciesName = _("P.Imperial"),                                                          \
        .cryId = CRY_PALADIN_IMPERIALDRAMON,                                                     \
        .natDexNum = NATIONAL_DEX_PALADIN_IMPERIALDRAMON,                                        \
        .categoryName = _("A.H.Knight"),                                                         \
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
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_TSUNOMON}),                              \
        /*.formSpeciesIdTable = sFighterImperialdramonFormSpeciesIdTable,*/                      \
        /*.formChangeTable = sFighterImperialdramonFormChangeTable,*/                            \
        .isLegendary = FALSE
    [SPECIES_PALADIN_IMPERIALDRAMON] =
    {
        PALADIN_IMPERIALDRAMON_MISC_INFO,
    },
#endif //D_FAMILY_PALADIN_IMPERIALDRAMON

#ifdef __INTELLISENSE__
};
#endif