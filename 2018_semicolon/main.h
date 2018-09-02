#pragma once
#include "stdafx.h"

#ifndef MAIN
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

//typedef int bool;
//#define true 1
//#define false 0

#define DEF_RET_VAL 0 //����Ʈ ���� ���
#define ERR_RET_VAL 1 //���� �߻� �� ���� ��� �ڵ鸵.
//#define PROGRAM_VERSION "0.8.2_r4" //0.month.day_revision

#define DEFAULT_TXT_COLOR CR_WHITE
#define DEFAULT_BG_COLOR CR_BLACK

#define MAX_ENEMY 50
#define MAX_BULLET 50
#define MAX_ENEMY_BULLET 50


#pragma once
typedef struct _Bullet {
	int posx;
	int posy;
	bool isused;
} Bullet;


typedef struct _Jet {
	int posx;
	int posy;
	int health;
	int level;
} Jet;


extern Jet Enemy[(MAX_ENEMY + 2)];
extern Jet Player;
extern Bullet Pl_Bullet[MAX_BULLET + 2];
extern Bullet En_Bullet[MAX_ENEMY_BULLET];
extern int Round; //���߿� ���忡 ���� �� ������ �پ��ϰ� �������. ���� �׷��ٰ� ���� ��Ż�� ������ �����ҰŰ���.

extern HWND hwnd;
extern HDC hdc; //������ �ڵ�


#define MAIN

#endif


int main(); //������ �Ǽ�
void gotoxy(short x, short y);
int prn_xy(const char print[], int x, int y, int txtcolor, int bgcolor, bool enter);
int prn_xy(int print, int x, int y, int txtcolor, int bgcolor, bool enter);

void init();
void hidecursor();

void load(void);

void drawPlayer(void);
void drawBullet(int i);      //�÷��̾� �ҷ��� �׸��� �Լ�. �׸� �Ҹ��� �ε������� �Ѱܹ���.
void drawEnemyBullet(int i); //���ʹ� �ҷ��� �׸��� �Լ�. �׸� �Ҹ��� �ε������� �Ѱܹ���.

void title(void);
void start(void);


void control(void);
void FuckthoseCvalnomeuEnemy(void); //�Ѿ� �߻� ���� �Լ� (�÷��̾� -> ������)

void FuckThoseCvalnomeuPlayer(int i); //�Ѿ� �߻� ���� �Լ� (���ʹ� -> �÷��̾�). ���ڰ� i�� �Ѱܹ޾� i�� ���ʹ̰� �����ݷ��� �߻�.
void drawEnemy(void);                 //���ڰ� ���� �� ��� ���� �ѹ��� ����ϴ� �����.
void spawnEnemy(int index_of_Enemy, int x, int y, int level);
//�Ѿ� ����°Ŷ� �Ȱ��� ������� �������. � �ε����� ���� �ִ��� ������ Ȯ���� Jet.health�� 0���� �ƴ����� �Ǵ�. ����� ���庰�� ������ ������ ��ġ�� �밡�ٷ� ������ ������ֱ� �ٶ�����. �ε����� ���ڷ� �޴� ������ ������ �ε������� �����̴� �˵��� �ٸ��� ����.  ���������ڴ� 0�� ����, 1�� ��������.

int chkAliveEnemy(void);
void LevelClear(void);

void gameOver(int time, int score);

int debugScreen(void);


/*start*/
//void SetColor(int num);
void Flush_buffer(void);
void AddRank(int time, int score);
void RankReset(void);
void RankSort(void);
void FileLoad(void);
void FileSave(void);

void RankDraw(bool enternick);


void SoundInit(void);

void StopSound(void);
void VolumeSetSound(void);
void SoundUpdate(void);


void VolumeCtrl(void);
void Sound_Play(int n);
/*
void start(void);
void help(void);
void EndScreen(void);
*/
