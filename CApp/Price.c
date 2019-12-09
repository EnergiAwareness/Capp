#include <stdio.h>
#include <stdlib.h>
#include "stdinHelper.h"
#include "ReturnErrors.h"
#include "Register.h"
#include "TextStrings.h"
#include "Existing.h"
#include "PriceCalls.h"

enum menu
{
	SELECTION,
	TODAY,
	TOMORROW,
    HISTORICAL,
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
			printf(" %s\n", GetTextString(PRICES_MENU));
			if ((errorCode = GetIntegerFromStdin(&state)) != OK)
			{
				state = SELECTION;
				printf("%s\n", GetErrorCodeString(errorCode));
			}
			break;
		}
		case TODAY:
		{
			if ((errorCode = Today()) != OK)
			{
				printf("%s\n", GetErrorCodeString(errorCode));
			}
			state = SELECTION;
			break;
		}
		case TOMORROW:
		{
			if ((errorCode = Tomorrow()) != OK) {
				printf("%s\n", GetErrorCodeString(errorCode));
			}

			state = SELECTION;
			break;
		}
        case HISTORICAL:
        {
            if ((errorCode = Historical()) != OK) {
                printf("%s\n", GetErrorCodeString(errorCode));
            }
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