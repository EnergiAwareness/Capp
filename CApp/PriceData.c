#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PriceData.h"
#include "ReturnErrors.h"
#include "FileHandler.h"


int GetHourPrice(int startDay, int startMonth, int endDay, int endMonth, _DateTimePrice* dateTimePrice, int* sizeOfStruct) {
	int count = 0, fileHeight = 0, i = 0, x = 0, errorCode = UNKNOWN_ERROR;
	char** loadedFileArray = NULL;
	char* temp;
	char delim[] = ";-";
	double data[6];
	
	if ((errorCode = LoadFile("elspot-prices_2018_hourly_dkk.csv", &loadedFileArray, &fileHeight)) == OK) {
		_DateTimePrice* builder = calloc(sizeof(_DateTimePrice), fileHeight);
		
		for (i = 0; i < fileHeight; i++) {
			temp = strtok(loadedFileArray[i], delim);
			for (x = 0; x < 6; x++) {
				if (temp != NULL) {
					data[x] = atof(temp);
				}
				else { break; }
				temp = strtok(NULL, delim);
			}

			if ((startDay >= data[0] && startMonth >= data[1]) || (endDay <= data[0] && endMonth <= data[1])) {
				builder[i].day = data[0];
				builder[i].month = data[1];
				builder[i].year = data[2];
				builder[i].hourStart = data[3];
				builder[i].hourEnd = data[4];
				builder[i].price = data[5];
				count++;
			}
		}
	}

	*sizeOfStruct = count;
	return errorCode;
}