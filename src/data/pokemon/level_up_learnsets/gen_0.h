#define LEVEL_UP_MOVE(lvl, moveLearned) {.move = moveLearned, .level = lvl}
#define LEVEL_UP_END {.move = LEVEL_UP_MOVE_END, .level = 0}

static const struct LevelUpMove sNoneLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_POUND),
    LEVEL_UP_END
};

#if P_FAMILY_AGUMON
static const struct LevelUpMove sAgumonLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_SCRATCH),
    LEVEL_UP_MOVE( 1, MOVE_PROTECT),
    LEVEL_UP_MOVE( 5, MOVE_EMBER),
    LEVEL_UP_MOVE( 5, MOVE_SMOKESCREEN),
    LEVEL_UP_END
};
#endif //P_FAMILY_AGUMON

#if P_FAMILY_GABUMON
static const struct LevelUpMove sGabumonLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_PROTECT),
    LEVEL_UP_MOVE( 5, MOVE_POWDER_SNOW),
    LEVEL_UP_MOVE( 5, MOVE_SAND_ATTACK),
    LEVEL_UP_END
};
#endif //P_FAMILY_GABUMON

