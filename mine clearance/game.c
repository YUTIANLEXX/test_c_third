#define _CRT_SECURE_NO_WARNINGS 1
//游戏的函数的实现
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
	printf("════════════════════\n");
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
	printf("\n/|══════════════════");
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
	printf("\n-----扫雷游戏------\n");
}

void Lay_thunder(char Findout[ROWS][COLS], int row, int col)
{
	//布置雷
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
//静态局部变量去修饰函数的时候,让这个函数只能在自己所在的源文件内看到,其它的内部当中是看不到的。
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
	//1.输入排查雷的坐标
	//2.检查坐标处是不是雷,布置雷存放的是字符'1',没有放置雷存放的是字符'0'。
	int x, y;
	int win = 0;
	while (win<row*col - Thunder)
	{
		static int j = 1;//延长生明周期,
		while (j)
		{
			color(8);
			printf("--------------------------\n");
			printf("[输入第一个坐标记得空一格!]\n");
			printf("--------------------------\n");
			j--;
			break;
		}
		color(11);
		printf("---------------\n");
		printf("请输入坐标>:");
		//x与y坐标范围 1~9
		scanf("%d %d", &x, &y);
		printf("---------------\n");
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Layouts[x][y] == '1')
			{
				printf("|══════════════════|\n");
				printf("|很遗憾,你被炸死了!|\n");
				printf("|══════════════════|\n");
				Print_board(Layouts, ROW, COL);
				Sleep(5000);
				break;
			}
			if (Findout[x][y] == '0')
			{
				color(6);
				printf("|═══════════════════════════════════|\n");
				printf("|宁已经在这里输入过坐标了,请重新输入!|\n");
				printf("|═══════════════════════════════════|\n");
			}
			if (Findout[x][y] == '1')
			{
				color(6);
				printf("|════════════════════════════════════|\n");
				printf("|宁已经在这里输入过坐标了,请重新输入!|\n");
				printf("|════════════════════════════════════|\n");
			}
			else
			{
				//不是雷情况下，统计x,y周围坐标有几个雷
				int Count = Statistics(Layouts, x, y);
				Findout[x][y] = Count + '0';
				Print_board(Findout, row, col);
				win++;
			}
		}
		else
		{
			printf("|═════════════════════════════|\n");
			printf("|宁输入的坐标范围错误!重新输入|\n");
			printf("|═════════════════════════════|\n");
		}
	}
	if (win == row*col - Thunder)
	{
		printf("|═══════════════════════|\n");
		printf("|恭喜你,排雷成功!太优秀了!|\n");
		printf("|═══════════════════════|\n");
		Print_board(Findout, ROW, COL);
	}
}