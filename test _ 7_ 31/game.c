#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][COL], int row, int col)
{
	//打印的棋盘样式
	//   |   |   
	//---|---|---
	//   |   |   
	//---|---|---
	//   |   |   
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]); //打印一个字符，后面会将其初始化为空格
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) //此条件必不可少，不需要打印第三趟的分割符了
		{
			for (j = 0; j < col; j++)
			{
				printf("---"); //打印分割符
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标:> ");
		scanf("%d %d", &x, &y);
		//1.判断坐标是否合理
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//2.判断坐标是否已被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标不在范围内，请重新输入\n");
		}
	}
	printf("\n");
}
void computer_move(char board[ROW][COL], int row, int col)
{
	//判断坐标是否被占用
	printf("电脑下棋\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	printf("\n");
}
int full_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char win(char board[ROW][COL], int row, int col)
{
	//这里我偷个懒，只判断了三行三列和两个对角线的状态，其实还可以有更好的解决方案
	//只是我还没有写完
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];

      //判断棋盘的状态，如果棋盘满了返回1，如果没满返回0
	int ret = full_board(board, ROW, COL);
	if (ret == 1)
	{
		return 'Q';//返回Q，则平局
	}
	return 'C';
}