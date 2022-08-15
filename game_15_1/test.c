#define _CRT_SECURE_NO_WARNINGS 1

////��������Ϸ
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("**************************************\n");
//	printf("********** 1. play  0. exit **********\n");
//	printf("**************************************\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int guess = 0;
//	printf("��ʼ�°�!\n");
//	while (1)
//	{
//		printf("������һ����:> ");
//		scanf("%d", &guess);
//		if (guess > 100)
//		{
//			printf("���볬����Ϸ���Χ����,������ѡ��\n");
//		}
//		else if (guess > ret)
//		{
//			printf("��´���\n");
//		}
//		else if (guess < ret)
//		{
//			printf("���С��\n");
//		}
//		else if (guess == ret)
//		{
//			printf("��ϲ��,��¶���\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("������ѡ��:> ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//printf("��ʼ��Ϸ\n");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����,������ѡ��\n");
//		}
//	} while (input);
//	return 0;
//}


//��������Ϸ

#include "game.h"


void menu()
{
	printf("**************************************\n");
	printf("*************** 1. play **************\n");
	printf("*************** 0. exit **************\n");
	printf("**************************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	while (1)
	{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("��һ�ʤ\n");
	else if (ret == '#')
		printf("���Ի�ʤ\n");
	else
		printf("ƽ��\n");
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
		}
	} while (input);
	return 0;
}