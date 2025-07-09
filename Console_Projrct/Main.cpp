#include "MainGame.h"
#include <time.h>

int main()
{
	// 커서 안보이게
	srand(time(NULL));
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = 0; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c); 

	MainGame mg;
	return 0;
}

