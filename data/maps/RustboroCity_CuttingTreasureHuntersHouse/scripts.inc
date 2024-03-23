RustboroCity_CuttingTreasureHuntersHouse_MapScripts::
	.byte 0

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TreasureHunter_1::
	lock
	faceplayer
    setvar VAR_TEMP_0, 1
	goto_if_set FLAG_MET_CUTTING_TREASURE_HUNTER, RustboroCity_CuttingTreasureHuntersHouse_EventScript_SkipGreeting
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_Greeting, MSGBOX_DEFAULT
	setflag FLAG_MET_CUTTING_TREASURE_HUNTER
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_CheckPlayerHasApricorn
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TreasureHunter_2::
	lock
	faceplayer
    setvar VAR_TEMP_0, 2
	goto_if_set FLAG_MET_CUTTING_TREASURE_HUNTER, RustboroCity_CuttingTreasureHuntersHouse_EventScript_SkipGreeting
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_Greeting, MSGBOX_DEFAULT
	setflag FLAG_MET_CUTTING_TREASURE_HUNTER
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_CheckPlayerHasApricorn
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_SkipGreeting::
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_HaveYouSeenAnyApricorns, MSGBOX_DEFAULT
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_CheckPlayerHasApricorn
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_CheckPlayerHasApricorn::
	call_if_eq VAR_TEMP_0, 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetPlayersApricorns_1
    call_if_eq VAR_TEMP_0, 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetPlayersApricorns_2
	goto_if_eq VAR_TEMP_1, 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_NoApricorns
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasApricorn
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetPlayersApricorns_1::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_PINK_APRICORN
	call_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasPinkApricorn
	checkitem ITEM_RED_APRICORN
	call_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasRedApricorn
	checkitem ITEM_GREEN_APRICORN
	call_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasGreenApricorn
	checkitem ITEM_WHITE_APRICORN
	call_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasWhiteApricorn
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetPlayersApricorns_2::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_BLUE_APRICORN
	call_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasBlueApricorn
	checkitem ITEM_YELLOW_APRICORN
	call_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasYellowApricorn
	checkitem ITEM_BLACK_APRICORN
	call_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasBlackArpricot
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasPinkApricorn::
	addvar VAR_TEMP_1, 1
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasRedApricorn::
	addvar VAR_TEMP_1, 2
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasGreenApricorn::
	addvar VAR_TEMP_1, 3
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasWhiteApricorn::
	addvar VAR_TEMP_1, 4
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasBlueApricorn::
	addvar VAR_TEMP_1, 1
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasYellowApricorn::
	addvar VAR_TEMP_1, 2
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasBlackArpricot::
	addvar VAR_TEMP_1, 3
	return

RustboroCity_CuttingTreasureHuntersHouse_EventScript_HasApricorn::
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_ThatsAnApricornIllTradeYou, MSGBOX_DEFAULT
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetTradeOptions
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetTradeOptions::
	goto_if_eq VAR_TEMP_0, 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ShowTradeOptions_1
    goto_if_eq VAR_TEMP_0, 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ShowTradeOptions_2
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_ShowTradeOptions_2

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ShowTradeOptions_1::
	message RustboroCity_CuttingTreasureHuntersHouse_Text_WhatDoYouWantToTrade
	waitmessage
	switch VAR_TEMP_1
	case 1,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsP
	case 2,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsR
	case 3,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPR
	case 4,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsG
	case 5,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPG
	case 6,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsRG
	case 7,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPRG
	case 8,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsW
	case 9,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPW
	case 10, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsRW
	case 11, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPRW
	case 12, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsGW
	case 13, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPGW
	case 14, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsRGW
	case 15, RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPRGW
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ShowTradeOptions_2::
	message RustboroCity_CuttingTreasureHuntersHouse_Text_WhatDoYouWantToTrade
	waitmessage
	switch VAR_TEMP_1
	case 1,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsB
	case 2,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsY
	case 3,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsBY
	case 4,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsK
	case 5,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsBK
	case 6,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsYK
	case 7,  RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsBYK
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsP::
    multichoice 0, 0, MULTI_APRICORNS_P, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsR::
    multichoice 0, 0, MULTI_APRICORNS_R, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPR::
    multichoice 0, 0, MULTI_APRICORNS_PR, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsG::
    multichoice 0, 0, MULTI_APRICORNS_G, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPG::
    multichoice 0, 0, MULTI_APRICORNS_PG, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsRG::
    multichoice 0, 0, MULTI_APRICORNS_RG, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPRG::
    multichoice 0, 0, MULTI_APRICORNS_PRG, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 3, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsW::
    multichoice 0, 0, MULTI_APRICORNS_W, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPW::
    multichoice 0, 0, MULTI_APRICORNS_PW, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsRW::
    multichoice 0, 0, MULTI_APRICORNS_RW, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPRW::
    multichoice 0, 0, MULTI_APRICORNS_PRW, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 3, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsGW::
    multichoice 0, 0, MULTI_APRICORNS_GW, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPGW::
    multichoice 0, 0, MULTI_APRICORNS_PGW, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 3, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsRGW::
    multichoice 0, 0, MULTI_APRICORNS_RGW, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 3, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsPRGW::
    multichoice 0, 0, MULTI_APRICORNS_PRGW, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn
    case 3, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn
    case 4, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsB::
    multichoice 0, 0, MULTI_APRICORNS_B, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlueApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsY::
    multichoice 0, 0, MULTI_APRICORNS_Y, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeYellowApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsBY::
    multichoice 0, 0, MULTI_APRICORNS_BY, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlueApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeYellowApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsK::
    multichoice 0, 0, MULTI_APRICORNS_K, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlackApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsBK::
    multichoice 0, 0, MULTI_APRICORNS_BK, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlueApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlackApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsYK::
    multichoice 0, 0, MULTI_APRICORNS_YK, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeYellowApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlackApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_ApricornOptionsBYK::
    multichoice 0, 0, MULTI_APRICORNS_BYK, FALSE
    switch VAR_RESULT
    case 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlueApricorn
    case 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeYellowApricorn
    case 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlackApricorn
    case 3, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
    end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradePinkApricorn::
	setvar VAR_0x8008, ITEM_PINK_APRICORN
	setvar VAR_0x8009, ITEM_PECHA_BERRY
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeRedApricorn::
	setvar VAR_0x8008, ITEM_RED_APRICORN
	setvar VAR_0x8009, ITEM_CHERI_BERRY
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeGreenApricorn::
	setvar VAR_0x8008, ITEM_GREEN_APRICORN
	setvar VAR_0x8009, ITEM_RAWST_BERRY
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeWhiteApricorn::
	setvar VAR_0x8008, ITEM_WHITE_APRICORN
	setvar VAR_0x8009, ITEM_ASPEAR_BERRY
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlueApricorn::
	setvar VAR_0x8008, ITEM_BLUE_APRICORN
	setvar VAR_0x8009, ITEM_ORAN_BERRY
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeYellowApricorn::
	setvar VAR_0x8008, ITEM_YELLOW_APRICORN
	setvar VAR_0x8009, ITEM_PERSIM_BERRY
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeBlackApricorn::
	setvar VAR_0x8008, ITEM_BLACK_APRICORN
	setvar VAR_0x8009, ITEM_CHESTO_BERRY
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TryTradeApricorn::
	bufferitemname STR_VAR_1, VAR_0x8008
	bufferitemname STR_VAR_2, VAR_0x8009
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_YoullTradeApricornForBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeApricorn
	checkitem VAR_0x8008, 2
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeApricorn
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_BagFull
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_TradeApricorn::
	removeitem VAR_0x8008
	giveitem VAR_0x8009
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_ItsADeal, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_0, 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetPlayersApricorns_1
    call_if_eq VAR_TEMP_0, 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetPlayersApricorns_2
	goto_if_eq VAR_TEMP_1, 0, RustboroCity_CuttingTreasureHuntersHouse_EventScript_EndTrade
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_TradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_CuttingTreasureHuntersHouse_EventScript_GetTradeOptions
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_BagFull::
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_DeclineTrade::
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_NoApricorns::
	goto_if_eq VAR_TEMP_0, 1, RustboroCity_CuttingTreasureHuntersHouse_EventScript_YouHaventGotAnyApricorns_1
    goto_if_eq VAR_TEMP_0, 2, RustboroCity_CuttingTreasureHuntersHouse_EventScript_YouHaventGotAnyApricorns_2
	goto RustboroCity_CuttingTreasureHuntersHouse_EventScript_YouHaventGotAnyApricorns_2
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_YouHaventGotAnyApricorns_1::
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_YouHaventGotAnyApricorns_1, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_YouHaventGotAnyApricorns_2::
	msgbox RustboroCity_CuttingTreasureHuntersHouse_Text_YouHaventGotAnyApricorns_2, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttingTreasureHuntersHouse_EventScript_EndTrade::
	release
	end

RustboroCity_CuttingTreasureHuntersHouse_Text_Greeting:
	.string "I'm a CUTTING TREASURE HUNTER!\p"
	.string "I'm an awesome dude who cuts down\n"
	.string "trees and gathers the treasures\l"
	.string "that have fallen on the ground.$"

RustboroCity_CuttingTreasureHuntersHouse_Text_HaveYouSeenAnyApricorns:
	.string "Tell me, have you seen any\n"
	.string "APRICORNS from felled trees?$"

RustboroCity_CuttingTreasureHuntersHouse_Text_YouHaventGotAnyApricorns_1:
	.string "You haven't got any treasures\n"
	.string "for me…\p"
	.string "If you see any APRICORNS, like the\n"
	.string "PINK APRICORN, trade it with me!$"

RustboroCity_CuttingTreasureHuntersHouse_Text_YouHaventGotAnyApricorns_2:
	.string "You haven't got any treasures\n"
	.string "for me…\p"
	.string "If you see any APRICORNS, like the\n"
	.string "BLUE APRICORN, trade it with me!$"

RustboroCity_CuttingTreasureHuntersHouse_Text_ThatsAnApricornIllTradeYou:
	.string "Oh, hey! That…\n"
	.string "That's an APRICORN!\p"
	.string "Oh, man, you've got to trade that\n"
	.string "with me! I'll give you something good!$"

RustboroCity_CuttingTreasureHuntersHouse_Text_WhatDoYouWantToTrade:
	.string "What do you want to trade?$"

RustboroCity_CuttingTreasureHuntersHouse_Text_YoullTradeApricornForBerry:
	.string "You'll trade your {STR_VAR_1} for\n"
	.string "my {STR_VAR_2}, then?$"

RustboroCity_CuttingTreasureHuntersHouse_Text_ItsADeal:
	.string "It's a done deal!\n"
	.string "Use that wisely!$"

RustboroCity_CuttingTreasureHuntersHouse_Text_TradeSomethingElse:
	.string "Do you want to trade something else?$"

RustboroCity_CuttingTreasureHuntersHouse_Text_BagFull:
	.string "Whoops, your BAG's full.\n"
	.string "Get rid of some items, friend!$"

RustboroCity_CuttingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind:
	.string "No? That's a bummer.\n"
	.string "Well, if you change your mind, come back.$"

