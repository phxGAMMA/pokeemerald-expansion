Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

Common_EventScript_PkmnCenterAssistant::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterAssistant_GoldCard
	msgbox gText_HowCanIAssistYourYourPkmn, MSGBOX_DEFAULT
	multichoice 17, 4, MULTI_PKMN_CENTER_ASSISTANT, FALSE
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterAssistant_RelearnMove_ChoosePkmn
    case 1, EventScript_PkmnCenterAssistant_DeleteMove_ChoosePkmn
    case 2, EventScript_PkmnCenterAssistant_RateName_ChoosePkmn
	case MULTI_B_PRESSED, EventScript_PkmnCenterAssistant_Goodbye
	end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	goto EventScript_PkmnCenterNurse_PlayerTurn
	end

EventScript_PkmnCenterAssistant_Goodbye::
	message gText_WeHopeToSeeYouAgain
	goto EventScript_PkmnCenterAssistant_PlayerTurn
	end

EventScript_PkmnCenterNurse_Goodbye2::
	message gText_WeHopeToSeeYouAgain2
	goto EventScript_PkmnCenterNurse_PlayerTurn
	end

EventScript_PkmnCenterAssistant_Goodbye2::
	message gText_WeHopeToSeeYouAgain2
	goto EventScript_PkmnCenterAssistant_PlayerTurn
	end

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	waitmessage
	closemessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterAssistant_RelearnMove_ChoosePkmn::
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterAssistant_Goodbye
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterAssistant_RelearnMove_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, EventScript_PkmnCenterAssistant_RelearnMove_NothingToRemember
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterAssistant_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterAssistant_IllTakeYourPkmn2
	waitmessage
	closemessage
	call EventScript_PkmnCenterAssistant_RelearnMove_TeachMove
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterAssistant_CheckPokerus
	goto EventScript_PkmnCenterAssistant_CheckTrainerHillAndUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterAssistant_DeleteMove_ChoosePkmn::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterAssistant_Goodbye
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterAssistant_RelearnMove_CantTeachEgg2
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, EventScript_PkmnCenterAssistant_DeleteMove_NothingToForget
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterAssistant_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterAssistant_IllTakeYourPkmn2
	waitmessage
	closemessage
	call EventScript_PkmnCenterAssistant_DeleteMove_ForgetMove
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterAssistant_CheckPokerus
	goto EventScript_PkmnCenterAssistant_CheckTrainerHillAndUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterAssistant_RateName_ChoosePkmn::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterAssistant_Goodbye
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterAssistant_RelearnMove_CantTeachEgg3
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterAssistant_RateName_NothingToRate
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterAssistant_RateName_NothingToRate
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterAssistant_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterAssistant_IllTakeYourPkmn2
	waitmessage
	closemessage
	call EventScript_PkmnCenterAssistant_RateName_ChangeName
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterAssistant_CheckPokerus
	goto EventScript_PkmnCenterAssistant_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterAssistant_RelearnMove_NothingToRemember::
	msgbox gText_NothingToRemember, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterAssistant_RelearnMove_ChoosePkmn
	end

EventScript_PkmnCenterAssistant_DeleteMove_NothingToForget::
	msgbox gText_NothingToForget, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterAssistant_DeleteMove_ChoosePkmn
	end

EventScript_PkmnCenterAssistant_RateName_NothingToRate::
	msgbox gText_NothingToRate, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterAssistant_RateName_ChoosePkmn
	end

EventScript_PkmnCenterAssistant_RelearnMove_CantTeachEgg::
	msgbox gText_CantTeachEgg, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterAssistant_RelearnMove_ChoosePkmn
	end

EventScript_PkmnCenterAssistant_RelearnMove_CantTeachEgg2::
	msgbox gText_CantTeachEgg, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterAssistant_DeleteMove_ChoosePkmn
	end

EventScript_PkmnCenterAssistant_RelearnMove_CantTeachEgg3::
	msgbox gText_CantTeachEgg, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterAssistant_RateName_ChoosePkmn
	end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterAssistant_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
	message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterAssistant_IllTakeYourPkmn2::
	message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	special HealPlayerParty
	return

EventScript_PkmnCenterAssistant_RelearnMove_TeachMove::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PC_ON
	waitse
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	playse SE_PC_LOGIN
	waitse
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	playse SE_PC_LOGIN
	waitse
	playse SE_PC_OFF
	waitse
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

EventScript_PkmnCenterAssistant_DeleteMove_ForgetMove::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PC_ON
	waitse
	playse SE_PC_LOGIN
	waitse
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, EventScript_PkmnCenterNurse_ReturnPkmn
	special MoveDeleterForgetMove
	waitstate
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	playse SE_PC_LOGIN
	waitse
	playse SE_PC_OFF
	waitse
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

EventScript_PkmnCenterAssistant_RateName_ChangeName::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PC_ON
	waitse
	playse SE_PC_LOGIN
	waitse
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ReturnPkmn
	waitstate
	playse SE_PC_LOGIN
	waitse
	playse SE_PC_OFF
	waitse
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

EventScript_PkmnCenterAssistant_CheckTrainerHillAndUnionRoom::
    specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
    goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterAssistant_ReturnPkmn
    specialvar VAR_RESULT, BufferUnionRoomPlayerName
    copyvar VAR_0x8008, VAR_RESULT
    goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterAssistant_ReturnPkmn
    goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterAssistant_PlayerWaitingInUnionRoom
    end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
	applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	goto EventScript_PkmnCenterNurse_Goodbye
	end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterAssistant_ReturnPkmn::
    goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterAssistant_ReturnPkmn2
    applymovement VAR_LAST_TALKED, Movement_PkmnCenterAssistant_Bow
    waitmovement 0
    goto EventScript_PkmnCenterAssistant_Goodbye
    end

EventScript_PkmnCenterNurse_ReturnPkmn2::
	applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	goto EventScript_PkmnCenterNurse_Goodbye2
	end

EventScript_PkmnCenterAssistant_ReturnPkmn2::
    applymovement VAR_LAST_TALKED, Movement_PkmnCenterAssistant_Bow
    waitmovement 0
    goto EventScript_PkmnCenterAssistant_Goodbye2
    end

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom2
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	goto EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterAssistant_PlayerWaitingInUnionRoom::
    goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterAssistant_PlayerWaitingInUnionRoom2
    goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterAssistant_ReturnPkmn
    setflag FLAG_NURSE_UNION_ROOM_REMINDER
    message CableClub_Text_PlayerIsWaiting
    waitmessage
    applymovement VAR_LAST_TALKED, Movement_PkmnCenterAssistant_Bow
    waitmovement 0
    goto EventScript_PkmnCenterAssistant_Goodbye
    end

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom2::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn2
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	goto EventScript_PkmnCenterNurse_Goodbye2
	end

EventScript_PkmnCenterAssistant_PlayerWaitingInUnionRoom2::
    goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterAssistant_ReturnPkmn2
    setflag FLAG_NURSE_UNION_ROOM_REMINDER
    message CableClub_Text_PlayerIsWaiting
    waitmessage
    applymovement VAR_LAST_TALKED, Movement_PkmnCenterAssistant_Bow
    waitmovement 0
    goto EventScript_PkmnCenterAssistant_Goodbye2
    end

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterAssistant_CheckPokerus::
    specialvar VAR_RESULT, IsPokerusInParty
    goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterAssistant_ExplainPokerus
    goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterAssistant_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterAssistant_ExplainPokerus::
    message gText_PokerusExplanation
    setflag FLAG_POKERUS_EXPLAINED
    goto EventScript_PkmnCenterAssistant_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye2
	end

EventScript_PkmnCenterAssistant_GoldCard::
    goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterAssistant_AskForUsual
    setflag FLAG_NURSE_MENTIONS_GOLD_CARD
    msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement VAR_LAST_TALKED, Common_Movement_Delay48
    waitmovement 0
    msgbox gText_NoticesGoldCard2, MSGBOX_DEFAULT
	multichoice 17, 4, MULTI_PKMN_CENTER_ASSISTANT, FALSE
	switch VAR_RESULT
    case 0, EventScript_PkmnCenterAssistant_GoldCardRelearnMove
    case 1, EventScript_PkmnCenterAssistant_GoldCardDeleteMove
    case 2, EventScript_PkmnCenterAssistant_GoldCardRateName
	case MULTI_B_PRESSED, EventScript_PkmnCenterAssistant_Goodbye2
    end

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye2
	end

EventScript_PkmnCenterAssistant_AskForUsual::
    msgbox gText_YouWantTheUsual2, MSGBOX_DEFAULT
    multichoice 17, 4, MULTI_PKMN_CENTER_ASSISTANT, FALSE
    switch VAR_RESULT
    case 0, EventScript_PkmnCenterAssistant_GoldCardRelearnMove
    case 1, EventScript_PkmnCenterAssistant_GoldCardDeleteMove
    case 2, EventScript_PkmnCenterAssistant_GoldCardRateName
    case MULTI_B_PRESSED, EventScript_PkmnCenterAssistant_Goodbye2
    end

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

EventScript_PkmnCenterAssistant_GoldCardRelearnMove::
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterAssistant_RelearnMove_ChoosePkmn
    end

EventScript_PkmnCenterAssistant_GoldCardDeleteMove::
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterAssistant_DeleteMove_ChoosePkmn
    end

EventScript_PkmnCenterAssistant_GoldCardRateName::
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterAssistant_RateName_ChoosePkmn
    end

EventScript_PkmnCenterNurse_PlayerTurn::
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	release
	end

EventScript_PkmnCenterAssistant_PlayerTurn::
	waitmessage
	closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
    waitmovement 0
    release
    end

Movement_PkmnCenterNurse_Bow:
	delay_4
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterAssistant_Bow:
	delay_4
    nurse_joy_bow
    delay_4
    step_end
