#pragma once

#define MAX_DEVICE_NAME 50

typedef struct _Devices {
	char deviceName[MAX_DEVICE_NAME];
	int kwh;
} devices;

/* Used to parse array from file into */
typedef struct _DateTimePrice {
	int day;
	int month;
	int year;
	int hourStart;
	int hourEnd;
	double price;
} _DateTimePrice;
