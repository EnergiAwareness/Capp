#pragma once


/*
 *  Function:  ClearStdinBuffer
 * --------------------
 *  Summary: Clears the Standard input buffer
 * --------------------
 *  Returns: Error code
 */
extern int ClearStdinBuffer();

extern int GetIntegerFromStdin(int* Variable);

extern int GetStringFromStdin(char* string, int maxLength);