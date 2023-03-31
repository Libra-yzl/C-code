#define _CRT_SECURE_NO_WARNINGS 1

////喝汽水 1瓶汽水1元 2个空瓶可以换一瓶汽水 给20元 可以多少汽水
//#include <stdio.h>
//
//int main()
//{
//	int money = 0;
//
//	while (scanf("%d", &money) != EOF)
//	{
//		int total = money;
//		int empty = money;
//
//		/*while (empty >= 2)
//		{
//			total += empty / 2;
//			empty = empty / 2 + empty % 2;
//		}*/
//
//		if (money > 0)
//		{
//			total = 2 * money - 1;
//		}
//		else
//		{
//			total = 0;
//		}
//
//		printf("%d\n", total);
//	}
//	return 0;
//}

////变种水仙花数
////655 = 6 * 55 + 65 * 5
////1425 = 1 * 425 + 14 * 25 + 142 * 5
//
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    for (int i = 10000; i < 100000; i++)
//    {
//        //判断是否为Lily Number
//        int sum = 0;
//        int tmp = i;
//        int j = 1;
//        while (j <= 5)
//        {
//            sum += (tmp % (int)pow(10, j)) * (tmp / (int)pow(10, j));
//            j++;
//        }
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//
//    return 0;
//}



////输入一个数组 实现一个函数
////调整数组中数字的顺序使所有奇数位于数组的前半部分
//
//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//
//		while (arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		while (arr[right] % 2 == 0)
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
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


////模拟实现strcpy strlen
//#include <stdio.h>
//#include <string.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//
//char* my_strcpy(char* str1,char* str2)
//{
//	char* start = str1;
//
//	while (*str1++ = *str2++);
//	return start;
//}
//
//int main()
//{
//	char str1[20] = { 0 };
//	char str2[] = "I like you";
//	
//	/*printf("%d\n", (int)strlen(str));
//	printf("%d\n", my_strlen(str));*/
//
//	printf("%s\n", strcpy(str1, str2));
//	printf("%s\n", my_strcpy(str1, str2));
//	return 0;
//}


//判断序列是否有序






//最低分最高分之差




//有序序列合并


