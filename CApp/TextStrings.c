#include "TextStrings.h"



char* menuName[TOTAL_STRINGS ] = {
	"Entered value was not a number",
	"Requested string could not be resolved",
};


char* GetTextString(int value)
{
	if (value >= 0 && value <= TOTAL_STRINGS)
	{
		return menuName[value];
	}
	else
	{
		return menuName[UNKNOWN_STRING_REQUEST];
	}
}