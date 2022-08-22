#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//int main()
//{
//    char str[501] = { 0 };
//    scanf("%s", str);
//    char tmp[128] = { 0 };
//    char* ptr = str;
//    int count = 0;
//    while (*ptr)
//    {
//        if (tmp[*ptr] != 1)
//        {
//            count++;
//        }
//        tmp[*ptr++] = 1;
//    }
//    printf("%d", count);
//    return 0;
//}

//int majorityElement(int* nums, int numsSize) {
//    int tmp = *nums;
//    int count = 0;
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (tmp == nums[i])
//        {
//            count++;
//        }
//        else
//        {
//            count--;
//            if (count == 0)
//            {
//                tmp = nums[i + 1];
//            }
//        }
//    }
//    return tmp;
//}

