#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdinHelper.h"

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

			if (scanf("%d", &state) != 0) {
				state = SELECTION;
				printf(""); // Find en tekststreng
				ClearStdinBuffer(); // flusher stdin
			}
			break;
		}
		case CREATE_DEVICE: {
			printf("Enter the name of your device: ");
			scanf(" %s", newdevice.deviceName);
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