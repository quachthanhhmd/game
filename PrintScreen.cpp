#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "console.h"
#include "information.h"
#include "Move.h"

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

void Chien_thang() {
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