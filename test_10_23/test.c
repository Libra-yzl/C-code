#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <time.h>
//
//int main()
//{
//	int begin = clock();
//	int i = 0;
//	int n = 0;
//	for (i = 0; i < 100000000; i++)
//	{
//		n++;
//	}
//	int end = clock();
//	printf("%dms\n", end - begin);
//	return 0;
//}

#include <stdio.h>

int main()
{
    int nums[] = { 1,2,3,4,5,6,7 };
    int k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i = 0;
    for (i = 0; i < numsSize / 2; i++)
    {
        int tmp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }
    for (i = 0; i < k / 2; i++)
    {
        int tmp = nums[i];
        nums[i] = nums[k - 1 - i];
        nums[k - 1 - i] = tmp;
    }
    for (i = 0; i < (numsSize - k) / 2; i++)
    {
        int tmp = nums[i + k];
        nums[i + k] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }
    for (i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
	return 0;
}
