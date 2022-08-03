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
	//��ӡ��������ʽ
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
			printf(" %c ",board[i][j]); //��ӡһ���ַ�������Ὣ���ʼ��Ϊ�ո�
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) //�������ز����٣�����Ҫ��ӡ�����˵ķָ����
		{
			for (j = 0; j < col; j++)
			{
				printf("---"); //��ӡ�ָ��
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
		printf("����������:> ");
		scanf("%d %d", &x, &y);
		//1.�ж������Ƿ����
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//2.�ж������Ƿ��ѱ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����ѱ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("���겻�ڷ�Χ�ڣ�����������\n");
		}
	}
	printf("\n");
}
void computer_move(char board[ROW][COL], int row, int col)
{
	//�ж������Ƿ�ռ��
	printf("��������\n");
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
	//������͵������ֻ�ж����������к������Խ��ߵ�״̬����ʵ�������и��õĽ������
	//ֻ���һ�û��д��
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

      //�ж����̵�״̬������������˷���1�����û������0
	int ret = full_board(board, ROW, COL);
	if (ret == 1)
	{
		return 'Q';//����Q����ƽ��
	}
	return 'C';
}