#include "GameManager.h"
#include "Common.h"

GameManager::GameManager()
{
	playerLife = 2;
	invincibleTimer = 0;
	WDLife = 1;

	killCount = 0;

	daroachLife = 9;
	metaKnightLife = 19;

	isCollide = false;
	playerInvincible = false;
	bossInvincible = false;

	playerLeft = playerRight = playerTop = playerBottom = 0;
	enemyLeft = enemyRight = enemyTop = enemyBottom = 0;
	daroachLeft = daroachRight = daroachTop = daroachBottom = 0;
	metaKnightLeft = metaKnightRight = metaKnightTop = metaKnightBottom = 0;

	laserHeight = laserLeft = laserRight = 0;

	_player = new Player;
	_enemy = new Enemy;
	_boss = new Boss;
	_dot = new Dot;
	_screenDot = new ScreenDot;
}

GameManager::~GameManager()
{
	delete _player;
	delete _enemy;
	delete _boss;
	delete _dot;
	delete _screenDot;
}

//==============================일반 스테이지	============================
void GameManager::GameStart()
{

	const int lifeCount = 3;
	playerInvincible = false;


	while (true)
	{
		system("cls");
		HitBox();
		CollisionDec();

		_player->MoveLogic();
		_player->LaserLogic();
		_enemy->EnemySpawnLogic();

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			Sleep(100);
			break;
		}
		

		// laser - enemy 충돌 판정
		for (size_t i = 0; i < _player->getLaser().size(); ++i)
		{
			if (!_player->getLaser()[i].activate)
			{
				continue;
			}
			for (size_t j = 0; j < _enemy->getTrashMob().size(); ++j)
			{
				if (!_enemy->getTrashMob()[j].isAlive)
				{
					continue;
				}
				// laser 히트박스
				laserLeft = _player->getLaser()[i].x;
				laserRight = _player->getLaser()[i].x + 4;
				laserHeight = _player->getLaser()[i].y;

				enemyLeft = _enemy->getTrashMob()[j].x;
				enemyRight = enemyLeft + _enemy->getTrashMob()[j].width - 1;
				enemyTop = _enemy->getTrashMob()[j].y;
				enemyBottom = enemyTop + _enemy->getTrashMob()[j].height - 1;

				if (laserLeft <= enemyRight && laserRight >= enemyLeft &&
					laserHeight <= enemyBottom && laserHeight >= enemyTop)
				{
					_player->getLaser()[i].activate = false;
					_enemy->getTrashMob()[j].isAlive = false;

					if (WDLife > 0 && WDLife < 2)
					{
						_dot->WaddleDeeHit(_enemy->getTrashMob()[j].x, _enemy->getTrashMob()[j].y);
						WDLife--;
					}
					else
					{
						_dot->WaddleDeeHit(_enemy->getTrashMob()[j].x, _enemy->getTrashMob()[j].y);
						killCount++;
					}

					break;
				}
			}
		}
		// 무적 시간(프레임)
		if (invincibleTimer)
		{
			invincibleTimer--;
			if (invincibleTimer <= 0)
			{
				playerInvincible = false;
			}
		}

		if (isCollide && !playerInvincible)
		{
			if (playerLife > 0 && playerLife <= 3)
			{
				_player->PlayerHit();
				playerLife--;
				playerInvincible = true;
				invincibleTimer = 100;
			}
			else
			{
				_player->Die();
				_player->GameOverHit();
				system("cls");
				cursorXY(80, 20);
				printf("GAME OVER!");
				Sleep(2000);
				break;
			}
		}

		for (int i = 0; i < playerLife + 1; i++)
		{
			_dot->Life(1 + i * 11, 45);
		}
		for (int i = playerLife + 1; i < lifeCount; i++)
		{
			_dot->LifeDec(1 + i * 11, 45);
		}

		if (killCount >= ENEMY_KILL_COUNT)
		{
			system("cls");
			cursorXY(80, 20);
			printf("STAGE CLEAR!");
			Sleep(2000);
			break;
		}

		cursorXY(85, 1);
		printf("남은 적: %d", ENEMY_KILL_COUNT - killCount);

		Sleep(10);
	}
}

// ==============================  1-boss	============================
void GameManager::BossStage1()
{
	int bossHitEffectTimer = 0;
	const int lifeCount = 3;
	playerInvincible = false;

	while (true)
	{
		system("cls");

		HitBox();
		CollisionDec();

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			Sleep(100);
			break;
		}

		_player->MoveLogic();
		_player->LaserLogic();
		_boss->Daroach();
		_boss->BossLaserLogic();
		_boss->UpdatePattern();

		// ========================== boss 피격 애니메이션 ======================
		if (_boss->isAlive())
		{
			if (_boss->isHit())
			{
				_dot->DaroachHit(_boss->getX(), _boss->getY());
				bossHitEffectTimer = 10;
				_boss->setHit(false);
			}
			else
			{
				_dot->Daroach(_boss->getX(), _boss->getY());
			}
		}

		if (bossHitEffectTimer > 0)
		{
			bossHitEffectTimer--;
		}

		// boss 피격무적 판정
		if (invincibleTimer)
		{
			invincibleTimer--;
			if (invincibleTimer <= 0)
			{
				bossInvincible = false;
			}
		}
		// ========================= playerLaser -> Boss 피격 =========================
		for (size_t i = 0; i < _player->getLaser().size(); i++)
		{
			if (!_player->getLaser()[i].activate)
			{
				continue;
			}

			// laser 히트박스
			laserLeft = _player->getLaser()[i].x;
			laserRight = _player->getLaser()[i].x + 4;
			laserHeight = _player->getLaser()[i].y;

			if (_boss->isAlive() &&
				!bossInvincible &&
				laserLeft <= daroachRight &&
				laserRight >= daroachLeft &&
				laserHeight >= daroachTop &&
				laserHeight <= daroachBottom)
			{
				_player->getLaser()[i].activate = false;

				if (daroachLife > 0 && daroachLife < 10)
				{
					bossHitEffectTimer = 5;
					_boss->DaroachHit();
					daroachLife--;
					bossInvincible = true;
					invincibleTimer = 10;
				}
				else
				{
					_boss->Die();
					_boss->DaroachClear();
					system("cls");
					cursorXY(80, 20);
					printf("STAGE CLEAR!");
					Sleep(2000);
					return;
				}
				// if 구역
			}
			// for문 구역
		}

		//========================== BossLaser->player 피격 ==========================

		vector<BossProjectile>& projectiles = _boss->getBossProjectile();

		if (!playerInvincible)
		{
			for (size_t i = 0; i < projectiles.size(); ++i)
			{
				if (!projectiles[i].activate)
				{
					continue;
				}

				if (projectiles[i].x >= playerLeft && 
					projectiles[i].x <= playerRight &&
					projectiles[i].y >= playerTop &&
					projectiles[i].y <= playerBottom)
				{
					projectiles[i].activate = false;
					isCollide = true;
					break;
				}
			}
		}

		//=======================   boss 발사체   =======================

		// vector<BossProjectile>& bossProjectiles = _boss->getBossProjectile();
		for (size_t i = 0; i < projectiles.size(); ++i)
		{
			if (projectiles[i].activate)
			{
				cursorXY(projectiles[i].x, projectiles[i].y);
				TextColor(4, 0);
				cout << "●";
				TextColor(7, 0);
			}
		}


		//======================== Daroach 체력 표기 ==========================
		for (int i = 0; i < daroachLife + 1; i++)
		{
			TextColor(4, 4);
			cursorXY(60 + i * 2, 2);
			printf("ㅁ");
			TextColor(7, 0);
		}
		for (int i = daroachLife + 1; i < 10; i++)
		{
			TextColor(8, 8);
			cursorXY(60  + i * 2, 2);
			printf("ㅁ");
			TextColor(7, 0);
		}

		if (isCollide && !playerInvincible)
		{
			if (playerLife > 0 && playerLife <= 3)
			{
				_player->PlayerHit();
				playerLife--;
				playerInvincible = true;
				invincibleTimer = 100;
			}
			else
			{
				_player->Die();
				_player->GameOverHit();
				system("cls");
				cursorXY(80, 20);
				printf("GAME OVER!");
				Sleep(2000);
				break;
			}
		}

		for (int i = 0; i < playerLife + 1; i++)
		{
			_dot->Life(1 + i * 11, 45);
		}
		for (int i = playerLife + 1; i < lifeCount; i++)
		{
			_dot->LifeDec(1 + i * 11, 45);
		}

		Sleep(16);
	}
}

// ==============================  2-boss	============================
void GameManager::BossStage2()
{
	while (true)
	{
		HitBox();
		CollisionDec();

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			Sleep(100);
			break;
		}

		_player->MoveLogic();
		_boss->MetaKnight();


		if (invincibleTimer)
		{
			invincibleTimer--;
			if (invincibleTimer <= 0)
			{
				bossInvincible = false;
			}
		}

		for (int i = 0; i < metaKnightLife + 1; i++)
		{
			TextColor(4, 4);
			cursorXY(135 + i * 2, 2);
			cout << "ㅁ";
			TextColor(7, 0);
		}
		for (int i = metaKnightLife + 1; i < 20; i++)
		{
			TextColor(8, 8);
			cursorXY(135 + i * 2, 2);
			cout << "ㅁ";
			TextColor(7, 0);
		}

		Sleep(3);
	}
}
// ==============================  HitBox	============================
void GameManager::HitBox()
{
	// player히트박스
	playerLeft = _player->getX();
	playerRight = _player->getX() + 12;
	playerTop = _player->getY();
	playerBottom = _player->getY() + 4;

	//// enemy 히트박스
	//enemyLeft = _enemy->getX();
	//enemyRight = _enemy->getX() + 8;
	//enemyTop = _enemy->getY();
	//enemyBottom = _enemy->getY() + 5;

	// Daroach 히트박스
	daroachLeft = _boss->getX();
	daroachRight = _boss->getX() + 12;
	daroachTop = _boss->getY();
	daroachBottom = _boss->getY() + 15;

	// MetaKnight 히트박스
	metaKnightLeft = _boss->getX();
	metaKnightRight = _boss->getX() +18;
	metaKnightTop = _boss->getY() + 1;
	metaKnightBottom = _boss->getY() + 13;

}

// ====================== player - trashMob 충돌		=====================
void GameManager::CollisionDec()
{
	isCollide = false;
	vector<TrashMob>& mobs = _enemy->getTrashMob();

	for (size_t i = 0; i < mobs.size(); ++i)
	{
		if (!mobs[i].isAlive)
		{
			continue;
		}

		int eLeft = mobs[i].x;
		int eRight = mobs[i].x + mobs[i].width;
		int eTop = mobs[i].y;
		int eBottom = mobs[i].y + mobs[i].height;

		if (playerLeft <= eRight &&
			playerRight >= eLeft &&
			playerTop <= eBottom &&
			playerBottom >= eTop)
		{
			isCollide = true;
			break;
		}
	}
}

// ====================== player - BossLaser충돌		=====================

