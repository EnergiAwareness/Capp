#include "TextStrings.h"


char* stringArray[TOTAL_STRINGS ] = {
	"Entered value was not a number",
	"Requested string could not be resolved",
	"Invaild selection",
	"Please enter a number to select following:",
	"Select option: \n0: List devises \n1: Get best prise \n2: Delete a devise \n3: Exit to devise menu",
	"Please enter the name of your device",
	"Please enter the KwH usage of your device",
	"Device was saved successfully",
	"Select option: \n1: Register new device \n2: Return"
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