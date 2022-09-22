.set ITEMID, VAR_0x8000
.set AMOUNT, VAR_0x8001

Std_ObtainItem::
	additem ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_TakeItem
	return

EventScript_TakeItem::
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferFanfare
	call_if_eq VAR_0x8007, TRUE, EventScript_ObtainedItem
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForItem
	return

EventScript_BufferFanfare::
	switch VAR_RESULT
	case POCKET_ITEMS,      EventScript_TryItemFanfare
	case POCKET_KEY_ITEMS,  EventScript_TryItemFanfare
	case POCKET_POKE_BALLS, EventScript_TryItemFanfare
	case POCKET_TM_HM,      EventScript_TryTMHMFanfare
	case POCKET_BERRIES,    EventScript_TryBerryFanfare
	end

EventScript_TryItemFanfare::
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_TryTMHMFanfare::
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedTMHM
	return

EventScript_TryBerryFanfare::
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedBerry
	return

EventScript_ObtainedItem::
	compare AMOUNT, TRUE
	goto_if_eq EventScript_ObtainedOneItem
	buffernumberstring 0, AMOUNT
	message gText_ObtainedItems
	goto EventScript_ContinueObtainedItem
EventScript_ObtainedOneItem:
	message gText_ObtainedOneItem
EventScript_ContinueObtainedItem:
	waitfanfare
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForItem::
	setvar VAR_RESULT, FALSE
	return

EventScript_PlayFanfareObtainedItem::
	playfanfare MUS_OBTAIN_ITEM
	return

EventScript_PlayFanfareObtainedTMHM::
	playfanfare MUS_OBTAIN_TMHM
	return

EventScript_PlayFanfareObtainedBerry::
	playfanfare MUS_OBTAIN_BERRY
	return

Std_ObtainDecoration::
	adddecoration ITEMID
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_ObtainDecorationMessage
	return

EventScript_ObtainDecorationMessage::
	bufferdecorationname STR_VAR_2, ITEMID
	call_if_eq VAR_0x8007, TRUE, EventScript_ObtainedDecor
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForDecor
	return

EventScript_ObtainedDecor::
	playfanfare MUS_OBTAIN_ITEM
	message gText_ObtainedOneItem
	waitfanfare
	waitmessage
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForDecor::
	setvar VAR_RESULT, FALSE
	return

Std_FindItem::
	lockall
	faceplayer
	waitse
	copyvar VAR_0x8004, ITEMID
	copyvar VAR_0x8005, AMOUNT
	checkitemspace ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferFanfare
	call_if_eq VAR_0x8007, TRUE, EventScript_PickUpItem
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomToPickUpItem
	releaseall
	return

EventScript_PickUpItem::
	removeobject VAR_LAST_TALKED
	additem VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, TRUE, EventScript_FoundTMHM
	call_if_eq VAR_0x8008, FALSE, EventScript_FoundItem
	waitfanfare
	waitmessage
	bufferitemnameplural STR_VAR_2, VAR_0x8004, VAR_0x8005
	pyramid_inchallenge
	return

EventScript_FoundTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, VAR_0x8005
	message gText_FoundItems
	return

EventScript_FoundItem::
    compare AMOUNT, TRUE
    goto_if_eq EventScript_FoundOneItem
    buffernumberstring 0, AMOUNT
    message gText_FoundItems
    return
EventScript_FoundOneItem:
    message gText_FoundOneItem
    return

EventScript_NoRoomToPickUpItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	return

EventScript_HiddenItemScript::
	lock
	waitse
	additem VAR_0x8005
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural STR_VAR_2, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_BufferFanfare
	goto_if_eq VAR_0x8007, TRUE, EventScript_PickUpHiddenItem
	goto_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForHiddenItem
	end

EventScript_PickUpHiddenItem::
	copyvar VAR_0x8008, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	goto_if_eq VAR_RESULT, TRUE, EventScript_FoundHiddenTMHM
	goto_if_eq VAR_RESULT, FALSE, EventScript_FoundHiddenItem
	end

EventScript_FoundHiddenTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, 1
	message gText_FoundItems
	goto EventScript_HiddenItemEnd
	end

EventScript_FoundHiddenItem::
	message gText_FoundOneItem
	goto EventScript_HiddenItemEnd
	end

EventScript_HiddenItemEnd::
	waitfanfare
	waitmessage
	copyvar VAR_0x8004, VAR_0x8008
	special TryPutTreasureInvestigatorsOnAir
	special SetHiddenItemFlag
	release
	end

EventScript_NoRoomForHiddenItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	releaseall
	end
