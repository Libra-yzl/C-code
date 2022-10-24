#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//bool isPalindrome(int x) {
//    if (x < 0 || (x % 10 == 0 && x != 0))
//        return false;
//    int tmp = 0;
//    while (tmp < x)
//    {
//        tmp = tmp * 10 + x % 10;
//        x /= 10;
//    }
//    if (tmp == x || tmp / 10 == x)
//    {
//        return true;
//    }
//    return false;
//}
//
//int main()
//{
//    int x = 0;
//    scanf("%d", &x);
//    bool ret = isPalindrome(x);
//    printf("%d\n", ret);
//	return 0;
//}

//char bra(char s)
//{
//    if (s == '(')
//        return ')';
//    else if (s == '{')
//        return '}';
//    else if (s == '[')
//        return ']';
//    return 0;
//}
//
//bool isValid(char* s) {
//    int n = (int)strlen(s);
//    if (n % 2 == 1)
//        return false;
//    char stack[6];
//    int top = 0;
//    for (int i = 0; i < n; i++)
//    {
//        char ch = s[i];
//        if (ch == '(' || ch == '[' || ch == '{')
//        {
//            stack[top++] = bra(ch);
//        }
//        else if (top == 0 || stack[top-1] != ch)
//            return false;
//        else
//            top--;
//    }
//    if (top)
//        return false;
//    return true;
//}
//
//int main()
//{
//    char s[] = "([][])";
//    bool ret = isValid(s);
//    printf("%d\n", ret);
//    return 0;
//}

//int removeElement(int* nums, int numsSize, int val) {
//    int fast = 0;
//    int slow = 0;
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[fast] != val)
//        {
//            nums[slow] = nums[fast];
//            slow++;
//        }
//        fast++;
//    }
//    return slow;
//}

int removeElement(int* nums, int numsSize, int val) {
    int right = numsSize;
    int left = 0;
    int i = 0;
    while (left < right)
    {
        if (nums[left] == val)
        {
            nums[left] = nums[right - 1];
            right--;
        }
        else
        {
            left++;
        }
    }
    return right;
}

int main()
{
    int nums[] = { 3,2,2,3,4,5,6,7 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;
    int ret = removeElement(nums, numsSize, val);
    int i = 0;
    for (i = 0; i < ret; i++)
    {
        printf("%d ", nums[i]);
    }
	return 0;
}