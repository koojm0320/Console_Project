#include "Enemy.h"
#include "Common.h"

Enemy::Enemy()
{
	_dot = new Dot;
	_alive = true;
	_y = 0;
	_x = 0;
}

Enemy::~Enemy()
{
	delete _dot;
}

void Enemy::EnemySpawnLogic()
{
	static int enemySpawnTimer = 0;
	enemySpawnTimer++;
	if (enemySpawnTimer >= 40)
	{
		int randY = rand() % 40 + 1;
		_trashMob.push_back(TrashMob(170, randY));
		enemySpawnTimer = 0;
	}

	for (size_t i = 0; i < _trashMob.size(); ++i)
	{
		if (_trashMob[i].isAlive)
		{
			int oldX = _trashMob[i].x;
			int oldY = _trashMob[i].y;

			TextColor(0, 0);
			for (int row = 0; row < 8; ++row)
			{
				cursorXY(oldX, oldY + row);
				cout << "            ";
			}
			_trashMob[i].x -= 1;
			int dir = rand() % 3 - 1;
			_trashMob[i].y += dir;
		}
		if (_trashMob[i].x < 1)
		{
			_trashMob[i].isAlive = false;
		}

		if (_trashMob[i].y < 1) _trashMob[i].y = 1;
		if (_trashMob[i].y > 44 - 5) _trashMob[i].y = 44 - 5;

		if (_trashMob[i].isAlive)
		{
			_dot->WaddleDee(_trashMob[i].x, _trashMob[i].y);
		}
	}

	/*
	for (size_t i = 0; i < _trashMob.size(); ++i)
	{
		if (_trashMob[i].isAlive)
		{
			_dot->WaddleDee(_trashMob[i].x, _trashMob[i].y);
		}
	}
	*/
}


vector<TrashMob>& Enemy::getTrashMob()
{
	return _trashMob;
}

void Enemy::EnemyUpdate()
{

}

void Enemy::ResetEnemy()
{
	
}
