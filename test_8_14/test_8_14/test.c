#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//
//	return 0;
//}
//
//#include < stdio.h >
//struct S
//{
//	int a;
//	int b;
//};
//
//int main()
//{
//	struct S a, * p = &a;
//
//	//struct S a;
//	//struct S* p = &a;
//
//	a.a = 99;
//	printf("%d\n", __________);
//	return 0;
//}
//
//A. a.a //ok
//B. *p.a //err
//C. p->a //ok
//D. (*p).a//ok

//
//struct stu
//{
//    int num;
//    char name[10];
//    int age;
//};
//
//void fun(struct stu* p)
//{
//    printf("%s\n", (*p).name);
//    return;
//}
//
//int main()
//{
//    struct stu students[3] = { 
//                              {9801,"zhang",20},
//                              {9802,"wang",19},
//                              {9803,"zhao",18}
//                             };
//    fun(students + 1);
//    return 0;
//}

//
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
//C语言的变量应该定义在当前代码块的最前面
//
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//	scanf("%d", &money);
//	//total = money;
//	//empty = money;
//	//while (empty >= 2)
//	//{
//	//	total += empty / 2;
//	//	empty = empty / 2 + empty%2;
//	//}
//
//	if (money <= 0)
//		total = 0;
//	else
//		total = 2 * money - 1;
//
//	printf("%d\n", total);
//
//	return 0;
//}


#include <stdio.h>
#include <math.h>
//
//int main()
//{
//    int i = 0;
//    for (i = 10000; i <= 99999; i++)
//    {
//        //判断i是否为lily number
//        //12345
//        //12345%10 = 5     12345/10=1234
//        //12345%100=45     12345/100=123
//        //12345%1000=345   12345/1000=12
//        //12345%10000=2345 12345/10000=1
//        int j = 0;
//        int sum = 0;
//        for (j = 1; j <= 4; j++)
//        {
//            int k = (int)pow(10, j);
//            sum += (i % k) * (i / k);
//        }
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void move_even_odd(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left<right)
//	{
//		//从前往后找一个偶数停下来
//		while ((left < right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//从后往前找一个奇数停下来
//		while ((left < right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = {1,1,7,4,8,3,5,9,2};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	move_even_odd(arr, sz);
//	print(arr, sz);
//	return 0;
//}
//
//
//
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int arr[50] = { 0 };
//    scanf("%d", &n);
//    int i = 0;
//    int flag1 = 0;//升序
//    int flag2 = 0;//降序
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        if (i > 0)
//        {
//            if (arr[i] > arr[i - 1])
//                flag1 = 1;
//            else if (arr[i] < arr[i - 1])
//                flag2 = 1;
//        }
//    }
//
//    if (flag1 + flag2 <= 1)
//        printf("sorted\n");
//    else
//        printf("unsorted\n");
//
//    return 0;
//}
//
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int max = 0;//假设最大值是0
//    int min = 100;//假设最小值是100
//    int i = 0;
//    int score = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &score);
//        if (score > max)
//            max = score;
//        if (score < min)
//            min = score;
//    }
//    printf("%d\n", max - min);
//
//    return 0;
//}
//
//
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    int arr1[n];//C99
//    int arr2[m];//C99
//    int i = 0;
//    int j = 0;
//    //输入
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//    //合并打印
//    i = 0;
//    j = 0;
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
//
//    if (i == n)
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
//
//    return 0;
//}

//

//*___*
//_*_*_
//__*__ 
//_*_*_
//*___*

#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) == 1)
//    {
//        int i = 0;
//        int j = 0;
//        for (i = 0; i < n; i++)
//        {
//            for (j = 0; j < n; j++)
//            {
//                if (i == j)
//                    printf("*");
//                else if (i + j == n - 1)
//                    printf("*");
//                else
//                    printf("_");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}
//
//
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) == 1)
//    {
//        //打印图案
//        //上 - n行
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            //打印一行
//            //打印空格
//            int j = 0;
//            for (j = 0; j < n - i; j++)
//            {
//                printf("  ");
//            }
//            //打印*
//            for (j = 0; j <= i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//        //下 - n+1行
//        for (i = 0; i < n + 1; i++)
//        {
//            //打印一行
//            //打印空格
//            int j = 0;
//            for (j = 0; j < i; j++)
//            {
//                printf("  ");
//            }
//            //打印*
//            for (j = 0; j < n + 1 - i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}
//

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	//00000000000000000000000011001000
//	//11001000 - a
//	//00000000000000000000000001100100
//	//01100100 - b
//	//
//	c = a + b;
//	//00000000000000000000000011001000 - a
//	//00000000000000000000000001100100 - b
//	//00000000000000000000000100101100
//	//00101100 - c
//	//00000000000000000000000000101100
//	//
//	printf("%d %d", a + b, c);//300 44
//	return 0;
//}

//
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三； b==2 a==3
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b==2) + (a==3) == 1) &&
//							((b==2) + (e==4) == 1) &&
//							((c==1) + (d==2) == 1) &&
//							((c==5) + (d==3) == 1) &&
//							((e==4) + (a==1) == 1))
//						{
//							if((a * b * c * d * e == 120) &&(a+b+c+d+e==15))
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//

//
//猜凶手
//题目内容：
//某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//凶手无非就是：A\B\C\D
//假设是A
//假设是B
//假设是C
//假设是D

//
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer!='A') + (killer=='C') + (killer=='D') + (killer!='D') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	return 0;
//}
//




