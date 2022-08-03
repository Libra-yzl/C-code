#define _CRT_SECURE_NO_WARNINGS 1
 //测试三子棋游戏
#include<stdio.h>
#include "game.h"

void menu()
{
	printf("******************************************************\n");
	printf("****************  1.play     0.exit  *****************\n");
	printf("******************************************************\n");
}

void game()
{
	
	//存放棋盘
	srand((unsigned int)time(NULL));
	char board[ROW][COL] = { 'a' };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	PrintBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		
		//玩家落子
		Player_Board(board, ROW, COL);
		//Exit();
		//判断玩家是否获胜
		PrintBoard(board, ROW, COL); //玩家落子一次打印一次棋盘
		ret = Is_Win(board, ROW, COL); //玩家落子一次判断是否获胜
		if (ret != 'C')
			break;

		//电脑落子
		Computer_Board(board, ROW, COL);
		//判断电脑是否获胜
		PrintBoard(board, ROW, COL); //电脑落子一次打印一次棋盘
		ret = Is_Win(board, ROW, COL);//电脑落子一次判断是否获胜
		if (ret != 'C')
			break;
	}
	if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == 'a')//dogfall 平局
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入:> ");
		//Exit();
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:
			//printf("三子棋\n");
			game();
			break;
		case 0:
			printf("游戏结束\n");
			//exit(0);
			break;
		default:
			printf("选择错误，请重新输入\n");
		}
	} while (input);
}

int main()
{
	//游戏测试
	test();
	return 0;
}