#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ReturnErrors.h"

int LoadFile(char _InputFileName[], char* _LoadedFile) {
    FILE* fp;
    char c, Buffer[128];
    int i = 0, CharCounter = 0;

    fp = fopen(_InputFileName, "r");

    if (fp == NULL) {
        return CANNOT_OPEN_FILE;
    }

    for (c = getc(fp); c != EOF; c = getc(fp)) {
        CharCounter++;
    }
    
    rewind(fp); // resets cursor pointer to start of file

    _LoadedFile = (char*)calloc(CharCounter, sizeof(char));

    i = 0;

    fread(_LoadedFile, sizeof(char), CharCounter, fp);

    fclose(fp);

    return OK;
}