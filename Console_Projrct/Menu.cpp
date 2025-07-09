#include "Menu.h"
#include "Common.h"


Menu::Menu()
{
	const int menuCount = 3;
	string menu[menuCount] = {
		"���� ����",
		"���� ����",
		"���� ����"
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
			if (i == select) cout << "�� ";
			else cout << "  ";
			
			cout << menu[i] << "  \n";
			TextColor(7, 0);
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			select--;
			if (select < 0) select = menuCount - 1;
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			select++;
			if (select >= menuCount) select = 0;
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
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
				cout << "�߸��� �Է��Դϴ�." << endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			cout << "������ �����մϴ�." << endl;
			return;
		}
	}
	Sleep(50);

}

Menu::~Menu()
{
	delete _stage;
	delete _screenDot;
}



void Menu::explane()
{
	system("cls");
	_screenDot->ExplaneScreen();

	TextColor(0, 12);
	cursorXY(81, 10);
	cout << "  HOW TO PLAY  \n";
	cursorXY(75, 15);
	cout << "  ����: ����Ű(��,��,��,��)  \n";
	cursorXY(80, 20);
	cout << "  ����: �ڵ� �߻�  \n";
	cursorXY(78, 25);
	cout << "  �������� ����: SPACE  \n";
	cursorXY(74, 30);
	cout << "  �ǵ��ư����� ESC�� ��������.  \n";

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			TextColor(7, 0);
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
}