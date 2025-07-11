#include "Menu.h"
#include "Common.h"


Menu::Menu()
{
	const int menuCount = 3;
	string menu[menuCount] = {
		"게임 시작",
		"게임 설명",
		"게임 종료"
	};

	int select = 0;

	printMenu();

	while (true)
	{
		cursorX = 85;
		cursorY = 40;

		for (int i = 0; i < menuCount; i++)
		{
			TextColor(0, 10);
			cursorXY(cursorX, cursorY + i - 1);
			if (i == select) cout << "▶ ";
			else cout << "  ";
			
			cout << menu[i] << "  \n";
			TextColor(15, 0);
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_Keybord.wav from 0"), NULL, 0, NULL);
			select--;
			if (select < 0) select = menuCount - 1;
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_Keybord.wav from 0"), NULL, 0, NULL);
			select++;
			if (select >= menuCount) select = 0;
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_Enter.wav from 0"), NULL, 0, NULL);
			if (select == 0)
			{
				_stageSelect = new StageSelect;
				_stageSelect->StageRun();
				system("cls");
				_screenDot->MainScreen();
				continue;
			}
			else if (select == 1)
			{
				explane();
				system("cls");
				_screenDot->MainScreen();
				continue;
			}
			else if (select == 2)
			{
				break;
			}
			else
			{
				cout << "잘못된 입력입니다." << endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			cout << "게임을 종료합니다." << endl;
			return;
		}
	}
	Sleep(50);

}

Menu::~Menu()
{
	// !
}



void Menu::explane()
{
	system("cls");
	_screenDot->ExplaneScreen();
	TextColor(15, 0);
	cursorXY(84, 20);
	cout << "커비 슈팅 게임 !";
	cursorXY(72, 22);
	cout << "커비의 보물을 뺏어간 악당을 물리쳐 주세요 !";
	TextColor(0, 15);
	cursorXY(72, 25);
	cout << "조작법 : 방향키 ( ←  →  ↑  ↓ )";
	cursorXY(72, 27);
	cout << "기본 공격 : 자동 공격";
	cursorXY(72, 29);
	cout << "기본 스테이지: 정해진 몹 수를 처지하면 클리어 !";
	cursorXY(72, 31);
	cout << "보스 스테이지: 보스의 체력이 0이 되면 클리어 !";
	
	TextColor(15, 0);
	cursorXY(75, 48);
	cout << "  메인 메뉴로 돌아가려면 ESC를 누르세요 ";
	
	
	while (true)
	{
	
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_ESC.wav from 0"), NULL, 0, NULL);
			TextColor(15, 0);
			system("cls");
			break;
		}
	
		Sleep(50);
	}

}

void Menu::printMenu()
{
	_screenDot = new ScreenDot;
	_screenDot->MainScreen();
	PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}