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

	// 일반 몬스터
	vector<string> _waddleDee;
	vector<string> _waddleDeeHit;

	// 1스테이지 보스
	vector<string> _daroach;
	vector<string> _daroachHit;

	// 2스테이지 보스
	vector<string> _metaKnight;
	vector<string> _metaKnightHit;

	// 아이콘
	vector<string> _kirbyStageSelect;
	vector<string> _life;
	vector<string> _lifeDec;
	vector<string> _powerUp;
	vector<string> _powerUpCooldown;
	
public:

	void kirby(short posX, short posY);
	void kirbyHit(short posX, short posY);

	void WaddleDee(short posX, short posY);
	void WaddleDeeHit(short posX, short posY);

	void Daroach(short posX, short posY);
	void DaroachHit(short posX, short posY);

	void MetaKnight(short posX, short posY);
	void MetaKnightHit(short posX, short posY);

	void KirbyStageSelect(short posX, short posY);

	void Life(short posX, short posY);
	void LifeDec(short posX, short posY);

	void PowerUp(short posX, short posY);
	void PowerUpCooldown(short posX, short posY);

	Dot();
	~Dot();
};

