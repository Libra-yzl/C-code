#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("*************************************\n");
	printf("**** 1.��ʼ��Ϸ       0.�˳���Ϸ ****\n");
	printf("*************************************\n");
}

//void game()
//{
//	//����ʱ��� ���������
//	srand((unsigned)time(NULL));
//	char ret = 0;
//
//	//��������������
//	char board[ROW][COL] = { 0 };
//	
//	//��ʼ�����̣���ӡ�ո� �������룩
//	init_board(board, ROW, COL);
//	//��ӡ����
//	display_board(board, ROW, COL);
//
//	//�ж���Ϸ״̬ 
//	//1.��һ�ʤ    '*'
//	//2.���Ի�ʤ    '#'
//	//3.ƽ��        'Q'
//	//4.��Ϸ����    'C'
//	while (1)
//	{
//		//�������
//		player_move(board, ROW, COL);
//		display_board(board, ROW, COL);
//		ret = is_win(board, ROW, COL);
//		if (ret != 'C')
//			break;
//
//		/*Sleep(3000);
//		system("cls");*/
//
//		//��������
//		computer_move(board, ROW, COL);
//		display_board(board, ROW, COL);
//		ret = is_win(board, ROW, COL);
//		if (ret != 'C')
//			break;
//
//		/*Sleep(3000);
//		system("cls");*/
//	}
//
//	//��Ϸ����
//	system("cls");
//	if (ret == '*')
//		printf("��Ϸ��������ϲ��һ�ʤ\n");
//	else if (ret == '#')
//		printf("��Ϸ��������ϲ���Ի�ʤ\n");
//	else
//		printf("��Ϸ������ƽ��\n");
//	
//	display_board(board, ROW, COL);
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		//�˵�
//		menu();
//
//		printf("������ѡ��>:");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			game();//��ʼ��Ϸ
//			break;
//		case 0:
//			printf("�˳���Ϸ");
//			break;
//		default:
//			printf("û�и�ѡ�������ѡ��\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


void game()
{
	//���������������
	srand((unsigned)time(NULL));

	//mine��������
	//show����չʾ����

	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//��ʼ������(mine ��ʼ��ȫ'0'    show ��ʼ��ȫ'*')
	init(mine, ROWS, COLS, '0');
	init(show, ROWS, COLS, '*');

	//��ӡ����
	//display(mine, ROW, COL);
	display(show, ROW, COL);

	//������
	set_mine(mine, ROW, COL);
	//display(mine, ROW, COL);

	//����
	//display(mine, ROW, COL);
	find_mine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;

	do
	{
		menu();

		printf("��ѡ��:");
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
			printf("û�и�ѡ�������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}