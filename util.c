#include "util.h"
void init(){
	system("mode con cols=116 lines=25 | title 검강화하기(베타)");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO consoleCursor = { 0, };
	consoleCursor.bVisible = FALSE;
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);
}
void go(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
