Common_EventScript_PkmnMartClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_PkmnMartClerk_GameClear
	goto_if_set FLAG_BADGE08_GET, EventScript_PkmnMartClerk_Badge08
	goto_if_set FLAG_BADGE07_GET, EventScript_PkmnMartClerk_Badge07
	goto_if_set FLAG_BADGE06_GET, EventScript_PkmnMartClerk_Badge06
	goto_if_set FLAG_BADGE05_GET, EventScript_PkmnMartClerk_Badge05
	goto_if_set FLAG_BADGE04_GET, EventScript_PkmnMartClerk_Badge04
	goto_if_set FLAG_BADGE03_GET, EventScript_PkmnMartClerk_Badge03
	goto_if_set FLAG_BADGE02_GET, EventScript_PkmnMartClerk_Badge02
	goto_if_set FLAG_BADGE01_GET, EventScript_PkmnMartClerk_Badge01
	goto_if_set FLAG_ADVENTURE_STARTED, EventScript_PkmnMartClerk_Expanded
	goto EventScript_PkmnMartClerk_Basic
	end

EventScript_PkmnMartClerk_GoodBye::
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_PkmnMartClerk_GameClear::
	pokemart EventScript_PkmnMartClerk_GameClearItems
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge08::
	pokemart EventScript_PkmnMartClerk_Badge08Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge07::
	pokemart EventScript_PkmnMartClerk_Badge07Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge06::
	pokemart EventScript_PkmnMartClerk_Badge06Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge05::
	pokemart EventScript_PkmnMartClerk_Badge05Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge04::
	pokemart EventScript_PkmnMartClerk_Badge04Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge03::
	pokemart EventScript_PkmnMartClerk_Badge03Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge02::
	pokemart EventScript_PkmnMartClerk_Badge02Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Badge01::
	pokemart EventScript_PkmnMartClerk_Badge01Items
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Expanded::
	pokemart EventScript_PkmnMartClerk_ExpandedItems
	goto EventScript_PkmnMartClerk_GoodBye
	end

EventScript_PkmnMartClerk_Basic::
	pokemart EventScript_PkmnMartClerk_BasicItems
	goto EventScript_PkmnMartClerk_GoodBye
	end

	.align 2
EventScript_PkmnMartClerk_GameClearItems:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_EXP_CANDY_XL
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_MAX_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge08Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_EXP_CANDY_XL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_MAX_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge07Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_MAX_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge06Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge05Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge04Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge03Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge02Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_Badge01Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_ExpandedItems:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_NONE
	release
	end

	.align 2
EventScript_PkmnMartClerk_BasicItems:
	.2byte ITEM_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_NONE
	release
	end
