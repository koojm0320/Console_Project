#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment (lib, "winmm.lib")

void cursorXY(int x, int y);
void TextColor(int font, int background);
