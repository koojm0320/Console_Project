#include "Menu.h"
#include "Common.h"
#include <time.h>

#pragma region Ư�̻���
/*
�ܼ� ���� ������ : 180*90
�ܼ� ���� ũ�� : 16

���� ���۸��� ������� �ʾ� �������� ���� �� ����.
*/
#pragma endregion


int main()
{
	srand((unsigned int)time(NULL));
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = 0; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c); 

	Menu mg;
	return 0;
}

