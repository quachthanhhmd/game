#include <conio.h>
#include <iostream>


#include "console.h"
#include "khoitao.h"
#include "Move.h"
#include "PrintScreen.h"


using namespace std;


static void In_level(int, char[][25] );
static bool Ket_thuc(int, int, int, char [][25]);
static void makeSpace(char[][25], int , int , int, int );
static void copy_lv(int, char[][25]);
static char Lay_phim();
static int Bang_control();
static int Lay_toa_do(char[][25], int , int&);
static bool Dung_tuong(int, int, int, char[][25]);
static void update(char[][25], int , int , int , bool );
static bool Is_Tele(char[][25], int , int, int, bool&, int, int);
//static bool Nhat_Bua(int, int, int, int, int);	

bool Tele1(char[][25], int , int , int );
bool Tele2(char[][25], int , int , int );
bool Tele3(char[][25], int, int, int);



static void In_level(int lv_game, char lvl[][25] ) {
	int size = 0;
	if (lv_game == 3) size = 25;
	else size = 20;
	
	for (int i = 0; i != size; ++i) {
		gotoXY(40, 8 + i);
		for (int j = 0; j != size; ++j) {
			if (lvl[i][j] == '#' || lvl[i][j] == '=' || lvl[i][j] == '|')
				cout << char(219); // buoc tuong
			else cout << lvl[i][j];
			}
	}

	cout << endl;
	

}



void move() {

	int x, y, lv_game = 0, Bua = 0;
	bool flag = 0;
	char lvl[25][25];

	if (!Start_game())
		return;

begin:
	if (lv_game == 3) {
		Chien_thang();
	}

	This_Level(++lv_game);
	copy_lv(lv_game, lvl);
	In_level(lv_game,lvl);

	while (1) {
		char move = Lay_phim();
		

		switch (move) {

		case 'c':
			control();
			while (1) {
				int select = Bang_control();
				if (!select)
					continue;

				if (select == 3) {
					Thank();
					return;
				}

				if (select == 2) {
					system("CLS");
					lv_game--;
					goto begin;;
				}

				if (select == 1) {
					system("CLS");
					In_level(lv_game, lvl);
				}
				break;
			}

			break;
		case 'u':
			x = Lay_toa_do(lvl, lv_game, y);

			if (!Dung_tuong(x - 1, y, lv_game, lvl)) {
				
				if (Ket_thuc(x - 1, y, lv_game,lvl)) {
					system("CLS");

					goto begin;;
				}

				if (Is_Tele(lvl, lv_game, x, y, flag, topx, topy)) break;


				if (flag) { //neu dich chuyen roi thi tra lai cong dich chuyen
					flag = 0;
					makeSpace(lvl, lv_game, x, y, 1);
				}
				else
					makeSpace(lvl, lv_game, x, y, 0);
				update(lvl, lv_game, x - 1, y, 0);
			}
			break;

		case 'd':
			x = Lay_toa_do(lvl, lv_game, y);

			if (!Dung_tuong(x + 1, y, lv_game, lvl)) {

				if (Ket_thuc(x + 1, y, lv_game, lvl)) {
					system("CLS");

					goto begin;;
				}

				if (Is_Tele(lvl, lv_game, x, y, flag, botx, boty)) break;

				if (flag) { //neu dich chuyen roi thi tra lai cong dich chuyen
					flag = 0;
					makeSpace(lvl, lv_game, x, y, 1);
				}
				else
					makeSpace(lvl, lv_game, x, y, 0);
				update(lvl, lv_game, x + 1, y, 0);
			}
			break;
		case 'l':
			x = Lay_toa_do(lvl, lv_game, y);

			if (!Dung_tuong(x, y - 1, lv_game, lvl )) {

				if (Ket_thuc(x, y - 1, lv_game, lvl)) {
					system("CLS");

					goto begin;;
				}

				if (Is_Tele(lvl, lv_game, x, y, flag, leftx, lefty))
					break;


				if (flag) { //neu dich chuyen roi thi tra lai cong dich chuyen
					flag = 0;
					makeSpace(lvl, lv_game, x, y, 1);
				}
				else
					makeSpace(lvl, lv_game, x, y, 0); //di binh thuong
				update(lvl, lv_game, x, y - 1, 0);
			}
			break;
		case 'r':
			x = Lay_toa_do(lvl, lv_game, y);

			if (!Dung_tuong(x, y + 1, lv_game, lvl)) {

				if (Ket_thuc(x, y + 1, lv_game,lvl )) {
					system("CLS");

					goto begin;;
				}

				if (Is_Tele(lvl, lv_game, x, y, flag, rightx, righty)) break;

				if (flag) { //neu dich chuyen roi thi tra lai cong dich chuyen
					flag = 0;
					makeSpace(lvl, lv_game, x, y, 1);
				}
				else
					makeSpace(lvl, lv_game, x, y, 0);
				update(lvl, lv_game, x, y + 1, 0);
			}
			break;
		default:
			break;
		}
	}


}


static char Lay_phim() {

	char key = 127;

	key = _getch();

	if (key == 0 || key == -32 ) {

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
	return key;
}


static int Bang_control() {

	char key = 127;

	key = _getch();

	if (key == 51)  return 3;
	if (key == 50) return 2;
	if (key == 49) return 1;
	return 0;
}


static int Lay_toa_do(char lvl[][25], int lv_game, int &y) { // lay vi tri con tro thoi diem hien tai
	int ToaDoX;

	int n;
	if (lv_game == 3) n = 25;
	else n = 20;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (lvl[i][j] == '@') {
				ToaDoX = i;
				y = j;
				return ToaDoX;
			}
		}
	}
	
	return 0;
}

static void update(char lvl[][25], int lv_game, int x, int y, bool flag) { // cap nhat vi tri hien tai
	if (lv_game == 1) {
		lvl[x][y] = me;
		gotoXY(40 + y, 8 + x);
		cout << me;

	}

	if (lv_game == 2) {
		lvl[x][y] = me;

		gotoXY(40 + y, 8 + x);
		cout << me;
	}

	if (lv_game == 3) {
		lvl[x][y] = me;

		gotoXY(40 + y, 8 + x);
		cout << me;
	}
}

static void makeSpace(char lvl[][25], int lv_game, int x, int y, int flag) {
	if (lv_game == 1) {
		if (flag == 0) {
			lvl[x][y] = space;
			gotoXY(40 + y, 8 + x);
			cout << ' ';
		}
		else {
			lvl[x][y] = 'x';
			gotoXY(40 + y, 8 + x);
			cout << 'x';
		}

	}
	if (lv_game == 2) {
		if (flag == 0) {
			lvl[x][y] = space;
			gotoXY(40 + y, 8 + x);
			cout << ' ';
		}
		else {
			lvl[x][y] = 'x';
			gotoXY(40 + y, 8 + x);
			cout << 'x';
		}
	}


	if (lv_game == 3) {
		if (flag == 0) {
			lvl[x][y] = space;
			gotoXY(40 + y, 8 + x);
			cout << ' ';
		}
		else {
			lvl[x][y] = 'x';
			gotoXY(40 + y, 8 + x);
			cout << 'x';
		}
	}
}

static bool Dung_tuong(int x, int y, int lv_game, char lvl[][25]) { //Xu li neu cham tuong
	if (lv_game == 1) {
		if (lvl[x][y] == '#' || lvl[x][y] == '|' || lvl[x][y] == '=') {
			return true;
		}
		else {
			return false;
		}
	}
	if (lv_game == 2) {
		if (lvl[x][y] == '#' || lvl[x][y] == '|' || lvl[x][y] == '=') {
			return true;
		}
		else {
			return false;
		}
	}

	if (lv_game == 3) {
		if (lvl[x][y] == '#' || lvl[x][y] == '|' || lvl[x][y] == '=') {
			return true;
		}
		else {
			return false;
		}
	}

	return true;
}

static bool Ket_thuc(int x, int y, int lv_game, char lvl[][25]) {
	if (lv_game == 1) {
		if (lvl[x][y] == 'O') {
			return true;
		}
		else {
			return false;
		}
	}
	if (lv_game == 2) {
		if (lvl[x][y] == 'O') {
			return true;
		}
		else {
			return false;
		}
	}

	if (lv_game == 3) {
		if (lvl[x][y] == 'O') {
			return true;
		}
		else {
			return false;
		}
	}
	return true;
}

// dich chuyen
bool Is_Tele(char lvl[][25], int lv_game, int x, int y, bool &flag, int buoc_di_x, int buoc_di_y) {
	if (lv_game == 1) {
		if (Tele1(lvl, lv_game, x + buoc_di_x, y + buoc_di_y)) {
			makeSpace(lvl, lv_game, x, y, 0);
			flag = 1;//luu vet la da dich chuyen r
			return 1;
		}
	}

	if (lv_game == 2) {
		if (Tele2(lvl, lv_game, x + buoc_di_x, y + buoc_di_y)) {
			makeSpace(lvl, lv_game, x, y, 0);
			flag = 1;//luu vet la da dich chuyen r
			return 1;
		}
	}

	if (lv_game == 3) {
		if (Tele3(lvl, lv_game, x + buoc_di_x, y + buoc_di_y)) {
			makeSpace(lvl, lv_game, x, y, 0);
			flag = 1;//luu vet la da dich chuyen r
			return 1;
		}
	}
	return 0;//khong dich chuyen duoc
}

bool Tele1(char lvl[][25], int lv_game, int x, int y) {
	int vt_x[9] = { 2, 10, 18, 18, 18, 18, 7, 4, 1 };
	int vt_y[9] = { 2, 2, 7, 3, 9, 5, 4, 8, 17 }; //mang cac vi tri x dich chuyen
	for (int i = 1; i <= 8; i++)
		if (x == vt_x[i] && y == vt_y[i]) {
			//char c = lvl1[x][y];

			makeSpace(lvl, lv_game, x, y, 1);

			if (i <= 4) update(lvl, lv_game, vt_x[i + 4], vt_y[i + 4], 1);
			else
				update(lvl, lv_game, vt_x[i - 4], vt_y[i - 4], 1);
			//lvl1[x][y] = c;
			return 1;
		}
	return 0;
}

bool Tele2(char lvl[][25], int lv_game, int x, int y) {
	int vt_x_lv2[13] = { 0, 17, 15 ,10, 7, 5, 1, 12, 16,17, 3, 8, 10 };
	int vt_y_lv2[13] = { 0, 1, 9, 12, 5, 16, 14, 7, 11, 6, 8, 11, 14 };
	for (int i = 1; i <= 12; i++)
		if (x == vt_x_lv2[i] && y == vt_y_lv2[i]) {
			//char c = lvl1[x][y];

			makeSpace(lvl, lv_game, x, y, 1);

			if (i <= 6) update(lvl, lv_game, vt_x_lv2[i + 6], vt_y_lv2[i + 6], 1);
			else
				update(lvl, lv_game, vt_x_lv2[i - 6], vt_y_lv2[i - 6], 1);
			//lvl1[x][y] = c;
			return 1;
		}
	return 0;
}
//

bool Tele3(char lvl[][25], int lv_game, int x, int y) {
	int vt_x_lv3[17] = { 0, 1,20, 19, 19, 10, 23,11,13, 21, 15, 23, 4, 5, 15, 13, 3 };
	int vt_y_lv3[17] = { 0, 1,22, 16, 14, 12, 9, 16, 3, 12, 20, 17, 14, 20, 6, 18, 20 };

	for (int i = 1; i <= 16; i++)
		if (x == vt_x_lv3[i] && y == vt_y_lv3[i]) {
			makeSpace(lvl, lv_game, x, y, 1);

			if (i <= 8) update(lvl, lv_game, vt_x_lv3[i + 8], vt_y_lv3[i + 8], 1);
			else
				update(lvl, lv_game, vt_x_lv3[i - 8], vt_y_lv3[i - 8], 1);
			return 1;
		}
	return 0;
}


static void copy_lv(int lv_game, char lvl[][25]) {
	if (lv_game == 1) {
		for (int i = 0; i != 20; i++)
			for (int j = 0; j != 20; j++)
				lvl[i][j] = lvl1[i][j];
	}

	if (lv_game == 2) {
		for (int i = 0; i != 20; i++)
			for (int j = 0; j != 20; j++)
				lvl[i][j] = lvl2[i][j];
	}

	if (lv_game == 3) {
		for (int i = 0; i != 25; i++)
			for (int j = 0; j != 25; j++)
				lvl[i][j] = lvl3[i][j];
	}
}
