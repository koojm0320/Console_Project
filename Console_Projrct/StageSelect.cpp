#include "StageSelect.h"
#include "Common.h"



StageSelect::StageSelect()
{
	_stage = new Stage;
	_dot = new Dot;
	_screenDot = new ScreenDot;
	stageCount = 4;
	selectStage = 0;
}

StageSelect::~StageSelect()
{
	delete _dot;
	delete _stage;
	delete _screenDot;
}


void StageSelect::StageRun()
{
	system("cls");

	int prevSelectStage = selectStage;
	while (true)
	{
		TextColor(15, 0);

		cursorXY(70, 15);
		cout << "���������� ������ �ּ���. (ENTER�� ����)" << endl;

		cursorXY(84, 48);
		cout << "�ڷΰ��� (ESC)";
		
		for (int i = 0; i < stageCount; i++)
		{
			cursorXY(stagePosX[i], stagePosY);
			int stageNum = (i / 2) + 1;
			int levelNum = (i % 2) + 1;
			cout << stageNum << "-" << levelNum;
		}
		if (prevSelectStage != selectStage)
		{
			TextColor(0, 0);
			// Ŀ�� Ŀ���� ����(5)��ŭ �ݺ��ϸ� �������� �����ϴ�.
			for (int i = 0; i < 5; ++i) {
				cursorXY(stagePosX[prevSelectStage] - 3, stagePosY - 2 + i);
				cout << "          "; // Ŀ�� �ʺ񺸴� �а� ���� ó��
			}
			prevSelectStage = selectStage;
		}

		_dot->KirbyStageSelect(stagePosX[selectStage] - 3, stagePosY - 2);

		// Ű �Է�
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_Keybord.wav from 0"), NULL, 0, NULL);
			selectStage--;
			if (selectStage < 0) selectStage = 0;
			Sleep(100);
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_Keybord.wav from 0"), NULL, 0, NULL);
			selectStage++;
			if (selectStage >= stageCount) selectStage = 3;
			Sleep(100);
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_Enter.wav from 0"), NULL, 0, NULL);
			if (selectStage > 0 && !GameManager::StageClear[selectStage - 1])
			{
				mciSendString(TEXT("play Kirby_NoEntry.wav from 0"), NULL, 0, NULL);
				cursorXY(68, 15);
				TextColor(4, 15);
				cout << "���� ���������� Ŭ�����ؾ� ���� �����մϴ�!";
				TextColor(15, 0);
				Sleep(1000);
				cursorXY(68, 15);
				cout << "                                           ";
				continue;
			}

			int stageNum = (selectStage / 2) + 1;
			int levelNum = (selectStage % 2) + 1;
			if (stageNum == 1)
			{
				PlaySound(NULL, 0, 0);
				if (levelNum == 1) _stage->Stage1_Level1();
				else if (levelNum == 2) _stage->Stage1_Boss();
				continue;
			}
			else if (stageNum == 2)
			{
				PlaySound(NULL, 0, 0);
				if (levelNum == 1) _stage->Stage2_Level1();
				else if (levelNum == 2)
				{
					_stage->Stage2_Boss();

					if (GameManager::StageClear[3] == true)
					{
						_screenDot->StageAllClear();
						mciSendString(TEXT("play Kirby_AllClear.wav from 0"), NULL, 0, NULL);
						cursorXY(70, 45);
						TextColor(15, 0);
						cout << "���� �޴��� ���ư��÷��� ESC�� �����ּ���";

						while (true)
						{
							if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
							{
								mciSendString(TEXT("play Kirby_ESC.wav from 0"), NULL, 0, NULL);
								system("cls");
								Sleep(100);
								PlaySound(TEXT("Kirby_Main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
								break;
							}
							Sleep(50);
						}
						break;
					}
				}
			}
			continue;
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			mciSendString(TEXT("play Kirby_ESC.wav from 0"), NULL, 0, NULL);
			system("cls");
			Sleep(100);
			break;
		}

		Sleep(50);
	}
}
