//ɨ����Ϸ�Ĳ���
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"

void menu()
{
	color(0);       //Black ��ɫ
	system("cls");	//����.
	color(10);
	printf("|-----------|ɨ����Ϸ|-----------|\n");
	printf("|********************************|\n");
	printf("|�����������������|\n");
	printf("|���   1.��ʼ  0.�˳�       ���|\n");
	printf("|�����������������|\n");
	printf("|0 = ������ ---------- 1 = ������|\n");
	printf("|--------------------------------|\n");
}

void game()
{
	printf(" ---------\n");
	printf("|PLAY GAME|\n");
	printf(" ---------\n");
	char Layouts[ROWS][COLS] = { 0 };//��Ų��ú��׵���Ϣ
	char Findout[ROWS][COLS] = { 0 };//����Ų���׵���Ϣ

	//��ʼ������
	Initialization(Layouts, ROWS, COLS, '0');//mine
	Initialization(Findout, ROWS, COLS, 'x');//show

	//��ӡ����
	/*Print_board(Layouts, ROW, COL);*/
	Print_board(Findout, ROW, COL);

	//������
	Lay_thunder(Layouts, ROW, COL);
	/*Print_board(Findout, ROW, COL);*/


	//�Ų���
	Check(Layouts, Findout, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		color(5);
		printf("\n");
		printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
		printf("|Please enter the interface number|:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("|�T�T�T�T�T�T�T�T|\n");
			printf("|�˳���Ϸ|\n");
			printf("|�T�T�T�T�T�T�T�T|\n");
			break;
		default:
			printf("\n");
			printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
			printf("|���������������5s������(��_��)|\n");
			printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
			Sleep(5000);
		}
	} while (input);
}

int main(void)
{
	test();
	return 0;
}