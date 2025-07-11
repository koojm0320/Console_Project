#pragma once
#include "Dot.h"

class ScreenDot
{
private:
	vector<string> _mainScreen;
	vector<string> _explaneScreen;
	vector<string> _stageAllClear;
	vector<string> _stageClear;
	vector<string> _stage1_1;
	vector<string> _stage1_Boss;
	vector<string> _stage2_1;
	vector<string> _stage2_Boss;
	vector<string> _gameOver;

public:
	void MainScreen();
	void ExplaneScreen();

	void StageAllClear();
	void StageClear();
	void GameOver();

	void Stage1_1();
	void Stage1_Boss();
	void Stage2_1();
	void Stage2_Boss();

	ScreenDot();
	~ScreenDot();
};

