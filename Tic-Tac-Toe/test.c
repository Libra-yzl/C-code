#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("******************************************\n");
	printf("***** 1.��ʼ��Ϸ          0.�˳���Ϸ *****\n");
	printf("******************************************\n");
}

void game()
{
	//���������ӵ�����
	char board[ROW][COL];

	//��ӡ����
	display_board(board, ROW, COL);
	//��ʼ��
	init_board(board, ROW, COL);
}

int main()
{
	int input = 0;
	do
	{
		menu();//�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("û�и�ѡ�� ������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}