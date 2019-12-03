#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICE_NAME 50

struct devices {
	char device[MAX_DEVICE_NAME];
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

	devices device[MAX_DEVICE_NAME];

	while (keepAlive) {
		
		switch (state)
		{
		case SELECTION: {
			printf("1: Create new device \n 9: To exit");

			if (scanf("%d", &state) != 0) {
				state = SELECTION;
				printf("IKKE TAL"); // lav en flush ting
			}
			break;
		}
		case CREATE_DEVICE: {
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
			
	return 0;
}