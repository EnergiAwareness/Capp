#include "Devices.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdinHelper.h"
#include "TextStrings.h"

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
	int state = MAIN_MENU, i = 0, run = 1, returnValue = EXIT_FAILURE;
	char *menuName[TOTAL - 1] = {
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
		switch (state) {
		case MAIN_MENU:
		{
			printf("Please enter a number to select following:\n");
			for (i = 1; i < TOTAL; i++)
			{
				printf("%d. %s\n", i, menuName[i - 1]);
			}
			if (scanf("%i", &state) == 0)
			{
				state = MAIN_MENU;
				ClearStdinBuffer();
				printf("%s\n", GetTextString(ENTERED_VALUE_WAS_NOT_A_NUMBER));
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
			printf("Invaild selection\n");
			state = MAIN_MENU;
			break;
		}
		}
	}
	return returnValue;
}