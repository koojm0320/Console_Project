#include "MainGame.h"

void main()
{
	// 커서 안보이게
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = 0; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c); 

	GameManager mg;
	mg.BossStage1();
	return;
}

