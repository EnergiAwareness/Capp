#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PriceData.h"
#include "ReturnErrors.h"
#include "FileHandler.h"


int GetHourPrice(int startDay, int startMonth, int endDay, int endMonth, _DateTimePrice* dateTimePrice, int* sizeOfStruct) {
	int fileHeight = 0, i = 0, errorCode = UNKNOWN_ERROR;
	char** loadedFileArray = NULL;
	char* temp;
	int count = 0;
	char delim[] = ";-";
	int day, month;
	
	if ((errorCode = LoadFile("elspot-prices_2018_hourly_dkk.csv", &loadedFileArray, &fileHeight)) == OK) {
		_DateTimePrice* builder = calloc(sizeof(_DateTimePrice), fileHeight);
		
		for (i = 0; i < fileHeight; i++) {
			temp = strtok(loadedFileArray[i], delim);
			day = getc(temp[0]);
			month = getc(temp[1]);
			if ((startDay >= day && startMonth >= month) || (endDay <= day && endMonth <= month)) {
				builder[i].day = atoi(temp[0]);
				builder[i].month = atoi(temp[1]);
				builder[i].year = atoi(temp[2]);
				builder[i].hourStart = atoi(temp[3]);
				builder[i].hourEnd = atoi(temp[4]);
				builder[i].price = atof(temp[5]);
				count++;
			}
			temp = strtok(NULL, delim);
		}
	}

	*sizeOfStruct = count;
	return errorCode;
}