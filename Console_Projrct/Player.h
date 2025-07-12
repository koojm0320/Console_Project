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
	Dot* _dot;
	
	// �÷��̾� ����, ��ġ
	int _x, _y;
	bool _alive;
	
	// ��ų ����
	bool _isSpeedUp;
	int _speedUpTimer;
	int _skillCooldown;

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

	int getSkillCooldown() const { return _skillCooldown; }

	// ������ ȿ�� ����
	void ActivateSpeedBoost();
	void UpdateSkillTimers();


	Player();
	~Player();
};

