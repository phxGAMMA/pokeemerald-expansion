BerryTreeScript::
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_CheckBerryGrowing
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckBerryStage0
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_CheckBerryGrowing::
	lockall
	goto BerryTreeScript
	end

BerryTree_EventScript_CheckBerryStage0::
	lockall
	faceplayer
	msgbox BerryTree_Text_SoftLoamySoil, MSGBOX_DEFAULT
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WantToPlant
	releaseall
	end

BerryTree_EventScript_CheckBerryStage1::
	lockall
	call BerryTree_EventScript_GetCareAdverb
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_TreeIsSeeding, MSGBOX_DEFAULT
	goto BerryTree_EventScript_WantToWater
	end

BerryTree_EventScript_CheckBerryStage2::
	lockall
	call BerryTree_EventScript_GetCareAdverb
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_TreeIsSprouting, MSGBOX_DEFAULT
	goto BerryTree_EventScript_WantToWater
	end

BerryTree_EventScript_CheckBerryStage3::
	lockall
	call BerryTree_EventScript_GetCareAdverb
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_TreeIsBlooming, MSGBOX_DEFAULT
	goto BerryTree_EventScript_WantToWater
	end

BerryTree_EventScript_CheckBerryStage4::
	lockall
	call BerryTree_EventScript_GetCareAdverb
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_TreeIsBlossoming, MSGBOX_DEFAULT
	goto BerryTree_EventScript_WantToWater
	end

BerryTree_EventScript_CheckBerryFullyGrown::
	lockall
	faceplayer
	buffernumberstring STR_VAR_2, VAR_0x8006
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_TreeIsGrown, MSGBOX_DEFAULT
	msgbox BerryTree_Text_WantToShake, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry
BerryTree_EventScript_CancelPickingBerry::
	msgbox BerryTree_Text_LeftTheTree, MSGBOX_DEFAULT
	releaseall
	end

BerryTree_EventScript_GetCareAdverb::
	goto_if_eq VAR_0x8005, 0, BerryTree_EventScript_SetAdverbPoor
	goto_if_eq VAR_0x8005, 1, BerryTree_EventScript_SetAdverbFair
	goto_if_eq VAR_0x8005, 2, BerryTree_EventScript_SetAdverbIdeal
	goto_if_eq VAR_0x8005, 3, BerryTree_EventScript_SetAdverbNice
	goto_if_eq VAR_0x8005, 4, BerryTree_EventScript_SetAdverbSplendid
	return

BerryTree_EventScript_SetAdverbPoor::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbPoor
	return

BerryTree_EventScript_SetAdverbFair::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbFair
	return

BerryTree_EventScript_SetAdverbIdeal::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbIdeal
	return

BerryTree_EventScript_SetAdverbNice::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbNice
	return

BerryTree_EventScript_SetAdverbSplendid::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbSplendid
	return

BerryTree_EventScript_WantToPlant::
	lockall
	msgbox BerryTree_Text_WantToPlant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPlanting
BerryTree_EventScript_ChooseBerryToPlant::
	closemessage
	fadescreen FADE_TO_BLACK
	special Bag_ChooseBerry
	waitstate
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_PlantBerry
BerryTree_EventScript_CancelPlanting::
	releaseall
	end

BerryTree_EventScript_ItemUsePlantBerry::
	special ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_PlantBerry::
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	special ObjectEventInteractionGetBerryName
	playfanfare MUS_HELP
	message BerryTree_Text_PlantedTheTree
	waitfanfare
	waitmessage
	return

BerryTree_EventScript_WantToWater::
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_WantToWater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WateredTheTree
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater
BerryTree_EventScript_ItemUseWailmerPail::
	lockall
	special ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_WateredTheTree::
	closemessage
	special ObjectEventInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
BerryTree_EventScript_TreeIsDelighted::
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_WateredTheTree, MSGBOX_DEFAULT
BerryTree_EventScript_DontWater::
	releaseall
	end

BerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, Common_EventScript_ShowBagIsFull
	special IncrementDailyPickedBerries
	call BerryTree_EventScript_BerriesFell
	special ObjectEventInteractionGetBerryCountString
	playfanfare MUS_OBTAIN_BERRY
	message BerryTree_Text_FoundBerry
	waitfanfare
	waitmessage
BerryTree_EventScript_ContinuePickingBerry::
	msgbox BerryTree_Text_ShakeSomeMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickApricorn
BerryTree_EventScript_EndPickingBerry::
	special ObjectEventInteractionRemoveBerryTree
	msgbox BerryTree_Text_ReturnToSprout, MSGBOX_DEFAULT
	releaseall
	end

BerryTree_EventScript_BerriesFell::
	message BerryTree_Text_ShookTheTree
	waitmessage
	delay 30
	return

BerryTree_EventScript_PickApricorn::
	random 3
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_EndPickingApricorn
	call BerryTree_EventScript_ChooseApricorn
	call BerryTree_EventScript_ChooseAmount
	call BerryTree_EventScript_BerriesFell
	bufferitemnameplural STR_VAR_1, VAR_TEMP_A, VAR_TEMP_F
	additem VAR_TEMP_A, VAR_TEMP_F
	playfanfare MUS_OBTAIN_BERRY
	message BerryTree_Text_FoundBerry
	waitfanfare
	waitmessage
	goto BerryTree_EventScript_ContinuePickingBerry
BerryTree_EventScript_EndPickingApricorn::
	special ObjectEventInteractionRemoveBerryTree
	call BerryTree_EventScript_ChoosePokemon
	call BerryTree_EventScript_ChooseLevel
	call BerryTree_EventScript_PokemonFell
	setwildbattle VAR_TEMP_A, VAR_TEMP_F
	playmoncry VAR_TEMP_A, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	dowildbattle
	releaseall
	end

BerryTree_EventScript_PokemonFell::
	message BerryTree_Text_PokemonAttacked
	waitmessage
	delay 30
	return

BerryTree_EventScript_ChooseApricorn::
	random 7
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_ChooseRedApricorn
	compare VAR_RESULT, 1
	goto_if_eq BerryTree_EventScript_ChooseBlueApricorn
	compare VAR_RESULT, 2
	goto_if_eq BerryTree_EventScript_ChooseYellowApricorn
	compare VAR_RESULT, 3
	goto_if_eq BerryTree_EventScript_ChooseGreenApricorn
	compare VAR_RESULT, 4
	goto_if_eq BerryTree_EventScript_ChoosePinkApricorn
	compare VAR_RESULT, 5
	goto_if_eq BerryTree_EventScript_ChooseWhiteApricorn
	compare VAR_RESULT, 6
	goto_if_eq BerryTree_EventScript_ChooseBlackApricorn
	return

BerryTree_EventScript_ChooseRedApricorn::
	setvar VAR_TEMP_A, ITEM_RED_APRICORN
	return

BerryTree_EventScript_ChooseBlueApricorn::
	setvar VAR_TEMP_A, ITEM_BLUE_APRICORN
	return

BerryTree_EventScript_ChooseYellowApricorn::
	setvar VAR_TEMP_A, ITEM_YELLOW_APRICORN
	return

BerryTree_EventScript_ChooseGreenApricorn::
	setvar VAR_TEMP_A, ITEM_GREEN_APRICORN
	return

BerryTree_EventScript_ChoosePinkApricorn::
	setvar VAR_TEMP_A, ITEM_PINK_APRICORN
	return

BerryTree_EventScript_ChooseWhiteApricorn::
	setvar VAR_TEMP_A, ITEM_WHITE_APRICORN
	return

BerryTree_EventScript_ChooseBlackApricorn::
	setvar VAR_TEMP_A, ITEM_BLACK_APRICORN
	return

BerryTree_EventScript_ChooseAmount::
	random 3
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_Choose2
	compare VAR_RESULT, 1
	goto_if_eq BerryTree_EventScript_Choose3
	compare VAR_RESULT, 2
	goto_if_eq BerryTree_EventScript_Choose4
	return

BerryTree_EventScript_Choose2::
	buffernumberstring STR_VAR_2, 2
	setvar VAR_TEMP_F, 2
	return

BerryTree_EventScript_Choose3::
	buffernumberstring STR_VAR_2, 3
	setvar VAR_TEMP_F, 3
	return

BerryTree_EventScript_Choose4::
	buffernumberstring STR_VAR_2, 4
	setvar VAR_TEMP_F, 4
	return

BerryTree_EventScript_ChoosePokemon::
	random 14
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_ChooseMetapod
	compare VAR_RESULT, 1
	goto_if_eq BerryTree_EventScript_ChooseKakuna
	compare VAR_RESULT, 2
	goto_if_eq BerryTree_EventScript_ChooseSpearow
	compare VAR_RESULT, 3
	goto_if_eq BerryTree_EventScript_ChooseParas
	compare VAR_RESULT, 4
	goto_if_eq BerryTree_EventScript_ChooseVenonat
	compare VAR_RESULT, 5
	goto_if_eq BerryTree_EventScript_ChooseHoothoot
	compare VAR_RESULT, 6
	goto_if_eq BerryTree_EventScript_ChooseLedyba
	compare VAR_RESULT, 7
	goto_if_eq BerryTree_EventScript_ChooseSpinarak
	compare VAR_RESULT, 8
	goto_if_eq BerryTree_EventScript_ChooseAipom
	compare VAR_RESULT, 9
	goto_if_eq BerryTree_EventScript_ChoosePineco
	compare VAR_RESULT, 10
	goto_if_eq BerryTree_EventScript_ChooseSilcoon
	compare VAR_RESULT, 11
	goto_if_eq BerryTree_EventScript_ChooseCascoon
	compare VAR_RESULT, 12
	goto_if_eq BerryTree_EventScript_ChooseSlakoth
	compare VAR_RESULT, 13
	goto_if_eq BerryTree_EventScript_ChooseNincada
	return

BerryTree_EventScript_ChooseMetapod::
	setvar VAR_TEMP_A, SPECIES_METAPOD
	return

BerryTree_EventScript_ChooseKakuna::
	setvar VAR_TEMP_A, SPECIES_KAKUNA
	return

BerryTree_EventScript_ChooseSpearow::
	setvar VAR_TEMP_A, SPECIES_SPEAROW
	return

BerryTree_EventScript_ChooseParas::
	setvar VAR_TEMP_A, SPECIES_PARAS
	return

BerryTree_EventScript_ChooseVenonat::
	setvar VAR_TEMP_A, SPECIES_VENONAT
	return

BerryTree_EventScript_ChooseHoothoot::
	setvar VAR_TEMP_A, SPECIES_HOOTHOOT
	return

BerryTree_EventScript_ChooseLedyba::
	setvar VAR_TEMP_A, SPECIES_LEDYBA
	return

BerryTree_EventScript_ChooseSpinarak::
	setvar VAR_TEMP_A, SPECIES_SPINARAK
	return

BerryTree_EventScript_ChooseAipom::
	setvar VAR_TEMP_A, SPECIES_AIPOM
	return

BerryTree_EventScript_ChoosePineco::
	setvar VAR_TEMP_A, SPECIES_PINECO
	return

BerryTree_EventScript_ChooseSilcoon::
	setvar VAR_TEMP_A, SPECIES_SILCOON
	return

BerryTree_EventScript_ChooseCascoon::
	setvar VAR_TEMP_A, SPECIES_CASCOON
	return

BerryTree_EventScript_ChooseSlakoth::
	setvar VAR_TEMP_A, SPECIES_SLAKOTH
	return

BerryTree_EventScript_ChooseNincada::
	setvar VAR_TEMP_A, SPECIES_NINCADA
	return

BerryTree_EventScript_ChooseLevel::
	goto_if_unset FLAG_BADGE01_GET, BerryTree_EventScript_WildLevel15
	goto_if_set FLAG_BADGE08_GET, BerryTree_EventScript_WildLevel58
	goto_if_set FLAG_BADGE07_GET, BerryTree_EventScript_WildLevel46
	goto_if_set FLAG_BADGE06_GET, BerryTree_EventScript_WildLevel42
	goto_if_set FLAG_BADGE05_GET, BerryTree_EventScript_WildLevel33
	goto_if_set FLAG_BADGE04_GET, BerryTree_EventScript_WildLevel31
	goto_if_set FLAG_BADGE03_GET, BerryTree_EventScript_WildLevel29
	goto_if_set FLAG_BADGE02_GET, BerryTree_EventScript_WildLevel24
	goto_if_set FLAG_BADGE01_GET, BerryTree_EventScript_WildLevel19
	return

BerryTree_EventScript_WildLevel15::
	setvar VAR_TEMP_F, 15
	return

BerryTree_EventScript_WildLevel58::
	setvar VAR_TEMP_F, 58
	return

BerryTree_EventScript_WildLevel46::
	setvar VAR_TEMP_F, 46
	return

BerryTree_EventScript_WildLevel42::
	setvar VAR_TEMP_F, 42
	return

BerryTree_EventScript_WildLevel33::
	setvar VAR_TEMP_F, 33
	return

BerryTree_EventScript_WildLevel31::
	setvar VAR_TEMP_F, 31
	return

BerryTree_EventScript_WildLevel29::
	setvar VAR_TEMP_F, 29
	return

BerryTree_EventScript_WildLevel24::
	setvar VAR_TEMP_F, 24
	return

BerryTree_EventScript_WildLevel19::
	setvar VAR_TEMP_F, 19
	return

BerryTree_Text_TreeIsSeeding:
	.string "The {STR_VAR_1} tree is seeding {STR_VAR_2}.$"

BerryTree_Text_TreeIsSprouting:
	.string "The {STR_VAR_1} tree is sprouting {STR_VAR_2}.$"

BerryTree_Text_TreeIsBlooming:
	.string "The {STR_VAR_1} tree is blooming {STR_VAR_2}.$"

BerryTree_Text_TreeIsBlossoming:
	.string "The {STR_VAR_1} tree is blossoming {STR_VAR_2}.$"

BerryTree_Text_TreeIsGrown:
	.string "The {STR_VAR_1} tree is fully grown.$"

BerryTree_Text_CareAdverbPoor:
	.string "poorly$"

BerryTree_Text_CareAdverbFair:
	.string "fairly$"

BerryTree_Text_CareAdverbIdeal:
	.string "ideally$"

BerryTree_Text_CareAdverbNice:
	.string "nicely$"

BerryTree_Text_CareAdverbSplendid:
	.string "splendidly$"

BerryTree_Text_SoftLoamySoil:
	.string "It's soft, loamy soil.$"

BerryTree_Text_WantToPlant:
	.string "Would you like to plant a Berry tree?$"

BerryTree_Text_PlantedTheTree:
	.string "{PLAYER} planted the {STR_VAR_1} Berry.$"

BerryTree_Text_WantToWater:
	.string "Would you like to water it?$"

BerryTree_Text_WateredTheTree:
	.string "The {STR_VAR_1} tree is delighted.$"

BerryTree_Text_WantToShake:
	.string "Would you like to shake it?$"

BerryTree_Text_LeftTheTree:
	.string "{PLAYER} left the tree alone.$"

BerryTree_Text_ShookTheTree:
	.string "Berries fell from the tree.$"

BerryTree_Text_PokemonAttacked:
	.string "A Pokémon fell from the tree!$"

BerryTree_Text_ShakeSomeMore:
	.string "Shake it some more?$"

BerryTree_Text_FoundBerry:
	.string "{PLAYER} found {STR_VAR_2} {STR_VAR_1}!$"

BerryTree_Text_FoundOneBerry:
	.string "{PLAYER} found one {STR_VAR_1}!$"

BerryTree_Text_ReturnToSprout:
	.string "The tree begins to wither.$"
