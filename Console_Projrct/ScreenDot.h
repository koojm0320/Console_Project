#pragma once
#include "Dot.h"

class ScreenDot
{
private:
	vector<string> _mainScreen;
	vector<string> _explaneScreen;
	vector<string> _stageAllClear;

public:
	void MainScreen();
	void ExplaneScreen();

	void StageAllClear();

	ScreenDot();
	~ScreenDot();
};

