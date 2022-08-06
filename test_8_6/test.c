#define _CRT_SECURE_NO_WARNINGS 1

////有序序列的合并
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	int arr1[100] = { 0 };
//	int arr2[100] = { 0 };
//	int arr[200] = { 0 };
//	int i = 0;
//	for (i = 0; i < n + m; i++)
//	{
//		for (i = 0; i < n; i++)
//		{
//			scanf("%d", &arr1[i]);
//			arr[i] = arr1[i];
//		}
//		for (; i < n + m; i++)
//		{
//			scanf("%d", &arr2[i]);
//			arr[i] = arr2[i];
//		}
//	}
//	for (i = 0; i < n + m; i++)
//	{
//		int j = 0;
//		int flag = 1;
//		for (j = 0; j < n + m - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (1 == flag)
//			break;
//	}
//	for (i = 0; i < n + m; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//打印x形图案
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		//使用二维数组打印图案
//      //规律很重要
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i == j || i == n - j - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

////打印弓箭图案
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0; 
//	while (scanf("%d", &n) != EOF)
//	{
//		//打印上半部分
//		int i = 0;
//		for (i = 0; i <= n; i++)
//		{
//			int j = 0;
//			//打印空格
//			for (j = 0; j < 2 * n - 2 * i; j++)
//			{
//				printf(" ");
//			}
//			//打印*
//			for (j = 0; j < i + 1; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//		//打印下半部分
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < 2 + 2 * i; j++)
//			{
//				printf(" ");
//			}
//			for (j = 0; j < n - i; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}