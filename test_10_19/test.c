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
	printf("开始猜吧！\n");
	while (1)
	{
		printf("请输入一个数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("你猜大了,重新猜吧\n");
		}
		else if (guess < ret)
		{
			printf("你猜小了,重新猜吧\n");
		}
		else
		{
			printf("恭喜你，你猜对了!\n");
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
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("没有这个选项，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}