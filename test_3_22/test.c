#define _CRT_SECURE_NO_WARNINGS 1

////上三角矩阵判定
//#define n 3
//
//#include <stdio.h>
//
//int main()
//{
//    //int n = 0;
//    //scanf("%d", &n);
//    int arr[n][n];
//    //输入
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//            //printf("%d ", arr[i][j]);
//        }
//        //printf("\n");
//    }
//
//    //判断
//    int flag = 1;//是上三角矩阵
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (arr[i][j] != 0)
//            {
//                printf("NO\n");
//                flag = 0;
//                goto end;//不是上三角矩阵直接跳出双层循环
//            }
//        }
//    }
//end:
//
//    if (1 == flag)
//    {
//        printf("YES\n");
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    long long n = 0;
//    scanf("%d", &n);
//
//    //进制转换
//    long long sum = 0;
//
//    long long i = 0;
//    while (n)
//    {
//        long long m = n % 6;
//        sum += (m * (long long)pow((long long)10, (long long)i));
//        i++;
//        n /= 6;
//    }
//
//    printf("%lld", sum);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    //int sum = 0;
//
//    //最大公约数
//    int tmp_n = n;
//    int tmp_m = m;
//    int r = 1;
//    while (tmp_n % tmp_m)
//    {
//        r = tmp_n % tmp_m;
//        tmp_n = tmp_m;
//        tmp_m = r;
//    }
//
//    //sum += m + n * m / r;
//    printf("%d", tmp_m + n * m / tmp_m);
//    return 0;
//}

//#define n 10
//
//#include <stdio.h>
//
//int main()
//{
//    //int n = 0;
//    //scanf("%d", &n);
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    int del = 0;
//    scanf("%d", &del);
//
//    //删除
//    int flag1 = 1;//无删除元素
//    int flag2 = 1;
//    int count = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] == del)
//        {
//            count++;
//            flag1 = 0;//有删除元素
//            flag2 = 0;
//            int tmp = i;
//            while (tmp < n)
//            {
//                arr[tmp] = arr[tmp + 1];
//                tmp++;
//            }
//            //break; //删除元素后跳出循环
//        }
//        if (0 == flag2)
//        {
//            i = 0;
//            flag2 = 1;
//        }
//    }
//
//    //打印
//    if (1 == flag1)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            printf("%d ", arr[i]);
//        }
//    }
//    else
//    {
//        for (int i = 0; i < n - count; i++)
//        {
//            printf("%d ", arr[i]);
//        }
//    }
//}

//#define n 10
//#include <stdio.h>
//
//int main()
//{
//    /*int n = 0;
//    scanf("%d", &n);*/
//    int arr[n];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    //删除
//    int del = 0;
//    scanf("%d", &del);
//    int fast = 0;//快指针--找需要删除的元素
//    int slow = 0;
//    while (fast < n)
//    {
//        if (arr[fast] != del)
//        {
//            arr[slow] = arr[fast];
//            fast++;
//            slow++;
//        }
//        else
//        {
//            fast++;
//        }
//    }
//    for (int i = 0; i < slow; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//三种方法求模拟实现strlen()

//1.

#include <stdio.h>

//int my_strlen(char* str)
//{
//	int count = 0;//计数器
//
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
// 

////2.递归
//
//int my_strlen(char* str)
//{
//	//int count = 0;
//
//	if (*str == '\0')
//		return 0;
//	else
//		return my_strlen(str + 1)+1;
//}
// 

////3.指针-指针
//
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*start)
//		start++;
//	return (int)(start - str);
//}
//
//int main()
//{
//	char str[] = "abcdefgh";
//	int ret = my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int* p = &a;
//	int** pp = &p;
//	*pp = 200;
//	*p = 10;
//	printf("%d", a);
//	return 0;
//}