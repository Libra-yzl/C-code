#define _CRT_SECURE_NO_WARNINGS 1

#include "g.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	//   |   |
	//---|---|---
	//   |   |  
	//---|---|---
	//   |   |
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
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
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void MovePlayer(char board[ROW][COL], int row, int col)
{
	printf("玩家落子\n");
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("输入坐标:");
		scanf("%d %d", &x, &y);
		
		//判断坐标合理性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已占用 重新输入\n");
			}
		}
		else
		{
			printf("坐标非法 请重新输入\n");
		}
	}
}

void MoveComputer(char board[ROW][COL], int row, int col)
{
	printf("电脑落子\n");
	while (1)
	{
		//随机数生成坐标
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int is_full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Win(char board[ROW][COL], int row, int col)
{
	//三行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//三列
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	//对角线
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[0][2] == board[2][2] && board[1][1] != ' ')
		return board[1][1];

	//判断是否平局
	if (is_full(board, row, col) == 1)
		return 'Q';
	return 'C';
}