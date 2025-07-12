#pragma once
#include "Dot.h"

// 레이저를 정의하기 위한 구조체
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
	
	// 플레이어 생존, 위치
	int _x, _y;
	bool _alive;
	
	// 스킬 관련
	bool _isSpeedUp;
	int _speedUpTimer;
	int _skillCooldown;

	// 레이저 목록 벡터
	vector<Laser> _laser;


public:
	// 플레이어&레이저 이동 및 발사 로직
	void LaserLogic();
	void MoveLogic();

	// 플레이어 상태
	void PlayerHit();
	void GameOverHit();
	void Die();
	bool isAlive() const { return _alive; }

	// getter
	int getX() { return _x; }
	int getY() { return _y; }
	vector<Laser>& getLaser();

	int getSkillCooldown() const { return _skillCooldown; }

	// 아이템 효과 적용
	void ActivateSpeedBoost();
	void UpdateSkillTimers();


	Player();
	~Player();
};

