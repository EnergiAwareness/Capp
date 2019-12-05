#include "TextStrings.h"


char* stringArray[TOTAL_STRINGS ] = {
	"Entered value was not a number",
	"Requested string could not be resolved",
	"Invaild selection",
	"Please enter a number to select following:",
	"Please enter the name of your device",
	"Please enter the KwH usage of your device"
};


char* GetTextString(int value)
{
	if (value >= 0 && value < TOTAL_STRINGS) {
		return stringArray[value];
	}
	else {
		return stringArray[UNKNOWN_STRING_REQUEST];
	}
}