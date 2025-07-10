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

	int _patternTimer;   // 패턴 내부 타이머
	int _currentPattern; // 현재 실행 중인 패턴 번호

	vector<BossProjectile> _bossProjectile;

	int shooterX;
	int shooterY;

public:

	int getX() { return _x; }
	int getY() { return _y; }

	void Die();
	bool isAlive() const { return _alive; }
	
	// 피격 getter setter
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

