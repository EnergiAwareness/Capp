#include <stdlib.h>
#include "PriceData.h"
#include "ReturnErrors.h"

int ParseFileToStruct(int startDay, int startMonth, int endDay, int endMonth, _DateTimePrice* dateTimePrice, size_t* sizeOfStruct) {
	int fileHeight, i;
	char** loadedFileArray;
	char temp[256];
	size_t count = 0;
	int errorCode;

	if ((errorCode = LoadFile("test.csv", &loadedFileArray, &fileHeight)) != OK)
	{
		return errorCode;
	}


	_DateTimePrice builder;

	for (i = 0; i < fileHeight; i++) {

		strncpy(temp, loadedFileArray[i], 2);
		builder.day = atoi(temp);

		strncpy(temp, loadedFileArray[i] + 3, 2);
		builder.month = atoi(temp);

		strncpy(temp, loadedFileArray[i] + 6, 4);
		builder.year = atoi(temp);

		strncpy(temp, loadedFileArray[i] + 11, 2);
		builder.hourStart = atoi(temp);

		strncpy(temp, loadedFileArray[i] + 14, 2);
		builder.hourEnd = atoi(temp);

		strncpy(temp, loadedFileArray[i] + 16, strlen(loadedFileArray[i] + 16));
		builder.price = atof(temp);

		if (startDay <= builder.day && startMonth <= builder.month
			&& endMonth >= builder.month && endDay >= builder.day) {
			dateTimePrice[i] = builder;
			count++;
		}
	}
	*sizeOfStruct = count;
	/* Enter a return value */
}