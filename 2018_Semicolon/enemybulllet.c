#include "fucking_header.h"

void spawnEnemy(int index_of_Enemy, int x, int y, int health) {
	//if (isRight) {
		Enemy[index_of_Enemy].posx = x;
		Enemy[index_of_Enemy].posy = y;
		Enemy[index_of_Enemy].health = health;
	//}
	/*
	else {
		Enemy[index_of_Enemy].posx = 3;
		Enemy[index_of_Enemy].posy = 5 - index_of_Enemy;
		Enemy[index_of_Enemy].health = 2;
	}
	*/
}

void drawEnemy(void) {
	for (int i = 0; i < MAX_ENEMY; i++) {
		/*
		if (Enemy[i].health == 0) {
			continue;
		}
		else {
			*/
		if (Enemy[i].health == 1) {
			prn_xy("��", Enemy[i].posx, Enemy[i].posy, CR_YELLOW, CR_BLACK, false);	//���� �����̶� ������ ��� ����� ������ ������� �������°� ���... �ּ����� ���� �ϸ� ������ �ǰ��� ���ּ�.   
		}
		else if (Enemy[i].health == 2) {
			prn_xy("��", Enemy[i].posx, Enemy[i].posy, CR_LRED, CR_BLACK, false);	//���� �����̶� ������ ��� ����� ������ ������� �������°� ���... �ּ����� ���� �ϸ� ������ �ǰ��� ���ּ�.  
		}
		else if (Enemy[i].health == 3) {
			prn_xy("��", Enemy[i].posx, Enemy[i].posy, CR_TURQ, CR_BLACK, false);	//���� �����̶� ������ ��� ����� ������ ������� �������°� ���... �ּ����� ���� �ϸ� ������ �ǰ��� ���ּ�.  
		}

			/*
			if (Enemy[i].posx - i > 60)	//���Ⱑ ���ư��� ����� �����ʿ� �ִ� ���̶� ���ʿ� �ִ� ���̶� ��Ī���� �������. ��Ȯ�� ����� ���� �׸� ���� ÷���ϰ���.
			{
				Enemy[i].posx--;
				Enemy[i].posy++;
			}

			else if (Enemy[i].posx - i > 40)
			{
				Enemy[i].posx--;
				Enemy[i].posy--;
			}

			else if (Enemy[i].posx - i < 20)
			{
				Enemy[i].posx++;
				Enemy[i].posy++;
			}

			else if (Enemy[i].posx - i < 40)
			{
				Enemy[i].posx++;
				Enemy[i].posy--;
			}
			*/
			
		//}
	}
}

void FuckThoseCvalnomeuPlayer(void)
{
	for (int i = 0; i < 20; i++)
	{
		if (Enemy[i].health == 0)
			break;

		else
		{
			for (int j = 0; j < 100; j++)
			{
				if (En_Bullet[j].isused == 1)
					break;

				else
				{
					En_Bullet[j].isused = 1;
					En_Bullet[j].posx = Enemy[i].posx;
					En_Bullet[j].posy = Enemy[i].posy;
				}
			}
		}
	}
}