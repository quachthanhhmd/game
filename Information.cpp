#include "console.h" //Thu vien mau sac
#include "information.h" //Thu vien dieu huong
#include "Move.h" // thuc hien di


void FixConsole() {
	Nocursortype();
	BlockZoomConsole();
}

void Run_maze() {

	Welcome();
	move();
}
