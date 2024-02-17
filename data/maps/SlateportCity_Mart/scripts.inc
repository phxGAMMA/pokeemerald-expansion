SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk::
	goto Common_EventScript_PkmnMartClerk
	end

SlateportCity_Mart_EventScript_Cashier::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_GLITTER_MAIL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_BEAD_MAIL
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_TROPIC_MAIL
	.2byte ITEM_DREAM_MAIL
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_NONE
	release
	end

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man::
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
	.string "The MARKET does have some interesting\n"
	.string "merchandise.\p"
	.string "But there are some items you can only\n"
	.string "get at a POKéMON MART.$"

SlateportCity_Mart_Text_GreatBallIsBetter:
	.string "A GREAT BALL is better than a POKé BALL\n"
	.string "at catching POKéMON.\p"
	.string "With this, I should be able to get that\n"
	.string "elusive POKéMON…$"

