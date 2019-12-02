#include "Devices.h"
#include <stdio.h>
#include <stdlib.h>

enum MenuOptions
{
	PRICE = 0,
	DEVICES,
	EXIT,
	TOTAL, //Must always be the last!
};

void main(void) {
	int selectionIdx = -1;
	/*char menuName[TOTAL];
	menuName[EXIT] = "Exit program";
	menuName[PRICE] = "Price";
	menuName[DEVICES] = "Devices";*/



	printf("Welcome to Energy advisor 1.0");

	switch (selectionIdx) {
	case PRICE:
	{
		break;
	}
	case DEVICES:
	{
		break;
	}
	default:
	{
		break;
	}
	}

	return EXIT_FAILURE;
}