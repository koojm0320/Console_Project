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

	// �÷��̾� ���� ���� �ڷ���
	int playerLife;
	int playerInvincibleTimer;
	int bossInvincibleTimer;
	bool isCollide;
	bool playerInvincible;

	// ���� ���� ���� �ڷ���
	int WDLife;
	int const ENEMY_KILL_COUNT = 10;
	int killCount;
	int daroachLife;
	int metaKnightLife;
	bool bossInvincible;

	// �÷��̾� ��Ʈ�ڽ�
	int playerLeft;
	int playerRight;
	int playerTop;
	int playerBottom;

	// �̸� ��Ʈ�ڽ�
	int enemyLeft;
	int enemyRight;
	int enemyTop;
	int enemyBottom;

	// 1�������� ���� ��Ʈ�ڽ�
	int daroachLeft;
	int daroachRight;
	int daroachTop;
	int daroachBottom;

	// 2�������� ���� ��Ʈ�ڽ�
	int metaKnightLeft;
	int metaKnightRight;
	int metaKnightTop;
	int metaKnightBottom;

	// �÷��̾� ������
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

