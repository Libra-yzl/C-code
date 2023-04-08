#define _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"

void menu()
{
	printf("************************************\n");
	printf("          1.Add        2.Del     \n");
	printf("          3.Search     4.Modify  \n");
	printf("          5.Show       6.Sort    \n");
	printf("                0.Exit          \n");
	printf("************************************\n");

}

enum Options
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void test_contact()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			DestroyContact(&con);
			printf("退出\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
}

//int main()
//{
//	test_contact();
//	return 0;
//}

#include <stdio.h>
#include <math.h>


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	int i = 0;
//	while (n)
//	{
//		sum += (n % 10) % 2 * pow(10, i);
//		i++;
//		n /= 10;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//#define N 10
//
//int main()
//{
//	/*int n = 0;
//	scanf("%d", &n);*/
//	int arr[N];
//	//输入
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//排序
//	qsort(arr, N, sizeof(int), cmp_int);
//
//	//打印
//	for (int i = N - 1; i >= N - 5; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//	int n = 0;
//	while (scanf("%d", &n) != EOF) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j <= i; j++) {
//				printf("%d ", j + 1);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (i + j == n - 1)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n + 1];
//	memset(arr, 0, (n + 1) * sizeof(int));
//	//输入
//	int m = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &m);
//		arr[m] = 1;
//	}
//
//	//打印
//	for (int i = 1; i <= n; i++)
//	{
//		if (arr[i] != 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (i + j >= n - 1)
//					printf("* ");
//				else
//					printf("  ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	union
//	{
//		short a;
//		char i[2];
//	}*s, k;
//	s = &k;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	printf("%x\n", s->a);
//	return 0;
//}

#include<stdio.h>
int main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;
	s = &a;
	s->i[0] = 0x38;
	s->i[1] = 0x39;
	printf("%zd\n", sizeof(a));
	printf("%x\n", a.k);
	return 0;
}