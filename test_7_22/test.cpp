//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <graphics.h>
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")
//
//
//int menu()
//{
//	printf("**********************************************\n");
//	printf("*************  1 - 100之间猜数字  ************\n");
//	printf("**********    1.play     0.exit     **********\n");
//	printf("**********************************************\n");
//	return 0;
//}
//
//int game()
//{
//	int guess = 0;
//	int ret = 0;
//	ret = rand()%100 + 1; // 生成1 - 100之间的随机数 rand()- 范围 --> 0-RAND_MAX(32767)
//	//printf("%d\n", ret);
//	printf("开始猜吧！\n");
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess == ret)
//		{
//			printf("恭喜你，你猜对了\n");
//			break;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	mciSendString(L"play src/bj.mp3 repeat",0,0,0);
//	srand((unsigned int)time(NULL));
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:> ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		default:
//			break;
//		case 1:
//			//printf("开始游戏\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}