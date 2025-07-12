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

	// 보스 생존, 위치 관련
	int _x;
	int _y;
	bool _alive;
	bool _isHit;

	// 보스 패턴 관련
	bool _isDash;
	int _dashSpeed;
	int _originX;
	int _bossMoveTimer;
	int _patternTimer;
	int _currentPattern;
	double verticalSpeed;
	double direction;

	vector<BossProjectile> _bossProjectile;

public:
	// 보스 종류
	void Daroach();
	void MetaKnight();
	int getX() { return _x; }
	int getY() { return _y; }

	void Die();
	bool isAlive() const { return _alive; }
	
	// 피격 getter setter
	bool isHit() const { return _isHit; }
	void setHit(bool isHit) { _isHit = isHit; }


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

	void BossDash();

	void RandMove();

	Boss();
	~Boss();
};

