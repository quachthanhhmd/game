
#include "console.h"

#include "Move.h"
#include "Setting.h"
#include "PrintScreen.h"

using namespace std;



bool Start_game() {
	char Batdau;
	Batdau = _getch();
	clrscr();
	if (Batdau == 13) {
		return 1;
	}
	return 0;
}

void Welcome() {
	string hello = "WELCOME TO LET ME OUT";
	string howto = "USE ARROW KEY TO MOVE. EXIT IS 'O'";
	string start = "PRESS \"ENTER\" TO START. PRESS ANY OTHER KEY WILL EXIT THE GAME";
	string ready = "ARE YOU READY ?";

	gotoXY(44, 10);
	for (auto ch :hello) {
		cout << ch;
		Sleep(40);
	}

	gotoXY(38, 12);
	for (auto ch : howto) {
		cout << ch;
		Sleep(40);
	}

	gotoXY(25, 14);
	for (auto ch : start) {
		cout << ch;
		Sleep(40);
	}

	gotoXY(46, 16);
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

		gotoXY(30, 8 + i);
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

bool Chien_thang() {
	clrscr();
	gotoXY(1, 29);
	cout << "Press 'y' to restart the game, any other button will exit the game";
	for (int i = 0; ; i++) {

		int color = rand() % 16;
		TextColor(color);
		gotoXY(50, 10);
		cout << "You Win!";
		
		if (_kbhit()) {
			char end = _getch();
			if (end == 88 || end == 121) return 1;
			else
				return 0;
		}
		Sleep(300);
		
	}
	return 0;
}


void Control() {
	clrscr();
	TextColor(ColorCode_White);
	gotoXY(50, 10);
	cout << "1 Coutinue" << endl;
	gotoXY(50, 11);
	cout << "2 Reset level" << endl;
	gotoXY(50, 12);
	cout << "3 Quit game" << endl;

}

void Thank() {
	clrscr();
	gotoXY(45, 10);
	TextColor(ColorCode_White);
	cout << "Thank you for playing our game";
	gotoXY(30, 27);
	cout << ' ';
}

void This_Level(int lv_game) {
	clrscr();
	gotoXY(50, 10);
	TextColor(ColorCode_White);
	cout << "LEVEL " << lv_game;

	Sleep(2000);
	clrscr();
}

void NumberofHammer(int Hammer) {
	gotoXY(40, 7);
	TextColor(ColorCode_White);
	cout << "Hammer: " << Hammer;
}

void Hp(int Mau) {
	gotoXY(30, 7);
	TextColor(ColorCode_White);
	cout << "HP: " << Mau;

}

// In ra Màn hình khi Thất bại
void IsLost() {
	clrscr();
	gotoXY(50, 8);
	cout << "You are lost\n";
	gotoXY(25, 9);
	cout << "Press 'enter' to restart the game, any other button will exit the game";

}

void PrintTime(int m, int s) {
	gotoXY(30, 7);
	set_clock();
	cout << setw(2) << m << ":"
		<< setw(2) << s;
}


void Help(int lv_game) {
	if (lv_game == 1) {
		TextColor(ColorCode_White);
		gotoXY(52, 8);
		cout << "Welcome to Level 1!";
		gotoXY(52, 10);
		cout << "In this level, your character is '@' and you have to ";
		gotoXY(52, 11);
		cout << "move it to 'O' so as to win this level";
		gotoXY(52, 13);
		cout << "'Teleport' is your special ability in level 1";
		gotoXY(52, 15);
		cout << "To 'Teleport' you have to move your character to teleport gates,";
		gotoXY(52, 16);
		cout << "known as symbol 'x', with different colors.";
		gotoXY(52, 18);
		cout << "Different teleport gate will move your character to other possition.";
		gotoXY(52, 20);
		cout << "For example, if your character move to gate 'x' colour with red, ";
		gotoXY(52, 21);
		cout << "you will move to the other 'x' coloured with red,";
		gotoXY(52, 23);
		cout << "if 'x' coloured with blue, you will move to 'x' coloured with blue";
		gotoXY(52, 25);
		cout << "Tip: You can use one gate many times as you want !!!";
	}
	if (lv_game == 2) {
		TextColor(ColorCode_White);
		gotoXY(52, 7);
		cout << "Congratulations, you won Level 1. Here is some tips for the";
		gotoXY(52, 8);
		cout << "level 2, take note my friends ! :D";
		gotoXY(52, 10);
		cout << "In this level, you have one more special ability: 'Pounding walls'.";
		
		gotoXY(52, 12);
		cout << "You have to take those hammers which are represented by letter 'T'";
		gotoXY(52, 13);
		printf("Remember,ONE hammer can pound ONLY ONE wall ('%c') so use it widely to ", char(219));
		gotoXY(52, 14);
		cout << "win this level";
		gotoXY(52, 16);
		cout << "To pound wall, choose the wall you want to pound and press 'Space',";
		gotoXY(52, 17);
		cout << "the wall will disappear!";
		gotoXY(52, 19);
		cout << "For example, you want to pound the wall on the right side of";
		gotoXY(52, 20);
		cout << "your character?? (the wall must be NEXT TO your character), press";
		gotoXY(52, 21);
		cout << "right arrow key, then press 'Space'";
		gotoXY(52, 23);
		cout << "One more thing you should notice, the 'Ugly Monster' !";
		gotoXY(52, 25);
		cout << "If your character touch the head of 'Ugly Monster', you will lose";
		gotoXY(52, 26);
		cout << "your HP!";
		gotoXY(52, 28);
		cout << "HP = 0, you LOSE, so watch your steps!";
	}

	if (lv_game == 3) {
		TextColor(ColorCode_White);
		gotoXY(57, 8);
		cout << "WOW!!! You come through Level 2! Excellent!!!";
		gotoXY(57, 10);
		cout << "But, in level 3, things are even getting CRAZIER !";
		gotoXY(57, 12);
		cout << "You will say bye bye to the 'Ugly Monster',";
		gotoXY(57, 13);
		cout << "and meet your new friend: Time !";
		gotoXY(57, 15);
		cout << "if you don't want to lose, You have to find your way out before";
		gotoXY(57, 16);
		cout << "the time run out";
		gotoXY(57, 18);
		cout << "Do you see the 's' ?";
		gotoXY(57, 20);
		cout << "hose are bonus time! Take it and you will have 5 extra seconds";
		gotoXY(57, 21);
		cout << "to finish level";
		gotoXY(57, 23);
		cout << "Time runs out, START now or never !";
	}
}