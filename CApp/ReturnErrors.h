#pragma once

extern enum ReturnValues {
	OK,
	UNABLE_TO_CLEAR_STDIN,
	UNKNOWN_ERROR,
	UNABLE_TO_SAVE_FILE,
	//inset erroes above this.
	TOTAL_RETURN_VALUES
};

extern char* GetErrorCodeString(int value);