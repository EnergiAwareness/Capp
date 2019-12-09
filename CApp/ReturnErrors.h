#pragma once

enum ReturnValues {
	OK,
	UNABLE_TO_CLEAR_STDIN,
	UNKNOWN_ERROR,
	INPUT_WAS_NOT_A_NUMBER,
	CANNOT_SAVE_TO_FILE,
	EXISTING_FAILED,
    CANNOT_OPEN_FILE,
	//inset erroes here
	TOTAL_RETURN_VALUES //MUST BE LAST
};

extern char* GetErrorCodeString(int value);