#pragma once
#include "Stage.h"
#include "StageSelect.h"
#include "ScreenDot.h"
#include <iostream>
#include <Windows.h>
#include <string>

//using namespace std;

class Menu
{
private:
	Stage* _stage;
	Dot* _dot;
	ScreenDot* _screenDot;
	StageSelect* _stageSelect;

	// 플레이어 선택 관련 자료형
	int cursorX;
	int cursorY;
	int playerChoice;
	

public:
	void explane();
	void printMenu();

	Menu();
	~Menu();
};

