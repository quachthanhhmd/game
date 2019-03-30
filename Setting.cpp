#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <direct.h>

#include "console.h"
#include "Setting.h"


//Màu săc của các cổng dịch chuyển
void get_color(int x, int y, int lv_game) {
	int vt_x_lv1[9] = { 2, 10, 18, 18, 18, 18, 7, 4, 1 };
	int vt_y_lv1[9] = { 2, 2, 7, 3, 9, 5, 4, 8, 17 }; //mang cac vi tri x dich chuyen

	int vt_x_lv2[13] = { 0, 17, 15 ,10, 7, 5, 1, 12, 16,17, 3, 8, 10 };
	int vt_y_lv2[13] = { 0, 1, 9, 12, 5, 16, 14, 7, 11, 6, 8, 11, 14 };

	int vt_x_lv3[17] = { 0, 1,20, 19, 19, 10, 23,11,13, 21, 15, 23, 4, 5, 15, 13, 3 };
	int vt_y_lv3[17] = { 0, 1,22, 16, 14, 12, 9, 16, 3, 12, 20, 17, 14, 20, 6, 18, 20 };

	if (lv_game == 1) {
		for (int i = 1; i <= 8; i++)
			if (x == vt_x_lv1[i] && y == vt_y_lv1[i])
				if (i <= 4)
					TextColor(i);
				else
					TextColor(i - 4);
	}

	if (lv_game == 2) {
		for (int i = 1; i <= 12; i++)
			if (x == vt_x_lv2[i] && y == vt_y_lv2[i])
				if (i <= 6)
					TextColor(i);
				else
					TextColor(i - 6);
	}

	if (lv_game == 3) {
		for (int i = 1; i <= 16; i++)
			if (x == vt_x_lv3[i] && y == vt_y_lv3[i])
				if (i <= 8)
					TextColor(i);
				else
					TextColor(i - 8);
	}
}

//Màu sắc của nhân vật
void set_me() {
	TextColor(ColorCode_Red);
}

// Màu sắc của lối thoát
void set_out() {
	TextColor(ColorCode_Pink);
}

void set_monster() {
	TextColor(ColorCode_Cyan);

}

void set_clock() {
	TextColor(ColorCode_White);
}


//Lấy dữ liệu các dự án trong trò chơi
void Get_data(char &last_move, bool &Not_moving, int &Blood, int &Add_s, bool &Lost, int & m, int &s, int &Hammer) {

	last_move = NULL; //Biến lưu vết biến di chuyển trở về NULL
	Not_moving = false;// mặc định là đang di chuyển
	Blood = 3;//Số máu quy định cho màn 2 là 3
	Add_s = 0;//Thời gian cộng thêm mặc định là 0
	Lost = 0; // Mặc định là vẫn chưa thua
	m = 1; //số phút để hoàn thành trò chơi ở lv3
	s = 0; //số giây để hoàn thành trò chơi ở lv3
	Hammer = 0;//Số búa ban đầu bằng 0
}


void Stop(std::thread &pthread) {
	TerminateThread((void*)pthread.native_handle(), 0); // Dừng tiểu trình
	pthread.join(); // Join tiểu trình trước khi kết thúc
}
