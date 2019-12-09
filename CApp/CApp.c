/*
gruppe:
*/

#include <stdio.h>
#include <stdlib.h>
#include "Devices.h"
#include "stdinHelper.h"
#include "TextStrings.h"
#include "ReturnErrors.h"
#include "LoadFile.h"

enum states
{
	MAIN_MENU,//Must be first!
	PRICE,
	DEVICES,
	ABOUT,
	EXIT,
	TOTAL, //Must be last!
};

int main(void) {
	int state = MAIN_MENU, i = 0, run = 1, returnValue = EXIT_FAILURE, errorCode = 0;
	char* menuName[TOTAL - 1] = {
	"Price",
	"Devices",
	"About",
	"Exit program",
	};

	
	printf("*****************************************************\n");
	printf("************Welcome to Energy advisor 1.0************\n");
	printf("*****************************************************\n");
	printf("*****************************************************\n\n");
	

	while (run)
	{
		errorCode = OK;
		switch (state) {
		case MAIN_MENU:
		{
			printf("%s\n", GetTextString(SELET_A_NUMBER));
			for (i = 1; i < TOTAL; i++)
			{
				printf("%d. %s\n", i, menuName[i - 1]);
			}

			if ((errorCode = GetIntegerFromStdin(&state)) != OK)
			{
				state = MAIN_MENU;
				printf("%s\n", GetErrorCodeString(errorCode));
			}
			break;
		}
		case PRICE:
		{
			state = MAIN_MENU;
			break;
		}
		case DEVICES:
		{
			if ((errorCode = Devices()) != OK)
			{
				printf("%s\n", GetErrorCodeString(errorCode));
			}
			state = MAIN_MENU;
			break;
		}
		case ABOUT:
		{
			printf("This program was developed by group A400B for first semester group project P1 2019.\n"
				"The project is about Energy price awareness\n"
				"Created by:\n"
				"Martin Lindblom Hansen\n"
				"Rune Bohnstedt\n"
				"Kim Helstrup Pedersen\n"
				"Micklas Skov\n"
				"Claes Mortensen\n"
				"Lars Christensen\n"
				"Frederik L. Jakobsen\n\n");
			state = MAIN_MENU;
			break;
		}
		case EXIT:
		{
			run = 0;
			returnValue = EXIT_SUCCESS;
			break;
		}
		default:
		{
			printf("%s\n", GetTextString(INVALID_SELECTION));
			state = MAIN_MENU;
			break;
		}
		}
	}
	return returnValue;
}