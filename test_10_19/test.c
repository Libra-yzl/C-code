#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void menu()
{
	printf("**********************************\n");
	printf("              1.play\n");
	printf("              0.exit\n");
	printf("**********************************\n");
}

void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;
	printf("��ʼ�°ɣ�\n");
	while (1)
	{
		printf("������һ������:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("��´���,���²°�\n");
		}
		else if (guess < ret)
		{
			printf("���С��,���²°�\n");
		}
		else
		{
			printf("��ϲ�㣬��¶���!\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
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
			printf("û�����ѡ�������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}