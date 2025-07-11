#pragma once
#include <Windows.h>
#include <iostream>
#include "GameManager.h"

using namespace std;

class Stage
{
private:
    GameManager* _gameManager;
    ScreenDot* _screenDot;

public:
    void Stage1_Level1();
    void Stage1_Boss();

    void Stage2_Level1();
    void Stage2_Boss();


	Stage();
	~Stage();
};

