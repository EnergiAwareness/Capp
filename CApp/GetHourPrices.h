#pragma once
#include "Structs.h"
#include "LoadFile.h"
#include <string.h>

size_t ParseFileToStruct(int startDay, int startMonth, int endDay, int endMonth, _DateTimePrice* dateTimePrice);
