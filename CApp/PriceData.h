#pragma once

typedef struct _DateTimePrice {
	int day;
	int month;
	int year;
	int hourStart;
	int hourEnd;
	double price;
} _DateTimePrice;

extern int ParseFileToStruct(int startDay, int startMonth, int endDay, int endMonth, _DateTimePrice* dateTimePrice, size_t* sizeOfStruct);
