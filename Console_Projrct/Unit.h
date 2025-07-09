#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Unit
{
private:


protected:
	int _hp;		// 체력
	int _atk;		// 공격력
	bool _alive;	// 생사판별

public:
	void PlayerInfo();
	void TrashMobInfo();
	void BossInfo();
	Unit();
	~Unit();
};

