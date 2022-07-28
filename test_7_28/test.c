#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("***********************************************\n");
	printf("*************    1.play   0.exit   ************\n");
	printf("***********************************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	init_board(board, ROW, COL);
	//打印棋盘
	print_board(board, ROW, COL);
	
	while (1)
	{
		//玩家下棋
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	printf("请选择:> ");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		game();
		break;
	case 0:
		printf("游戏结束\n");
		break;
	default:
		printf("选择错误，请重新选择\n");
		break;
	}
	return 0;
}