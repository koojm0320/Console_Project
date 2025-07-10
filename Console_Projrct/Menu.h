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
	int cursorX;
	int cursorY;
	int playerChoice;
	Stage* _stage;
	Dot* _dot;
	ScreenDot* _screenDot;
	StageSelect* _stageSelect;
	

public:
	void explane();
	void printMenu();

	Menu();
	~Menu();
};

