MauvilleCity_GameCorner_MapScripts::
	.byte 0

    @ Game Corner prices
	.set PORYGON_COINS,  9999
	.set DRATINI_COINS,  9999
	.set LARVITAR_COINS, 9999
	.set BAGON_COINS,    9999
	.set BELDUM_COINS,   9999
	.set GIBLE_COINS,    9999
	.set DEINO_COINS,    9999
	.set GOOMY_COINS,    9999
	.set JANGMO_O_COINS, 9999
	.set DREEPY_COINS,   9999
	.set FRIGIBAX_COINS, 9999

	.set GIMMIGHOUL_COIN_COINS, 1
	.set LEEK_COINS,            50
	.set LIGHT_BALL_COINS,      50
	.set LUCKY_PUNCH_COINS,     50
	.set METAL_POWDER_COINS,    50
	.set QUICK_POWDER_COINS,    50
	.set THICK_CLUB_COINS,      50
	.set DRAGON_SCALE_COINS,    100
	.set PRISM_SCALE_COINS,     100
	.set DEEP_SEA_SCALE_COINS,  100
	.set DEEP_SEA_TOOTH_COINS,  100
	.set LEADERS_CREST_COINS,   150
	.set AMULET_COIN_COINS,     500
	.set EXP_SHARE_COINS,       500
	.set LUCKY_EGG_COINS,       500

	.set SWEET_APPLE_COINS,         100
	.set SYRUPY_APPLE_COINS,        100
	.set TART_APPLE_COINS,          100
	.set CRACKED_POT_COINS,         100
	.set UNREMARKABLE_TEACUP_COINS, 100
	.set AUSPICIOUS_ARMOR_COINS,    150
	.set MALICIOUS_ARMOR_COINS,     150
	.set GALARICA_CUFF_COINS,       300
	.set GALARAICA_WREATH_COINS,    300
	.set BLACK_AUGURITE_COINS,      400
	.set LINKING_CORD_COINS,        400
	.set METAL_ALLOY_COINS,         500
	.set PEAT_BLOCK_COINS,          500
	.set CHIPPED_POT_COINS,         2000
	.set MASTERPIECE_TEACUP_COINS,  2000

	.set BERRY_SWEET_COINS,      50
	.set CLOVER_SWEET_COINS,     50
	.set FLOWER_SWEET_COINS,     50
	.set LOVE_SWEET_COINS,       50
	.set RIBBON_SWEET_COINS,     50
	.set STAR_SWEET_COINS,       50
	.set STRAWBERRY_SWEET_COINS, 50
	.set UPGRADE_COINS,          100
	.set DUBIOUS_DISC_COINS,     100
	.set ELECTIRIZER_COINS,      100
	.set MAGMARIZER_COINS,       100
	.set PROTECTOR_COINS,        100
	.set REAPER_CLOTH_COINS,     100
	.set SATCHET_COINS,          100
	.set WHIPPED_DREAM_COINS,    100

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

MauvilleCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeClerk_1::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_1
	release
	end

MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_1::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_1

MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_1::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1::
	setvar VAR_0x8004, SCROLL_MULTI_GAME_CORNER_VENDOR_1
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Porygon
	case 1, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Dratini
	case 2, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Larvitar
	case 3, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Bagon
	case 4, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Beldum
	case 5, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Gible
	case 6, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Deino
	case 7, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Goomy
	case 8, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_JangmoO
	case 9, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Dreepy
	case 10, MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Frigibax
	case 11, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	end

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Porygon::
	setvar VAR_TEMP_1, 1
	bufferspeciesname STR_VAR_1, SPECIES_PORYGON
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Dratini::
	setvar VAR_TEMP_1, 2
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Larvitar::
	setvar VAR_TEMP_1, 3
	bufferspeciesname STR_VAR_1, SPECIES_LARVITAR
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Bagon::
	setvar VAR_TEMP_1, 4
	bufferspeciesname STR_VAR_1, SPECIES_BAGON
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Beldum::
	setvar VAR_TEMP_1, 5
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Gible::
	setvar VAR_TEMP_1, 6
	bufferspeciesname STR_VAR_1, SPECIES_GIBLE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Deino::
	setvar VAR_TEMP_1, 7
	bufferspeciesname STR_VAR_1, SPECIES_DEINO
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Goomy::
	setvar VAR_TEMP_1, 8
	bufferspeciesname STR_VAR_1, SPECIES_GOOMY
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_JangmoO::
	setvar VAR_TEMP_1, 9
	bufferspeciesname STR_VAR_1, SPECIES_JANGMO_O
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Dreepy::
	setvar VAR_TEMP_1, 10
	bufferspeciesname STR_VAR_1, SPECIES_DREEPY
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ChoosePrize_1_Frigibax::
	setvar VAR_TEMP_1, 11
	bufferspeciesname STR_VAR_1, SPECIES_FRIGIBAX
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_1

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Porygon
	case 2, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Dratini
	case 3, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Larvitar
	case 4, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Bagon
	case 5, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Beldum
	case 6, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Gible
	case 7, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Deino
	case 8, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Goomy
	case 9, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_JangmoO
	case 10, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Dreepy
	case 11, MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Frigibax
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Porygon::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PORYGON_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PORYGON
	givemon SPECIES_PORYGON, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins PORYGON_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Dratini::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DRATINI_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	givemon SPECIES_DRATINI, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins DRATINI_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Larvitar::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LARVITAR_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LARVITAR
	givemon SPECIES_LARVITAR, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins LARVITAR_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Bagon::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, BAGON_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BAGON
	givemon SPECIES_BAGON, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins BAGON_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Beldum::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, BELDUM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins BELDUM_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Gible::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, GIBLE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GIBLE
	givemon SPECIES_GIBLE, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins GIBLE_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Deino::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DEINO_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DEINO
	givemon SPECIES_DEINO, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins DEINO_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Goomy::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, GOOMY_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GOOMY
	givemon SPECIES_GOOMY, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins GOOMY_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_JangmoO::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, JANGMO_O_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_JANGMO_O
	givemon SPECIES_JANGMO_O, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins JANGMO_O_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Dreepy::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DREEPY_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DREEPY
	givemon SPECIES_DREEPY, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins DREEPY_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_1_Frigibax::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, FRIGIBAX_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FRIGIBAX
	givemon SPECIES_FRIGIBAX, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1
	removecoins FRIGIBAX_COINS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_SendMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_SendMonToPC
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_1::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_1
	end

MauvilleCity_GameCorner_EventScript_NoRoomForPrize_1::
	call Common_EventScript_NoMoreRoomForPokemon
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_1
	end

MauvilleCity_GameCorner_EventScript_SendMonToParty::
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_1
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_1
	end

MauvilleCity_GameCorner_EventScript_SendMonToPC::
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_1
    call Common_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_1
	end

MauvilleCity_GameCorner_EventScript_PrizeClerk_2::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_2
	release
	end

MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_2::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_2

MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2::
	setvar VAR_0x8004, SCROLL_MULTI_GAME_CORNER_VENDOR_2
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_GimmighoulCoin
	case 1, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_Leek
	case 2, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LightBall
	case 3, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LuckyPunch
	case 4, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_MetalPowder
	case 5, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_QuickPowder
	case 6, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_ThickClub
	case 7, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_DragonScale
	case 8, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_PrismScale
    case 9, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_DeapSeaScale
    case 10, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_DeapSeaTooth
	case 11, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LeadersCrest
    case 12, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_AmuletCoin
    case 13, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_ExpShare
    case 14, MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LuckyEgg
	case 15, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	end

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_GimmighoulCoin::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_GIMMIGHOUL_COIN
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_Leek::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_LEEK
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LightBall::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_LIGHT_BALL
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LuckyPunch::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_LUCKY_PUNCH
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_MetalPowder::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_METAL_POWDER
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_QuickPowder::
	setvar VAR_TEMP_1, 6
	bufferitemname STR_VAR_1, ITEM_QUICK_POWDER
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_ThickClub::
	setvar VAR_TEMP_1, 7
	bufferitemname STR_VAR_1, ITEM_THICK_CLUB
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_DragonScale::
	setvar VAR_TEMP_1, 8
	bufferitemname STR_VAR_1, ITEM_DRAGON_SCALE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_PrismScale::
	setvar VAR_TEMP_1, 9
	bufferitemname STR_VAR_1, ITEM_PRISM_SCALE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_DeapSeaScale::
	setvar VAR_TEMP_1, 10
	bufferitemname STR_VAR_1, ITEM_DEEP_SEA_SCALE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_DeapSeaTooth::
	setvar VAR_TEMP_1, 11
	bufferitemname STR_VAR_1, ITEM_DEEP_SEA_TOOTH
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LeadersCrest::
	setvar VAR_TEMP_1, 12
	bufferitemname STR_VAR_1, ITEM_LEADERS_CREST
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_AmuletCoin::
	setvar VAR_TEMP_1, 13
	bufferitemname STR_VAR_1, ITEM_AMULET_COIN
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_ExpShare::
	setvar VAR_TEMP_1, 14
	bufferitemname STR_VAR_1, ITEM_EXP_SHARE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ChoosePrize_2_LuckyEgg::
	setvar VAR_TEMP_1, 15
	bufferitemname STR_VAR_1, ITEM_LUCKY_EGG
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_2

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_GimmighoulCoin
	case 2, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_Leek
	case 3, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LightBall
	case 4, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LuckyPunch
	case 5, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_MetalPowder
	case 6, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_QuickPowder
	case 7, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_ThickClub
	case 8, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_DragonScale
	case 9, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_PrismScale
    case 10, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_DeapSeaScale
    case 11, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_DeapSeaTooth
	case 12, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LeadersCrest
    case 13, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_AmuletCoin
    case 14, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_ExpShare
    case 15, MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LuckyEgg
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_GimmighoulCoin::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, GIMMIGHOUL_COIN_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_GIMMIGHOUL_COIN
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins GIMMIGHOUL_COIN_COINS
	additem ITEM_GIMMIGHOUL_COIN
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_Leek::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LEEK_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_LEEK
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins LEEK_COINS
	additem ITEM_LEEK
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LightBall::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LIGHT_BALL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_LIGHT_BALL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins LIGHT_BALL_COINS
	additem ITEM_LIGHT_BALL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LuckyPunch::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LUCKY_PUNCH_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_LUCKY_PUNCH
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins LUCKY_PUNCH_COINS
	additem ITEM_LUCKY_PUNCH
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_MetalPowder::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, METAL_POWDER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_METAL_POWDER
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins METAL_POWDER_COINS
	additem ITEM_METAL_POWDER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_QuickPowder::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, QUICK_POWDER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_QUICK_POWDER
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins QUICK_POWDER_COINS
	additem ITEM_QUICK_POWDER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_ThickClub::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, THICK_CLUB_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_THICK_CLUB
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins THICK_CLUB_COINS
	additem ITEM_THICK_CLUB
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_DragonScale::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DRAGON_SCALE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_DRAGON_SCALE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins DRAGON_SCALE_COINS
	additem ITEM_DRAGON_SCALE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_PrismScale::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PRISM_SCALE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_PRISM_SCALE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins PRISM_SCALE_COINS
	additem ITEM_PRISM_SCALE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_DeapSeaScale::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DEEP_SEA_SCALE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins DEEP_SEA_SCALE_COINS
	additem ITEM_DEEP_SEA_SCALE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_DeapSeaTooth::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DEEP_SEA_TOOTH_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins DEEP_SEA_TOOTH_COINS
	additem ITEM_DEEP_SEA_TOOTH
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LeadersCrest::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LEADERS_CREST_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_LEADERS_CREST
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins LEADERS_CREST_COINS
	additem ITEM_LEADERS_CREST
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_AmuletCoin::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, AMULET_COIN_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins AMULET_COIN_COINS
	additem ITEM_AMULET_COIN
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_ExpShare::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, EXP_SHARE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins EXP_SHARE_COINS
	additem ITEM_EXP_SHARE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_2_LuckyEgg::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LUCKY_EGG_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2
	checkitemspace ITEM_LUCKY_EGG
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2
	removecoins LUCKY_EGG_COINS
	additem ITEM_LUCKY_EGG
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_2::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_NoRoomForPrize_2::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_2
	end

MauvilleCity_GameCorner_EventScript_PrizeClerk_3::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_3
	release
	end

MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_3::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_3

MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3::
	setvar VAR_0x8004, SCROLL_MULTI_GAME_CORNER_VENDOR_3
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_SweetApple
	case 1, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_SyrupyApple
	case 2, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_TartApple
	case 3, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_CrackedPot
	case 4, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_UnremarkableTeacup
    case 5, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_AuspiciousArmor
    case 6, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_MaliciousArmor
    case 7, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_GalaricaCuff
    case 8, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_GalaricaWreath
    case 9, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_BlackAugurite
    case 10, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_LinkingCord
    case 11, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_MetalAlloy
    case 12, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_PeatBlock
    case 13, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_ChippedPot
    case 14, MauvilleCity_GameCorner_EventScript_ChoosePrize_3_MasterpieceTeacup
	case 15, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	end

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_SweetApple::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_SWEET_APPLE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_SyrupyApple::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_SYRUPY_APPLE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_TartApple::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TART_APPLE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_CrackedPot::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_CRACKED_POT
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_UnremarkableTeacup::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_UNREMARKABLE_TEACUP
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_AuspiciousArmor::
	setvar VAR_TEMP_1, 6
	bufferitemname STR_VAR_1, ITEM_AUSPICIOUS_ARMOR
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_MaliciousArmor::
	setvar VAR_TEMP_1, 7
	bufferitemname STR_VAR_1, ITEM_MALICIOUS_ARMOR
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_GalaricaCuff::
	setvar VAR_TEMP_1, 8
	bufferitemname STR_VAR_1, ITEM_GALARICA_CUFF
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_GalaricaWreath::
	setvar VAR_TEMP_1, 9
	bufferitemname STR_VAR_1, ITEM_GALARICA_WREATH
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_BlackAugurite::
	setvar VAR_TEMP_1, 10
	bufferitemname STR_VAR_1, ITEM_BLACK_AUGURITE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_LinkingCord::
	setvar VAR_TEMP_1, 11
	bufferitemname STR_VAR_1, ITEM_LINKING_CORD
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_MetalAlloy::
	setvar VAR_TEMP_1, 12
	bufferitemname STR_VAR_1, ITEM_METAL_COAT @ placeholder
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_PeatBlock::
	setvar VAR_TEMP_1, 13
	bufferitemname STR_VAR_1, ITEM_PEAT_BLOCK
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_ChippedPot::
	setvar VAR_TEMP_1, 14
	bufferitemname STR_VAR_1, ITEM_CHIPPED_POT
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ChoosePrize_3_MasterpieceTeacup::
	setvar VAR_TEMP_1, 15
	bufferitemname STR_VAR_1, ITEM_MASTERPIECE_TEACUP
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_3

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_SweetApple
	case 2, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_SyrupyApple
	case 3, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_TartApple
	case 4, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_CrackedPot
	case 5, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_UnremarkableTeacup
    case 6, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_AuspiciousArmor
    case 7, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_MaliciousArmor
    case 8, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_GalaricaCuff
    case 9, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_GalaricaWreath
    case 10, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_BlackAugurite
    case 11, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_LinkingCord
    case 12, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_MetalAlloy
    case 13, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_PeatBlock
    case 14, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_ChippedPot
    case 15, MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_MasterpieceTeacup
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_SweetApple::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, SWEET_APPLE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_SWEET_APPLE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins SWEET_APPLE_COINS
	additem ITEM_SWEET_APPLE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_SyrupyApple::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, SYRUPY_APPLE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_SYRUPY_APPLE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins SYRUPY_APPLE_COINS
	additem ITEM_SYRUPY_APPLE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_TartApple::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TART_APPLE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_TART_APPLE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins TART_APPLE_COINS
	additem ITEM_TART_APPLE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_CrackedPot::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CRACKED_POT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_CRACKED_POT
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins CRACKED_POT_COINS
	additem ITEM_CRACKED_POT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_UnremarkableTeacup::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, UNREMARKABLE_TEACUP_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_UNREMARKABLE_TEACUP
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins UNREMARKABLE_TEACUP_COINS
	additem ITEM_UNREMARKABLE_TEACUP
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_AuspiciousArmor::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, AUSPICIOUS_ARMOR_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_AUSPICIOUS_ARMOR
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins AUSPICIOUS_ARMOR_COINS
	additem ITEM_AUSPICIOUS_ARMOR
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_MaliciousArmor::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, MALICIOUS_ARMOR_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_MALICIOUS_ARMOR
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins MALICIOUS_ARMOR_COINS
	additem ITEM_MALICIOUS_ARMOR
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_GalaricaCuff::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, GALARICA_CUFF_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_GALARICA_CUFF
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins GALARICA_CUFF_COINS
	additem ITEM_GALARICA_CUFF
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_GalaricaWreath::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, GALARAICA_WREATH_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_GALARICA_WREATH
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins GALARAICA_WREATH_COINS
	additem ITEM_GALARICA_WREATH
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_BlackAugurite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, BLACK_AUGURITE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_BLACK_AUGURITE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins BLACK_AUGURITE_COINS
	additem ITEM_BLACK_AUGURITE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_LinkingCord::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LINKING_CORD_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_LINKING_CORD
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins LINKING_CORD_COINS
	additem ITEM_LINKING_CORD
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_MetalAlloy::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, METAL_ALLOY_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_METAL_COAT @ placeholder
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins METAL_ALLOY_COINS
	additem ITEM_METAL_COAT @ placeholder
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_PeatBlock::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PEAT_BLOCK_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_PEAT_BLOCK
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins PEAT_BLOCK_COINS
	additem ITEM_PEAT_BLOCK
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_ChippedPot::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CHIPPED_POT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_CHIPPED_POT
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins CHIPPED_POT_COINS
	additem ITEM_CHIPPED_POT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_3_MasterpieceTeacup::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, MASTERPIECE_TEACUP_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3
	checkitemspace ITEM_MASTERPIECE_TEACUP
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3
	removecoins MASTERPIECE_TEACUP_COINS
	additem ITEM_MASTERPIECE_TEACUP
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_3::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_NoRoomForPrize_3::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_3
	end

MauvilleCity_GameCorner_EventScript_PrizeClerk_4::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_4
	release
	end

MauvilleCity_GameCorner_EventScript_ChoosePrizeMessage_4::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_4

MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChoosePrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4::
	setvar VAR_0x8004, SCROLL_MULTI_GAME_CORNER_VENDOR_4
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_BerrySweet
	case 1, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_CloverSweet
	case 2, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_FlowerSweet
	case 3, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_LoveSweet
	case 4, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_RibbonSweet
	case 5, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_StarSweet
    case 6, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_StrawberrySweet
    case 7, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Upgrade
    case 8, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_DubiousDisc
    case 9, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Electirizer
    case 10, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Magmarizer
    case 11, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Protector
    case 12, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_ReaperCloth
    case 13, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Satchet
    case 14, MauvilleCity_GameCorner_EventScript_ChoosePrize_4_WhippedDream
	case 15, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	end

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_BerrySweet::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_BERRY_SWEET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_CloverSweet::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_CLOVER_SWEET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_FlowerSweet::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_FLOWER_SWEET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_LoveSweet::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_LOVE_SWEET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_RibbonSweet::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_RIBBON_SWEET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_StarSweet::
	setvar VAR_TEMP_1, 6
	bufferitemname STR_VAR_1, ITEM_STAR_SWEET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_StrawberrySweet::
	setvar VAR_TEMP_1, 7
	bufferitemname STR_VAR_1, ITEM_STRAWBERRY_SWEET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Upgrade::
	setvar VAR_TEMP_1, 8
	bufferitemname STR_VAR_1, ITEM_UPGRADE
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_DubiousDisc::
	setvar VAR_TEMP_1, 9
	bufferitemname STR_VAR_1, ITEM_DUBIOUS_DISC
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Electirizer::
	setvar VAR_TEMP_1, 10
	bufferitemname STR_VAR_1, ITEM_ELECTIRIZER
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Magmarizer::
	setvar VAR_TEMP_1, 11
	bufferitemname STR_VAR_1, ITEM_MAGMARIZER
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Protector::
	setvar VAR_TEMP_1, 12
	bufferitemname STR_VAR_1, ITEM_PROTECTOR
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_ReaperCloth::
	setvar VAR_TEMP_1, 13
	bufferitemname STR_VAR_1, ITEM_REAPER_CLOTH
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_Satchet::
	setvar VAR_TEMP_1, 14
	bufferitemname STR_VAR_1, ITEM_SACHET
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ChoosePrize_4_WhippedDream::
	setvar VAR_TEMP_1, 15
	bufferitemname STR_VAR_1, ITEM_WHIPPED_DREAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmPrize_4

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelPrizeSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_BerrySweet
	case 2, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_CloverSweet
	case 3, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_FlowerSweet
	case 4, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_LoveSweet
	case 5, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_RibbonSweet
	case 6, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_StarSweet
    case 7, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_StrawberrySweet
    case 8, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Upgrade
    case 9, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_DubiousDisc
    case 10, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Electirizer
    case 11, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Magmarizer
    case 12, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Protector
    case 13, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_ReaperCloth
    case 14, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Satchet
    case 15, MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_WhippedDream
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_BerrySweet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, BERRY_SWEET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_BERRY_SWEET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins BERRY_SWEET_COINS
	additem ITEM_BERRY_SWEET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_CloverSweet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CLOVER_SWEET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_CLOVER_SWEET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins CLOVER_SWEET_COINS
	additem ITEM_CLOVER_SWEET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_FlowerSweet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, FLOWER_SWEET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_FLOWER_SWEET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins FLOWER_SWEET_COINS
	additem ITEM_FLOWER_SWEET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_LoveSweet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LOVE_SWEET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_LOVE_SWEET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins LOVE_SWEET_COINS
	additem ITEM_LOVE_SWEET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_RibbonSweet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, RIBBON_SWEET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_RIBBON_SWEET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins RIBBON_SWEET_COINS
	additem ITEM_RIBBON_SWEET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_StarSweet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, STAR_SWEET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_STAR_SWEET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins STAR_SWEET_COINS
	additem ITEM_STAR_SWEET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_StrawberrySweet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, STRAWBERRY_SWEET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_STRAWBERRY_SWEET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins STRAWBERRY_SWEET_COINS
	additem ITEM_STRAWBERRY_SWEET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Upgrade::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, UPGRADE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_UPGRADE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins UPGRADE_COINS
	additem ITEM_UPGRADE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_DubiousDisc::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DUBIOUS_DISC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_DUBIOUS_DISC
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins DUBIOUS_DISC_COINS
	additem ITEM_DUBIOUS_DISC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Electirizer::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, ELECTIRIZER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_ELECTIRIZER
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins ELECTIRIZER_COINS
	additem ITEM_ELECTIRIZER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Magmarizer::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, MAGMARIZER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_MAGMARIZER
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins MAGMARIZER_COINS
	additem ITEM_MAGMARIZER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Protector::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PROTECTOR_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_PROTECTOR
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins PROTECTOR_COINS
	additem ITEM_PROTECTOR
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_ReaperCloth::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, REAPER_CLOTH_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_REAPER_CLOTH
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins REAPER_CLOTH_COINS
	additem ITEM_REAPER_CLOTH
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_Satchet::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, SATCHET_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_SACHET
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins SATCHET_COINS
	additem ITEM_SACHET
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_ConfirmPrize_4_WhippedDream::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, WHIPPED_DREAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4
	checkitemspace ITEM_WHIPPED_DREAM
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4
	removecoins WHIPPED_DREAM_COINS
	additem ITEM_WHIPPED_DREAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPrize_4::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_NoRoomForPrize_4::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePrize_4
	end

MauvilleCity_GameCorner_EventScript_CancelPrizeSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_50_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_50_COINS
	addcoins 50
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "This is MAUVILLE GAME CORNER.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some COINS for\n"
	.string "the games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS.\n"
	.string "Would you like some?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your COINS!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your COIN CASE is full.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need COINS, then?\n"
	.string "Good luck on your adventure!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your COINS for\n"
	.string "prizes here.$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough COINS.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "Oh, is that so? \n"
	.string "You need to save some COINS before\l"
	.string "coming back here.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "Here you go!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "I made a mistake and got two of\n"
	.string "the same DOLLS.\p"
	.string "Would you like one of them?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "Huh?\n"
	.string "You want it, but not right now?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a COIN CASE.\p"
	.string "I think the young lady next door\n"
	.string "had one. Go see her!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some COINS!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "MAUVILLE has something for\n"
	.string "everyone.\p"
	.string "For me, it's the GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "The ROULETTE tables have different\n"
	.string "rates.\p"
	.string "Check your COINS if you're going to\n"
	.string "pick a table.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "COINS are needed to play here\n"
	.string "in the GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "This ROULETTE thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Up to three COINS can be used to play\n"
	.string "the SLOTS.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the REEL TIME\n"
	.string "bonus game, you'll receive extra COINS.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Here's some information for you\n"
	.string "about the SLOTS.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more REEL TIME chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "REEL TIME chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 COINS, but it's\n"
	.string "very difficult to get.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a COIN CASE.$"

