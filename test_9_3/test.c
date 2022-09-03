#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int* selfDividingNumbers(int left, int right, int* returnSize)
//{
//    int i = 0;
//    int flag = 1;
//    *returnSize = 0;
//    int* nums = (int*)calloc(1000, sizeof(int));
//    for (i = left; i <= right; i++)
//    {
//        int tmp = i;
//        while (tmp % 10)
//        {
//            if (i % tmp != 0)
//            {
//                flag = 0;
//                break;
//            }
//            tmp /= 10;
//            if (tmp == 0)
//                break;
//        }
//        if (1 == flag)
//            nums[(*returnSize)++] = i;
//
//    }
//    return nums;
//}

int main()
{
    int left = 0;
    int right = 0;
    int j = 0;
    scanf("%d %d", &left, &right);
    int i = 0;
    int flag = 1;
    int nums[20] = { 0 };
    for (i = left; i <= right; i++)
    {
        int tmp = i;
        while (tmp %= 10)
        {
            if (i % tmp != 0)
            {
                flag = 0;
                break;
            }
            tmp /= 10;
            if (tmp == 0)
                break;
        }
        if (1 == flag)
        {
            nums[j] = i;
            j++;
        }

    }
    for (i = 0; i < j; i++)
        printf("%d ", nums[i]);
	return 0;
}