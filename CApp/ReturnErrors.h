#pragma once

enum ReturnValues {
	OK,
	UNABLE_TO_CLEAR_STDIN,
	UNKNOWN_ERROR,
	INPUT_WAS_NOT_A_NUMBER,
	//inset erroes here
	TOTAL_RETURN_VALUES
};

extern char* GetErrorCodeString(int value);