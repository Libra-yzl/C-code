#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int num = 10;
//int main()
//{
//    int num = 1;
//    printf("num = %d\n", num);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int a[][3] = { {0,1,2},{3,4,5} };
//    int i, j;
//    int sz = sizeof(a) / sizeof(a[0]);
//    for (i = 0; i < sz; i++)
//    {
//        for (j = 0; j < 3; j++)
//        {
//            printf("%d ", a[i][j]);
//        }
//    }
//    return 0;
//}
//将数组A中的内容和数组B中的内容交换
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char A[5];
//	char B[5];
//	char C[5];
//	scanf("%s", A);
//	scanf("%s", B);
//	printf("A[] = \"%s\"\n", A);
//	printf("B[] = \"%s\"\n", B);
//	strcpy(C, A);
//	strcpy(A, B);
//	strcpy(B, C);
//	printf("A[] = \"%s\"\n", A);
//	printf("B[] = \"%s\"\n", B);
//	return 0;
//}
//#include <stdio.h>
//void init(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz/2; i++)
//	{
//		int tmp = arr[i];
//		arr[i] = arr[sz - i - 1];
//		arr[sz - i - 1] = tmp;
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr,sz);
//	print(arr,sz);
//	reverse(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//冒泡排序
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[] = { 1,3,5,8,7,6,9,10,2,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (j = 0; j < sz; j++)
//	{
//		for (i = 0; i < sz-1-j; i++)
//		{
//			if (arr[i] < arr[i + 1])
//			{
//				int tmp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = tmp;
//			}
//		}
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int N, M, i, j;
//    int sum = 0;
//    int arr[5][5];
//    scanf("%d %d", &N, &M);
//    for (i = 0; i < N; i++)
//    {
//        for (j = 0; j < M; j++)
//        {
//            scanf("%d ", &arr[i][j]);
//            if (arr[i][j] > 0)
//            {
//                sum = sum + arr[i][j];
//            }
//        }
//    }
//    printf("%d", sum);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int n, m, i, j;
//    int arr[10][10];
//    scanf("%d %d", &n, &m);
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d ", &arr[i][j]);
//        }
//    }
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            printf("%d ", arr[j][i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char arr[] = { 'b', 'i', 't' };
//    printf("%d\n", strlen(arr));
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    printf("%zd\n", strlen("c:\test\121"));
//    return 0;
//}

//#include <stdio.h>
//int Max(int m, int n)
//{
//	if (m > n)
//	{
//		return m;
//	}
//	else
//		return n;
//}
//int main()
//{
//	int m, n, max;
//	scanf("%d %d", &m, &n);
//	max = Max(m, n);
//	printf("max = %d", max);
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int a = 1;
//    int b;
//    switch (a)
//    {
//    case 1: b = 30;
//    case 2: b = 20;
//    case 3: b = 16;
//    default: b = 0;
//    }
//    printf("%d", b);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = b;
//		b = a;
//		a = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = c;
//		c = a;
//		a = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = c;
//		c = b;
//		b = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d", count);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	if (x % y == 0)
//	{
//		printf("%d", x);
//	}
//	else
//	{
//		while (1)
//		{
//			if (x < y)
//			{
//				int tmp = x;
//				x = y;
//				y = tmp;
//			}
//			int r = x % y;
//			int tmp = y;
//			x = r;
//			y = x;
//			if (x % y == 0)
//			{
//				break;
//			}
//		}
//		printf("%d", x);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %-2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include <stdio.h>
int Max(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			arr[i] = arr[i + 1];
		}
	}
	return arr[i];
}
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int max = Max(arr,sz);
	printf("max = %d", max);
	return 0;
}