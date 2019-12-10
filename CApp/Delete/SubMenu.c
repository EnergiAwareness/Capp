#include <stdio.h>
#include <stdlib.h>
#include "stdinHelper.h"
#include "ReturnErrors.h"
#include "TextStrings.h"
#include "PriceCalls.h"


enum menu
{
	SELECTION = 0,
	REGISTER = 1,
	EXISTING = 2,
	TODAY = 1,
	TOMORROW = 2,
	HISTORICAL = 3,
	BACK = 9,
};

int Price(void) {

	int returnCode = UNKNOWN_ERROR, run = 1, state = 0, errorCode = OK;

	while (run)
	{
		errorCode = OK;
		switch (state)
		{
		case SELECTION:
		{
			printf("%s\n%s\n", GetTextString(SELET_A_NUMBER), GetTextString(PRICES_MENU));
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

int Devices(void) {

	int returnCode = UNKNOWN_ERROR, run = 1, state = 0, errorCode = OK;

	while (run)
	{
		errorCode = OK;
		switch (state)
		{
		case SELECTION:
		{
			printf("%s\n%s\n", GetTextString(SELET_A_NUMBER), GetTextString(DEVICE_MENU));
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
			if (Existing() != OK) {
				printf("%s\n", GetErrorCodeString(EXISTING_FAILED));
			}

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