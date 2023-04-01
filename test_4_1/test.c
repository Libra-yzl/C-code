#define _CRT_SECURE_NO_WARNINGS 1

////判断序列是否有序
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[n];
//    int flag1 = 0;
//    int flag2 = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        if (i > 0 && arr[i] < arr[i - 1])
//        {
//            flag1 = 1;
//        }
//        else if (i > 0 && arr[i] >= arr[i - 1])
//        {
//            flag2 = 1;
//        }
//    }
//    if (flag1 + flag2 == 1)
//    { 
//        printf("sorted\n");
//    }
//    else
//    {
//        printf("unsorted\n");
//    }
//    return 0;
//}

//最低分最高分之差
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int score[n];
    int max = 0;
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
    }
    max = score[0];
    min = score[0];
    for (int i = 0; i < n; i++)
    {
        if (score[i] > max)
            max = score[i];
        if (score[i] < min)
            min = score[i];
    }
    printf("%d", max - min);
    return 0;
}


//有序序列合并

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp_int(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    int arr[n + m];
//    //输入
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d ", &arr[i]);
//    }
//    for (int i = n - 1; i < n + m; i++)
//    {
//        scanf("%d ", &arr[i]);
//    }
//    qsort(arr, n + m, sizeof(arr[0]), cmp_int);
//    for (int i = 0; i < n + m; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp_int(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    int arr1[n];
//    int arr2[m];
//    //输入
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d ", &arr1[i]);
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d ", &arr2[i]);
//    }
//    // qsort(arr, n+m, sizeof(arr[0]), cmp_int);
//    // for (int i = 0; i < n+m; i++)
//    // {
//    //     printf("%d ", arr[i]);
//    // }
//
//    //打印
//    i = 0;
//    int j = 0;
//    while (i < n && j < m)
//    {
//        if (arr1[i] < arr2[j])
//        {
//            printf("%d ", arr1[i]);
//            i++;
//        }
//        else if (arr1[i] >= arr2[j])
//        {
//            printf("%d ", arr2[j]);
//            j++;
//        }
//    }
//    //判断是否有一组未打印完
//    if (i == n && j < m)
//    {
//        for (; j < m; j++)
//        {
//            printf("%d ", arr2[j]);
//        }
//    }
//    else
//    {
//        for (; i < n; i++)
//        {
//            printf("%d ", arr1[i]);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int arr[10][10];
//
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                //打印*
//                if (i == j || (i + j == n - 1))
//                {
//                    arr[i][j] = '*';
//                }
//                //打印空格
//                else
//                {
//                    arr[i][j] = ' ';
//                }
//            }
//        }
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                printf("%c", arr[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        //打印上半部分
//        for (int i = 0; i < n; i++)
//        {
//            //打印空格
//            for (int j = 0; j < n - i; j++)
//            {
//                printf("  ");
//            }
//            //打印*
//            for (int j = 0; j <= i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//
//        //打印下半部分
//        for (int i = 0; i <= n; i++)
//        {
//            //打印空格
//            for (int j = 0; j < i; j++)
//            {
//                printf("  ");
//            }
//            //打印*
//            for (int j = 0; j <= n - i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", (int)strlen(a));
//    return 0;
//}

////5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
////A选手说：B第二，我第三；
////B选手说：我第二，E第四；
////C选手说：我第一，D第二；
////D选手说：C最后，我第三；
////E选手说：我第四，A第一；
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include <stdio.h>
//
//int main()
//{
//	for (int a = 1; a <= 5; a++)
//	{
//		for (int b = 1; b <= 5; b++)
//		{
//			for (int c = 1; c <= 5; c++)
//			{
//				for (int d = 1; d <= 5; d++)
//				{
//					for (int e = 1; e <= 5; e++)
//					{
//						if ((b == 2) + (a == 3) == 1 &&
//							(b == 2) + (e == 4) == 1 &&
//							(c == 1) + (d == 2) == 1 &&
//							(c == 5) + (d == 3) == 1 &&
//							(e == 4) + (a == 1) == 1 && a*b*c*d*e == 120)
//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

////日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
////以下为4个嫌疑犯的供词:
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说
////已知3个人说了真话，1个人说的是假话。
////现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include <stdio.h>
//
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	return 0;
//}