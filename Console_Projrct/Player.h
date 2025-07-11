#pragma once
#include "Dot.h"

// �������� �����ϱ� ���� ����ü
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
	int _x, _y;
	Dot* _dot;

	bool _alive;

	// ������ ��� ����
	vector<Laser> _laser;

public:
	// �÷��̾�&������ �̵� �� �߻� ����
	void LaserLogic();
	void MoveLogic();

	// �÷��̾� ����
	void PlayerHit();
	void GameOverHit();
	void Die();
	bool isAlive() const { return _alive; }

	// getter
	int getX() { return _x; }
	int getY() { return _y; }
	vector<Laser>& getLaser();


	Player();
	~Player();
};

