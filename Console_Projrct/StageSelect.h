#pragma once
#include "Dot.h"
#include "Stage.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class StageSelect
{
private:
	Stage* _stage;
	Dot* _dot;
	ScreenDot* _screenDot;
	int stageCount;
	int selectStage;
	const int stagePosX[4] = { 30, 60, 120, 150 };
	const int stagePosY = 25;

public:
	void StageRun();
	StageSelect();
	~StageSelect();
};

