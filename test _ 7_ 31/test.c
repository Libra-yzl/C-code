#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//三子棋游戏
void menu() //实现菜单函数
{
	printf("***************************************\n");
	printf("***************三子棋 游戏*************\n");
	printf("*************1.play   0.exit***********\n");
	printf("***************************************\n");
}
void game()
{
	//1.定义一个二维数组来存储棋盘
	char board[ROW][COL] = { 0 };
	//2.初始化棋盘
	init_board(board, ROW, COL);
	//3.打印棋盘
	print_board(board, ROW, COL);
	char ret = 0;
	//玩家与电脑下棋是一个互动的过程，用循环实现
	while (1)
	{
		//4.玩家下棋
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		//玩家落子一次判断一次游戏状态
		//游戏四种状态(电脑获胜游戏结束，玩家获胜游戏结束，平局游戏结束，游戏还未结束)
		ret = win(board, ROW, COL);
		if (ret != 'C')
			break;
		//5.电脑下棋
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = win(board, ROW, COL);
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
#include <stdio.h>
int main()
{
	//使用时间戳来生成随机数
	srand((unsigned int)time(NULL));
	// 菜单函数
	menu();
	int input = 0;
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		printf("开始游戏\n");
		game();//游戏函数
		break;
	case 0:
		break;
	default:
		break;
	}
		return 0;

}