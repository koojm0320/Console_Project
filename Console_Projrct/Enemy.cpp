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
//		// 왼쪽 벽으로 가면 오른쪽으로 좌표를 재설정
//		// 나중에 바꿔야 함
//		// 도트 없애기
//		_x = 170;
//		_y = rand() % 45;
//	}
//	else
//	{
//		_dot->WaddleDee(_x, _y);
//	}
//}
//
//// 리스폰
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
	// TODO: 여기에 return 문을 삽입합니다.
	return _trashMob;
}

