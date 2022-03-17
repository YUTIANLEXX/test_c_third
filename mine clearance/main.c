//扫雷游戏的测试
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"

void menu()
{
	color(0);       //Black 黑色
	system("cls");	//清屏.
	color(10);
	printf("|-----------|扫雷游戏|-----------|\n");
	printf("|********************************|\n");
	printf("|★★★★★★★★★★★★★★★★|\n");
	printf("|★★   1.开始  0.退出       ★★|\n");
	printf("|★★★★★★★★★★★★★★★★|\n");
	printf("|0 = 不是雷 ---------- 1 = 它是雷|\n");
	printf("|--------------------------------|\n");
}

void game()
{
	printf(" ---------\n");
	printf("|PLAY GAME|\n");
	printf(" ---------\n");
	char Layouts[ROWS][COLS] = { 0 };//存放布置好雷的信息
	char Findout[ROWS][COLS] = { 0 };//存放排查出雷的信息

	//初始化棋盘
	Initialization(Layouts, ROWS, COLS, '0');//mine
	Initialization(Findout, ROWS, COLS, 'x');//show

	//打印棋盘
	/*Print_board(Layouts, ROW, COL);*/
	Print_board(Findout, ROW, COL);

	//布置雷
	Lay_thunder(Layouts, ROW, COL);
	/*Print_board(Findout, ROW, COL);*/


	//排查雷
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
		printf("|═════════════════════════════════|\n");
		printf("|Please enter the interface number|:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("|════════|\n");
			printf("|退出游戏|\n");
			printf("|════════|\n");
			break;
		default:
			printf("\n");
			printf("|═════════════════════════════════|\n");
			printf("|由于你输入错误罚你5s不能玩(→_→)|\n");
			printf("|═════════════════════════════════|\n");
			Sleep(5000);
		}
	} while (input);
}

int main(void)
{
	test();
	return 0;
}