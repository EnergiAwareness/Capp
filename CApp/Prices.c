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
	if ((errorCode = ParseFileToStruct(tm.tm_mday, tm.tm_mon + 1, tm.tm_mday, tm.tm_mon + 1, callPrices, &structSize)) == OK) {
		PrintOutPriceData(callPrices, structSize);
	}

	return errorCode;
}

int Tomorrow() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* callPrices = NULL;
	size_t structSize = 0;
	int i = 0;
	int errorCode = UNKNOWN_ERROR;

	if ((errorCode = ParseFileToStruct(tm.tm_mday + 1, tm.tm_mon + 1, tm.tm_mday + 1, tm.tm_mon + 1, callPrices, &structSize)) == OK) {
		PrintOutPriceData(callPrices, structSize);
	}

	return errorCode;
}

int Historical() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* callPrices = NULL;
	size_t structSize = 0;
	int errorCode = UNKNOWN_ERROR;

	printf("GetTextString\n", DATE_INPUT);
	scanf_s("%d:%d %d:%d", &tm.tm_mday, &tm.tm_mon + 1, &tm.tm_mday, &tm.tm_mon + 1);

	if ((errorCode = ParseFileToStruct(tm.tm_mday, tm.tm_mon + 1, tm.tm_mday, tm.tm_mon + 1, callPrices, &structSize)) == OK) {
		PrintOutPriceData(callPrices, structSize);
	}

	return errorCode;
}

void PrintOutPriceData(_DateTimePrice* prices, int cnt)
{
	int i;
	for (i = 0; i < cnt; i++) {
		printf("%d - %d %d-%d: %2.lf dkk", prices[i].day, prices[i].month, prices[i].hourStart, prices[i].hourEnd, prices[i].price);
	}
}