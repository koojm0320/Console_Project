#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Dot.h"
#include "ScreenDot.h"
#include <time.h>

class GameManager
{
	Player* _player;
	Enemy* _enemy;
	Boss* _boss;
	Dot* _dot;
	ScreenDot* _screenDot;

	int playerLife;
	int playerInvincibleTimer;
	int bossInvincibleTimer;

	int WDLife;
	int const ENEMY_KILL_COUNT = 10;
	int killCount;

	int daroachLife;
	int metaKnightLife;

	bool isCollide;
	bool playerInvincible;
	bool bossInvincible;

	// player
	int playerLeft;
	int playerRight;
	int playerTop;
	int playerBottom;

	// enemy
	int enemyLeft;
	int enemyRight;
	int enemyTop;
	int enemyBottom;

	// boss1
	int daroachLeft;
	int daroachRight;
	int daroachTop;
	int daroachBottom;

	// boss2
	int metaKnightLeft;
	int metaKnightRight;
	int metaKnightTop;
	int metaKnightBottom;

	// laser
	int laserLeft;
	int laserRight;
	int laserHeight;

public:
	void Stage1_1();
	void Stage2_1();
	void BossStage1();
	void BossStage2();
	void HitBox();
	void CollisionDec();

	GameManager();
	~GameManager();
};

