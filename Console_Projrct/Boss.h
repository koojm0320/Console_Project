#pragma once
#include "Dot.h"

class Boss
{
private:
	Dot* _dot;
	int _x;
	int _y;

	bool _alive;

	int shooterX;
	int shooterY;

public:

	int getX() { return _x; }
	int getY() { return _y; }

	void Die();
	bool isAlive() const { return _alive; }

	void Daroach();
	void MetaKnight();

	int BshooterGetX() { return shooterX; }
	int BshooterGetY() { return shooterY; }

	void DaroachHit();
	void DaroachClear();

	void MetaKnightHit();
	void MetaKnightClear();
	

	void Pattern1();

	Boss();
	~Boss();
};

