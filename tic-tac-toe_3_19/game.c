#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;//������
	int j = 0;//������

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//��ʼ��Ϊ�ո�
			board[i][j] = ' ';
		}
	}
}

void display_board(char board[ROW][COL], int row, int col)
{
	//   |    |           С1
	//---| ---| ---  1    С2
	//   1    2
	//   |    |
	//---| ---| ---  2
	
	//   |    |     3
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡһ��
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//
			printf(" %c ", board[i][j]);
			//��ӡ|
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//��ӡ������ʱ����ӡ С2
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				//��ӡ---
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	printf("�������:\n");

	//��������
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("����������:>");
		scanf("%d %d", &x, &y);

		//�ж�����Ϸ��ԣ�1.��ҽǶȣ�����Դ����(1,1)   2.�����Ƿ��Ѿ���ռ�ã�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] != ' ')
			{
				printf("�������ѱ�ռ�ã�����������\n");
			}
			else
			{
				//����Ϸ������������ʾΪ '*'
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("����Ƿ�,����������\n");
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	printf("��������:\n");
	while (1)
	{
		//��������
		int x = rand() % row;
		int y = rand() % col;

		//�ж�����Ϸ���
		if (x >= 0 && x < row && y >= 0 && y < col)
		{
			//�ж������Ƿ�ռ��
			if (board[x][y] == ' ')
			{
				//����������ʾΪ '#'
				board[x][y] = '#';
				break;
			}
		}
	}
}

//�ж������Ƿ����� ��������1 ���򷵻�0
static int is_full(char board[ROW][COL], int row, int col)
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

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//�����ж�
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	
	//�����ж�
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}

	//�Խ����ж�
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	//�ж������Ƿ�����
	int ret = is_full(board, ROW, COL);
	if (1 == ret)
		return 'Q';
	return 'C';
}


//ɨ��

void init(char mine[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = set;
		}
	}
}

void display(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	//��ӡ�к�
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		//��ӡ�к�
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = 0; //ͳ�Ʋ��õ��׵�����

	while (count < EASY_COUNT)
	{
		//�����׵�����
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		//�жϺϷ���
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return ((
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]) - 8 * '0');
}

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//����
	int x = 0;
	int y = 0;

	//ͳ�����׵����� ��win = row*col-EASY_COUNT ���׳ɹ� ��Ϸ����
	int win = 0;

	while (win < row * col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d %d", &x, &y);

		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж������Ƿ��Ų��
			if (show[x][y] == '*')
			{
				//�ж������Ƿ�Ϊ��
				if (mine[x][y] == '1')
				{
					display(mine, ROW, COL);
					printf("���ź����㱻ը����\n");
					break;
				}
				else
				{
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					win++;
					display(show, ROW, COL);
				}
			}
			else
			{
				printf("�������Ѿ����Ų��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("���׳ɹ�����Ϸ����\n");
	}
}