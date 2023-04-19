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
	printf("�������\n");
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("��������:");
		scanf("%d %d", &x, &y);
		
		//�ж����������
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�����Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("������ռ�� ��������\n");
			}
		}
		else
		{
			printf("����Ƿ� ����������\n");
		}
	}
}

void MoveComputer(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
	while (1)
	{
		//�������������
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
	//����
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//����
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[0][2] == board[2][2] && board[1][1] != ' ')
		return board[1][1];

	//�ж��Ƿ�ƽ��
	if (is_full(board, row, col) == 1)
		return 'Q';
	return 'C';
}