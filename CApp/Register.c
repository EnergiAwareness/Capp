#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdinHelper.h"
#include "ReturnErrors.h"
#include "TextStrings.h"
#include "Structs.h"
#include "SaveToFile.h"

#define INT_MAX_CHAR 10

enum States {
	SELECTION,
	CREATE_DEVICE,
	EXIT,
};

int RegisterDevice() {
	int state = 0, keepAlive = 1, errorCode = OK;
	devices newdevice;

	while (keepAlive) {

		switch (state) {
		case SELECTION: {
			printf("%s\n", GetTextString(SELECT_REGISTER));

			if (scanf("%d", &state) == 0) {
				state = SELECTION;
				ClearStdinBuffer();
				printf("%s\n", GetTextString(ENTERED_VALUE_WAS_NOT_A_NUMBER));				
			}
			break;
		}
		case CREATE_DEVICE: {
			printf("%s\n", GetTextString(ENTER_NAME_OF_DEVICE));

			if ((errorCode = GetStringFromStdin(newdevice.deviceName, MAX_DEVICE_NAME)) == OK) {
				printf("%s\n", GetTextString(ENTER_POWER_USAGE_OF_DEVICE));

				if ((errorCode = GetIntegerFromStdin(&newdevice.kwh)) != OK) {
					printf("%s\n", GetErrorCodeString(errorCode));
					state = SELECTION;
				}
				else {
					/*SaveCfg(newdevice, 1);*/								
					printf("%s\n", GetTextString(DEVICE_SAVED_SUCCESSFULLY));

					state = SELECTION;
				}
			}
			else {
				printf("%s\n", GetErrorCodeString(errorCode));
			}			
			break;
		}
		case EXIT: {
			keepAlive = 0;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}


int SaveCfg(devices deviceList[], int deviceCount) {
	char device = calloc(deviceCount, MAX_DEVICE_NAME + INT_MAX_CHAR);
	char ckwh[MAX_DEVICE_NAME];
	int returnCode = OK;

	if (device != NULL) {
		for (int i = 0; i < deviceCount; i++) {
			strcpy(device, deviceList[i].deviceName);
			strcat(device, ", kwh: ");
			sprintf(ckwh, "%d", deviceList[i].kwh);
			strcat(device, ckwh);
			strcat(device, "; ");
		}
		returnCode = SaveToFile(device, strlen(device));
	}
	else {
		returnCode = UNKNOWN_ERROR;
	}
	free(device);

	return returnCode;
}