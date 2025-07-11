#include "Enemy.h"
#include "Common.h"

Enemy::Enemy()
{
	_dot = new Dot;
	_alive = true;
}

Enemy::~Enemy()
{
	delete _dot;
}

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
	// TODO: 여기에 return 문을 삽입합니다.
	return _trashMob;
}

