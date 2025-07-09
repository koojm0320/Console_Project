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
}

Boss::~Boss()
{
	delete _dot;
}


void Boss::Daroach()
{
	_x = 150;
	_y = 16;
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
		
			if (_bossProjectile[i].x < 0 || 
				_bossProjectile[i].x > 180 || 
				_bossProjectile[i].y < 0 || 
				_bossProjectile[i].y > 180)
			{
				_bossProjectile[i].activate = false;
			}
		}
	}
}

void Boss::UpdatePattern()
{
	_patternTimer = 0;
	if (_patternTimer > 100)
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
// 일직선 발사
void Boss::BossPattern1()
{
	static double angle = 0.0;
	if (_patternTimer % 30 == 0)
	{
		double speed = 2.0;

		double dx = cos(angle) * speed;
		double dy = sin(angle) * speed;
		_bossProjectile.push_back(BossProjectile(_x, _y + 8, dx, dy));

		angle += 0.5;

		/*if (angle > 90)
		{
			angle -= 0.5;
		}
		else if (angle < -90)
		{
			angle += 0.5;
		}*/
	}
}

// 나선형 발사
void Boss::BossPattern2()
{
	if (_patternTimer % 60 == 0)
	{
		_bossProjectile.push_back(BossProjectile(_x, _y + 8, -3.0, 0.0));
	}
}


vector<BossProjectile>& Boss::getBossProjectile()
{
	// TODO: 여기에 return 문을 삽입합니다.
	return _bossProjectile;
}


