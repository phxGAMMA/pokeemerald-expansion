Common_EventScript_SetupRivalGfxId::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EventScript_SetupRivalGfxIdFemale
	goto_if_eq VAR_RESULT, FEMALE, EventScript_SetupRivalGfxIdMale
	end

EventScript_SetupRivalGfxIdFemale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

EventScript_SetupRivalGfxIdMale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

Common_EventScript_SetupRivalOnBikeGfxId::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EventScript_SetupRivalOnBikeGfxIdFemale
	goto_if_eq VAR_RESULT, FEMALE, EventScript_SetupRivalOnBikeGfxIdMale
	end

EventScript_SetupRivalOnBikeGfxIdFemale::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE
	return

EventScript_SetupRivalOnBikeGfxIdMale::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_BRENDAN_MACH_BIKE
	return

Common_EventScript_SetupEnigmaGfxId::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EventScript_SetupEnigmaGfxIdFemale
	goto_if_eq VAR_RESULT, FEMALE, EventScript_SetupEnigmaGfxIdMale
	end

EventScript_SetupEnigmaGfxIdFemale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEAF
	return

EventScript_SetupEnigmaGfxIdMale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RED
	return

@ Unused
Common_EventScript_SetupEncounterGfxIdNightDay::
	gettimeofday
	goto_if_eq VAR_0x8000, 3, EventScript_SetupZigzagoonGfxId
	goto EventScript_SetupPoochyenaGfxId
	end

EventScript_SetupZigzagoonGfxId::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ZIGZAGOON_1
	return

EventScript_SetupPoochyenaGfxId::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_POOCHYENA
	return
