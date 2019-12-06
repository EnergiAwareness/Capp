#pragma once

#define MAX_DEVICE_NAME 50

typedef struct devices {
	char deviceName[MAX_DEVICE_NAME];
	int kwh;
} devices;

