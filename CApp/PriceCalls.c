#include "PriceCalls.h"

int today() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice *callPrices;
	size_t structSize = 0;
	int i = 0;
	int errorCode;

	if ((errorCode = ParseFileToStruct(tm.tm_mday, tm.tm_mon + 1, tm.tm_mday, tm.tm_mon + 1, &callPrices, &structSize)) != OK)
		return (errorCode);

	for (i = 0; i < structSize; i++) {
		printf("%d - %d %d-%d: %.2lf dkk", callPrices->day, callPrices->month, callPrices->hourStart, callPrices->hourEnd, callPrices->price);
	}
}

int tomorrow() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* callPrices;
	size_t structSize = 0;
	int i = 0;
	int errorCode;

	if ((errorCode = ParseFileToStruct(tm.tm_mday + 1, tm.tm_mon + 1, tm.tm_mday + 1, tm.tm_mon + 1, callPrices, &structSize)) != OK)
		return (errorCode);

	for (i = 0; i < structSize; i++) {
		printf("%d - %d %d-%d: %.2lf dkk", callPrices->day, callPrices->month, callPrices->hourStart, callPrices->hourEnd, callPrices->price);
	}
}

int history() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* callPrices;
	size_t structSize = 0;
	int i = 0;
	int errorCode;

	GetTextString(13);
	scanf_s("%d:%d %d:%d", &tm.tm_mday, &tm.tm_mon + 1, &tm.tm_mday, &tm.tm_mon + 1);
	
	if ((errorCode = ParseFileToStruct(tm.tm_mday, tm.tm_mon + 1, tm.tm_mday, tm.tm_mon + 1, callPrices, &structSize)) != OK)
		return (errorCode);

	for (i = 0; i < structSize; i++) {
		printf("%d - %d %d-%d: %2.lf dkk", callPrices->day, callPrices->month, callPrices->hourStart, callPrices->hourEnd, callPrices->price);
	}
}