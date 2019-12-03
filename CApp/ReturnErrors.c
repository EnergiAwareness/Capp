#include <stdlib.h>
#include "ReturnErrors.h"


char* errorStrings[TOTAL_RETURN_VALUES] = {
	"OK",
	"Unable to clear stdin buffer",
	"Unkowned error"
};

char* GetErrorCodeString(int value)
{
	if (value >= 0 && value < TOTAL_RETURN_VALUES)
	{
		return errorStrings[value];
	}
	else
	{
		return errorStrings[UNKNOWN_ERROR];
	}
}