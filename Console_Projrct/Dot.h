#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class Dot
{
private:
	// 배경
	vector<string> _mainScreen;
	
	// 유닛
	vector<string> _kirby;
	vector<string> _kirbyHit;

	vector<string> _waddleDee;
	vector<string> _waddleDeeHit;

	vector<string> _daroach;
	vector<string> _daroachHit;

	vector<string> _metaKnight;
	vector<string> _metaKnightHit;

	// 아이템
	vector<string> _hpUp;
	vector<string> _atkSpeedUp;
	vector<string> _atkPowerUp;


	// 아이콘
	vector<string> _kirbyStageSelect;
	vector<string> _life;
	vector<string> _lifeDec;

public:

	void kirby(short posX, short posY);
	void kirbyHit(short posX, short posY);

	void WaddleDee(short posX, short posY);
	void WaddleDeeHit(short posX, short posY);

	void Daroach(short posX, short posY);
	void DaroachHit(short posX, short posY);

	void MetaKnight(short posX, short posY);
	void MetaKnightHit(short posX, short posY);

	void HPUp(short posX, short posY);
	void AtkSpeedUp(short posX, short posY);
	void AtkPowerUp(short posX, short posY);


	void KirbyStageSelect(short posX, short posY);

	void Life(short posX, short posY);
	void LifeDec(short posX, short posY);

	Dot();
	~Dot();
};

