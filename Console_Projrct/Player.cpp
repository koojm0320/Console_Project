#include "Player.h"
#include "Common.h"

Player::Player()
{
	_alive = true;
	_dot = new Dot;
	_x = 1;
	_y = 1;
}

Player::~Player()
{
	delete _dot;
}


void Player::MoveLogic()
{
	cursorXY(_x, _y);

	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//	system("pause");

	// player 이동
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) _x -= 2;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) _x += 2;
	if (GetAsyncKeyState(VK_UP) & 0x8000) --_y;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) ++_y;

	// 플레이어 이동 범위 제한
	if (_x < 1) _x = 1;
	if (_x > 166) _x = 166;
	if (_y < 1) _y = 1;
	if (_y > 44) _y = 44;

	UpdateSkillTimers();
	_dot->kirby(_x, _y);
	
}


void Player::LaserLogic()
{
	static int laserFireTimer = 0;
	laserFireTimer++;

	int fireInterval = _isSpeedUp ? 15 : 30;

	if (laserFireTimer >= fireInterval)
	{
		_laser.push_back(Laser(_x + 12, _y + 2));
		mciSendString(TEXT("play Kirby_Laser.wav from 0"), NULL, 0, NULL);
		laserFireTimer = 0;
	}

	for (size_t i = 0; i < _laser.size(); ++i)
	{
		if (_laser[i].activate)
		{

			_laser[i].x += 4;
		}
		if (_laser[i].x > 180)
		{
			_laser[i].activate = false;
		}
	}

	for (size_t i = 0; i < _laser.size(); ++i)
	{
		if (_laser[i].activate)
		{
			cursorXY(_laser[i].x, _laser[i].y);
			TextColor(6, 6);
			cout << "ㅁㅁ";
			TextColor(15, 0);
		}
	}
}


void Player::PlayerHit()
{
	_dot->kirbyHit(_x, _y);
	Sleep(100);
	_dot->kirby(_x, _y);
}

void Player::GameOverHit()
{
	_dot->kirbyHit(_x, _y);
	Sleep(500);
}

vector<Laser>& Player::getLaser()
{
	// TODO: 여기에 return 문을 삽입합니다.
	return _laser;
}

void Player::ActivateSpeedBoost()
{
	if (_skillCooldown == 0)
	{
		mciSendString(TEXT("play Kirby_PowerUp.wav from 0"), NULL, 0, NULL);
		_isSpeedUp = true;
		_speedUpTimer = 150;   // 5초간 지속 (60프레임 기준)
		_skillCooldown = 300;  // 10초의 쿨타임 설정 (60프레임 기준)
	}
}

void Player::UpdateSkillTimers()
{
	if (_speedUpTimer > 0)
	{
		_speedUpTimer--;
		if (_speedUpTimer == 0)
		{
			_isSpeedUp = false; // 지속시간이 끝나면 효과 종료
		}
	}

	// 스킬 쿨타임 감소
	if (_skillCooldown > 0)
	{
		_skillCooldown--;
	}

	TextColor(0, 11);
	cursorXY(34, 44);
	printf("쿨타임: %.1fs", _skillCooldown / 30.0);
	TextColor(15, 0);
}


void Player::Die()
{
	_alive = false;
}