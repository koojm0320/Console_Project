#include "Stage.h"
#include "Common.h"

Stage::Stage()
{
	_gameManager = new GameManager;
}

Stage::~Stage()
{
	delete _gameManager;
}

// vector or 배열로 묶을 수 있을거같음
void Stage::Stage1_Level1()
{
	system("cls");
	cursorXY(89, 24);
	cout << "1-1";
	Sleep(2000);
	_gameManager->GameStart();
}

void Stage::Stage1_Boss()
{
	system("cls");
	cursorXY(86, 24);
	cout << "1-BOSS";
	Sleep(2000);
	_gameManager->BossStage1();
}

void Stage::Stage2_Level1()
{
	system("cls");
	cursorXY(89, 24);
	cout << "2-1";
	Sleep(2000);
	_gameManager->GameStart();
}

void Stage::Stage2_Boss()
{
	system("cls");
	cursorXY(86, 24);
	cout << "2-BOSS";
	Sleep(2000);
	_gameManager->BossStage2();
}
