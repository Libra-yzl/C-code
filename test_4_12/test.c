#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    int* ret = (int*)malloc(2 * sizeof(int));
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i + 1; j < numsSize; j++)
//        {
//            if (nums[i] + nums[j] == target)
//            {
//                *(ret + 0) = i;
//                *(ret + 1) = j;
//                *returnSize = 2;
//                return ret;
//            }
//        }
//    }
//    *returnSize = 0;
//    return NULL;
//}
//
//int main()
//{
//    twoSum(nums, numsSize, target, returnSize);
//	return 0;
//}

#include <stdio.h>
#include <stddef.h>

#define OFFSETOF(s_type, s_memb) (int)&(((s_type*)0)->s_memb)

struct S
{
	char a;
	int b;
	char c;
};

int main()
{
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, b));
	printf("%d\n", OFFSETOF(struct S, c));
	/*printf("%d\n", offsetof(struct S, a));
	printf("%d\n", offsetof(struct S, b));
	printf("%d\n", offsetof(struct S, c));*/
	return 0;
}