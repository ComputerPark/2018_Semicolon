/*
ä���� ����� ���α׷�

Hell O, world!
-��, �� ����!

�� ������ ���Τ����� 4���� X�� ���� �������.
ä���ڴ� �� X���� ���α׷��� ���� X�� �ִ��� �˰� �Ǳ� �ٶ�.(�ױ� ����)
�߷� �ڵ�����

��, goto��
�������� �� X��
����?? ^^

FUCKYOU!!!
������ ����
*/


#include "fucking_header.h"
#include "disclaimer.h"

void hidecursor() {
	// <!---------------console cursor settings--------->
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // true ���� , false �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ�� ������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
	// <!---------------console cursor settings end----->
}
void init() {
	system("title Hell, O world!");
	system("mode con cols=80 lines=30");
	hidecursor();
}

int main() {
	
	init();
	
	intro();
	control();
	return DEF_RET_VAL;

}
