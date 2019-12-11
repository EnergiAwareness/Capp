#include <stdio.h>
#include <time.h>
#include <string.h>
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

typedef struct _BestTime
{
	char timeStamp[11];
	double price;
}BestTime;

devices* existingDevices = NULL;

int ChooseDevice(int* selectedDevice);
/*
* Function: Devices
* -------------------
* Menu that handles the device menu selection 
*
* parameters: none
*
* returns: error code reflecting the execution status
*/
int Devices(void) {
	int returnCode = UNKNOWN_ERROR, run = 1, state = 0, errorCode = OK;
	existingDevices = calloc(ARRAY_SIZE, sizeof(devices));

	/*LoadCfg();*/

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

/*
* Function: Existing
* --------------------------
* Menu that handles existing devices
*
* parameters: none
*
* returns: error code reflecting the execution status
*/
int Existing(void) {
	int state = SELECTION, keepAlive = 1, i = 0, selectedDevice = 0;

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
			BestTime bt;
			if (ChooseDevice(&selectedDevice) != OK) {
				printf("%s\n", GetTextString(NO_DEVICE_TO_GET_PRICE_ON));
			}
			else {
				printf("%s\n", GetTextString(GET_RUN_TIME_IN_MINUTES));
				GetBestTime(&bt, 10);
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

/*
* Function: ChooseDevice
* --------------------------
* Takes user input and and checks if device exists
*
* parameters: selectedDevice
*
* returns: error code reflecting user input
*/
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

/*
* Function: RegisterDevice
* --------------------------
* Menu that handles device registration
* 
* parameters: none 
*
* returns: error code reflecting the execution status
*/
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
					/*SaveCfg(existingDevices, missing);*/
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
	char device = calloc(deviceCount, MAX_DEVICE_NAME + INT_MAX_CHAR);
	char ckwh[MAX_DEVICE_NAME];
	int returnCode = OK;

	if (device != NULL) {
		for (int i = 0; i < deviceCount; i++) {
			strcpy(device, deviceList[i].deviceName);
			strcat(device, ";");
			sprintf(ckwh, "%d", deviceList[i].kwh);
			strcat(device, ckwh);
			strcat(device, "\n");
		}
		returnCode = SaveToFile(&device, strlen(device), "devices.ini");
	}
	else {
		returnCode = UNKNOWN_ERROR;
	}

	free(device);
	return returnCode;
}

int LoadCfg(devices deviceList[]) {
	int returnCode = UNKNOWN_ERROR, fileHeight = 0, i = 0;
	char** loadedFileArray = NULL;
	char delim[] = ";";
	char* temp;

	if ((returnCode = LoadFile("elspot-prices_2018_hourly_dkk.csv", &loadedFileArray, &fileHeight)) == OK) {
		for (i = 0; i < fileHeight; i++) {
			temp = strtok(loadedFileArray[i], delim);
			if (temp != NULL) {
				strcpy(deviceList[i].deviceName, temp);
				temp = strtok(NULL, delim);
				if (temp != NULL) {
					deviceList[i].kwh = atoi(temp);
				}
				else {
					returnCode = UNABLE_TO_DECODE_DEVICE_CONFIG;
				}
			}
			else {
				returnCode = UNABLE_TO_DECODE_DEVICE_CONFIG;
			}
		}
	}
	return returnCode;
}

int GetBestTime(BestTime* bestTimeToStart, int runTimeInMinutes)
{
	int errorCode = UNKNOWN_ERROR, i = 0, startHourPosition = 0, startMin = 0, minLeft = 0, minTemp = 0, hourTemp = 0;
	int foundStartHour = 0, foundStartMin = 0, pos = 0, nextDay = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* hourPrices = NULL;
	size_t structSize = 0;
	double price = 0, newPrice = 0;

	if ((errorCode = GetHourPrice(tm.tm_mday, tm.tm_mon, tm.tm_mday+1, tm.tm_mon, &hourPrices, &structSize)) == OK)
	{
		minLeft = runTimeInMinutes;
		for (i = 0; i < structSize; i++)
		{
			hourPrices[i].price = hourPrices[i].price / 1000 / 60; //convert mwh to kwh then hour to minut
		}

		startHourPosition = tm.tm_hour + (int)(((double)tm.tm_min + 5) / 60); //find start position of time data.
		startMin = (tm.tm_min + 5) % 60;//find start min within the hour

		price = hourPrices[startHourPosition].price * (60 - startMin); //calculate price for the firste hour and minutes
		minLeft = runTimeInMinutes - (60 - startMin); // find amount of minutes left
		hourTemp = minLeft / 60; // find hours left
		minLeft = minLeft % 60; // find minutes left after hours has been subtracted
		
		for (i = 1; i <= hourTemp; i++)
		{
			price += hourPrices[startHourPosition + i].price * 60; // add x hours price to the total price
		}
		
		price += hourPrices[startHourPosition + hourTemp + 1].price * minLeft; //add price for the last minutes
		//price for starting window has now been calculated
		minLeft = ((48 - startHourPosition + hourTemp) * 60) + (60 - startMin);

		hourTemp += startHourPosition + (60 - startMin) / 60; //hour offset
		minTemp = ((runTimeInMinutes % 60) + startMin) % 60; //minute offset
		newPrice = price;
		
		int time1 = 0;
		int time2 = 0;
		int time3 = 0;
		int time4 = 0;

		int const1 = startHourPosition;// hourTemp - runTimeInMinutes / 60;

		for (i = 0; i < minLeft; i++)
		{
			time1 = hourTemp + ((minTemp + i) / 60);
			time2 = (minTemp + i) % 60;
			time3 = const1 + (startMin + i) / 60;
			time4 = (startMin + i) % 60;
			printf("%d, %d - %d, %d\n", time1, time2, time3, time4);

			newPrice += hourPrices[hourTemp + (minTemp + i) / 60].price;
			newPrice -= hourPrices[const1 + (startMin + i) / 60].price;
			if (newPrice < price)
			{
				price = newPrice;
				pos = const1 + (startMin + i) / 60;
				if (pos > 23)
					nextDay = 1;
				foundStartHour = hourPrices[pos].hourStart;
				foundStartMin = (startMin + i) % 60;
				printf("%f, %d, %d, %d, %d\n", price, pos, nextDay, foundStartHour, foundStartMin);
			}
		}
	}

	return errorCode;
}