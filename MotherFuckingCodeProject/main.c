/*
Hell O, world! (Codeneme Semicolon)
-��, �� ����!
�� X���� ���α׷��� 4���� X���� �ڴ����� �߷� �ڵ�����
��, goto��
FUCKYOU!!!
������ X��
-(c) 2018 Semicolon team;
*/

#include "fucking_header.h"
#include "disclaimer.h"

void hidecursor() {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // true ���� , false �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ�� ������
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
	}

}

int main() {
	init();
	
	start();
	control();
	return DEF_RET_VAL;
}