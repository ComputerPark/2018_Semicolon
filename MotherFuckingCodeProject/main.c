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
}

int main() {
	init();
	title();
	control();
	return DEF_RET_VAL;
}