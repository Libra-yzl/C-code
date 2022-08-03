#define _CRT_SECURE_NO_WARNINGS 1
 //������������Ϸ
#include<stdio.h>
#include "game.h"

void menu()
{
	printf("******************************************************\n");
	printf("****************  1.play     0.exit  *****************\n");
	printf("******************************************************\n");
}

void game()
{
	
	//�������
	srand((unsigned int)time(NULL));
	char board[ROW][COL] = { 'a' };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	PrintBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		
		//�������
		Player_Board(board, ROW, COL);
		//Exit();
		//�ж�����Ƿ��ʤ
		PrintBoard(board, ROW, COL); //�������һ�δ�ӡһ������
		ret = Is_Win(board, ROW, COL); //�������һ���ж��Ƿ��ʤ
		if (ret != 'C')
			break;

		//��������
		Computer_Board(board, ROW, COL);
		//�жϵ����Ƿ��ʤ
		PrintBoard(board, ROW, COL); //��������һ�δ�ӡһ������
		ret = Is_Win(board, ROW, COL);//��������һ���ж��Ƿ��ʤ
		if (ret != 'C')
			break;
	}
	if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == 'a')//dogfall ƽ��
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("������:> ");
		//Exit();
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:
			//printf("������\n");
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			//exit(0);
			break;
		default:
			printf("ѡ���������������\n");
		}
	} while (input);
}

int main()
{
	//��Ϸ����
	test();
	return 0;
}