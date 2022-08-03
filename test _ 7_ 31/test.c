#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��������Ϸ
void menu() //ʵ�ֲ˵�����
{
	printf("***************************************\n");
	printf("***************������ ��Ϸ*************\n");
	printf("*************1.play   0.exit***********\n");
	printf("***************************************\n");
}
void game()
{
	//1.����һ����ά�������洢����
	char board[ROW][COL] = { 0 };
	//2.��ʼ������
	init_board(board, ROW, COL);
	//3.��ӡ����
	print_board(board, ROW, COL);
	char ret = 0;
	//��������������һ�������Ĺ��̣���ѭ��ʵ��
	while (1)
	{
		//4.�������
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		//�������һ���ж�һ����Ϸ״̬
		//��Ϸ����״̬(���Ի�ʤ��Ϸ��������һ�ʤ��Ϸ������ƽ����Ϸ��������Ϸ��δ����)
		ret = win(board, ROW, COL);
		if (ret != 'C')
			break;
		//5.��������
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = win(board, ROW, COL);
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
#include <stdio.h>
int main()
{
	//ʹ��ʱ��������������
	srand((unsigned int)time(NULL));
	// �˵�����
	menu();
	int input = 0;
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		printf("��ʼ��Ϸ\n");
		game();//��Ϸ����
		break;
	case 0:
		break;
	default:
		break;
	}
		return 0;

}