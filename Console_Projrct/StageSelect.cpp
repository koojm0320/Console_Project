#include "StageSelect.h"
#include "Common.h"



StageSelect::StageSelect()
{
	_stage = new Stage;
	_dot = new Dot;
	stageCount = 4;
	selectStage = 0;
}

StageSelect::~StageSelect()
{
	delete _dot;
	delete _stage;
}


void StageSelect::StageRun()
{


	while (true)
	{
		system("cls");

		cursorXY(70, 15);
		cout << "스테이지를 선택해 주세요. (SPACE로 선택)" << endl;

		for (int i = 0; i < stageCount; i++)
		{
			cursorXY(stagePosX[i], stagePosY);
			int stageNum = (i / 2) + 1;
			int levelNum = (i % 2) + 1;
			cout << stageNum << "-" << levelNum;
		}

		if (selectStage < 0) selectStage = 0;
		if (selectStage >= stageCount) selectStage = stageCount - 1;

		cursorXY(stagePosX[selectStage] - 3, stagePosY - 2);
		_dot->KirbyStageSelect(stagePosX[selectStage] - 3, stagePosY - 2);

		// 키 입력
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			selectStage--;
			Sleep(100);
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			selectStage++;
			Sleep(100);
		}
		else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			int stageNum = (selectStage / 2) + 1;
			int levelNum = (selectStage % 2) + 1;
			if (stageNum == 1)
			{
				if (levelNum == 1) _stage->Stage1_Level1();
				else if (levelNum == 2) _stage->Stage1_Boss();
				continue;
			}
			else if (stageNum == 2)
			{
				if (levelNum == 1) _stage->Stage2_Level1();
				else if (levelNum == 2) _stage->Stage2_Boss();
			}
			continue;
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			system("cls");
			Sleep(100);
			break;
		}

		Sleep(50);
	}
}
