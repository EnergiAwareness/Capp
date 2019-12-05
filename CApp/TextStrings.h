#pragma once


extern char* GetTextString(int value);

//Added new item here must also be added the char *array in the c file to work.
enum Text_Strings
{
	ENTERED_VALUE_WAS_NOT_A_NUMBER,
	UNKNOWN_STRING_REQUEST,
	INVALID_SELECTION,
	SELET_A_NUMBER,
	EXISTING_MENU,
	ENTER_NAME_OF_DEVICE,
	ENTER_POWER_USAGE_OF_DEVICE,
	TOTAL_STRINGS//MOST BE LAST!!
};