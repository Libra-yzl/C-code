#define _CRT_SECURE_NO_WARNINGS 1

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。

//#include <stdio.h>
//
//struct point
//{
//	int x;
//	int y;
//};
//
//struct point find(int arr[3][3], int row, int col, int key)
//{
//	int x = 0;
//	int y = col - 1;
//	struct point ret = { -1, -1 };
//	while ((x <= 2) && (y >= 0))
//	{
//		if (arr[x][y] == key)
//		{
//			ret.x = x;
//			ret.y = y;
//			return ret;
//		}
//		else if (arr[x][y] > key)
//		{
//			y--;
//		}
//		else
//		{
//			x++;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	//1 2 3
//	//4 5 6
//	//7 8 9
//	struct point ret = find(arr, 3, 3, 10);
//	if ((ret.x != -1) && (ret.y != -1))
//	{
//		printf("找到了:%d %d\n", ret.x, ret.y);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//
////时间复杂度小于O(N)
////最坏(循环遍历数组)的情况下时间复杂度等于O(N)
//
//int find(int arr[3][3], int* row, int* col, int key)
//{
//	int x = 0;   //从左上角开始找
//	int y = *col - 1;//
//	while ((x <= *row - 1) && (y >= 0))
//	{
//		if (arr[x][y] == key)
//		{
//			*row = x;
//			*col = y;
//			return 1;
//		}
//		else if (arr[x][y] < key)
//		{
//			//比这一行最大的元素大，找该元素的下一行，即行数+1
//			x++;
//		}
//		else
//		{	
//			//比这一列最大的元素小，找该元素的左一列，即列数-1
//			y--;
//		}
//	}
//	/**row = -1;
//	*col = -1;*/
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	//三行三列的杨氏矩阵
//	int x = 3;
//	int y = 3;
//	int key = 0;
//	printf("请输入要查找的数:> ");
//	scanf("%d", &key);
//	//将x，y 进行地址传递
//	//方便后面返回查找值的下标 (返回型参数)
//	int ret = find(arr, &x, &y, key);
//	//if ((x != -1) && (y != -1))
//	if (1 == ret)
//	{
//		printf("找到了:%d %d", x, y);
//	}
//	else
//		printf("找不到\n");
//	return 0;
//}

//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//#include <stdio.h>
//#include <string.h>
//
//void left_rot(char* str, int k)
//{
//	int i = 0;
//	int len = (int)strlen(str);
//	//char* arr = str;
//	//利用循环控制左旋字符的个数
//	for (i = 0; i < k; i++)
//	{
//		char* arr = str;
//		while (arr < str + len - 1)  
//		{
//			//让旋转的字符 与数组其他元素顺序交换 直到最后元素的位置
//			char tmp = *arr;
//			*arr = *(arr + 1);
//			*(arr + 1) = tmp;
//			arr++;
//		}
//	}
//}
//
//int main()
//{
//	char str[100] = {0};
//	printf("请输入字符串:> ");
//	scanf("%[^\n]", str);
//	int k = 0;
//	printf("请输入要左旋的字符个数:> ");
//	scanf("%d", &k);
//	printf("左旋前的字符串:> %s\n", str);
//	left_rot(str, k);
//	printf("左旋后的字符串:> %s\n", str);
//	return 0;
//}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//给定s1 =AABCD和s2 = BCDAA，返回1 ,给定s1 = abcd和s2 = ACBD，返回0.

//#include <stdio.h>
//#include <string.h>
//
//int judge(char* s1, char* s2)
//{
//	int len1 = (int)strlen(s1);
//	int len2 = (int)strlen(s2);
//	if (len1 == len2)
//	{
//		int i = 0;
//		for (i = 0; i < len1; i++)
//		{
//			char* str = s1;
//			while (str < (s1 + len1 - 1))
//			{
//				if (strcmp(s1, s2) == 0)
//					return 1;
//				char tmp = *str;
//				*str = *(str + 1);
//				*(str + 1) = tmp;
//				str++;
//			}
//			if (strcmp(s1, s2) == 0)
//				break;
//		}
//	}
//	if (len1 != len2)
//		return 0;
//}
//
//int main()
//{
//	char s1[10];
//	char s2[10];
//	printf("请输入字符串s1:> ");
//	scanf("%s", s1);
//	printf("请输入字符串s2:> ");
//	scanf("%s", s2);
//	int ret = judge(s1, s2);
//	if (1 == ret)
//		printf("1");
//	else
//		printf("0");
//	return 0;
//}

//杨氏矩阵
//#include <stdio.h>
//
//struct point
//{
//	int x;
//	int y;
//};
//
//struct point find(int arr[3][3], int row, int col, int key)
//{
//	struct point ret = { -1, -1 };
//	int x = 0;
//	int y = col - 1;
//	while ((x <= 2) && (y >= 0))
//	{
//		if (arr[x][y] == key)
//		{
//			ret.x = x;
//			ret.y = y;
//			return ret;
//		}
//		else if (arr[x][y] < key)
//		{
//			x++;
//		}
//		else
//		{
//			y--;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int key = 0;
//	printf("请输入要查找的元素:> ");
//	while (scanf("%d", &key) != EOF)
//	{
//		struct point ret = find(arr, 3, 3, key);
//		if ((-1 != ret.x) && (-1 != ret.y))
//		{
//			printf("找到了:> %d %d\n", ret.x, ret.y);
//			printf("请输入要查找的元素:> ");
//		}
//		else
//		{
//			printf("找不到\n");
//			printf("请输入要查找的元素:> ");
//		}
//	}
//	return 0;
//}

#include <stdio.h>

void find(int arr[3][3], int* row, int* col, int key)
{
	int x = 0;
	int y = *col - 1;
	while ((x <= *row - 1) && (y >= 0))
	{
		if (arr[x][y] == key)
		{
			*row = x;
			*col = y;
			return;
		}
		else if (arr[x][y] > key)
		{
			y--;
		}
		else
		{
			x++;
		}
	}
	*row = -1;
	*col = -1;
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3;
	int y = 3;
	int key = 0;
	printf("请输入要查找的数字:> ");
	scanf("%d", &key);
	find(arr, &x, &y, key);
	if ((x != -1) && (y != -1))
	{
		printf("找到了:> %d %d", x, y);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}