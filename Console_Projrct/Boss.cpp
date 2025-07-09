#include "Boss.h"
#include "Common.h"



Boss::Boss()
{
	_alive = true;
	_dot = new Dot;
	_x = 0;
	_y = 0;

	shooterX = 0;
	shooterY = 0;
}

Boss::~Boss()
{
	delete _dot;
}


void Boss::Daroach()
{
	_x = 150;
	_y = 16;
	_dot->Daroach(_x, _y);

	if (!_alive)
	{
		return;
	}

	//Pattern1();
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
	_dot->DaroachHit(_x, _y);
	Sleep(100);
	_dot->Daroach(_x, _y);
}
void Boss::DaroachClear()
{
	_dot->DaroachHit(_x, _y);
	Sleep(2000);
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

void Boss::Pattern1()
{

}

void Boss::Die()
{
	_alive = false;
}