#define _CRT_SECURE_NO_WARNINGS 1


//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果

//#include <stdio.h>
//
//double sum(double flag)
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		flag += 1.0 / i;
//		flag = -flag;
//	}
//	return flag;
//}
//
//double sum_new(double flag)
//{
//	int i = 0;
//	double flag1 = 0;
//	double flag2 = 0;
//	for (i = 1; i <= 100; i += 2)
//	{
//		flag1 += 1.0 / i;
//	}
//	for (i = 2; i <= 100; i += 2)
//	{
//		flag2 += 1.0 / i;
//	}
//	return (flag1 - flag2);
//}
//
//int main()
//{
//	double flag = 0;
//	double sum1 = sum(flag);
//	printf("sum = %lf\n", sum1);
//	double sum2 = sum_new(flag);
//	printf("sum = %lf\n", sum2);
//	return 0;
//}

//编写程序数一下 1到 100 的所有整数中出现多少个数字9

//#include <stdio.h>
//
//int Find(int count)
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//			printf("%d ", i);
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int count = 0;
//	count = Find(count);
//	printf("\ncount = %d", count);
//	return 0;
//}

//编写代码在一个整形有序数组中查找具体的某个数
//要求：找到了就打印数字所在的下标，找不到则输出：找不到。

//#include <stdio.h>
//
//int binary_arr(int* arr, int sz, int k)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
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
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	int k = 0;
//	scanf("%d", &k);
//	ret = binary_arr(arr, sz, k);
//	if (ret != -1)
//	{
//		printf("找到了，下标是%d\n", ret);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf(" 0.exit     1.play\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int guess = 0;
//	printf("开始猜吧\n");
//	while (1)
//	{
//		printf("请输入一个数字:>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("你猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("你猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，你猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//实现一个函数来交换两个整数的内容。
//#include <stdio.h>
//
//void Swap(int* a, int* b)
//{
//	(*a) = (*a) ^ (*b);
//	(*b) = (*a) ^ (*b);
//	(*a) = (*b) ^ *(a);
//}
//
//void Swap1(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("a = %d, b = %d\n", a, b);
//	//Swap(&a, &b);
//	Swap1(&a, &b);
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//
//int is_leap(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int print_leap(int count)
//{
//	int i = 0;
//
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int year = 0;
//	int count = 0;
//	scanf("%d", &year);
//	int ret = is_leap(year);
//	if (1 == ret)
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//	printf("打印1000-2000年的闰年\n");
//	count = print_leap(count);
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//7_24
//递归和非递归分别实现求n的阶乘
//#include <stdio.h>
//
//int Fac1(int n)
//{
//	int i = 0;
//	int fac = 1;
//	for (i = 1; i <= n; i++)
//	{
//		fac *= i;
//	}
//	return fac;
//}
//
//int Fac2(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac2(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret1 = Fac1(n);
//	int ret2 = Fac2(n);
//	printf("fac = %d\n", ret1);
//	printf("fac = %d\n", ret2);
//	return 0;
//}

//#include <stdio.h>
//
//void print(int n)
//{
//	if (n < 9)
//	{
//		printf("%d ", n);
//	}
//	else
//	{
//		print(n / 10);
//		printf("%d ", n % 10);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}