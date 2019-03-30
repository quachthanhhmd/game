
#include "KeyBoard.h"

char Lay_phim() {

	char key = 127;


	key = _getch();

	if (key == 0 || key == -32) {

		key = _getch();

		if (key == 72) {
			key = 'u';
		}
		else if (key == 75) {
			key = 'l';
		}
		else if (key == 77) {
			key = 'r';
		}
		else if (key == 80) {
			key = 'd';
		}

	}
	else
		if (key == 27) {
			key = 'c';
		}
		else
			if (key == 13)
				key = 'e';
			else
				if (key == 32)
					 key = 's';
				else
					key = 'k';
	return key;
}


int Bang_control() {

	char key = 127;

	key = _getch();

	if (key == 51)  return 3;
	if (key == 50) return 2;
	if (key == 49) return 1;
	return 0;
}
