#include "Enemy.h"
#include "Common.h"

Enemy::Enemy()
{
	_dot = new Dot;
	//_y = rand() % 45;
	//_x = 170;
	_alive = true;
}

Enemy::~Enemy()
{
	delete _dot;
}


//void Enemy::WaddleDee()
//{
//
//	srand(time(NULL));
//	--_x;
//
//	if (!_alive)
//	{
//		return;
//	}
//	//ResetEnemy();
//}
//
//void Enemy::WaddleDeeHit()
//{
//	_dot->WaddleDeeHit(_x, _y);
//	Sleep(50);
//	_dot->WaddleDee(_x, _y);
//}
//
//
//void Enemy::Die()
//{
//	_dot->WaddleDeeHit(_x, _y);
//	Sleep(50);
//	_dot->WaddleDee(_x, _y);
//	_alive = false;
//}

//void Enemy::ResetEnemy()
//{
//	if (_x < 1)
//	{
//		// ���� ������ ���� ���������� ��ǥ�� �缳��
//		// ���߿� �ٲ�� ��
//		// ��Ʈ ���ֱ�
//		_x = 170;
//		_y = rand() % 45;
//	}
//	else
//	{
//		_dot->WaddleDee(_x, _y);
//	}
//}
//
//// ������
//void Enemy::Respawn()
//{
//	_x = 170;
//	_y = rand() % 45;
//	_alive = true;
//}

void Enemy::EnemySpawnLogic()
{
	static int enemySpawnTimer = 0;
	enemySpawnTimer++;
	if (enemySpawnTimer >= 50)
	{
		int randY = rand() % 45 + 1;
		_trashMob.push_back(TrashMob(170, randY));
		enemySpawnTimer = 0;
	}

	for (size_t i = 0; i < _trashMob.size(); ++i)
	{
		if (_trashMob[i].isAlive)
		{
			_trashMob[i].x -= 1;
			int dir = rand() % 3 - 1;
			_trashMob[i].y += dir;
		}
		if (_trashMob[i].x < 1)
		{
			_trashMob[i].isAlive = false;
		}

		if (_trashMob[i].y < 1) _trashMob[i].y = 1;
		if (_trashMob[i].y > 44) _trashMob[i].y = 44;
	}

	for (size_t i = 0; i < _trashMob.size(); ++i)
	{
		if (_trashMob[i].isAlive)
		{
			_dot->WaddleDee(_trashMob[i].x, _trashMob[i].y);
		}
	}
}


vector<TrashMob>& Enemy::getTrashMob()
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return _trashMob;
}

