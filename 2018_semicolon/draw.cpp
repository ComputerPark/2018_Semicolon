#include "stdafx.h"
#include "main.h"

/*
#define BULLET ";"	//�Ѿ��� �����ݷ����� �ٲٸ� �� ����. ������ ��� �Ѿ��� �̰ɷ� �ٲ�߰���.
#define BULLET "��"
#define BULLET "^"
#define BULLET "��"
#define BULLET "��"	//�Ѿ� ��� �������ҵ�...
*/
#define BULLET "��"
#define ENEMY_BULLET ";"

void drawPlayer(void) {
	/*
	for (int i = Player.posx*10-20; i <= Player.posx*10+20; i++) {
	for (int j = Player.posy*15+100; j <= Player.posy*15+120; j++)
	{

	SetPixel(hdc, i, j, RGB(0, 255, 255));     // ���� ��´�. RGB( , , )���� ���� ���� �޶�����.
	}
	}
	*/
	prn_xy("��", Player.posx, Player.posy, CR_LGREEN, CR_BLACK, false);
}


void drawBullet(int i) {
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_TURQ, CR_BLACK, false);
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy + 1, CR_TURQ, CR_BLACK, false);
}

void drawEnemyBullet(int i) {
	prn_xy(ENEMY_BULLET, En_Bullet[i].posx, En_Bullet[i].posy, CR_TURQ, CR_BLACK, false);
	prn_xy(ENEMY_BULLET, En_Bullet[i].posx, En_Bullet[i].posy - 1, CR_TURQ, CR_BLACK, false);
}
