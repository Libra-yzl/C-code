#define _CRT_SECURE_NO_WARNINGS 1

////递归求解n的k次方
//#include <stdio.h>
//
//double Pow(int n, int k)
//{
//	if (k < 0)
//		return 1.0 / Pow(n, -k);
//	else if (0 == k)
//		return 1;
//	else
//		return n * Pow(n, k - 1);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//
//	//计算n的k次方
//	double ret = Pow(n, k);
//	printf("n^k = %lf\n", ret);
//	return 0;
//}


////写一个递归函数DigitSum(n) 输入一个非负整数 返回组成他的数字之和
//#include <stdio.h>
//
//int DigitSum(int n)
//{
//	if (n > 9)
//		return DigitSum(n / 10) + n % 10;
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个非负整数:>");
//	scanf("%d", &n);
//
//	//DigitSum函数
//	int ret = DigitSum(n);
//	printf("%d的每位数之和为%d\n", n, ret);
//	return 0;
//}

//编写一个函数reverse_string(char* string)
//将参数字符串中的字符反向排列
//不能使用C函数库中的字符串操作函数
//
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;//字符计数器
//
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//
//void reverse_string(char* str, int sz)
//{
//	char* left = str;
//	char* right = str + sz - 1;
//
//	while (left < right)
//	{
//		//交换第一位和最后一位
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}

//void reverse_string(char* str, int sz)
//{
//	char left = 0;
//	char right = sz - 1;
//
//	while (left < right)
//	{
//		char tmp = *(left + str);
//		*(left + str) = *(right + str);
//		*(right + str) = tmp;
//		left++;
//		right--;
//	}
//}

////递归
//void reverse_string(char* str)
//{
//	int sz = my_strlen(str);
//	char* left = str;
//	char* right = str + sz - 1;
//
//	char tmp = *left;
//	*left = *right;
//	*right = '\0';
//
//	if (my_strlen(str) > 1)
//		reverse_string(str + 1);
//
//	*right = tmp;
//}
//
//int main()
//{
//	char str[] = "abcdef";
//	int sz = my_strlen(str);
//
//	reverse_string(str);
//	printf("%s\n", str);
//	return 0;
//}

////递归 非递归实现求斐波那契数列
//#include <stdio.h>
//
//int count = 0;//统计某项计算的次数
//
//int Fib_rec(int n)
//{
//	if (n == 4)
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return Fib_rec(n - 1) + Fib_rec(n - 2);
//}
//
//int Fib_cir(int n)
//{
//	//斐波那契数列的前两项
//	int a = 1;
//	int b = 1;
//	int c = 1;
//
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;//斐波那契数列项数
//	printf("请输入要求的斐波那契数列的项数:>");
//	scanf("%d", &n);
//
//	Fib_rec(n);//递归
//	Fib_cir(n);//循环
//
//	printf("递归求斐波那契数列第n项:%d\n循环求斐波那契数列第n项:%d\n", Fib_rec(n), Fib_cir(n));
//	printf("递归计算斐波那契数列n为3时的次数：%d", count);
//	return 0;
//}


////将数组A和数组B中的内容交换 Swap函数实现
//#include <stdio.h>
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Swap(int* arr1, int* arr2, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//
//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//
//	printf("交换前arr1数组：");
//	print(arr1, sz);
//	printf("交换前arr2数组：");
//	print(arr2, sz);
//
//	Swap(arr1, arr2, sz);
//	
//	printf("\n交换后arr1数组：");
//	print(arr1, sz);
//	printf("交换后arr2数组：");
//	print(arr2, sz);
//
//	return 0;
//}


//创建一个整型数组 完成对数组的操作
//实现函数init() 对数组初始化为全0
//实现函数print() 打印函数的每个元素
////实现函数reverse() 函数完成数组元素的逆置
//#include <stdio.h>
//
//void init(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = i + 1;
//	}
//}
//
//void reverse(int* arr, int sz)
//{
//	int* left = arr;
//	int* right = arr + sz - 1;
//
//	while (left < right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	init(arr, sz);
//	printf("逆置前的数组：");
//	print(arr, sz);
//
//	reverse(arr, sz);
//	printf("逆置后的数组：");
//	print(arr, sz);
//
//	return 0;
//}


////冒泡排序
//#include <stdio.h>
//
//int count = 0;//统计冒泡排序进行了多少次
//
//void bubble_sort(int* arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//数据有序的标志
//		//count++;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			count++;
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;//此时数据还未完全有序
//			}
//		}
//		if (1 == flag)//说明数组中的数据已经完全有序 结束循环
//			break;
//	}
//}
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	
//	printf("排序前的数组:");
//	print(arr, sz);
//
//	bubble_sort(arr, sz);
//
//	printf("排序后的数组:");
//	print(arr, sz);
//
//	//printf("此次冒泡排序进行排序的次数为%d次\n", count);
//	return 0;
//}


////行列互换 -- 转置矩阵
//#include <stdio.h>
//
//#define n 2
//#define m 3
//
//int main()
//{
//	int arr[n][m];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	printf("原矩阵:\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	printf("转置矩阵:\n");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//求一个整数在内存中存储的1的个数
#include <stdio.h>

int main()
{
	int flag = 1; //按位与1
	int n = 0;
	int k = 32;
	printf("请输入一个数字:>");
	scanf("%d", &n);
	int tmp = n;

	int count = 0;//统计二进制1的个数
	while (k)
	{
		if ((n & flag) == 1)
			count++;
		n >>= 1;
		k--;
	}
	printf("%d的二进制中1的个数为%d个", tmp, count);
	return 0;
}
