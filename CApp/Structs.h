#pragma once

#define MAX_DEVICE_NAME 50

struct devices {
	char deviceName[MAX_DEVICE_NAME];
	int kwh;
};
typedef struct devices devices;