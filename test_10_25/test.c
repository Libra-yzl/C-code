#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int searchInsert(int* nums, int numsSize, int target) {
//    if (target > nums[numsSize - 1])
//        return numsSize;
//    else if (target < nums[0])
//        return 0;
//    int left = 0;
//    int right = numsSize;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] == target)
//            return mid;
//        else if (target < nums[mid])
//        {
//            right = mid - 1;
//        }
//        else if (target > nums[mid])
//        {
//            left = mid;
//        }
//    }
//    return right;
//}
//
//int main()
//{
//	return 0;
//}


//int searchInsert(int* nums, int numsSize, int target) {
//    int left = 0;
//    int right = numsSize;
//    while (left < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (target > nums[mid])
//            left = mid + 1;
//        else
//            right = mid;
//    }
//    return left;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    return 0;
//}

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int index = len - 1;
    //����ո�
    while (isspace(s[index]))
    {
        index--;
    }
    int digit_count = 0;
    while (index >= 0 && !isspace(s[index]))//ѭ������һ�������ո����
    {
        digit_count++;
        index--;
    }
    return digit_count;
}

#include <stdio.h>

int main()
{

	return 0;
}