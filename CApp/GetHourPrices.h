#pragma once
#include "Structs.h"
#include "LoadFile.h"
#include <string.h>
#include "ReturnErrors.h"

int ParseFileToStruct(int startDay, int startMonth, int endDay, int endMonth, _DateTimePrice* dateTimePrice, size_t* sizeOfStruct);
