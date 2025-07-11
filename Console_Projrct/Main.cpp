#include "MainGame.h"
#include "Common.h"
#include <time.h>

#pragma region 특이사항
/*
콘솔 버퍼 사이즈 : 180*90



*/
#pragma endregion


int main()
{
	srand((unsigned int)time(NULL));
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = 0; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c); 

	//GameManager mg;
	//mg.BossStage2();

	MainGame mg;
	return 0;
}

