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
//	printf("*************  1 - 100֮�������  ************\n");
//	printf("**********    1.play     0.exit     **********\n");
//	printf("**********************************************\n");
//	return 0;
//}
//
//int game()
//{
//	int guess = 0;
//	int ret = 0;
//	ret = rand()%100 + 1; // ����1 - 100֮�������� rand()- ��Χ --> 0-RAND_MAX(32767)
//	//printf("%d\n", ret);
//	printf("��ʼ�°ɣ�\n");
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (guess == ret)
//		{
//			printf("��ϲ�㣬��¶���\n");
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
//		printf("��ѡ��:> ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		default:
//			break;
//		case 1:
//			//printf("��ʼ��Ϸ\n");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}