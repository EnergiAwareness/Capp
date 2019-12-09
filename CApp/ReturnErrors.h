#pragma once

enum ReturnValues {
	OK,
	UNABLE_TO_CLEAR_STDIN,
	UNKNOWN_ERROR,
	INPUT_WAS_NOT_A_NUMBER,
	CANNOT_SAVE_TO_FILE,
	EXISTING_FAILED,
	//inset erroes here
	TOTAL_RETURN_VALUES
};

extern char* GetErrorCodeString(int value);