#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>  //strlen()----求字符串长度
#include<Windows.h> //----用到了Sleep()函数------休息函数
#include<stdlib.h>  //----用到了system()函数-----调用系统命令函数

//编写代码，演示多个字符从两边移动，向中间汇聚
int main()
{
	char str1[] = "welcome to our home!!!!";
	char str2[] = "#######################";
	int left = 0;
	//int right = sizeof(str1) / sizeof(str2) - 1;//这是错误的计算元素个数，
	//因为字符串里结束的标志是'\0'，使用sizeof()计算字符串长度时，会将其包括在内，故应-2.
	int right = strlen(str1) - 1;
	while (left <= right)
	{
		str2[left] = str1[left];
		str2[right] = str1[right];
		
		left++;
		right--;
		
		Sleep(1000);//Sleep()函数是一个每隔()ms打印内容的函数----休息函数
		system("cls");//-----system()是调用系统命令的函数，cls---清空屏幕内容
		printf("%s\n", str2);
	}
	
	return 0;
}

////在一个有序的数组中查找一个具体的数字n
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//二分查找
//	int n = 17;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算arr[]中的元素个数
//	int left = 0; //左边元素下标初始化
//	int right = sz - 1; //右边元素下标初始化
//	while (left <= right)
//	{
//		int mid = (left + right) / 2; //中间元素下标初始化
//		if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] == n)
//		{
//			printf(" 找到了，下标是%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
	
	////直接查找
	//int n = 6;
	//int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//for (i = 0; i < sz; i++)
	//{
	//	if (arr[i] == n)
	//	{
	//		printf("找到了，下标是%d", i);
	//		break;
	//	}
	//}
	//if (i >= sz)
	//{
	//	printf("找不到");
	//}

//	return 0;
//}

////1!+2!+...+10! = ?
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//	printf("sum = %d", sum);
//	return 0;
//}

////计算n的阶乘
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("请输入一个数：");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("ret = %d", ret);
//	return 0;
//}