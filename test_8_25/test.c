#define _CRT_SECURE_NO_WARNINGS 1

//int findMaxConsecutiveOnes(int* nums, int numsSize) {
//    int i = 0;
//    int count = 0;
//    int arr[10001] = { 0 };
//    for (i = 0; i < numsSize; i++)
//    {
//        if (1 == nums[i])
//        {
//            count++;
//        }
//        else
//        {
//            arr[i] = count;
//            count = 0;
//            continue;
//        }
//    }
//    if (i == numsSize)
//    {
//        arr[i] = count;
//    }
//    int max = 0;
//    for (i = 0; i < 10001; i++)
//    {
//        if (max < arr[i])
//        {
//            max = arr[i];
//        }
//    }
//    return max;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int count = 0;
//    for (i = 2; i <= n; i++)
//    {
//        int sum = 1;//sum为1，下面就不用计算1 * i（本身）了
//        int j = 0;
//        for (j = 2; j <= sqrt(i); j++)//自身不用加了
//        {
//            if (i % j == 0)
//            {
//                sum += j;
//                if (j != sqrt(i))
//                {
//                    sum += i / j;
//                }
//            }
//        }
//        if (sum == i)
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int count = 0;
//    for (i = 1; i < n; i++)
//    {
//        int sum = 0;
//        int j = 0;
//        for (j = 1; j <= i; j++)
//        {
//            if (i % j == 0)
//            {
//                if (i == j)
//                    break;
//                sum += j;
//            }
//        }
//        if (sum == i)
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i = 0;
    int count = 0;
    int arr[10001] = { 0 };
    for (i = 0; i < numsSize; i++)
    {
        if (1 == nums[i])
        {
            count++;
        }
        else
        {
            arr[i] = count;
            count = 0;
            continue;
        }
    }
    if (i == numsSize)
    {
        arr[i] = count;
    }
    int max = 0;
    for (i = 0; i < 10001; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}