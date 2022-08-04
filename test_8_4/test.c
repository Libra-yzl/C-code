#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d\n%d", ret, sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0; //要查找的数
//	scanf("%d", &n);
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//   //另外一种不会溢出的计算中间值的方法
//   // int mid = left + (right - left)
//	int right = sz - 1;
// //有序的数组，使用二分查找
//	while (left <= right)
//	{
//		int mid = (left + right) / 2; //这种方法可能会溢出
//   // int mid = left + (right - left)
// 
//		if (arr[mid] == n)
//		{
//			printf("找到了，下标是%d\n", mid);
//			break;
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//	}
//	if (left > right)
//	{
//		printf("没有该数字\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//int main()
//{
//	char arr[] = "Welcome to bit!!!!";
//	char arr1[] = "##################";
//	int sz = (int)strlen(arr);
//	int i = 0;
//  int left = 0;
//  int right = (int)strlen(arr)
// 
//  while (left <= right)
//  {
//		arr1[left] = arr[left];
//      arr1[right] = arr[right];
//		left++;
//		right--;
//  } 
//	for (i = 0; i <= sz / 2; i++)
//	{
//		arr1[i] = arr[i];
//		arr1[sz - i] = arr[sz - i];
//		Sleep(1000); //Sleep函数，单位是ms
//		system("cls"); //system是调用系统函数的函数，cls表示清屏
//		printf("%s\n", arr1);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//
//
//void menu()
//{
//	printf("*******************************\n");
//	printf("********1.play    0.exit*******\n");
//	printf("*******************************\n");
//}
//void game()
//{
//	int guess = 0;
//	//生成随机数
//	int ret = rand() % 100 + 1; //rand()函数范围 0 - 32767   生成1 - 100之间的随机数
//	while (1)
//	{
//		printf("请输入一个数字:> ");
//		scanf("%d", &guess);
//		if (guess == ret)
//		{
//			printf("恭喜你，你猜对了\n");
//			break;
//		}
//		else if (guess > ret)
//		{
//			printf("你猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("你猜小了\n");
//		}
//	}
//	Sleep(1000);
//	system("cls");
//}
//int main()
//{
//	int input = 0;
//	//设置随机数的生成器
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:> ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		default:
//			printf("选择错误，请重新选择\n");
//		case 1:
//		{
//			game();
//			break;
//		}
//		case 0:
//		{
//			printf("退出游戏\n");
//			break;
//		}
//		}
//	} while (input);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char passward[10] = { 0 };
//	system("shutdown -s -t 60");
////flag:
//	while (1)
//	{
//		printf("电脑将在60s后关机，如果输入\"我是猪\",取消关机\n");
//		scanf("%s", passward);
//		if (strcmp(passward, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			printf("关机取消\n");
//			break;
//		}
//	}
//	/*else
//	{
//		goto flag;
//	}*/
//	return 0;
//}