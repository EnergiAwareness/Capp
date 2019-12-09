#include "LoadFile.h"

int LoadFile(char InputFileName[], char*** LoadedFileArray) {
    int Width = 0, Height = 0, Index = 0;

    FindWidthAndLengthOfFile(InputFileName, &Width, &Height);

    /*printf(" Length: %d, Height: %d", Width, Height);

    char** LoadedFile;

    LoadedFile = malloc(Height, sizeof(char**));*/
    //if (LoadedFile != NULL)
    //    for (int i = 0; i < Height; i++)
    //        LoadedFile[i] = malloc(Width, sizeof(char*));

    //printf(" %d\n", sizeof(LoadedFile));

    char** LoadedFile;
    LoadedFile = calloc(Height, sizeof(char**));
    if (LoadedFile != NULL)
        for (int i = 0; i < Height; i++)
            LoadedFile[i] = calloc(Width, sizeof(char*));

    if (LoadedFile != NULL)
    {

        LoadFileToStringArray(LoadedFile, InputFileName, Width);
    }

    *LoadedFileArray = LoadedFile;

    return Height;
}

int FindWidthAndLengthOfFile(char _InputFileName[], int* Width, int* Length) {
    FILE* fp;
    char Buffer[128];
    int CurrentStringLength = 0, CurrentFileLength = 0;

    fopen_s(&fp, _InputFileName, "r");

    if (fp == NULL)
        return CANNOT_OPEN_FILE;

    while (!feof(fp)) {
        fgets(Buffer, 128, fp);
        CurrentStringLength = strlen(Buffer);

        if (CurrentStringLength > * Width)
            * Width = CurrentStringLength;

        CurrentFileLength++;

    }
    *Length = CurrentFileLength + 1;

    fclose(fp);
}

int LoadFileToStringArray(char* _LoadedFile[], char _InputFileName[], int _Width) {
    FILE* fp;
    int Index = 0;

    fopen_s(&fp, _InputFileName, "r");

    if (fp == NULL)
        return CANNOT_OPEN_FILE;

    while (!feof(fp)) {
        fgets(_LoadedFile[Index], _Width, fp);

        printf(" %s", _LoadedFile[Index]);

        Index++;
    }
}