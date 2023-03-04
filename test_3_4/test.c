#define _CRT_SECURE_NO_WARNINGS 1

//计算n的阶乘
#include <stdio.h>

//int main()
//{
//	int sum = 0;
//	for (int j = 1; j <= 5; j++)
//	{
//		int ret = 1;
//		for (int i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret *= n;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//在一组数组中查找数字
//二分查找

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int k = 0;
//	scanf("%d", &k);
//	while (left <= right)
//	{
//		//int mid = (left + right) / 2;
//		int mid = left + (right - left) / 2;//求平均值的一种方法
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了,下标是%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("不存在哦\n");
//	return 0;
//}

//演示多个字符从中间向两边移动
#include <string.h>
#include <Windows.h>
#include <stdlib.h>

//int main()
//{
//	char arr1[] = "Welcome to bit !!!";
//	char arr2[] = "##################";
//	int length = (int)strlen(arr2);
//	int left = 0;
//	int right = length - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		Sleep(1000);
//		system("cls");
//		printf("%s\n", arr2);
//		left++;
//		right--;
//	}
//	//printf("%s\n", arr2);
//	return 0;
//}

//模拟登录密码三次

//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "bitbit") == 0)
//		{
//			printf("密码正确，登录成功\n");
//			break;
//		}
//		else
//			printf("密码错误，请重试\n");
//	}
//	if (3 == i)
//		printf("密码错误已达上限，退出程序\n");
//	return 0;
//}

//猜数字游戏
//#include <time.h>
//
//void menu()
//{
//	printf("############################\n");
//	printf("1.play                0.exit\n");
//	printf("############################\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1; //产生1-100的数字
//	int guess = 0;
//	printf("开始猜吧！\n");
//	while (1)
//	{
//		printf("请输入一个数字:>");
//		scanf("%d", &guess);
//		if (guess < ret)
//			printf("你猜小了\n");
//		else if (guess > ret)
//			printf("你猜大了\n");
//		else
//		{
//			printf("恭喜你，你猜对了!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//设置随机数生成器
//	do
//	{
//		menu();//菜单函数
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();//游戏函数
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("没有该选项，请重试\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	printf("请您输入我是猪，否则电脑将会在一分钟之内关机\n");
again:
	printf("请输入:>");
	scanf("%s", input);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
		printf("取消关机\n");
		exit(0);
	}
	goto again;
	return 0;
}