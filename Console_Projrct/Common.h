#pragma once
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")

// 프로젝트에서 전반에서 공통적으로 사용하는 함수를 모아놓은 파일.
// 콘솔 커서 위치 제어 함수, 텍스트 색상 변경 함수, 사운드 관련 라이브버리를 포함하고 있음.
void cursorXY(int x, int y);
void TextColor(int font, int background);
