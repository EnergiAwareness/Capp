#include <stdio.h>
#include <stdlib.h>
#include "stdinHelper.h"
#include "ReturnErrors.h"
#include "Register.h"
#include "TextStrings.h"

enum menu
{
	SELECTION,
	REGISTER,
	EXISTING,
	BACK,
};

int Devices(void) {

	int returnCode = UNKNOWN_ERROR, run = 1, state = 0, errorCode = OK;

	while (run)
	{
		errorCode = OK;
		switch (state)
		{
		case SELECTION:
		{
			printf("%s\n", GetTextString(SELET_A_NUMBER));
			printf("1. Register a new device\n2. Select a existing device\n3. Exit to main menu\n");
			if ((errorCode = GetIntegerFromStdin(&state)) != OK)
			{
				state = SELECTION;
				printf("%s\n", GetErrorCodeString(errorCode));
			}
			break;
		}
		case REGISTER:
		{
			if ((errorCode = RegisterDevice()) != OK)
			{
				printf("%s\n", GetErrorCodeString(errorCode));
			}
			state = SELECTION;
			break;
		}
		case EXISTING:
		{
			state = SELECTION;
			break;
		}
		case BACK:
		{
			run = 0;
			returnCode = OK;
			break;
		}
		default:
			state = SELECTION;
			printf("%s\n", GetTextString(INVALID_SELECTION));
			break;
		}
	}

	return returnCode;
}