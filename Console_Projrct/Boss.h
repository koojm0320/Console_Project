#pragma once
#include "Dot.h"

struct BossProjectile
{
	int x, y;
	double dx, dy;
	bool activate;

	BossProjectile(int startX, int startY, double dirX, double dirY) :
		x(startX), y(startY), dx(dirX), dy(dirY), activate(true) {};
};

class Boss
{
private:
	Dot* _dot;
	int _x;
	int _y;

	bool _alive;
	bool _isHit;

	int _bossMoveTimer;

	int _patternTimer;   // ���� ���� Ÿ�̸�
	int _currentPattern; // ���� ���� ���� ���� ��ȣ

	vector<BossProjectile> _bossProjectile;

	int shooterX;
	int shooterY;

public:

	int getX() { return _x; }
	int getY() { return _y; }

	void Die();
	bool isAlive() const { return _alive; }
	
	// �ǰ� getter setter
	bool isHit() const { return _isHit; }
	void setHit(bool isHit) { _isHit = isHit; }

	void Daroach();
	void MetaKnight();

	void DaroachHit();
	void DaroachClear();

	void MetaKnightHit();
	void MetaKnightClear();
	

	vector<BossProjectile>& getBossProjectile();

	void UpdatePattern1();
	void UpdatePattern2();
	void BossLaserLogic();

	void BossPattern1();
	void BossPattern2();
	void BossPattern3();
	void BossPattern4();

	void RandMove();

	Boss();
	~Boss();
};

