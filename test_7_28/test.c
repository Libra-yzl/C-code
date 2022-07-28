#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("***********************************************\n");
	printf("*************    1.play   0.exit   ************\n");
	printf("***********************************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	init_board(board, ROW, COL);
	//��ӡ����
	print_board(board, ROW, COL);
	
	while (1)
	{
		//�������
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	printf("��ѡ��:> ");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		game();
		break;
	case 0:
		printf("��Ϸ����\n");
		break;
	default:
		printf("ѡ�����������ѡ��\n");
		break;
	}
	return 0;
}