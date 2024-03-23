.set LOCALID_TREASURE_HUNTER, 1

Route114_SmashingTreasureHuntersTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_SmashingTreasureHuntersTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_SmashingTreasureHuntersTunnel_OnLoad
	.byte 0

Route114_SmashingTreasureHuntersTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_SmashingTreasureHuntersTunnel_EventScript_MoveFossilManiac
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_TREASURE_HUNTER, 6, 5
	setobjectmovementtype LOCALID_TREASURE_HUNTER, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_SmashingTreasureHuntersTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_SmashingTreasureHuntersTunnel_EventScript_CloseDesertUnderpass
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_SmashingTreasureHuntersTunnel_EventScript_HunterMentionCaveIn::
	lockall
	applymovement LOCALID_TREASURE_HUNTER, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_TreasureHunter::
	lock
	faceplayer
	goto_if_set FLAG_MET_SMASHING_TREASURE_HUNTER, Route114_SmashingTreasureHuntersTunnel_EventScript_SkipGreeting
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_Greeting, MSGBOX_DEFAULT
	setflag FLAG_MET_SMASHING_TREASURE_HUNTER
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_CheckPlayerHasBone
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_SkipGreeting::
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_HaveYouSeenAnyBones, MSGBOX_DEFAULT
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_CheckPlayerHasBone
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_CheckPlayerHasBone::
	call Route114_SmashingTreasureHuntersTunnel_EventScript_GetPlayersBones
	goto_if_eq VAR_TEMP_1, 0, Route114_SmashingTreasureHuntersTunnel_EventScript_NoBones
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_HasBone
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_GetPlayersBones::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_RARE_BONE
	call_if_eq VAR_RESULT, TRUE, Route114_SmashingTreasureHuntersTunnel_EventScript_HasRareBone
	checkitem ITEM_ODD_KEYSTONE
	call_if_eq VAR_RESULT, TRUE, Route114_SmashingTreasureHuntersTunnel_EventScript_HasOddKeystone
	return

Route114_SmashingTreasureHuntersTunnel_EventScript_HasRareBone::
	addvar VAR_TEMP_1, 1
	return

Route114_SmashingTreasureHuntersTunnel_EventScript_HasOddKeystone::
	addvar VAR_TEMP_1, 2
	return

Route114_SmashingTreasureHuntersTunnel_EventScript_HasBone::
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_ThatsABoneIllTradeYou, MSGBOX_DEFAULT
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_ShowTradeOptions
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_ShowTradeOptions::
	message Route114_SmashingTreasureHuntersTunnel_Text_WhatDoYouWantToTrade
	waitmessage
	switch VAR_TEMP_1
	case 1,  Route114_SmashingTreasureHuntersTunnel_EventScript_BoneOptionsA
	case 2,  Route114_SmashingTreasureHuntersTunnel_EventScript_BoneOptionsB
	case 3,  Route114_SmashingTreasureHuntersTunnel_EventScript_BoneOptionsAB
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_BoneOptionsA::
	multichoice 0, 0, MULTI_BONES_A, FALSE
	switch VAR_RESULT
	case 0, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeRareBone
	case 1, Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_BoneOptionsB::
	multichoice 0, 0, MULTI_BONES_B, FALSE
	switch VAR_RESULT
	case 0, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeOddBone
	case 1, Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_BoneOptionsAB::
	multichoice 0, 0, MULTI_BONES_AB, FALSE
	switch VAR_RESULT
	case 0, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeRareBone
	case 1, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeOddBone
	case 2, Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeRareBone::
	setvar VAR_0x8008, ITEM_RARE_BONE
	multichoice 0, 0, MULTI_BONES_RARE, FALSE
	switch VAR_RESULT
	case 0, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeHelixFossil
	case 1, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeDomeFossil
	case 2, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeRootFossil
	case 3, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeClawFossil
	case 4, Route114_SmashingTreasureHuntersTunnel_EventScript_ShowTradeOptions
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_ShowTradeOptions
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeHelixFossil::
	setvar VAR_0x8009, ITEM_HELIX_FOSSIL
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_TryTradeBone

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeDomeFossil::
	setvar VAR_0x8009, ITEM_DOME_FOSSIL
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_TryTradeBone

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeRootFossil::
	setvar VAR_0x8009, ITEM_ROOT_FOSSIL
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_TryTradeBone

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeClawFossil::
	setvar VAR_0x8009, ITEM_CLAW_FOSSIL
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_TryTradeBone

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeOddBone::
	setvar VAR_0x8008, ITEM_ODD_KEYSTONE
	multichoice 0, 0, MULTI_BONES_ODD, FALSE
	switch VAR_RESULT
	case 0, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeOldAmber
	case 1, Route114_SmashingTreasureHuntersTunnel_EventScript_TradePrettyFeather
	case 2, Route114_SmashingTreasureHuntersTunnel_EventScript_ShowTradeOptions
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_ShowTradeOptions
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeOldAmber::
	setvar VAR_0x8009, ITEM_OLD_AMBER
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_TryTradeBone

Route114_SmashingTreasureHuntersTunnel_EventScript_TradePrettyFeather::
	setvar VAR_0x8009, ITEM_PRETTY_FEATHER
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_TryTradeBone

Route114_SmashingTreasureHuntersTunnel_EventScript_TryTradeBone::
	bufferitemname STR_VAR_1, VAR_0x8008
	bufferitemname STR_VAR_2, VAR_0x8009
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_YoullTradeBoneForStone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, TRUE, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeBone
	checkitem VAR_0x8008, 2
	goto_if_eq VAR_RESULT, FALSE, Route114_SmashingTreasureHuntersTunnel_EventScript_TradeBone
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_BagFull
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_TradeBone::
	removeitem VAR_0x8008
	giveitem VAR_0x8009
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_ItsADeal, MSGBOX_DEFAULT
	call Route114_SmashingTreasureHuntersTunnel_EventScript_GetPlayersBones
	goto_if_eq VAR_TEMP_1, 0, Route114_SmashingTreasureHuntersTunnel_EventScript_EndTrade
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_TradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_SmashingTreasureHuntersTunnel_EventScript_ShowTradeOptions
	goto Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_BagFull::
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_DeclineTrade::
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_ComeBackIfYouChangeMind, MSGBOX_DEFAULT
	release
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_NoBones::
	msgbox Route114_SmashingTreasureHuntersTunnel_Text_YouHaventGotAnyBones, MSGBOX_DEFAULT
	release
	end

Route114_SmashingTreasureHuntersTunnel_EventScript_EndTrade::
	release
	end

Route114_SmashingTreasureHuntersTunnel_Text_Greeting:
	.string "I'm the SMASHING TREASURE HUNTER!\p"
	.string "I'm the awesome dude who mines\n"
	.string "deep into caves to find treasures\l"
	.string "hidden beneath the ground.$"

Route114_SmashingTreasureHuntersTunnel_Text_HaveYouSeenAnyBones:
	.string "Tell me, have you seen any BONES\n"
	.string "of POKéMON from ancient times?$"

Route114_SmashingTreasureHuntersTunnel_Text_YouHaventGotAnyBones:
	.string "You haven't got any treasures\n"
	.string "for me…\p"
	.string "If you see any BONES, like the RARE\n"
	.string "BONE, you've got to trade it with me!$"

Route114_SmashingTreasureHuntersTunnel_Text_ThatsABoneIllTradeYou:
	.string "Oh, hey! That…\n"
	.string "That's a BONE! I'm looking for those!\p"
	.string "Oh, man, you've got to trade that\n"
	.string "with me! I'll give you something good!$"

Route114_SmashingTreasureHuntersTunnel_Text_WhatDoYouWantToTrade:
	.string "What do you want to trade?$"

Route114_SmashingTreasureHuntersTunnel_Text_YoullTradeBoneForStone:
	.string "You'll trade your {STR_VAR_1} for\n"
	.string "my {STR_VAR_2}, then?$"

Route114_SmashingTreasureHuntersTunnel_Text_ItsADeal:
	.string "It's a done deal!\n"
	.string "Use that wisely!$"

Route114_SmashingTreasureHuntersTunnel_Text_TradeSomethingElse:
	.string "Do you want to trade something else?$"

Route114_SmashingTreasureHuntersTunnel_Text_BagFull:
	.string "Whoops, your BAG's full.\n"
	.string "Get rid of some items, friend!$"

Route114_SmashingTreasureHuntersTunnel_Text_ComeBackIfYouChangeMind:
	.string "No? That's a bummer.\n"
	.string "Well, if you change your mind, come back.$"

Route114_SmashingTreasureHuntersTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "It's not safe that way…\p"
	.string "I was digging away, you see…\n"
	.string "When the whole wall collapsed…\p"
	.string "I think there's a giant cavern\n"
	.string "underneath now…\p"
	.string "But I've left it alone because I don't\n"
	.string "think there are any BONES there…$"

