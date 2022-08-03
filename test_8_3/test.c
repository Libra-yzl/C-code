#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//struct stu
//{
//    int num;
//    char name[10];
//    int age;
//};
//
//
//void fun(struct stu* p)
//{
//    printf("%s\n", (*p).name);
//    return;
//}
//
//
//int main()
//{
//    struct stu students[3] = { {9801,"zhang",20},
//                              {9802,"wang",19},
//                              {9803,"zhao",18}
//    };
//    fun(students + 1);
//    return 0;
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
//#include <stdio.h>
//
//struct Water
//{
//	int price;
//	int emp_bottle;
//};
//int main()
//{
//	struct Water s = { 1, 2 };
//	int money = 0;
//	printf("请输入money额度:> ");
//	while ((scanf("%d", &money)) != EOF)
//	{
//		int much_water = money / s.price;
//		int exchange_water = much_water / s.emp_bottle;
//		int all_water = much_water + exchange_water;
//		printf("总共能有%d瓶汽水\n", all_water);
//		getchar();
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    int i = 0;
//    for (i = 10000; i < 100000; i++)
//    {
//        //计算出位数
//        int tmp = i;
//        int n = 0;
//        while (tmp /= 10)
//        {
//            n++;
//        }
//        //求和相加sum
//        int j = 0;
//        int sum = 0;
//        for (j = 1; j <= n; j++)
//        {
//            sum += (i / (int)pow(10, j)) * (i % (int)pow(10, j));
//        }
//        //比较sum 和 i
//        if (sum == i)
//        {
//            printf("%d ", sum);
//        }
//
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int max = Max(a, b);
//	printf("max = %d", max);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int sum = 0;
//    for (i = 0; i < 5; i++)
//    {
//        scanf("%d ", &n);
//        sum += n;
//    }
//    printf("%d", sum);
//    return 0;
//}

////转换秒数
//#include <stdio.h>
//
//int main()
//{
//	int s = 0;
//	scanf("%d", &s);
//	int h = s / 3600;
//	int m = (s % 3600) / 60;
//	int sec = (s % 3600) % 60;
//	printf("%d %d %d", h, m, sec);
//	return 0;
//}

// 素数
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\n%d", count);
//	return 0;
//}

//素数
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int count = 0;
//		for (i = 1; i <= n; i++)
//		{
//			int j = 0;
//			for (j = 2; j <= sqrt(i); j++)
//			{
//				if (i % j == 0)
//				{
//					break;
//				}
//			}
//			if (j > sqrt(i))
//			{
//				count++;
//				printf("%d ", i);
//			}
//		}
//		printf("\ncount = %d", count);
//		getchar();
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
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
//	printf("\ncount = %d\n", count);
//	return 0;
//}