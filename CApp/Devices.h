#pragma once

#define MAX_DEVICE_NAME 50

typedef struct Devices {
	char deviceName[MAX_DEVICE_NAME];
	int kwh;
} devices;

extern int Existing(void);

extern int RegisterDevice(void);

extern int Devices(void);