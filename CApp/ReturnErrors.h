#pragma once

extern enum ReturnValues {
	OK,
	UNABLE_TO_CLEAR_STDIN,
	UNKNOWN_ERROR,
	//inset erroes here
	TOTAL_RETURN_VALUES
};

extern char* GetErrorCodeString(int value);