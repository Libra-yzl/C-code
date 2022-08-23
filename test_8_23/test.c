#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int* selfDividingNumbers(int left, int right, int* returnSize) {
//    *returnSize = 0;
//    int i = 0;
//    int nums[10000] = { 0 };
//    for (i = left; i <= right; i++)
//    {
//        int flag = 1;
//        int tmp = i;
//        do
//        {
//            tmp %= 10;
//            if (i % tmp != 0)
//            {
//                flag = 0;
//                break;
//            }
//        } while (tmp /= 10);
//        if (1 == flag)
//        {
//            nums[*returnSize] = i;
//            returnSize++;
//        }
//    }
//    return nums;
//}
//
//int main()
//{
//
//	return 0;
//}

//#include <stdio.h>
//
//int* selfDividingNumbers(int left, int right, int* returnSize)
//{
//    int* ret = (int*)calloc(1000, sizeof(int));//动态申请足够大的空间用于存放返回的自除数
//    *returnSize = 0;
//    for (int i = left; i <= right; i++)
//    {
//        int num = i;
//        while (num)
//        {
//            int tmp = num % 10;//计算余数
//            if (tmp == 0 || (i % tmp) != 0)
//            {//判断i自身与余数取模是否为0
//                break;
//            }
//            num /= 10;
//        }
//        //如果num==0表示通过了每一位数的取模判断，则i就是自除数
//        if (0 == num)
//        {
//            ret[(*returnSize)++] = i;
//        }
//        return ret;
//    }
//}
//
//int main()
//{
//
//	return 0;
//}

//int* selfDividingNumbers(int left, int right, int* returnSize) {
//    *returnSize = 0;
//    int i = 0;
//    int* nums = (int*)calloc(1000, sizeof(int));
//    for (i = left; i <= right; i++)
//    {
//        int flag = 1;
//        int tmp = i;
//        while (tmp)
//        {
//            tmp %= 10;
//            if (tmp == 0 || (i % tmp) != 0)
//            {
//                flag = 0;
//                break;
//            }
//            tmp /= 10;
//        }
//        if (1 == flag)
//        {
//            nums[(*returnSize)++] = i;
//        }
//    }
//    return nums;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    
//    return 0;
//}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int* num = (int*)malloc(numsSize * sizeof(int));//分配内存
    *returnSize = numsSize;
    int left = 1;
    int right = 1;
    int i = 0;    //第一次循环将每个元素左边的值累乘
    for (i = 0; i < numsSize; i++)
    {
        num[i] = left; //将每次累乘的left存下来
        left *= nums[i];
    }
    //第二次循环将每个元素右边的值累乘
    for (i = numsSize - 1; i >= 0; i--)
    {
        num[i] *= right;//将累乘的right与left相乘，得到除自身的乘积
        right *= nums[i];
    }
    return num;
}