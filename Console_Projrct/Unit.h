#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Unit
{
private:


protected:
	int _hp;		// ü��
	int _atk;		// ���ݷ�
	bool _alive;	// �����Ǻ�

public:
	void PlayerInfo();
	void TrashMobInfo();
	void BossInfo();
	Unit();
	~Unit();
};

