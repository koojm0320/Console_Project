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
	// 메인화면, 게임설명화면 도트
	void MainScreen();
	void ExplaneScreen();

	// 스테이지 클리어,패배 시 출력 도트
	void StageAllClear();
	void StageClear();
	void GameOver();

	// 각 스테이지 진입 화면 도트
	void Stage1_1();
	void Stage1_Boss();
	void Stage2_1();
	void Stage2_Boss();

	ScreenDot();
	~ScreenDot();
};

