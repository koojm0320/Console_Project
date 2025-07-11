#include "Stage.h"
#include "Common.h"

Stage::Stage()
{
	_gameManager = new GameManager;
	_screenDot = new ScreenDot;
}

Stage::~Stage()
{
	delete _gameManager;
	delete _screenDot;
}

// vector or 배열로 묶을 수 있을거같음
void Stage::Stage1_Level1()
{
	delete _gameManager;
	_gameManager = new GameManager;

	system("cls");
	_screenDot->Stage1_1();
	Sleep(2000);
	_gameManager->Stage1_1();
}

void Stage::Stage1_Boss()
{
	delete _gameManager;
	_gameManager = new GameManager;

	system("cls");
	_screenDot->Stage1_Boss();
	Sleep(2000);
	_gameManager->BossStage1();
}

void Stage::Stage2_Level1()
{
	delete _gameManager;
	_gameManager = new GameManager;

	system("cls");
	_screenDot->Stage2_1();
	Sleep(2000);
	_gameManager->Stage2_1();
}

void Stage::Stage2_Boss()
{
	delete _gameManager;
	_gameManager = new GameManager;

	system("cls");
	_screenDot->Stage2_Boss();
	Sleep(2000);
	_gameManager->BossStage2();
}
