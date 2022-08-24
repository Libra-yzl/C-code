#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
////写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		while (a)
//		{
//			int tmp = a ^ b;
//			a = (a & b) << 1;
//			b = tmp;
//		}
//		printf("%d\n", b);
//	}
//	return 0;
//}


//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int* ret = (int*)malloc(sizeof(int) * (numsSize));
//    *returnSize = 0;
//    int i = 0;
//    for (i = 1; i <= numsSize; i++)
//    {
//        int j = 0;
//        int flag = 1;
//        for (j = 0; j < numsSize; j++)
//        {
//            if (i == nums[j])
//            {
//                flag = 0;
//                break;
//            }
//        }
//        if (1 == flag)
//        {
//            ret[(*returnSize)++] = i;
//        }
//    }
//    return ret;
//}

//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
//{
//    for (int i = 0; i < numsSize; i++) 
//    {
//        int x = (nums[i] - 1) % numsSize;
//        nums[x] += numsSize;
//    }
//    int* ret = malloc(sizeof(int) * numsSize);
//    *returnSize = 0;
//    for (int i = 0; i < numsSize; i++) 
//    {
//        if (nums[i] <= numsSize) 
//        {
//            ret[(*returnSize)++] = i + 1;
//        }
//    }
//    return ret;
//}


//#include <stdio.h>
//
//int main()
//{
//	printf("%d", 0 % 2);
//	return 0;
//}