#define _CRT_SECURE_NO_WARNINGS 1

//编写代码，不允许创建临时变量，求字符串长度
	//1.
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0; //计数器
//
//	while (1)
//	{
//		if (*str != '\0')
//		{
//			count++;
//			str++;
//		}
//		else
//			break;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//	//2.递归方法
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return  0;
//}


//求n的阶乘
//	//1.
//
//#include <stdio.h>
//
//int fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fac(n));
//	return 0;
//}
	
//	//2.递归
//
//#include <stdio.h>
//
//int fac(int n)
//{
//	if (n < 2)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fac(n));
//	return 0;
//}


//求斐波那契数列的第n个数

//	//递归
//#include <stdio.h>
//
//int Fib(int n)
//{
//	if (n < 3)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	//给出Fib数列的前两项
//	int a = 1;
//	int b = 1;
//
//	int n = 0;
//	scanf("%d", &n);
//
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b; 
//		b = c;
//
//		n--;
//	}
//	printf("%d\n", c);
//	return 0;
//}


//猜数字游戏

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("***********************************\n");
	printf("***** 1.开始游戏   0.退出游戏 *****\n");
	printf("***********************************\n");
}

void game()
{
	int ret = rand() % 100 + 1; //产生一个1-100的数字
	int guess = 0;

	printf("开始猜吧！\n");
	while (1)
	{
		printf("请猜一个数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("你猜大了\n");
		}
		else if (guess < ret)
		{
			printf("你猜小了\n");
		}
		else
		{
			printf("恭喜你,你猜对了！\n");
			break;
		}
	}
}

int main()
{
	//随机数种子
	srand((unsigned)time(NULL));
	
	int input = 0;

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
			printf("没有这个选项,请重新选择\n");
		}
	} while (input);
	return 0;
}