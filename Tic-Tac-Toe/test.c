#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("******************************************\n");
	printf("***** 1.开始游戏          0.退出游戏 *****\n");
	printf("******************************************\n");
}

void game()
{
	//定义存放棋子的棋盘
	char board[ROW][COL];

	//打印棋盘
	display_board(board, ROW, COL);
	//初始化
	init_board(board, ROW, COL);
}

int main()
{
	int input = 0;
	do
	{
		menu();//菜单
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
			printf("没有该选项 请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}