#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>	 //�������
#include <time.h>
#include "disclaimer.h"
#include "key_define.h"
#include "color_HELL_NOGADA.h"


#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") //���� ���� �Լ���

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)




typedef int bool;
#define true 1
#define false 0

#define DEF_RET_VAL 0 //����Ʈ ���� ���
//#define PROGRAM_VERSION "0.8.2_r4" //0.month.day_revision

#define DEFAULT_TXT_COLOR CR_WHITE 
#define DEFAULT_BG_COLOR CR_BLACK 

#define MAX_ENEMY 50
#define MAX_BULLET 50

typedef struct _Bullet {
	int posx;
	int posy;
	bool isused;
}Bullet;



typedef struct _Jet {
	int posx;
	int posy;
	int health;
	int level;
}Jet;


Jet Enemy[(MAX_ENEMY+2)];
Jet Player;
Bullet Pl_Bullet[MAX_BULLET+2];
Bullet En_Bullet[100];
int Round;	//���߿� ���忡 ���� �� ������ �پ��ϰ� �������. ���� �׷��ٰ� ���� ��Ż�� ������ �����ҰŰ���.



void gotoxy(int x, int y);
int prn_xy(char *print, int x, int y, int txtcolor, int bgcolor, bool enter);

void init();
void hidecursor();

void load(void);

void drawPlayer(void);
void drawBullet(int i);
void title(void);
void start(void);


void control(void);
void FuckthoseCvalnomeuEnemy(void);

void FuckThoseCvalnomeuPlayer(void);	//���ڰ� ���� ��� ���� �Ѳ����� ��°���. ����?
void drawEnemy(void);	//���ڰ� ���� �� ��� ���� �ѹ��� ����ϴ� �����.
void spawnEnemy(int index_of_Enemy, int x, int y, int level);	//�Ѿ� ����°Ŷ� �Ȱ��� ������� �������. � �ε����� ���� �ִ��� ������ Ȯ���� Jet.health�� 0���� �ƴ����� �Ǵ�. ����� ���庰�� ������ ������ ��ġ�� �밡�ٷ� ������ ������ֱ� �ٶ�����. �ε����� ���ڷ� �޴� ������ ������ �ε������� �����̴� �˵��� �ٸ��� ����.  ���������ڴ� 0�� ����, 1�� ��������.

int chkAliveEnemy(void);
void LevelClear(void);

void gameOver(void);

HWND hwnd;
HDC hdc; //������ �ڵ�

/*
void start(void);
void help(void);
void EndScreen(void);
*/

