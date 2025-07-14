#include "GameManager.h"
#include "Common.h"

bool GameManager::StageClear[4]{ false, false ,false ,false };

GameManager::GameManager()
{
	playerLife = 0;
	playerInvincibleTimer = 0;
	bossInvincibleTimer = 0;

	killCount = 0;

	daroachLife = 0;
	metaKnightLife = 0;

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

// ===================================================================================================
// ==============================================    1-1    ==========================================
// ===================================================================================================
void GameManager::Stage1_1()
{
	killCount = 0;
	const int lifeCount = 3;
	playerInvincible = false;
	playerLife = 2;

	PlaySound(TEXT("Kirby_Stage.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			_player->ActivateSpeedBoost();
		}
		//system("cls");
		HitBox();
		CollisionDec();


		_player->MoveLogic();
		_player->LaserLogic();
		_enemy->EnemySpawnLogic();

		cursorXY(85, 1);
		TextColor(15, 0);
		printf("���� ��: %d ", ENEMY_KILL_COUNT - killCount);

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_ESC.wav from 0"), NULL, 0, NULL);
			Sleep(100);
			playerLife = 2;
			PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}
		

		// laser - enemy �浹 ����
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
				// laser ��Ʈ�ڽ�
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

					cursorXY(_player->getLaser()[i].x, _player->getLaser()[i].y);
					TextColor(0, 0);
					cout << "    "; // ������ ũ��(2ĭ)��ŭ �������� ����
					// �߰�
					int enemyX = _enemy->getTrashMob()[j].x;
					int enemyY = _enemy->getTrashMob()[j].y;

					_enemy->getTrashMob()[j].isAlive = false;

					mciSendString(TEXT("play Kirby_TrashMobDie.wav from 0"), NULL, 0, NULL);
					_dot->WaddleDeeHit(_enemy->getTrashMob()[j].x, _enemy->getTrashMob()[j].y);

					Sleep(50);

					TextColor(0, 0);
					for (int row = 0; row < 8; ++row)
					{
						cursorXY(enemyX, enemyY + row);
						cout << "              ";
					}

					killCount++;
					break;
				}
			}
		}
		// ���� �ð�(������)
		if (playerInvincibleTimer)
		{
			playerInvincibleTimer--;
			if (playerInvincibleTimer <= 0)
			{
				playerInvincible = false;
			}
		}

		if (isCollide && !playerInvincible)
		{
			mciSendString(TEXT("play Kirby_Hit.wav from 0"), NULL, 0, NULL);
			if (playerLife > 0 && playerLife <= 3)
			{
				_player->PlayerHit();
				playerLife--;
				playerInvincible = true;
				playerInvincibleTimer = 50;
			}
			else
			{
				PlaySound(NULL, 0, 0);
				_player->Die();
				_player->GameOverHit();
				system("cls");
				_screenDot->GameOver();
				mciSendString(TEXT("play Kirby_GameOver.wav from 0"), NULL, 0, NULL);
				Sleep(4000);
				system("cls");
				PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			}
		}

		// �÷��̾� ü�� ǥ��
		for (int i = 0; i < playerLife + 1; i++)
		{
			_dot->Life(1 + i * 11, 45);
		}
		for (int i = playerLife + 1; i < lifeCount; i++)
		{
			_dot->LifeDec(1 + i * 11, 45);
		}

		if (_player->getSkillCooldown() > 0)
		{
			// ��Ÿ���� ���� ���� ��
			_dot->PowerUpCooldown(35, 45);
		}
		else
		{
			// ��ų�� ����� �� ���� ��
			_dot->PowerUp(35, 45);
		}

		if (killCount >= ENEMY_KILL_COUNT)
		{
			PlaySound(NULL, 0, 0);
			Sleep(2000);
			system("cls");
			playerLife = 2;
			StageClear[0] = true;
			PlaySound(TEXT("Kirby_StageClear.wav"), NULL, SND_FILENAME | SND_ASYNC);
			_screenDot->StageClear();
			Sleep(3000);
			system("cls");
			PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}

		Sleep(10);
	}
}

// ===================================================================================================
// ==============================================    2-1    ==========================================
// ===================================================================================================
void GameManager::Stage2_1()
{
	killCount = 0;
	const int lifeCount = 3;
	playerInvincible = false;
	playerLife = 2;

	PlaySound(TEXT("Kirby_Stage.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			_player->ActivateSpeedBoost();
		}
		//system("cls");
		HitBox();
		CollisionDec();


		_player->MoveLogic();
		_player->LaserLogic();
		_enemy->EnemySpawnLogic();

		cursorXY(85, 1);
		TextColor(15, 0);
		printf("���� ��: %d ", ENEMY_KILL_COUNT - killCount);

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_ESC.wav from 0"), NULL, 0, NULL);
			Sleep(100);
			playerLife = 2;
			PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}


		// laser - enemy �浹 ����
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
				// laser ��Ʈ�ڽ�
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

					cursorXY(_player->getLaser()[i].x, _player->getLaser()[i].y);
					TextColor(0, 0);
					cout << "    "; // ������ ũ��(2ĭ)��ŭ �������� ����
					// �߰�
					int enemyX = _enemy->getTrashMob()[j].x;
					int enemyY = _enemy->getTrashMob()[j].y;

					_enemy->getTrashMob()[j].isAlive = false;

					mciSendString(TEXT("play Kirby_TrashMobDie.wav from 0"), NULL, 0, NULL);
					_dot->WaddleDeeHit(_enemy->getTrashMob()[j].x, _enemy->getTrashMob()[j].y);

					Sleep(50);

					TextColor(0, 0);
					for (int row = 0; row < 8; ++row)
					{
						cursorXY(enemyX, enemyY + row);
						cout << "              ";
					}

					killCount++;
					break;
				}
			}
		}
		// ���� �ð�(������)
		if (playerInvincibleTimer)
		{
			playerInvincibleTimer--;
			if (playerInvincibleTimer <= 0)
			{
				playerInvincible = false;
			}
		}

		if (isCollide && !playerInvincible)
		{
			mciSendString(TEXT("play Kirby_Hit.wav from 0"), NULL, 0, NULL);
			if (playerLife > 0 && playerLife <= 3)
			{
				_player->PlayerHit();
				playerLife--;
				playerInvincible = true;
				playerInvincibleTimer = 50;
			}
			else
			{
				PlaySound(NULL, 0, 0);
				_player->Die();
				_player->GameOverHit();
				system("cls");
				_screenDot->GameOver();
				mciSendString(TEXT("play Kirby_GameOver.wav from 0"), NULL, 0, NULL);
				Sleep(4000);
				system("cls");
				PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			}
		}

		// �÷��̾� ü�� ǥ��
		for (int i = 0; i < playerLife + 1; i++)
		{
			_dot->Life(1 + i * 11, 45);
		}
		for (int i = playerLife + 1; i < lifeCount; i++)
		{
			_dot->LifeDec(1 + i * 11, 45);
		}

		if (_player->getSkillCooldown() > 0)
		{
			// ��Ÿ���� ���� ���� ��
			_dot->PowerUpCooldown(35, 45);
		}
		else
		{
			// ��ų�� ����� �� ���� ��
			_dot->PowerUp(35, 45);
		}

		if (killCount >= ENEMY_KILL_COUNT)
		{
			PlaySound(NULL, 0, 0);
			Sleep(2000);
			system("cls");
			playerLife = 2;
			StageClear[2] = true;
			PlaySound(TEXT("Kirby_StageClear.wav"), NULL, SND_FILENAME | SND_ASYNC);
			_screenDot->StageClear();
			Sleep(3000);
			system("cls");
			PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}

		Sleep(10);
	}
}

// ===================================================================================================
// ==============================================   1-boss  ==========================================
// ===================================================================================================
void GameManager::BossStage1()
{
	int bossHitEffectTimer = 0;
	const int lifeCount = 3;
	playerInvincible = false;
	playerLife = 2;
	daroachLife = 19;

	PlaySound(TEXT("Kirby_Boss.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (true)
	{
		//system("cls");
		HitBox();
		CollisionDec();

		cursorXY(75, 1);
		cout << "- �������� ������ ���� - ";

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			Sleep(100);
			playerLife = 2;
			PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}

		// ���� �ܻ� ����
		if (_boss->isAlive())
		{
			TextColor(0, 0);
			for (int i = 0; i < 15; ++i)
			{
				cursorXY(_boss->getX(), _boss->getY() + i);
				cout << "                        ";
			}
		}

		_player->MoveLogic();
		_player->LaserLogic();
		_boss->Daroach();
		//_boss->BossLaserLogic();
		_boss->UpdatePattern1();
		_boss->RandMove();

		// boss �ǰ� �ִϸ��̼�
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

		// boss �ǰݹ��� ����
		if (bossInvincibleTimer)
		{
			bossInvincibleTimer--;
			if (bossInvincibleTimer <= 0)
			{
				bossInvincible = false;
			}
		}

		// plaer �ǰݹ��� ����
		if (playerInvincibleTimer)
		{
			playerInvincibleTimer--;
			if (playerInvincibleTimer <= 0)
			{
				playerInvincible = false;
			}
		}
		// playerLaser -> Boss �ǰ�
		for (size_t i = 0; i < _player->getLaser().size(); i++)
		{
			if (!_player->getLaser()[i].activate)
			{
				continue;
			}

			// laser ��Ʈ�ڽ�
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
				mciSendString(TEXT("play Kirby_BossDamage.wav from 0"), NULL, 0, NULL);

				cursorXY(_player->getLaser()[i].x, _player->getLaser()[i].y);
				TextColor(0, 0);
				cout << "    "; // ������ ũ��(2ĭ)��ŭ �������� ����

				if (daroachLife > 0 && daroachLife < 20)
				{
					bossHitEffectTimer = 5;
					_boss->DaroachHit();
					daroachLife--;
					bossInvincible = true;
					bossInvincibleTimer = 10;
				}
				else
				{
					PlaySound(NULL, 0, 0);
					_boss->Die();
					_boss->DaroachClear();
					system("cls");
					StageClear[1] = true;
					_screenDot->StageClear();
					mciSendString(TEXT("play Kirby_StageClear.wav from 0"), NULL, 0, NULL);
					Sleep(3000);
					system("cls");
					PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					return;
				}
			}
		}

		// BossLaser->player �ǰ�

		vector<BossProjectile>& projectiles = _boss->getBossProjectile();


		// boss �߻�ü
		for (size_t i = 0; i < projectiles.size(); ++i)
		{
			if (projectiles[i].activate)
			{
				cursorXY(projectiles[i].x, projectiles[i].y);
				TextColor(0, 0);
				cout << "  ";
			}
		}
		
		_boss->BossLaserLogic();

		for (size_t i = 0; i < projectiles.size(); ++i)
		{
			if (projectiles[i].activate)
			{
				cursorXY(projectiles[i].x, projectiles[i].y);
				TextColor(4, 0);
				cout << "��";
				TextColor(15, 0);

				if (!playerInvincible &&
					projectiles[i].x >= playerLeft &&
					projectiles[i].x <= playerRight &&
					projectiles[i].y >= playerTop &&
					projectiles[i].y <= playerBottom)
				{
					projectiles[i].activate = false;
					isCollide = true;
				}
			}
		}


		// Daroach ü�� ǥ��
		for (int i = 0; i < daroachLife + 1; i++)
		{
			TextColor(4, 4);
			cursorXY(67 + i * 2, 2);
			printf("��");
			TextColor(15, 0);
		}
		for (int i = daroachLife + 1; i < 20; i++)
		{
			TextColor(8, 8);
			cursorXY(67  + i * 2, 2);
			printf("��");
			TextColor(15, 0);
		}

		if (isCollide && !playerInvincible)
		{
			mciSendString(TEXT("play Kirby_Hit.wav from 0"), NULL, 0, NULL);
			if (playerLife > 0 && playerLife <= 3)
			{
				_player->PlayerHit();
				playerLife--;
				playerInvincible = true;
				playerInvincibleTimer = 10;
			}
			else
			{
				PlaySound(NULL, 0, 0);
				_player->Die();
				_player->GameOverHit();
				Sleep(1000);
				system("cls");
				_screenDot->GameOver();
				mciSendString(TEXT("play Kirby_GameOver.wav from 0"), NULL, 0, NULL);
				Sleep(4000);
				system("cls");
				PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			}
		}

		// �÷��̾� ü�� ��Ʈ ���
		for (int i = 0; i < playerLife + 1; i++)
		{
			_dot->Life(1 + i * 11, 45);
		}
		for (int i = playerLife + 1; i < lifeCount; i++)
		{
			_dot->LifeDec(1 + i * 11, 45);
		}

		// ��ų ��Ÿ�� ��Ʈ ���
		if (_player->getSkillCooldown() > 0)
		{
			// ��Ÿ���� ���� ���� ��
			_dot->PowerUpCooldown(35, 45);
		}
		else
		{
			// ��ų�� ����� �� ���� ��
			_dot->PowerUp(35, 45);
		}

		Sleep(10);
	}
}

// ===================================================================================================
// ==============================================   2-boss  ==========================================
// ===================================================================================================
void GameManager::BossStage2()
{
	int bossHitEffectTimer = 0;
	const int lifeCount = 3;
	playerInvincible = false;
	playerLife = 2;
	metaKnightLife = 19;

	PlaySound(TEXT("Kirby_Boss.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			_player->ActivateSpeedBoost();
		}

		//system("cls");

		HitBox();
		isCollide = false;


		cursorXY(75, 1);
		cout << "- ������ ��� ��Ÿ����Ʈ - ";

		// �ܻ� ����
		if (_boss->isAlive())
		{
			TextColor(0, 0);
			// ��Ÿ ����Ʈ�� ����(14)��ŭ �ݺ�
			for (int i = 0; i < 14; ++i) {
				cursorXY(_boss->getX(), _boss->getY() + i);
				// ��Ÿ ����Ʈ�� �ʺ�(18)���� �а� �������� ����
				cout << "                                    ";
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			Sleep(100);
			playerLife = 2;
			PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}

		_player->MoveLogic();
		_player->LaserLogic();
		_boss->MetaKnight();
		//_boss->BossLaserLogic();
		_boss->UpdatePattern2();
		_boss->RandMove();

		// boss �ǰ� �ִϸ��̼�
		if (_boss->isAlive())
		{
			if (_boss->isHit())
			{
				_dot->MetaKnightHit(_boss->getX(), _boss->getY());
				bossHitEffectTimer = 10;
				_boss->setHit(false);
			}
			else
			{
				_dot->MetaKnight(_boss->getX(), _boss->getY());
			}
		}

		if (bossHitEffectTimer > 0)
		{
			bossHitEffectTimer--;
		}

		// boss �ǰݹ��� ����
		if (bossInvincibleTimer)
		{
			bossInvincibleTimer--;
			if (bossInvincibleTimer <= 0)
			{
				bossInvincible = false;
			}
		}

		// plaer �ǰݹ��� ����
		if (playerInvincibleTimer)
		{
			playerInvincibleTimer--;
			if (playerInvincibleTimer <= 0)
			{
				playerInvincible = false;
			}
		}
		// playerLaser -> Boss �ǰ�
		for (size_t i = 0; i < _player->getLaser().size(); i++)
		{
			if (!_player->getLaser()[i].activate)
			{
				continue;
			}

			// laser ��Ʈ�ڽ�
			laserLeft = _player->getLaser()[i].x;
			laserRight = _player->getLaser()[i].x + 4;
			laserHeight = _player->getLaser()[i].y;

			if (_boss->isAlive() &&
				!bossInvincible &&
				laserLeft <= metaKnightRight &&
				laserRight >= metaKnightLeft &&
				laserHeight >= metaKnightTop &&
				laserHeight <= metaKnightBottom)
			{
				_player->getLaser()[i].activate = false;
				mciSendString(TEXT("play Kirby_BossDamage.wav from 0"), NULL, 0, NULL);
				cursorXY(_player->getLaser()[i].x, _player->getLaser()[i].y);
				TextColor(0, 0);
				cout << "    "; // ������ ũ��(2ĭ)��ŭ �������� ����

				if (metaKnightLife > 0 && metaKnightLife < 20)
				{
					bossHitEffectTimer = 5;
					_boss->MetaKnightHit();
					metaKnightLife--;
					bossInvincible = true;
					bossInvincibleTimer = 10;
				}
				else
				{
					PlaySound(NULL, 0, 0);
					_boss->Die();
					_boss->MetaKnightClear();
					system("cls");
					StageClear[3] = true;
					_screenDot->GameOver();
					mciSendString(TEXT("play Kirby_StageClear.wav from 0"), NULL, 0, NULL);
					system("cls");
					Sleep(3000);
					return;
				}
				// if ����
			}
			// for�� ����
		}

		// BossLaser->player �ǰ�

		vector<BossProjectile>& projectiles = _boss->getBossProjectile();

		for (size_t i = 0; i < projectiles.size(); ++i)
		{
			if (projectiles[i].activate)
			{
				cursorXY(projectiles[i].x, projectiles[i].y);
				TextColor(0, 0);
				cout << "  ";
			}
		}

		_boss->BossLaserLogic();

		for (size_t i = 0; i < projectiles.size(); ++i)
		{
			if (projectiles[i].activate)
			{
				cursorXY(projectiles[i].x, projectiles[i].y);
				TextColor(11, 0);
				cout << "��";
				TextColor(15, 0);

				if (!playerInvincible &&
					projectiles[i].x >= playerLeft &&
					projectiles[i].x <= playerRight &&
					projectiles[i].y >= playerTop &&
					projectiles[i].y <= playerBottom)
				{
					projectiles[i].activate = false;
					isCollide = true;
				}
			}
		}

		// Boss->player �ǰ�
		if (!playerInvincible &&
			_boss->isAlive() &&
			playerRight >= metaKnightLeft && 
			playerLeft <= metaKnightRight && 
			playerBottom >= metaKnightTop && 
			playerTop <= metaKnightBottom)   
		{
			isCollide = true;
		}

		// metaKnightLife ü�� ǥ��
		for (int i = 0; i < metaKnightLife + 1; i++)
		{
			TextColor(4, 4);
			cursorXY(67 + i * 2, 2);
			printf("��");
			TextColor(15, 0);
		}
		for (int i = metaKnightLife + 1; i < 20; i++)
		{
			TextColor(8, 8);
			cursorXY(67 + i * 2, 2);
			printf("��");
			TextColor(15, 0);
		}

		// �÷��̾� �ǰ� ����
		if (isCollide && !playerInvincible)
		{
			mciSendString(TEXT("play Kirby_Hit.wav from 0"), NULL, 0, NULL);
			if (playerLife > 0 && playerLife <= 3)
			{
				_player->PlayerHit();
				playerLife--;
				playerInvincible = true;
				playerInvincibleTimer = 10;
			}
			else
			{
				PlaySound(NULL, 0, 0);
				_player->Die();
				_player->GameOverHit();
				Sleep(1000);
				system("cls");
				_screenDot->GameOver();
				mciSendString(TEXT("play Kirby_GameOver.wav from 0"), NULL, 0, NULL);
				Sleep(4000);
				system("cls");
				PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			}
		}

		// �÷��̾� ü�� ǥ�� ��Ʈ
		for (int i = 0; i < playerLife + 1; i++)
		{
			_dot->Life(1 + i * 11, 45);
		}
		for (int i = playerLife + 1; i < lifeCount; i++)
		{
			_dot->LifeDec(1 + i * 11, 45);
		}

		if (_player->getSkillCooldown() > 0)
		{
			// ��Ÿ���� ���� ���� ��
			_dot->PowerUpCooldown(35, 45);
		}
		else
		{
			// ��ų�� ����� �� ���� ��
			_dot->PowerUp(35, 45);
		}

		Sleep(10);
	}
}
// ==============================   HitBox   ============================
void GameManager::HitBox()
{
	// player��Ʈ�ڽ�
	playerLeft = _player->getX() + 1;
	playerRight = _player->getX() + 12;
	playerTop = _player->getY() + 1;
	playerBottom = _player->getY() + 4;

	//// enemy ��Ʈ�ڽ�
	//enemyLeft = _enemy->getX();
	//enemyRight = _enemy->getX() + 8;
	//enemyTop = _enemy->getY();
	//enemyBottom = _enemy->getY() + 5;

	// Daroach ��Ʈ�ڽ�
	daroachLeft = _boss->getX() + 1;
	daroachRight = _boss->getX() + 12;
	daroachTop = _boss->getY() + 1;
	daroachBottom = _boss->getY() + 15;

	// MetaKnight ��Ʈ�ڽ�
	metaKnightLeft = _boss->getX();
	metaKnightRight = _boss->getX() +18;
	metaKnightTop = _boss->getY() + 1;
	metaKnightBottom = _boss->getY() + 13;

}

// ====================== player - trashMob �浹		=====================
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
