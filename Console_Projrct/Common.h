#pragma once
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")

// ������Ʈ���� ���ݿ��� ���������� ����ϴ� �Լ��� ��Ƴ��� ����.
// �ܼ� Ŀ�� ��ġ ���� �Լ�, �ؽ�Ʈ ���� ���� �Լ�, ���� ���� ���̺������ �����ϰ� ����.
void cursorXY(int x, int y);
void TextColor(int font, int background);
