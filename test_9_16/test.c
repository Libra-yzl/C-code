#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            //打印空格
//            int j = 0;
//            for (j = 0; j < n - i - 1; j++)
//            {
//                printf(" ");
//            }
//            //打印*
//            printf("*");
//            printf("\n");
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
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            int j = 0;
//            for (j = 0; j <= i; j++)
//            {
//                printf("%d ", j + 1);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int arr[50];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    qsort(arr, n, sizeof(int), cmp);
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     int n = 0;
//     int num = 0;
//     while (scanf("%d", &n) != EOF)
//     {
//         int count = 0;
//         do
//         {
//             int rem = n % 10;
//             if (0 == rem % 2)
//             {
//                 rem = 0;
//             }
//             else
//             {
//                 rem = 1;
//             }
//             num += rem * pow(10, count++);
//         }while (n /= 10);
//     }
//     printf("%d\n", num);
//     num = 0;
//     return 0;
// }

//递归实现
#include <stdio.h>

int fun(int n)
{
    int rem = n % 10;
    int tmp = rem % 2;
    if (n /= 10)
    {
        return fun(n) * 10 + tmp;
    }
    return tmp;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int ret = fun(n);
    printf("%d\n", ret);
    return 0;
}