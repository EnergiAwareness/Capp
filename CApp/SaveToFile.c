#include <stdio.h>
#include <stdlib.h>

int SaveToFile(char buffer[], int lenght) {
	int i = 0;
	
	FILE* outputFile;
	
	outputFile = fopen("saveFile", "w");
	if (outputFile == NULL) { /*skal den lave en fil?*/
		printf("%s", /*inster Error code here*/);
		return /*error code*/;
	}
	else {
		for (i = 0; i < lenght; i++) {
			fputc(buffer[i], outputFile);
		}
		fclose(outputFile);
	}

	return 0;
}