#define _CRT_SECURE_NO_WARNINGS 1
//��Ϸ�ĺ�����ʵ��
#include "game.h"
#include<stdio.h>

void color(short x)
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Initialization(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Print_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	color(7);
	printf("�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	for (i = 0; i <= row; i++)
	{
		if (i == 0)
		{
			printf("%d|", i);
		}
		else
		{
			printf("%d|", i);
		}
	}
	printf("\n/|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T");
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c|", board[i][j]);
		}
		printf("\n");
	}
	color(6);
	printf("\n-----ɨ����Ϸ------\n");
}

void Lay_thunder(char Findout[ROWS][COLS], int row, int col)
{
	//������
	int count = Thunder;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (Findout[x][y] = '0')
		{
			Findout[x][y] = '1';
			count--;
		}
	}
}
//��̬�ֲ�����ȥ���κ�����ʱ��,���������ֻ�����Լ����ڵ�Դ�ļ��ڿ���,�������ڲ������ǿ������ġ�
static int Statistics(char Layouts[ROWS][COLS], int x, int y)
{
	return Layouts[x - 1][y - 1] +
		Layouts[x][y - 1] +
		Layouts[x + 1][y - 1] +
		Layouts[x - 1][y] +
		Layouts[x + 1][y] +
		Layouts[x - 1][y + 1] +
		Layouts[x][y + 1] +
		Layouts[x + 1][y + 1] - 8 * '0';
}
void Check(char Layouts[ROWS][COLS], char Findout[ROWS][COLS], int row, int col)
{
	//1.�����Ų��׵�����
	//2.������괦�ǲ�����,�����״�ŵ����ַ�'1',û�з����״�ŵ����ַ�'0'��
	int x, y;
	int win = 0;
	while (win<row*col - Thunder)
	{
		static int j = 1;//�ӳ���������,
		while (j)
		{
			color(8);
			printf("--------------------------\n");
			printf("[�����һ������ǵÿ�һ��!]\n");
			printf("--------------------------\n");
			j--;
			break;
		}
		color(11);
		printf("---------------\n");
		printf("����������>:");
		//x��y���귶Χ 1~9
		scanf("%d %d", &x, &y);
		printf("---------------\n");
		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Layouts[x][y] == '1')
			{
				printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
				printf("|���ź�,�㱻ը����!|\n");
				printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
				Print_board(Layouts, ROW, COL);
				Sleep(5000);
				break;
			}
			if (Findout[x][y] == '0')
			{
				color(6);
				printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
				printf("|���Ѿ������������������,����������!|\n");
				printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
			}
			if (Findout[x][y] == '1')
			{
				color(6);
				printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
				printf("|���Ѿ������������������,����������!|\n");
				printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
			}
			else
			{
				//����������£�ͳ��x,y��Χ�����м�����
				int Count = Statistics(Layouts, x, y);
				Findout[x][y] = Count + '0';
				Print_board(Findout, row, col);
				win++;
			}
		}
		else
		{
			printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
			printf("|����������귶Χ����!��������|\n");
			printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
		}
	}
	if (win == row*col - Thunder)
	{
		printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
		printf("|��ϲ��,���׳ɹ�!̫������!|\n");
		printf("|�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T|\n");
		Print_board(Findout, ROW, COL);
	}
}