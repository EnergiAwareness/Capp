#include "TextStrings.h"


char* stringArray[TOTAL_STRINGS ] = {
	"Entered value was not a number",
	"Requested string could not be resolved",
	"Invaild selection",
	"Please enter a number to select following:",
	"Select option: \n1: List devises \n2: Get best prise \n3: Delete a devise \n4: Return",
	"Please enter the name of your device",
	"Please enter the KwH usage of your device",
	"Enter device to use",
	"Device could not be deleted",
	"Device was succesfully deleted",
	"Could not get best price",
	"Device was saved successfully",
	"Select option: \n1: Register new device \n2: Return",
	"Please enter two dates in the following format: 'DD:MM DD:MM' starting with the oldest date"
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