#include "Unit.h"
#include "Common.h"



Unit::Unit()
{
	_hp = 1;
	_atk = 0;
	_alive = true;
}

Unit::~Unit()
{
	// ¼Ò¸êÀÚ
}

void Unit::PlayerInfo()
{
	_hp = 3;
	_atk = 1;
	_alive = true;
}

void Unit::TrashMobInfo()
{
	_hp = 1;
	_atk = 1;
	_alive = true;
}

void Unit::BossInfo()
{
}

