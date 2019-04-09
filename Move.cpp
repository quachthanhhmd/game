#pragma comment (lib, "winmm.lib")
#include <conio.h>
#include <iostream>
#include <mutex>

#include "khoitao.h"
#include "Setting.h"
#include "KeyBoard.h"
#include "console.h"
#include "Move.h"
#include "PrintScreen.h"


using namespace std;


static bool EndGame(char[][25], TOADO, int , int );
static void makeSpace(char lvl[][25], int, TOADO, int);
static void copy_lv(char[][25], int);
static TOADO Lay_toa_do(char[][25], int);
static bool Dung_tuong(char[][25], TOADO, int, int );
static void update(char[][25], TOADO, int ,int );
static bool IsTele(char[][25], int , TOADO, bool&, int, int);

static bool CollectHammer(char[][25], TOADO, int, int);
static bool PoundingWalls(char[][25], int , TOADO , int , int );

bool Tele1(char[][25], int, TOADO);
bool Tele2(char[][25], int , TOADO);
bool Tele3(char[][25], int, TOADO);


thread pthread;


//Khai báo mảng mê cung 
char lvl[25][25];

mutex mtx;

//Đếm Ngược thời gian và in ra màn hình
void Countdown() {
	
	bool flag = 1; //đánh dấu là đã cập nhật thời gian ở thời điểm đó rồi
	int total = m * 60 + s;
	while (total + Add_s)
	{
		if (m == 0 && s <= 10) Beep(587, 500);
		mtx.lock();
		PrintTime(m, s);
		mtx.unlock();
		Sleep(1000);

		if (s + Add_s > 60) {
			
			m++;
			s = 60 - (total + Add_s) % 60;
			total += Add_s;
			Add_s = 0;
			flag = 0;
			
		}
		if (m == 0 && s == 1)
		{
			clrscr();
			Lost = 1;
			TerminateThread((void*)pthread.native_handle(), 0);
			return;	
		}
		else if (m >= 1 && s == 0)
		{
			m--;
			s += 60;
		}

		s = (total + Add_s - 1) % 60 ;

		if (Add_s != 0) Add_s--;
		else 
			total--;
		
	}
}




// Nhặt được thời gian
static bool Collect_time(char lvl[][25], TOADO vitri, int move_x, int move_y) {
	if (lvl[vitri.x + move_x][vitri.y + move_y] == 's')
		return 1;
	return 0;

}


//Quái di chuyên trên mê cung
void MonsterMoves(char lvl[][25], int lv_game, int toado, int batdau, int ketthuc) {
	int flag = 0; // danh dau la vua moi va cham
	Hp(Blood);
Begin:
	for (int i = batdau + 1; i <= ketthuc; i++) {

		if (lvl[toado][i] == '@' ||lvl[toado][i - 1] == '@') {
			if (!flag) {
				Hp(--Blood);
				Beep(587, 500);
			}
			makeSpace(lvl, lv_game, { toado, i - 2 }, 0);
			flag = 1;
		}
		else {
			set_monster();
			gotoXY(coordx - 1 + i, coordy + toado);
			
			cout << '=' << Quai;
		

			flag = 0;
			if (lvl[toado][i - 2] != '@')
				makeSpace(lvl, lv_game,{ toado, i - 2}, 0);
	
		}

		if (Blood == 0) {
			clrscr();
			Lost = 1;

			TerminateThread((void*)pthread.native_handle(), 0);

			return;
		}
		Sleep(200);
	}

	flag = 0;
	for (int i = ketthuc - 1; i >= batdau; i--) {

		if (lvl[toado][i] == '@' || lvl[toado][i + 1] == '@') {
			if (!flag) {
				Hp(--Blood);
				Beep(587, 500);
			}
			makeSpace(lvl, lv_game, {toado, i + 2}, 0);
			flag = 1;
		}
		else {
			mtx.lock();
			gotoXY(coordx + i, coordy + toado);
			set_monster();
			cout << Quai << '=';
			mtx.unlock();
			flag = 0;

			if (lvl[toado][i + 2] != '@')
				makeSpace(lvl, lv_game, { toado, i + 2 }, 0);
		}
	

		if (Blood == 0) {
			clrscr();
			Lost = 1;

			TerminateThread((void*)pthread.native_handle(), 0);

			return;
		}

		Sleep(200);
	}
	goto Begin;;
}


int MovingCases(char lvl[][25], int lv_game, TOADO vitri, int move_x, int move_y, bool &Not_moving, bool &flag, int &Hammer) {
	if (!Dung_tuong(lvl, vitri, move_x, move_y)) {
		Not_moving = 0;

		if (EndGame(lvl, vitri, move_x, move_y)) {
			clrscr();

			return 1;
		}

		if (CollectHammer(lvl, vitri, move_x, move_y)) {
			NumberofHammer(++Hammer);
		}

		if (Collect_time(lvl, vitri, move_x, move_y))
			Add_s += 5;  // thoi gian tang 5 giay

		if (IsTele(lvl, lv_game, vitri, flag, move_x, move_y)) return 2;


		if (flag) { //neu dich chuyen roi thi tra lai cong dich chuyen
			flag = 0;
			makeSpace(lvl, lv_game, vitri, 1);
		}
		else
			makeSpace(lvl, lv_game, vitri, 0);

		update(lvl, vitri, move_x, move_y);
	}
	else Not_moving = 1;
	return 0;
}

void GetMoving(char move, char &move_x, char &move_y) {
	if (move == 'u') {
		move_x = topx;
		move_y = topy;
	}

	if (move == 'd') {
		move_x = botx;
		move_y = boty;
	}

	if (move == 'r') {
		move_x = rightx;
		move_y = righty;
	}

	if (move == 'l') {
		move_x = leftx;
		move_y = lefty;
	}

}


void Moving() {
	//Khởi Tạo
	TOADO vitri;
	int Case;
	bool flag = 0;
	char last_move;
	bool Not_moving = NULL;
	char move_x, move_y;
	int lv_game = 0;
	int Hammer = 0;
	int Music = 0;
	//-------------

	if (!Start_game()) {
		Thank();
		return;
	}
	//Music on
	

	

begin:
	if ((Music) % 2 == 0)
		PlaySound("NEW-ZEALAND-STORY.wav", 0, SND_ASYNC | SND_FILENAME | SND_LOOP);

	Get_data(last_move, Not_moving, Blood, Add_s, Lost, m, s, Hammer);

	if (lv_game == 3) {
		Stop(pthread);
		if ((Music) % 2 == 0)
			PlaySound("Victory.wav", 0, SND_ASYNC | SND_FILENAME | SND_LOOP);
		if (Chien_thang()) {
			lv_game = 0;
			goto begin;
		}
		else {
			clrscr();
			return;
		}
	}

	This_Level(++lv_game);
	Help(lv_game);
	copy_lv(lvl,lv_game);
	In_level(lvl, lv_game);

	if (lv_game == 2 || lv_game == 3) NumberofHammer(Hammer);

	if (lv_game == 2) 
		pthread = thread(MonsterMoves,lvl, lv_game, lv2_1_toadox, lv2_1_start, lv2_1_end); //luồng quái di chuyển
		
	
	
	if (lv_game == 3) {
		pthread = thread(Countdown); //luồng đồng hồ đếm ngược
	}
	
	
	
	while (1) {
		if (!Lost) {
			char move;

			if (_kbhit())
				move = GetKey();
			else
				continue;
			if (Lost) continue;


			vitri = Lay_toa_do(lvl, lv_game);
			switch (move) {
			case 'm':
				
				if ((++Music) % 2) 
					PlaySound(0, 0, 0);
				else 
					PlaySound("NEW-ZEALAND-STORY.wav", 0, SND_ASYNC | SND_FILENAME | SND_LOOP);
				
					
				break;
			case 'c':
				SuspendThread((void*)pthread.native_handle());

				Control();

				while (1) {
					int select = GetKeyControl();
					if (!select)
						continue;

					if (select == 3) {
						Thank();
						if (lv_game != 1)
							Stop(pthread);
						return;
					}

					if (select == 2) {
						clrscr();
						if (lv_game != 1)
							Stop(pthread);
						lv_game--;
						if ((Music) % 2 == 0)
							PlaySound(0, 0, 0);
						goto begin;;
					}

					if (select == 1) {
						clrscr();
						Help(lv_game);
						In_level(lvl, lv_game);
						if (lv_game != 1) NumberofHammer(Hammer);
						if (lv_game == 2) Hp(Blood);
					}

					break;
				}
				ResumeThread((void*)pthread.native_handle());

				break;

			case 's':
				if (Hammer && last_move != NULL) {
					GetMoving(last_move, move_x, move_y);
					if (PoundingWalls(lvl, lv_game, vitri, move_x, move_y)) {
						NumberofHammer(--Hammer);
					}
				}
				break;

			case 'u': 
			case 'd': 
			case 'l':
			case 'r':
				GetMoving(move, move_x, move_y);

				Case = MovingCases(lvl, lv_game, vitri, move_x, move_y, Not_moving, flag, Hammer);
				if (Case == 1) {
					if (lv_game == 2) {
						Stop(pthread);
					}
					goto begin;
					
				}
				else
					if (Case == 2) continue;
				break;

			
			default:
				break;
			}
			if (lv_game == 2) Sleep(220);
			else
				Sleep(150);
			if (move == 'l' || move == 'u' || move == 'r' || move == 'd')
				last_move = move;
		}
		else { 
			// Nếu Thua
			IsLost();
			if ((Music) % 2 == 0)
				PlaySound("Defeat.wav", 0, SND_ASYNC | SND_FILENAME | SND_LOOP);
			while (1) {
				char move = GetKey();
				if (move == 'e') {
					pthread.join();
					lv_game = 0;
					goto begin;
				}
				else
					break;
			}
			break;
		}
	}
	
	pthread.join();


}




static TOADO Lay_toa_do(char lvl[][25], int lv_game) { // lay vi tri con tro thoi diem hien tai

	int n;
	if (lv_game == 3) n = 25;
	else n = 20;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (lvl[i][j] == '@')
				return { i,j };
			}
	}
	
	
	return { 0,0 };
}

static void update(char lvl[][25] , TOADO Position, int move_x, int move_y) { // cap nhat vi tri hien tai
		lvl[Position.x + move_x][Position.y + move_y] = me;
		mtx.lock();
		gotoXY(30 + Position.y + move_y, 8 + Position.x + move_x);
		set_me();
		cout << me;
		mtx.unlock();

}

static void makeSpace(char lvl[][25],int lv_game, TOADO Position, int flag) {
	mtx.lock();
		if (flag == 0) {
			lvl[Position.x][Position.y] = space;
			gotoXY(coordx + Position.y, coordy + Position.x);
			cout << ' ';
		}
		else {
			lvl[Position.x][Position.y] = 'x';
			gotoXY(coordx + Position.y, coordy + Position.x);
			get_color(Position.x, Position.y, lv_game);
			cout << 'x';
		}
	mtx.unlock();
	
}

static bool Dung_tuong(char lvl[][25], TOADO vitri, int move_x, int move_y) { //Xu li neu cham tuong
		
	if (lvl[vitri.x + move_x][vitri.y + move_y] == '#' || lvl[vitri.x + move_x][vitri.y + move_y] == '|' ||lvl[vitri.x + move_x][vitri.y + move_y] == '=') {
		return true;
	}
	else {
		return false;
	}

}

static bool EndGame(char lvl[][25], TOADO vitri, int move_x, int move_y) {
	if (lvl[vitri.x + move_x][vitri.y + move_y] == 'O') {
			return true;
	}
	else {
		return false;
	}
	
}

// dich chuyen
static bool IsTele(char lvl[][25], int lv_game, TOADO vitri, bool &flag, int buoc_di_x, int buoc_di_y) {
	TOADO vitri_dichuyen = { vitri.x + buoc_di_x, vitri.y + buoc_di_y };

	if (lv_game == 1) {
		
		if (Tele1(lvl, lv_game, vitri_dichuyen)) {
			makeSpace(lvl, lv_game, vitri, 0);
			flag = 1;//luu vet la da dich chuyen r
			return 1;
		}
	}

	if (lv_game == 2) {
		if (Tele2(lvl, lv_game, vitri_dichuyen)) {
			makeSpace(lvl, lv_game, vitri, 0);
			flag = 1;//luu vet la da dich chuyen r
			return 1;
		}
	}

	if (lv_game == 3) {
		if (Tele3(lvl, lv_game, vitri_dichuyen)) {
			makeSpace(lvl, lv_game, vitri, 0);
			flag = 1;//luu vet la da dich chuyen r
			return 1;
		}
	}
	return 0;//khong dich chuyen duoc
}

bool Tele1(char lvl[][25],int lv_game, TOADO vitri_dichuyen) {
	int vt_x_lv1[9] = { 2, 10, 18, 18, 18, 18, 7, 4, 1 };
	int vt_y_lv1[9] = { 2, 2, 7, 3, 9, 5, 4, 8, 17 }; //mang cac vi tri x dich chuyen

	for (int i = 1; i <= 8; i++)
		if (vitri_dichuyen.x == vt_x_lv1[i] && vitri_dichuyen.y == vt_y_lv1[i]) {

			makeSpace(lvl, lv_game , vitri_dichuyen, 1);

			if (i <= 4) update(lvl, { vt_x_lv1[i + 4], vt_y_lv1[i + 4] }, 0, 0);
			else
				update(lvl, { vt_x_lv1[i - 4], vt_y_lv1[i - 4] }, 0, 0);
			
			return 1;
		}
	return 0;
}

bool Tele2(char lvl[][25], int lv_game, TOADO NewPosition) {

	int vt_x_lv2[13] = { 0, 17, 15 ,10, 7, 5, 1, 12, 16,17, 3, 8, 10 };
	int vt_y_lv2[13] = { 0, 1, 9, 12, 5, 16, 14, 7, 11, 6, 8, 11, 14 };
	for (int i = 1; i <= 12; i++)
		if (NewPosition.x == vt_x_lv2[i] && NewPosition.y == vt_y_lv2[i]) {

			makeSpace(lvl, lv_game, NewPosition, 1);

			if (i <= 6) update(lvl, { vt_x_lv2[i + 6], vt_y_lv2[i + 6] }, 0, 0);
			else
				update(lvl, { vt_x_lv2[i - 6], vt_y_lv2[i - 6] }, 0, 0);
			
			return 1;
		}
	return 0;
}
//

bool Tele3(char lvl[][25], int lv_game, TOADO NewPosition) {
	int vt_x_lv3[17] = { 0, 1,20, 19, 19, 10, 23,11,13, 21, 15, 23, 4, 5, 15, 13, 3 };
	int vt_y_lv3[17] = { 0, 1,22, 16, 14, 12, 9, 16, 3, 12, 20, 17, 14, 20, 6, 18, 20 };

	for (int i = 1; i <= 16; i++)
		if (NewPosition.x == vt_x_lv3[i] && NewPosition.y == vt_y_lv3[i]) {
			makeSpace(lvl, lv_game, NewPosition, 1);

			if (i <= 8) update(lvl, { vt_x_lv3[i + 8], vt_y_lv3[i + 8] }, 0, 0);
			else
				update(lvl, { vt_x_lv3[i - 8], vt_y_lv3[i - 8] }, 0, 0);
			return 1;
		}
	return 0;
}


static void copy_lv(char lvl[][25], int lv_game) {
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

//Nhặt được búa
static bool CollectHammer(char lvl[][25], TOADO position, int Move_x, int Move_y) {
	if (lvl[position.x + Move_x][position.y + Move_y] == 'T') {
		return 1;
	}
	return 0;
}

static bool PoundingWalls(char lvl[][25],int lv_game, TOADO position, int move_x, int move_y) {
	TOADO NewPosition = { position.x + move_x,position.y + move_y };
	if (lvl[NewPosition.x][NewPosition.y] == '#') {
		makeSpace(lvl, lv_game, NewPosition, 0);
		return 1;
	}
	return 0;
}