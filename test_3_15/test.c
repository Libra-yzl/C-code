#define _CRT_SECURE_NO_WARNINGS 1

////打印100-200之间的素数
//
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0; //计数器
//	for (i = 101; i < 200; i += 2)
//	{
//		//判断素数
//		int flag = 1; //标志是素数
//		for (int j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (1 == flag)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

////三个数按从大到小输出
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	int tmp = 0;//临时变量 中转
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

////判断闰年(1000 - 2000)
////能被4整除不能被100整除
////能被400整除
//#include <stdio.h>
//
//int main()
//{
//	int year = 0;
//	int count = 0;//计数器
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			count++;
//			printf("%d ", year);
//		}
//	}
//	printf("\n总共有%d个闰年\n", count);
//	return 0;
//}

//最大公约数（两种方法）

////第一种方法
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = a < b ? a : b;
//	while (1)
//	{
//		if (a % min == 0 && b % min == 0)
//		{
//			printf("%d\n", min);
//			break;
//		}
//		min--;
//	}
//	return 0;
//}

////辗转相除法
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int r = 0;//余数
//	while (r = a % b)
//	{
//		a = b;
//		b = r;
//	}
//	printf("%d\n", b);
//	return 0;
//}

////乘法表
//
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, i * j);
//		}
//		printf("\n");//一行打印完后换行
//	}
//	return 0;
//}

////最小公倍数 (a * b / k) k是a和b的最大公约数
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = a < b ? a : b;
//	while (1)
//	{
//		if (a % min == 0 && b % min == 0)
//			break;
//		min--;
//	}
//	printf("%d\n", a * b / min);
//	return 0;
//}

//求10个数中最大的

#include <stdio.h>

int main()
{
	int arr[] = { 2,5,4,6,8,9,6,99,4,10,56,79 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int max = arr[0];
	for (int i = 0; i < sz; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d\n", max);
	return 0;
}