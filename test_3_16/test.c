#define _CRT_SECURE_NO_WARNINGS 1

////写一个函数判断是不是素数
//	//是素数返回1，不是返回0
//
//#include <stdio.h>
//#include <math.h>
//
//int is_prime(int num)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(num); i++)
//	{
//		if (num % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0; //计数器
//	//100-200的数字找出素数
//	for (i = 100; i < 200; i++)
//	{
//		int ret = is_prime(i);
//		if (1 == ret)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}



////写一个函数判断是不是闰年
//
//#include <stdio.h>
//
//int is_leap_year(int year)
//{
//	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0; //计数器
//
//	//1000-2000的年份
//	for (i = 1000; i <= 2000; i++)
//	{
//		//判断是不是闰年
//		int ret = is_leap_year(i);
//		//返回1说明是闰年
//		if (1 == ret)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}


////写一个函数，实现一个有序数组的二分查找
//
//#include <stdio.h>
//
//int binary_search(int* arr, int sz, int k)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	//二分查找
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//
//	//实现二分查找
//	int ret = binary_search(arr, sz, k);
//	if (ret != -1)
//		printf("找到了，下标是%d\n", ret);
//	else
//		printf("不存在这个数\n");
//	return 0;
//}


////写一个函数，用一次这个函数，num的值加1
//
//#include <stdio.h>
//
//int num_add(int* num)
//{
//	return ++(*num);
//}
//
//int main()
//{
//	int num = 0;
//
//	int ret = 0;
//	num_add(&num);
//	num_add(&num);
//	num_add(&num);
//	num_add(&num);
//	ret = num_add(&num);
//
//	printf("ret = %d\n", ret);
//	return 0;
//}


//输入一个无符号整型，输出每一位 例如：输入：1234   输出：1 2 3 4

#include <stdio.h>

void print(int num)
{
	if (num > 9)
		print(num / 10);
	printf("%d ", num % 10);
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	print(num);
	return 0;
}


////输入小写字母，转换为大写字母，并输出ASCII值
//#include <stdio.h>
//
//int main()
//{
//	char input = 0;
//	printf("请输入一个小写字母:>");
//	scanf("%c", &input);
//	printf("大写字母:%c\nASCII值:%d\n", input - 32, input);
//	return 0;
//}