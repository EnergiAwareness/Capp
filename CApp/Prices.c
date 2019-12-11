#include <stdlib.h>
#include <time.h>
#include "Prices.h"
#include "ReturnErrors.h"
#include "TextStrings.h"
#include "ReturnErrors.h"
#include "FileHandler.h"
#include "PriceData.h"

void PrintOutPriceData(_DateTimePrice* prices, int cnt);

int Today() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* callPrices = NULL;
	size_t structSize = 0;
	int errorCode = UNKNOWN_ERROR;
	if ((errorCode = GetHourPrice(tm.tm_mday, tm.tm_mon + 1, tm.tm_mday, tm.tm_mon + 1, &callPrices, &structSize)) == OK) {
		PrintOutPriceData(callPrices, structSize);
	}

	free(callPrices);
	return errorCode;
}

int Tomorrow() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* callPrices = NULL;
	size_t structSize = 0;
	int errorCode = UNKNOWN_ERROR;

	if ((errorCode = GetHourPrice(tm.tm_mday + 1, tm.tm_mon + 1, tm.tm_mday + 1, tm.tm_mon + 1, &callPrices, &structSize)) == OK) {
		PrintOutPriceData(callPrices, structSize);
	}

	free(callPrices);
	return errorCode;
}

int Historical() {
	int startDay = 0, startMonth = 0, endDay = 0, endMonth = 0;
	_DateTimePrice* callPrices = NULL;
	size_t structSize = 0;
	int errorCode = UNKNOWN_ERROR;

	printf("%s\n", GetTextString(DATE_INPUT));
	scanf_s("%d:%d %d:%d", &startDay, &startMonth, &endDay, &endMonth);

	if ((errorCode = GetHourPrice(startDay, startMonth, endDay, endMonth, &callPrices, &structSize)) == OK) {
		PrintOutPriceData(callPrices, structSize);
	}

	free(callPrices);
	return errorCode;
}

void PrintOutPriceData(_DateTimePrice* prices, int cnt)
{
	int i;
	for (i = 0; i < cnt; i++) {
		printf("|Date: %2d-%2d-%4d | Hour: %2d-%2d | Price:%7.3lf DKK / KwH|\n", prices[i].day, prices[i].month, prices[i].year, prices[i].hourStart, prices[i].hourEnd, prices[i].price/1000);
	}
}