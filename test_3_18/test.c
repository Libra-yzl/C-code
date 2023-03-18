#define _CRT_SECURE_NO_WARNINGS 1

////冒泡排序
//
//#include <stdio.h>
//
//void bubble_sort(int* arr, int sz)
//{
//	//冒泡排序
//	int i = 0;
//	int count = 0; //计数器
//
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟冒泡排序
//		int j = 0;
//		int flag = 1; //数据有序的标志
//
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0; //数据此时还未完全有序
//			}
//		}
//		count++;
//
//		//数据完全有序，程序结束
//		if (1 == flag)
//			break;
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr, sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


#include "game.h"

