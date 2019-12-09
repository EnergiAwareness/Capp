#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ReturnErrors.h"

int FindWidthAndLengthOfFile(char _InputFileName[], int* Width, int* Length);
int LoadFileToStringArray(char* _LoadedFile[], char _InputFileName[], int _Width);

int LoadFile(char InputFileName[], char*** LoadedFileArray);
