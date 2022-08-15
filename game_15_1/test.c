#define _CRT_SECURE_NO_WARNINGS 1

////猜数字游戏
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("**************************************\n");
//	printf("********** 1. play  0. exit **********\n");
//	printf("**************************************\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int guess = 0;
//	printf("开始猜吧!\n");
//	while (1)
//	{
//		printf("请输入一个数:> ");
//		scanf("%d", &guess);
//		if (guess > 100)
//		{
//			printf("输入超过游戏最大范围的数,请重新选择\n");
//		}
//		else if (guess > ret)
//		{
//			printf("你猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("你猜小了\n");
//		}
//		else if (guess == ret)
//		{
//			printf("恭喜你,你猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("请输入选择:> ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//printf("开始游戏\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误,请重新选择\n");
//		}
//	} while (input);
//	return 0;
//}


//三子棋游戏

#include "game.h"


void menu()
{
	printf("**************************************\n");
	printf("*************** 1. play **************\n");
	printf("*************** 0. exit **************\n");
	printf("**************************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	while (1)
	{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家获胜\n");
	else if (ret == '#')
		printf("电脑获胜\n");
	else
		printf("平局\n");
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误,请重新选择\n");
		}
	} while (input);
	return 0;
}