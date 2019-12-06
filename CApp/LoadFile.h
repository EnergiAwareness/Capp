#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ReturnErrors.h"

void FindWidthAndLengthOfFile(char _InputFileName[], int* Width, int* Length);
void LoadFileToStringArray(char* _LoadedFile[], char _InputFileName[], int _Width);

int LoadFile(char InputFileName[], char*** LoadedFileArray);
