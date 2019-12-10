#pragma once

extern int SaveToFile(char buffer[], int lenght, char fileName[]);
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "ReturnErrors.h"

extern int LoadFile(char InputFileName[], char*** LoadedFileArray, int* AmountOfStrings);