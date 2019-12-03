#pragma once


extern char* GetTextString(int value);

//Added new item here must also be added the char *array in the c file to work.
extern enum Text_Strings
{
	ENTERED_VALUE_WAS_NOT_A_NUMBER,
	UNKNOWN_STRING_REQUEST,
	TOTAL_STRINGS//MOST BE LAST!!
};