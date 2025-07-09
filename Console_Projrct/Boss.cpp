#include "Boss.h"
#include "Common.h"



Boss::Boss()
{
	_alive = true;
	_dot = new Dot;
	_x = 0;
	_y = 0;
	_isHit = false;

	shooterX = 0;
	shooterY = 0;

	_patternTimer = 0;
	_currentPattern = 0;

	_bossMoveTimer = 0;
}

Boss::~Boss()
{
	delete _dot;
}


void Boss::Daroach()
{
	_x = 150;
	// _y = 16;
	// _dot->Daroach(_x, _y);

	if (!_alive)
	{
		return;
	}

}

void Boss::MetaKnight()
{
	_x = 140;
	_y = 16;
	_dot->MetaKnight(_x, _y);

	if (!_alive)
	{
		return;
	}
}

void Boss::DaroachHit()
{
	//_dot->DaroachHit(_x, _y);
	//Sleep(100);
	//_dot->Daroach(_x, _y);
	_isHit = true;
}
void Boss::DaroachClear()
{
	_dot->DaroachHit(_x, _y);
	Sleep(500);
	_dot->Daroach(_x, _y);
	Sleep(1000);
}

void Boss::MetaKnightHit()
{
	_dot->MetaKnightHit(_x, _y);
	Sleep(100);
	_dot->MetaKnight(_x, _y);
}
void Boss::MetaKnightClear()
{
	_dot->MetaKnightHit(_x, _y);
	Sleep(2000);
}

void Boss::Die()
{
	_alive = false;
}

void Boss::BossLaserLogic()
{
	for (size_t i = 0; i < _bossProjectile.size(); ++i)
	{
		if (_bossProjectile[i].activate)
		{
			_bossProjectile[i].x += static_cast<int>(_bossProjectile[i].dx);
			_bossProjectile[i].y += static_cast<int>(_bossProjectile[i].dy);
		
			if (_bossProjectile[i].y < 1 || _bossProjectile[i].y > 45)
			{
				_bossProjectile[i].dy *= -1;
			}


			if (_bossProjectile[i].x < 1)
			{
				_bossProjectile[i].activate = false;
			}
		}
	}
}

void Boss::UpdatePattern()
{
	_patternTimer++;
	if (_patternTimer > 200)
	{
		_patternTimer = 0;
		_currentPattern = (_currentPattern + 1) % 2;
		_bossProjectile.clear();
	}

	switch (_currentPattern)
	{
	case 0:
		BossPattern1();
		break;
	case 1:
		BossPattern2();
		break;
	}
}
// ������ �߻�
void Boss::BossPattern1()
{
	static double verticalSpeed = 0.0;
	static int direction = 1;

	if (_patternTimer % 10 == 0)
	{
		double dx = -2.0;
		double dy = verticalSpeed;

		_bossProjectile.push_back(BossProjectile(_x - 10, _y + 8, dx, dy));

		verticalSpeed += 0.2 * direction;

		if (verticalSpeed > 1.5 || verticalSpeed < -1.5)
		{
			direction *= -1;
		}

	}
}

// ������ �߻�
void Boss::BossPattern2()
{
	if (_patternTimer % 40 == 0)
	{
		_bossProjectile.push_back(BossProjectile(_x, _y + 8, -3.0, -1.0));

		_bossProjectile.push_back(BossProjectile(_x, _y + 8, -3.0, 0.0));

		_bossProjectile.push_back(BossProjectile(_x, _y + 8, -3.0, 1.0));
	}
}

void Boss::RandMove()
{
	_bossMoveTimer++;

	if (_bossMoveTimer > 120)
	{
		_bossMoveTimer = 0;

		_y = (rand() % 26) + 5;
	}
}


vector<BossProjectile>& Boss::getBossProjectile()
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return _bossProjectile;
}


