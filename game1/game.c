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
		//��ӡһ��
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
		{   //��ӡ�ָ���
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
	//�ж������Ƿ����
	
	while (1)
	{
		
		printf("���������\n");
		printf("����������:> ");
		//Exit();
		scanf("%d%d", &x,&y);
		//Exit();
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�����������������
		{
			//�жϸ�λ���Ƿ��Ѿ�����
			if (board[x-1][y-1] == ' ')
			{
				//�����λ��δ���ӣ�����ҿ�������
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("��λ���ѱ�ռ��\n");
			}
		}
		else//����Ƿ�
		{
			printf("��Ч������\n");
			break;
		}
	}
}

void Computer_Board(char board[ROW][COL], int row, int col)
{
	printf("����������\n");
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
	for (i = 0; i < row; i++) //�ж�����
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++) //�ж�����
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[0][2];
	}
	//�ж������Ƿ����ˣ�������ˣ�����1   û������0
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