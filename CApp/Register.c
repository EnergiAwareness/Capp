#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdinHelper.h"
#include "ReturnErrors.h"
#include "TextStrings.h"
#include "Structs.h"

enum States {
	SELECTION,
	CREATE_DEVICE,
	EXIT,
};

int RegisterDevice() {
	int state = 0, keepAlive = 1, errorCode = OK;
	devices newdevice;

	while (keepAlive) {

		switch (state)
		{
		case SELECTION: {
			printf("%s\n", GetTextString(SELET_A_NUMBER));
			printf("1: Create new device \n2: Return\n");

			if (scanf("%d", &state) == 0) {
				state = SELECTION;
				ClearStdinBuffer();
				printf("%s\n", GetTextString(ENTERED_VALUE_WAS_NOT_A_NUMBER));				
			}
			break;
		}
		case CREATE_DEVICE: {
			printf("%s\n", GetTextString(ENTER_NAME_OF_DEVICE));

			if ((errorCode = GetStringFromStdin(newdevice.deviceName, MAX_DEVICE_NAME)) == OK)
			{
				printf("%s\n", GetTextString(ENTER_POWER_USAGE_OF_DEVICE));
				if ((errorCode = GetIntegerFromStdin(newdevice.kwh)) != OK)
				{
					printf("%s\n", GetErrorCodeString(errorCode));
				}
				else
				{
					
					//SaveCfg(newdevice);

					printf("%s\n", GetTextString(DEVICE_SAVED_SUCCESSFULLY));
					state = SELECTION;
				}
			}
			else
			{
				printf("%s\n", GetErrorCodeString(errorCode));
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