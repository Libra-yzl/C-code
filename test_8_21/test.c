#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int compare_str(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//
//int main()
//{
//    //int n = 0;
//    char str[1001] = {0};
//    scanf("%s", str);
//    int len = (int)strlen(str);
//    qsort(str, len, sizeof(char), compare_str);
//    printf("%s\n", str);
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[1001] = { 0 };
//    scanf("%s", str);
//    int len = (int)strlen(str);
//    int i = 0;
//    for (i = 0; i < len - 1; i++)
//    {
//        int flag = 1;
//        int j = 0;
//        for (j = 0; j < len - 1 - i; j++)
//        {
//            if (str[j] > str[j + 1])
//            {
//                char tmp = str[j];
//                str[j] = str[j + 1];
//                str[j + 1] = tmp;
//                flag = 0;
//            }
//        }
//        if (1 == flag)
//        {
//            break;
//        }
//    }
//    printf("%s", str);
//    return 0;
//}

//#include <stdio.h>
//
//int pivotIndex(int* nums, int numsSize) {
//	int i, j;
//	for (i = 0; i < numsSize; i++) 
//	{//从假设中心点为0开始进行统计判断
//		int l_sum = 0;
//		int r_sum = 0;//初始化左边之和和右边之和为0
//		for (j = 0; j < numsSize; j++)
//		{
//			if (j < i) 
//				l_sum += nums[j]; //小于i坐标的都是左边的数字
//			else if (j > i) 
//				r_sum += nums[j];//大于i坐标的都是右边的数字
//		} 
//		if(l_sum == r_sum) 
//		{//如果两遍相等则i就是中心坐标
//			return i;
//		}
//	} 
//	return - 1;
//}
//
//int main()
//{
//	int nums[6] = { 1,1,-1,1,-1,-1 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = pivotIndex(nums, numsSize);
//	printf("ret = %d\n", ret);
//	return 0;
//}


//#include <stdio.h>
//
////斐波那契数列递归实现
//
//int Fib1(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib1(n - 1) + Fib1(n - 2);
//}
//
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
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
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib1(n);
//	printf("ret = %d\n", ret);
//	ret = Fib(n);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//
//int Fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fac(n);
//	printf("ret = %d\n", ret);
//	int i = 0;
//	ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("ret = %d\n", ret);
//	return 0;
//}
