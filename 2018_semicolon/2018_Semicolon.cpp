/*
Hell O, world! (Codeneme Semicolon)
-헬, 오 월드! (코드네임 세미콜론)
이 프로그램은 4명의 코더들의 발로 코딩했음
앙, goto띠
FUCKYOU!!!
포인터 X까
-(c) 2018 Semicolon team;
*/


// 2018_Semicolon.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "main.h"


Jet Enemy[(MAX_ENEMY + 2)];
Jet Player;
Bullet Pl_Bullet[MAX_BULLET + 2];
Bullet En_Bullet[MAX_ENEMY_BULLET];
int Round; //나중에 라운드에 따라 적 움직임 다양하게 만들거임. 물론 그러다가 내가 멘탈이 터져서 빡종할거같음.
HWND hwnd;
HDC hdc; //윈도우 핸들


void hidecursor() {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // true 보임 , false 안보임
	ConsoleCursor.dwSize = 1;       // 커서 사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void init() {

	system("title Hell, O world!");
	system("mode con cols=80 lines=30");
	hidecursor();
	for (int i = 0; i <= MAX_ENEMY; i++) {

		Enemy[i].health = 0;
		Enemy[i].posx = 0;
		Enemy[i].posy = 0;
		Enemy[i].level = 0;
	}
	for (int i = 0; i <= MAX_BULLET; i++) {

		Pl_Bullet[i].posx = 0;
		Pl_Bullet[i].posy = 0;
		Pl_Bullet[i].isused = false;


	}
	for (int i = 0; i <= MAX_ENEMY_BULLET; i++) {

		En_Bullet[i].posx = 0;
		En_Bullet[i].posy = 0;
		En_Bullet[i].isused = false;

	}
	Player.health = 3;
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(GetForegroundWindow());

	SoundInit();

}


int main() {
	init();

	start();

	return DEF_RET_VAL;
}
