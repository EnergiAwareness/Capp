#include <stdio.h>
#include <stdlib.h>
#include "ReturnErrors.h"

int SaveToFile(char buffer[], int lenght) {
	int i = 0;
	
	FILE* outputFile;
	
	outputFile = fopen("Config.cfg", "w");
	if (outputFile == NULL) {
		return CANNOT_SAVE_TO_FILE;
	}
	else {
		for (i = 0; i < lenght; i++) {
			fputc(buffer[i], outputFile);
		}
		fclose(outputFile);
	}

	return OK;
}