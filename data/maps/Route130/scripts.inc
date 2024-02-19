.set LOCALID_ENIGMA, 6

Route130_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
	.byte 0

Route130_OnTransition:
	call Common_EventScript_SetupEnigmaGfxId
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route130_EventScript_CheckSetAbnormalWeather
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, Route130_EventScript_SetMirageIslandLayout
@ Mirage Island isn't currently visible, hide any objects on the island. Only the first flag is actually associated with anything.
	setflag FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	end

Route130_EventScript_SetMirageIslandLayout::
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	end

Route130_EventScript_CheckSetAbnormalWeather::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route130_EventScript_Rodney::
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Katie::
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Santiago::
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Enigma::
	lock
	faceplayer
	fadeoutbgm 0
	msgbox Route130_Text_EnigmaElipsis, MSGBOX_DEFAULT
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route130_EventScript_StartEnigmaBattleLeaf
	goto_if_eq VAR_RESULT, FEMALE, Route130_EventScript_StartEnigmaBattleRed
	end

Route130_EventScript_StartEnigmaBattleLeaf::
	trainerbattle_no_intro TRAINER_LEAF, Route130_Text_EnigmaElipsis
	goto Route130_EventScript_AfterEnigmaBattle
	end

Route130_EventScript_StartEnigmaBattleRed::
	trainerbattle_no_intro TRAINER_RED, Route130_Text_EnigmaElipsis
	goto Route130_EventScript_AfterEnigmaBattle
	end

Route130_EventScript_AfterEnigmaBattle::
	msgbox Route130_Text_EnigmaElipsis, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ENIGMA
	setflag FLAG_DEFEATED_ROUTE_130_ENIGMA
	setflag FLAG_HIDE_ROUTE_130_ENIGMA
	fadescreen FADE_FROM_BLACK
	release
	end

Route130_Text_EnigmaElipsis:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …$"
