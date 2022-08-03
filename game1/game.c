#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void PrintBoard(char board[ROW][COL], int row, int col)
{
	/*   |   |   
	  ---|---|---
	     |   |   
	  ---|---|---
	     |   |      */
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//打印一行
		//printf(" %c | %c | %c  \n");
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{   //打印分割行
			//printf("---|---|---\n");
			for (j = 0; j < col; j++)
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
	printf("\n");
}
		

void InitBoard(char board[ROW][COL], int row, int col)
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

void Player_Board(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	//判断坐标是否合理
	
	while (1)
	{
		
		printf("玩家请落子\n");
		printf("请输入坐标:> ");
		//Exit();
		scanf("%d%d", &x,&y);
		//Exit();
		if (x >= 1 && x <= row && y >= 1 && y <= col)//满足条件，坐标合理
		{
			//判断该位置是否已经落子
			if (board[x-1][y-1] == ' ')
			{
				//如果该位置未落子，即玩家可以落子
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("该位置已被占用\n");
			}
		}
		else//坐标非法
		{
			printf("无效的坐标\n");
			break;
		}
	}
}

void Computer_Board(char board[ROW][COL], int row, int col)
{
	printf("电脑请落子\n");
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
}
int Is_Full(char board[ROW][COL],int row,int col)
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
char Is_Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) //判断三行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++) //判断三列
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[0][2];
	}
	//判断棋盘是否满了，如果满了，返回1   没满返回0
	int ret = Is_Full(board, ROW, COL);
	if (ret == 1)
	{
		return 'a';
	}
	return 'C';
}

//void Exit()
//{
//	char ret = getchar();
//	if (ret == 'x')
//		exit(0);
//}