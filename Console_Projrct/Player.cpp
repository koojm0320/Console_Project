#include "Player.h"
#include "Common.h"

Player::Player()
{
	_isMove = false;
	_alive = true;
	_dot = new Dot;
	_x = 1;
	_y = 1;
	oldX = _x;
	oldY = _y;

	_isSpeedUp = false;
	_speedUpTimer = 0;
	_skillCooldown = 0;
}

Player::~Player()
{
	delete _dot;
}


void Player::MoveLogic()
{
	cursorXY(_x, _y);

	UpdatePlayerMove();

	// player �̵�
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		_x -= 2;
		_isMove = true;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		_x += 2;
		_isMove = true;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		--_y;
		_isMove = true;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		++_y;
		_isMove = true;
	}
	// �÷��̾� �̵� ���� ����
	if (_x < 1) _x = 1;
	if (_x > 166) _x = 166;
	if (_y < 1) _y = 1;
	if (_y > 42) _y = 42;

	if (_isMove)
	{
		for (int i = 0; i < 9; ++i)
		{
			cursorXY(oldX - 1, oldY - 1 + i);
			TextColor(0, 0);
			cout << "         ";
		}
	}

	_dot->kirby(_x, _y);

	UpdateSkillTimers();

	
}

void Player::UpdatePlayerMove()
{
	if (GetAsyncKeyState(VK_LEFT)||
		GetAsyncKeyState(VK_RIGHT)||
		GetAsyncKeyState(VK_UP)||
		GetAsyncKeyState(VK_DOWN))
	{
		_isMove = true;
	}
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
			cursorXY(_laser[i].x, _laser[i].y);
			TextColor(0, 0);
			cout << "     "; // ������ ũ��(2ĭ)��ŭ �������� ����
		}

		_laser[i].x += 4;

		if (_laser[i].x > 180)
		{
			_laser[i].activate = false;
		}

		if (_laser[i].activate)
		{
			cursorXY(_laser[i].x, _laser[i].y);
			TextColor(6, 6);
			cout << "����";
		}
	}

	//for (size_t i = 0; i < _laser.size(); ++i)
	//{
	//	if (_laser[i].activate)
	//	{
	//		cursorXY(_laser[i].x, _laser[i].y);
	//		TextColor(6, 6);
	//		cout << "����";
	//		cursorXY(_laser[i].x - 4, _laser[i].y);
	//		TextColor(0, 0);
	//		cout << "    ";
	//	}
	//}
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
	// TODO: ���⿡ return ���� �����մϴ�.
	return _laser;
}

void Player::ActivateSpeedBoost()
{
	if (_skillCooldown == 0)
	{
		mciSendString(TEXT("play Kirby_PowerUp.wav from 0"), NULL, 0, NULL);
		_isSpeedUp = true;
		_speedUpTimer = 150;   // 5�ʰ� ���� (60������ ����)
		_skillCooldown = 300;  // 10���� ��Ÿ�� ���� (60������ ����)
	}
}

void Player::UpdateSkillTimers()
{
	if (_speedUpTimer > 0)
	{
		_speedUpTimer--;
		if (_speedUpTimer == 0)
		{
			_isSpeedUp = false; // ���ӽð��� ������ ȿ�� ����
		}
	}

	// ��ų ��Ÿ�� ����
	if (_skillCooldown > 0)
	{
		_skillCooldown--;
	}

	TextColor(0, 11);
	cursorXY(34, 44);
	printf("��Ÿ��: %.1fs", _skillCooldown / 30.0);
	TextColor(15, 0);
}


void Player::Die()
{
	_alive = false;
}