#include "fucking_header.h"
/*
#define BULLET ";"	//�Ѿ��� �����ݷ����� �ٲٸ� �� ����. ������ ��� �Ѿ��� �̰ɷ� �ٲ�߰���.
#define BULLET "��"
#define BULLET "^"
#define BULLET "��"
#define BULLET "��"	//�Ѿ� ��� �������ҵ�...
*/
#define BULLET "��"

void drawPlayer(void)
{
	prn_xy("��", Player.posx, Player.posy, CR_LGREEN, CR_BLACK, false);
}

void drawBullet(int i)
{
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy, CR_TURQ, CR_BLACK, false);
	prn_xy(BULLET, Pl_Bullet[i].posx, Pl_Bullet[i].posy + 1, CR_TURQ, CR_BLACK, false);
}

void FuckthoseCvalnomeuEnemy(void)
{
	int index = 0;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (Pl_Bullet[i].isused == 0)
		{
			index = i;
			break;
		}
	}

	Pl_Bullet[index].isused = 1;
	Pl_Bullet[index].posx = Player.posx;
	Pl_Bullet[index].posy = Player.posy;
}

int chkLvClear() { //����� �۵�����.
	int chk = 0;
	for (int i = 0; i <= MAX_ENEMY; i++) {
		if (Enemy[i].health == 0) {
			chk++;
		}
	}
	if (chk > 9999) {
		return 1;
	}
	
	return 0;
	
}

void control(void)
{
	int ps_tmp = 1, bl_tmp = 1;
	Round = 1;


	//for (int i = 0; i <= MAX_ENEMY; i++) {
		//spawnEnemy(i, (2+i), 5, (i+1));
	//}
	
	//�÷��̾� ���� �ݵ�� 3�� ����
	/*
	spawnEnemy(0, 20, 4, 3);
	spawnEnemy(1, 23, 4, 3);
	spawnEnemy(2, 26, 4, 3);

	spawnEnemy(3, 19, 6, 2);
	spawnEnemy(4, 22, 6, 2);
	spawnEnemy(5, 25, 6, 2);
	spawnEnemy(6, 28, 6, 2);
	*/
	for (int i = 0; i < 10; i++) {
		spawnEnemy(i, 20+(i*3), 4, 3);
	}
	for (int i = 10; i < 20; i++) {
		spawnEnemy(i, 20 + ((i - 10) * 3), 6, 2);
	}
	for (int i = 20; i < 30; i++) {
		spawnEnemy(i, 20 + ((i - 20) * 3), 8, 1);
	}
	

	Player.posx = 40;
	Player.posy = 26;
	while (true)
	{
		

		drawEnemy();
		
		//�ù� ������ break�������� continue�� ����� ���� �װŶ��� 2�ð����� ����� �־��ݾ�
		//�������!!!!!!!
		for (int i = 0; i < MAX_BULLET; i++)
		{
			if (Pl_Bullet[i].isused == false) {
				continue;
			}

			if (Pl_Bullet[i].posy < 1)
			{
				Pl_Bullet[i].isused = 0;
				continue;
			}

			for (int j = 0; j < MAX_ENEMY; j++)
			{
				if (Enemy[j].health == 0)
					continue;
				if (Pl_Bullet[i].posx == Enemy[j].posx && (Pl_Bullet[i].posy == Enemy[j].posy))
				{
					Pl_Bullet[i].isused = 0;
					Enemy[j].health--;
				}
			}

			if (Pl_Bullet[i].isused == true)
			{
				Pl_Bullet[i].posy--;

				drawBullet(i);
			}
		}

		

		for (int i = 0; i < 100; i++)
		{
			if (En_Bullet[i].isused == false)
				continue;

			if (En_Bullet[i].posy >= 29)
			{
				En_Bullet[i].isused = 0;
				continue;
			}

			if (En_Bullet[i].posx == Player.posx && En_Bullet[i].posy == Player.posy)
			{
				En_Bullet[i].isused = 0;
				Player.health--;
			}
		}
		

		if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && !(Player.posx < 3)) {
			if (ps_tmp == 1) {
				Player.posx--;
				ps_tmp++;
			}
			else {
				ps_tmp++;
			}
			
		}
		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(Player.posx > 77)) {
			if (ps_tmp == 1) {
				Player.posx++;
				ps_tmp++;
			}
			else {
				ps_tmp++;
			}
		}
		if (GetAsyncKeyState(KB_SPACE) && bl_tmp == 1)
			FuckthoseCvalnomeuEnemy();
		
		bl_tmp++;

		if (bl_tmp > 7) bl_tmp = 1;

		if (ps_tmp > 4) ps_tmp = 1;
		drawPlayer();

		system("cls");
		//if (chkLvClear) {
		//	LevelClear();
		//}
	}
}