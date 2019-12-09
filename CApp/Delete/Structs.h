#pragma once



/* Used to parse array from file into */
typedef struct _DateTimePrice {
	int day;
	int month;
	int year;
	int hourStart;
	int hourEnd;
	double price;
} _DateTimePrice;
