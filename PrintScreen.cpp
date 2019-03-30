
#include "console.h"

#include "Move.h"
#include "Setting.h"
#include "PrintScreen.h"

using namespace std;



bool Start_game() {
	char Batdau;
	Batdau = _getch();
	system("CLS");
	if (Batdau == 13) {
		return 1;
	}
	return 0;
}

void Welcome() {
	string hello = "WELCOME TO LET ME OUT";
	string howto = "SU DUNG CAC PHIM MUI TEN DE DI CHUYEN. LOI RA LA 'O'";
	string start = "NHAN PHIM \"ENTER\" DE BAT DAU CHOI. NHAN BAT KI PHIM NAO KHAC SE THOAT";
	string ready = "BAN DA SAN SANG CHUA ";

	gotoXY(44, 10);
	for (auto ch :hello) {
		cout << ch;
		Sleep(40);
	}

	gotoXY(30, 12);
	for (auto ch : howto) {
		cout << ch;
		Sleep(40);
	}

	gotoXY(25, 14);
	for (auto ch : start) {
		cout << ch;
		Sleep(40);
	}

	gotoXY(44, 16);
	for (auto ch : ready) {
		cout << ch;
		Sleep(40);
	}
}


void In_level(char lvl[][25],int lv_game) {
	int size = 0;
	if (lv_game == 3) size = 25;
	else size = 20;
	for (int i = 0; i != size; ++i) {

		gotoXY(40, 8 + i);
		for (int j = 0; j != size; ++j) {
			if (lvl[i][j] == 's') {
				TextColor(15);
				cout << lvl[i][j];
			}

			if (lvl[i][j] == '#' || lvl[i][j] == '=' || lvl[i][j] == '|') {
				TextColor(15);
				cout << char(219); // buoc tuong
			}

			if (lvl[i][j] == 'x') {
				get_color(i, j, lv_game);
				cout << lvl[i][j];
			}

			if (lvl[i][j] == 'T') {
				TextColor(15);
				cout << lvl[i][j];
			}

			if (lvl[i][j] == ' ') {
				TextColor(0);
				cout << lvl[i][j];
			}

			if (lvl[i][j] == '@') {
				set_me();
				cout << lvl[i][j];
			}

			if (lvl[i][j] == 'O') {
				set_out();
				cout << lvl[i][j];
			}
		}
	}

	cout << endl;

}

void Chien_thang() {
	clrscr();
	for (int i = 0; ; i++) {
		int color = rand() % 16;
		TextColor(color);
		gotoXY(50, 10);
		cout << "You Win!";
		Sleep(300);
	}
	return;
}


void control() {
	system("CLS");
	gotoXY(50, 10);
	cout << "1 Coutinue" << endl;
	gotoXY(50, 11);
	cout << "2 Reset level" << endl;
	gotoXY(50, 12);
	cout << "3 Quit game" << endl;

}

void Thank() {
	system("CLS");
	gotoXY(40, 10);
	cout << "Cam on cac ban da choi game cua nhom minh";
	gotoXY(30, 27);
	cout << ' ';
}

void This_Level(int lv_game) {
	system("CLS");
	gotoXY(50, 10);
	cout << "LEVEL " << lv_game;

	Sleep(2000);
	system("CLS");
}

void NumberofHammer(int Hammer) {
	gotoXY(50, 7);
	TextColor(ColorCode_White);
	cout << "Hammer: " << Hammer;
}

void Hp(int Mau) {
	gotoXY(40, 7);
	TextColor(ColorCode_White);
	cout << "HP: " << Mau;

}

// In ra Màn hình khi Thất bại
void IsLost() {
	clrscr();
	gotoXY(40, 8);
	cout << "Ban da thua\n";
	gotoXY(25, 9);
	cout << "Nhan 'enter' de bat dau lai tu dau, Nhan 'esc' se thoat";

}

