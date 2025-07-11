#pragma once
#include "Dot.h"
#include <time.h>

// 쫄몹의 정보를 정의하기 위한 구조체
struct TrashMob
{
	int x, y;
	int width = 10;
	int height = 5;
	bool isAlive;
	TrashMob(int posX, int posY) : x(posX), y(posY), isAlive(true) {};
};

class Enemy
{
private:
	Dot* _dot;
	int _x;
	int _y;

	bool _alive;

	vector<TrashMob> _trashMob;


public:
	int getX() { return _x; }
	int getY() { return _y; }
	
	vector<TrashMob>& getTrashMob();
	void EnemySpawnLogic();


	bool isAlive() const { return _alive; }
	

	Enemy();
	~Enemy();
};

