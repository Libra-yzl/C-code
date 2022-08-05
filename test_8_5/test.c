#define _CRT_SECURE_NO_WARNINGS 1
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分

//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//
//void odd(int* arr,int sz)
//{
//	assert(arr);//断言  --判断是否为空
//	int* left = arr;
//	int* right =arr + sz - 1;
//	while (left <= right)
//	{
//		if (*left % 2 == 0)
//		{
//			int tmp = *left;
//			*left = *right;
//			*right = tmp;
//			continue;
//		}
//		left++;
//		right--;
//	}
//	/*int i = 0;*/
//	/*int j = 0;
//	for (i = 0; i < sz/2; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (1 == flag)
//			break;
//	}*/
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	odd(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//模拟实现strccpy函数
// 
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcpy(char* det, const char* src)
//{
//	assert(det && src); //断言，判断是否为空指针
//	/*while (*src)
//	{
//		*det = *src;
//		det++;
//		src++;
//	}*/
//	//优化
//	char* tmp = det;
//	while (*det++ = *src++)
//	{
//		;
//	}
//	return tmp; //不能直接返回det 因为上面的det++改变了det的值
//	            //而strcpy函数的返回值时目标空间的起始位置
//}
//int main()
//{
//	char arr1[] = "hello bit!";
//	char arr2[] = "**************"; //打印多个观察是否传递'\0'
//	/*strcpy(arr2, arr1);
//	printf("%s\n", arr2);*/
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

////模拟实现库函数strlen
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//int my_strlen(const char* str)
//{
//	assert(str);//断言，是否为空
//	int ret = 0;
//	while (*str++)
//	{
//		ret++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "I am a bit person!";
//	int len = (int)strlen(arr);
//	int ret_len = my_strlen(arr);
//	printf("%d\n", len);
//	printf("%d\n", ret_len);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int arr[50];
//    int n = 0;
//    int flag1 = 0;
//    int flag2 = 0;
//    scanf("%d", &n);
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i < n - 1 ; i++)
//    {
//        if (arr[i] >= arr[i + 1])
//            flag1 = 1;
//        else if (arr[i] < arr[i + 1])
//            flag2 = 2;
//    }
//    if (flag1 && flag2)
//        printf("unsorted\n");
//    else
//        printf("sorted\n");
//    return 0;
//}

#include <stdio.h>

/*#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int gra[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &gra[i]);
    }
    int high = gra[0];
    int low = gra[0];
    for (i = 0; i < n; i++)
    {
        if (gra[i] > high)
            high = gra[i];
        else if (gra[i] < low)
            low = gra[i];
    }
    printf("%d", high - low);
    return 0;
}*/
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int k = 0;
    //成绩最高是100，最低是0，给high = 0，遍历整个序列
    //将较大值给，high最后high会是最大值，
    //反之，给low = 100，最后会是最小值
    int high = 0;
    int low = 100;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k > high)
            high = k;
        if (k < low)
            low = k;
    }
    printf("%d", high - low);
    return 0;
}