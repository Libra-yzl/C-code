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
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
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
	//判断坐标是否合理
	while (1)
	{
		printf("玩家下棋\n");
		printf("请输入坐标:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			//判断坐标是否被占用
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
			printf("坐标非法，请重新输入\n");
		}
	}
	printf("\n");
}

//电脑下棋
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("电脑下\n");
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
			{
				return 0;
			}
		}
	}
	return 1;
}
char win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//三列
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[0][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断棋盘是否满了,如果满了，返回1；反之，返回0
	int k = full_board(board, ROW, COL);
	if (k == 1)
	{
		return 'Q';
	}
	return 'C';
}