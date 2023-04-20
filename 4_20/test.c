#define _CRT_SECURE_NO_WARNINGS 1


#include "g.h"

void menu()
{
	printf("            1. play          \n");
	printf("            0. exit          \n");
}

void game()
{
	//设计2个数组存放信息
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	//mine初始化为全‘0’
	//show初始化为全‘*’
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');

	//打印棋盘
	//display_board(mine, ROW, COL);
	//display_board(show, ROW, COL);

	//布置雷
	set_mine(mine, ROW, COL);
	//排雷
	//display_board(mine, ROW, COL);
	display_board(show, ROW, COL);

	find_mine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);

	return 0;
}
