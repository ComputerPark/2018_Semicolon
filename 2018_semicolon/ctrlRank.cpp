/*
 * Original Source File by lghlove0509, Modded by Computerpark.
 * See Here: https://m.blog.naver.com/PostView.nhn?blogId=lghlove0509&logNo=220815708116&proxyReferer=http%3A%2F%2Fblog.naver.com%2FPostView.nhn%3FblogId%3Dlghlove0509%26logNo%3D220814680325
 * Big Thx to lghlove0509
 * Luv Your Code!
 */


#include "stdafx.h"
#include "main.h"



struct info {
	char name[10];
	int time;
	int score;
};

struct info rank[11];


/*�Է¹��� ����� �Լ�*/
void Flush_buffer(void)
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
/*������ ���� �� ����� �̸��� ����,�ð��� ��ŷ�� ����*/
void AddRank(int time, int score)
{
	RankDraw(true); //�ݵ�� ���� ȣ��
	system("pause");
	system("cls");
	Flush_buffer();
	gotoxy(33, 13);
	printf("�г���:");
	gotoxy(41, 13);
	scanf("%s",rank[10].name);
	//fgets(rank[10].name, 10, stdin);
	//system("pause");
	rank[10].time = time;
	rank[10].score = score;
	RankSort();
	FileSave();
	RankDraw(false);
}


void RankReset(void)
{
	int i;
	for (i = 0; i<11; i++)
		rank[i].score = 0; //������ 0���� ���·� ������ �����ϸ� �ð�,����,�̸��� ��� �ʱ�ȭ��	
	FileSave();
}


/*������ ���� ��ũ ����*/
void RankSort(void) //ranksort�Լ��� �� �̻��� �Էµ� ���¿��� ȣ���ϼ��� [���͹�]
{
	int i, j, cnt = 0;
	struct info temp;

	for (i = 0; i<10; i++)
	{
		for (j = 0; j<11; j++)
		{
			if(rank[j].time > 100000) {
				rank[j].score = 0;
				rank[j].time = 0;
				rank[j].name[10] = NULL;
			}
			if (rank[j].score < rank[j + 1].score)
			{
				temp = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = temp;
			}
			if (rank[j].score == rank[j+1].score) {
				if(rank[j].time > rank[j+1].time) {
					temp = rank[j];
					rank[j] = rank[j + 1];
					rank[j + 1] = temp;
				}
			}

		}
	}
	FileSave();
}


/*������ ���� ����Ǿ��ִ� �����͸� �ҷ���*/
void FileLoad(void)
{
	int i;
	FILE *savefile;

	savefile = fopen(".\\savefile\\rank.dat", "r");


	if (savefile == NULL) { //���� or ���� ������ ���� ���� 
		savefile = fopen(".\\savefile\\rank.dat", "a");
		fclose(savefile);
		return;
	}


	for (i = 0; i<10; i++)
		fscanf(savefile, "%d %d %s\n", &rank[i].time, &rank[i].score, &rank[i].name);

	fclose(savefile);
}


/*������ ���� TOP 10�� ��ŷ��� �� ����*/
void FileSave(void)
{
	int i;
	FILE *savefile;
	savefile = fopen(".\\savefile\\rank.dat", "w");

	for (i = 0; i<10; i++) {
		if (rank[i].score == 0) //������ 0���̸�
			fprintf(savefile, "0 0 ---\n");
		else
			fprintf(savefile, "%d %d %s\n", rank[i].time, rank[i].score, rank[i].name);
	}
	fclose(savefile);
}





void RankDraw(bool enternick)
{
	system("mode con cols=80 lines=40");
	const int x = 16;
	int i;

	FileLoad();
	RankSort();

	
	if(enternick==false) {
		prn_xy("ESC : ������", 50, 38, CR_WHITE, CR_BLACK, false);
		prn_xy("DELETE : ��ŷ �ʱ�ȭ", 10, 38, CR_RED, CR_BLACK, false);
		prn_xy("[��ŷ]", 21, 2, CR_TURQ, CR_BLACK, false);

		for (i = 0; i<10; i++) {
			//if (i == 0) SetColor(14);
			gotoxy(x, (i + 1) * 3 + 1);
			printf("[%d��]", i + 1);
			gotoxy(x + 8, (i + 1) * 3 + 1);
			printf("�г���: %s", rank[i].name);
			gotoxy(x + 26, (i + 1) * 3 + 1);
			printf("�ð�: %.1f��", (float)rank[i].time/10);
			gotoxy(x + 40, (i + 1) * 3 + 1);
			printf("����: %d", rank[i].score);
			//SetColor(7);
			Sleep(200);
		}
		while (1)
		{

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
			if (GetAsyncKeyState(VK_DELETE) & 0x8000) {
				RankReset();
				break;
			}


		}

		system("cls");
	}
	
}

