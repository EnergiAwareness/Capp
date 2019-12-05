#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdinHelper.h"
#include "ReturnErrors.h"
#include "TextStrings.h"

#define MAX_DEVICE_NAME 50

struct devices {
	char deviceName[MAX_DEVICE_NAME];
		int kwh;
};
typedef struct devices devices;

enum States {
	SELECTION,
	CREATE_DEVICE,
	EXIT = 9,
};

int RegisterDevice() {
	int state = 0, keepAlive = 1;
	devices newdevice;

	while (keepAlive) {

		switch (state)
		{
		case SELECTION: {
			printf("1: Create new device \n 9: To exit");

			if (scanf("%d", &state) == 0) {
				state = SELECTION;
				ClearStdinBuffer();
				printf("%s\n", GetTextString(ENTERED_VALUE_WAS_NOT_A_NUMBER));				
			}
			break;
		}
		case CREATE_DEVICE: {
			printf("Enter the name of your device: ");
			printf("Enter kwh");

			if (scanf(" %s", newdevice.deviceName) != 0
				|| (scanf(" %d", newdevice.kwh) !=0)) {

				SaveCfg(newdevice);				
			}
			else {
				ClearStdinBuffer();
				printf("%s\n", GetTextString(ENTERED_VALUE_WAS_NOT_A_NUMBER));				
				state = SELECTION;
			}
			break;
		}
		case EXIT: {
			keepAlive = 0;
			break;
		}
		default:
			printf("FORKERT");
			break;
		}
	}
	return 0;
}


int SaveCfg(devices device)
{
	int returnCode = UNKNOWN_ERROR;






	return returnCode;
}