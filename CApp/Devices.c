#include <stdio.h>
#include <time.h>
#include "stdinHelper.h"
#include "Devices.h"
#include "ReturnErrors.h"
#include "TextStrings.h"
#include "FileHandler.h"
#include "PriceData.h"


#define INT_MAX_CHAR 10
#define ARRAY_SIZE 10



enum state {
	SELECTION = 0,
	LISTE_ALL_DEVICES = 1,
	CREATE_DEVICE = 1,
	GET_BEST_PRICE = 2,
	DELETE_A_DEVICE = 3,
	REGISTER = 1,
	EXISTING = 2,
	BACK = 9,
};

devices* existingDevices = NULL;

int ChooseDevice(int* selectedDevice);

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

int Existing(void) {
	int state = SELECTION, keepAlive = 1, i = 0, selectedDevice = 0;
	existingDevices = calloc(ARRAY_SIZE, sizeof(devices));

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
		case BACK: {
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

int RegisterDevice(void) {
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
		case BACK: {
			keepAlive = 0;
			break;
		}
		default:
		{
			state = SELECTION;
			printf("%s\n", GetTextString(INVALID_SELECTION));
			break;
		}
		}
	}
	return 0;
}

int SaveCfg(devices deviceList[], int deviceCount) {
	/*char device = calloc(deviceCount, MAX_DEVICE_NAME + INT_MAX_CHAR);
	char ckwh[MAX_DEVICE_NAME];*/
	int returnCode = OK;

	//if (device != NULL) {
	//	for (int i = 0; i < deviceCount; i++) {
	//		strcpy(device, deviceList[i].deviceName);
	//		strcat(device, ", kwh: ");
	//		sprintf(ckwh, "%d", deviceList[i].kwh);
	//		strcat(device, ckwh);
	//		strcat(device, "; ");
	//	}
	//	returnCode = SaveToFile(&device, strlen(device), "devices.ini");
	//}
	//else {
	//	returnCode = UNKNOWN_ERROR;
	//}

	//free(device);
	return returnCode;
}

int GetBestTime(devices dev, char* startTime)
{
	int errorCode = UNKNOWN_ERROR;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* prices = NULL;
	size_t structSize = 0;

	if ((errorCode = GetHourPrice(tm.tm_mday, tm.tm_mon, tm.tm_mday, tm.tm_mon, prices, structSize)) == OK)
	{


	}

	return errorCode;
}