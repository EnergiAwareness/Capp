#include <time.h>
#include "GetHourPrices.h"

void today() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice *callPrices;
	ParseFileToStruct(tm.tm_mday, tm.tm_mon + 1, tm.tm_mday, tm.tm_mon + 1, callPrices, );
}

void tomorrow() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	_DateTimePrice* callPrices;
	ParseFileToStruct(tm.tm_mday + 1, tm.tm_mon + 1, tm.tm_mday + 1, tm.tm_mon + 1, callPrices);
}

void history() {

}