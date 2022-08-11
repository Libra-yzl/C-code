#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int arr[10][10];
//    while (scanf("%d", &n) != EOF)
//    {
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            int j = 0;
//            for (j = 0; j < n; j++)
//            {
//                if ((0 == i) || ((n - 1) == i) || (0 == j) || ((n - 1) == j))
//                {
//                    printf("* ");
//                }
//                else
//                    printf("  ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

////#include <stdio.h>
////
////int main()
////{
////    int n = 0;
////    scanf("%d", &n);
////    int i = 0;
////    int arr[51] = {0};
////    int flag = 0;
////    for (i = 0; i < n; i++)
////    {
////        scanf("%d", &arr[i]);
////    }
////    int insert = 0;
////    scanf("%d", &insert);
////    for (i = 0; i < n + 1; i++)
////    {
////        int k = n;
////        if (0 == flag)
////        {
////            if (arr[i] > insert)
////            {
////                while (k > i)
////                {
////                    arr[k] = arr[k - 1];
////                    k--;
////                }
////                arr[i] = insert;
////                flag = 1;
////            }
////        }
////        printf("%d ", arr[i]);
////    }
////    return 0;
////}

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[51] = { 0 };
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int insert = 0;
//	scanf("%d", &insert);
//	for (i = 0; i <= n; i++)
//	{
//		if (0 == i)
//		{
//			arr[i] = insert;
//		}
//		if (i < n)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				int tmp = arr[i + 1];
//				arr[i + 1] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#define INT_PTR int*
//typedef int* int_ptr;
//INT_PTR a, b;
//int_ptr c, d;

//int main()
//{
//	int arr[5 + 3] = { 0,1,3,5,7,9 };
//	char c1[] = { '1','2','3','4','5' };
//	char c2[] = { '\x10', '\xa', '\8' };
//	double x[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
//	return 0;
//}

#include <stdio.h>

#define INT int*
typedef int* int_ptr;
int main()
{
	int e = 0;
	INT a, b;
	a = &e;
	b = &e;
	int_ptr c, d;
	c = &e;
	d = &e;
	printf("%p %p %p %p", a, b, c, d);
	return 0;
}
//int main()
//{
//	int b;
//	char c[10];
//	scanf("%d%s", b, &c);
//	return 0;
//}