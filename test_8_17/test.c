#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//    int i = 0;
//    int flag = 0;
//    int tmp = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] < nums[i + 1] - 1)
//        {
//            flag = nums[i + 1] - 1;
//        }
//        if (nums[i] == nums[i + 1])
//        {
//            tmp = nums[i + 1];
//            nums[i + 1] = flag;
//        }
//    }
//    int num[2] = { 0 };
//    num[0] = tmp;
//    num[1] = flag;
//    return (*num);
//}
//
//int main()
//{
//    int nums[4] = { 1,2,2,4 };
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    int* returnSize;
//	int* p = findErrorNums()
//	return 0;
//}


#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int digit = 0;
    int lower = 0;
    int higher = 0;
    int other = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            char pwd[101];
            scanf("%s", pwd);
            if (pwd[0] >= '0' && pwd[0] <= '9')
            {
                printf("NO\n");
                continue;
            }
            if (strlen(pwd) < 8)
            {
                printf("NO\n");
                continue;
            }
            for (int i = 0; pwd[i] != '\0'; i++)
            {
                if (pwd[i] >= '0' && pwd[i] <= '9')
                    digit++;
                else if (pwd[i] >= 'a' && pwd[i] <= 'z')
                    lower++;
                else if (pwd[i] >= 'A' && pwd[i] <= 'Z')
                    higher++;
                else
                    other++;
            }
            if (other != 0)
            {
                printf("NO\n");
                continue;
            }
            if ((lower > 0) + (higher > 0) + (digit > 0) < 2)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
        }
    }
    return 0;
} 

