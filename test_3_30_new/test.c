#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

//计算阶乘
//1!+2!+3!+4!+5!

#include <stdio.h>

int main()
{
	int i = 0;
	int n = 0;
	scanf("%d", &n);
	int ret = 1;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		ret *= i;//n的阶乘
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}

//#include <stdio.h>
//
//int binary_search(int arr[], int sz, int k)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right)/ 2;
//		if (arr[mid] < k)
//		{
//			left = mid+1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid-1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int k = 0;
//	scanf("%d", &k);
//
//	int ret = binary_search(arr, sz, k);
//	if (ret != -1)
//		printf("找到了 下标是%d\n", ret);
//	else
//		printf("没有这个数字\n");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <stdlib.h>
//
//int main()
//{
//	char str1[] = "#########";
//	char str2[] = "hello bit";
//
//	int len = strlen(str1);
//	
//	while ()
//	{
//		*str1 = *str2;
//		*(str1 + len - 1) = *(str2 + len - 1);
//		Sleep(1000);
//		system("cls");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//	char passwd[20] = { 0 };
//	printf("1min之内输入我是猪否则就关机\n");
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//		printf("请输入:");
//		scanf("%s", passwd);
//
//		if (strcmp(passwd, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			printf("取消关机\n");
//			break;
//		}
//		else
//		{
//			printf("请重新输入 否则关机\n");
//		}
//	}
//	return 0;
//}