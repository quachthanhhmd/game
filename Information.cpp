#include <Windows.h>


#include "console.h" //Thu vien mau sac
#include "information.h" //Thu vien dieu huong
#include "Move.h" // thuc hien di 

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Run_maze() {

	Welcome();
	move();
	
}
