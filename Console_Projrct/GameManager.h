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

	// 플레이어 생존 관련 자료형
	int playerLife;
	int playerInvincibleTimer;
	int bossInvincibleTimer;
	bool isCollide;
	bool playerInvincible;

	// 적군 생존 관련 자료형
	int WDLife;
	int const ENEMY_KILL_COUNT = 10;
	int killCount;
	int daroachLife;
	int metaKnightLife;
	bool bossInvincible;

	// 플레이어 히트박스
	int playerLeft;
	int playerRight;
	int playerTop;
	int playerBottom;

	// 쫄몹 히트박스
	int enemyLeft;
	int enemyRight;
	int enemyTop;
	int enemyBottom;

	// 1스테이지 보스 히트박스
	int daroachLeft;
	int daroachRight;
	int daroachTop;
	int daroachBottom;

	// 2스테이지 보스 히트박스
	int metaKnightLeft;
	int metaKnightRight;
	int metaKnightTop;
	int metaKnightBottom;

	// 플레이어 레이저
	int laserLeft;
	int laserRight;
	int laserHeight;

public:
	static bool StageClear[4];

	void Stage1_1();
	void Stage2_1();
	void BossStage1();
	void BossStage2();
	void HitBox();
	void CollisionDec();

	GameManager();
	~GameManager();
};

