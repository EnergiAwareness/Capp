#include <stdlib.h>
#include "ReturnErrors.h"
#include "TextStrings.h"
#include "stdinHelper.h"

enum state {
	SELECTION,
	LISTE_ALL_DEVICES,
	GET_BEST_PRICE,
	DELETE_A_DEVICE,
	EXIT_TO_DEVICES
};

int Existing(void) {
	int state = SELECTION, run = 1, i = 0, choises = 0;

	while (run) {

		switch (state) {
		case SELECTION: {
			printf("%s\n", GetTextString(EXISTING_MENU));
			GetIntegerFromStdin(&state);
			break;
		}
		case LISTE_ALL_DEVICES: {
			/*print af devices*/
			break;
		}
		case GET_BEST_PRICE: {
			/*GetBestPrice(devices[choises]);*/
			break;
		}
		case DELETE_A_DEVICE: {
			/*set en structs inhold til 0*/
			break;
		}
		case EXIT_TO_DEVICES: {
			run = 0;
			break;
		}
		default: {
			printf("%s\n", GetTextString(INVALID_SELECTION));
			state = SELECTION;
			break;
		}
		}
	}
	return OK;
}