#pragma once
#include "Dot.h"

struct Laser
{
	int x, y;
	int width = 4;
	int height = 1;
	bool activate;
	Laser(int posX, int posY) : x(posX), y(posY), activate(true) {};
};

class Player
{
private:
	int _x;
	int _y;
	Dot* _dot;

	bool _alive;
	bool _shooterReset;

	vector<Laser> _laser;

public:
	void PlayerHit();
	void GameOverHit();

	// getter
	int getX() { return _x; }
	int getY() { return _y; }


	vector<Laser>& getLaser();

	void Die();
	bool isAlive() const { return _alive; }


	void LaserLogic();

	void MoveLogic();
	Player();
	~Player();
};

