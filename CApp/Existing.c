#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReturnErrors.h"
#include "TextStrings.h"
#include "stdinHelper.h"
#include "Structs.h"

#define ARRAY_SIZE 10

enum state {
	SELECTION,
	LISTE_ALL_DEVICES,
	GET_BEST_PRICE,
	DELETE_A_DEVICE,
	EXIT_TO_DEVICES
};

int Existing(void) {
	int state = SELECTION, keepAlive = 1, i = 0, selectedDevice = 0;
	devices *existingDevices = calloc(ARRAY_SIZE, sizeof(devices));

	/*LoadCfg();*/

	while (keepAlive) {

		switch (state) {
		case SELECTION: {
			printf("%s\n", GetTextString(EXISTING_MENU));
			GetIntegerFromStdin(&state);
			break;
		}
		case LISTE_ALL_DEVICES: {

			for (i = 0; i < 3; i++) {
				printf("Device: %d\nName: %s\nkWh: %d\n\n", i + 1, existingDevices[i].deviceName, existingDevices[i].kwh);
			}
			
			state = SELECTION;
			break;
		}
		case GET_BEST_PRICE: {
			if (ChooseDevice(&selectedDevice) != OK) {
				printf("%s\n", GetTextString(NO_DEVICE_TO_GET_PRICE_ON));
			}
			else {
				/*GetBestPrice(existingDevices[selectedDevice]);*/  //funktion skal laves
			}

			state = SELECTION;
			break;
		}
		case DELETE_A_DEVICE: {
			if (ChooseDevice(&selectedDevice) != OK) {
				printf("%s\n", GetTextString(COULD_NOT_DELETE_DEVICE));
			}
			else {
				strcpy(existingDevices[selectedDevice - 1].deviceName, "\0");
				existingDevices[selectedDevice - 1].kwh = 0;

				printf("%s\n", GetTextString(SUCCESFULLY_DELETED));
			}
			state = SELECTION;
			break;
		}
		case EXIT_TO_DEVICES: {
			keepAlive = 0;
			break;
		}
		default: {
			printf("%s\n", GetTextString(INVALID_SELECTION));
			state = SELECTION;
			break;
		}
		}
	}
	return OK;
}

int ChooseDevice(int* selectedDevice) {

	printf("%s\n", GetTextString(ENTER_WANTED_DEVICE));

	if (GetIntegerFromStdin(selectedDevice) != OK) {

		printf("%s\n", GetErrorCodeString(INPUT_WAS_NOT_A_NUMBER));
		return INPUT_WAS_NOT_A_NUMBER;
	}
	else {
		
		return OK;
	}
}