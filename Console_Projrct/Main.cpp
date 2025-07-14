#include "Menu.h"
#include "Common.h"
#include <time.h>

#pragma region 특이사항
/*
콘솔 버퍼 사이즈 : 180*90
콘솔 글자 크기 : 16

더블 버퍼링을 사용하지 않아 깜빡임이 있을 수 있음.
*/
#pragma endregion


int main()
{
	srand((unsigned int)time(NULL));
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = 0; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c); 


	GameManager mg;
	mg.Stage1_1();
	//Menu mg;
	return 0;
}

