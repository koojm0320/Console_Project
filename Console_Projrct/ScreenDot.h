#pragma once
#include "Dot.h"

class ScreenDot
{
private:
	vector<string> _mainScreen;
	vector<string> _explaneScreen;
	vector<string> _stage1;

public:
	void MainScreen();
	void ExplaneScreen();

	void Stage1();
	void Stage2();
	void Stage3();

	ScreenDot();
	~ScreenDot();
};

