#define _CRT_SECURE_NO_WARNINGS 1


////#include <stdio.h>
////#include <math.h>
////
////int main()
////{
////    int m = 0;
////    scanf("%d", &m);
////    int start = m * m - (m - 1);
////    int k = m * m * m;
////    int count = 0;
////    printf("%d", start);
////    while (1)
////    {
////        count += start;
////        if (count == k)
////            break;
////        start += 2;
////        printf("+%d", start);
////    }
////    return 0;
////}
//
//#include <stdio.h>
//
//int main()
//{
//    long n = 0;
//    long k = 0;
//    while (~scanf("%ld %ld", &n, &k))
//    {
//        if (k == 0)
//        {
//            printf("%ld", n * n);
//            continue;
//        }
//        long count = 0;
//        for (long y = k + 1; y <= n; y++)
//        {
//            count += ((n / y) * (y - k)) + (n % y < k ? 0 : (n % y - k + 1));
//        }
//        printf("%ld", count);
//    }
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    char str[1001] = { 0 };
//    scanf("%s", str);
//    int k = 0;
//    scanf("%d", &k);
//    int i = 0;
//    for (i = 0; i < k; i++)
//    {
//        printf("%c", str[i]);
//    }
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    char str[1001] = { 0 };
//    scanf("%s", str);
//    int k = 0;
//    scanf("%d", &k);
//    str[k] = '\0';
//    printf("%s", str);
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    int year = 0;
//    int month = 0;
//    int data = 0;
//    scanf("%d %d %d", &year, &month, &data);
//    int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//    {
//        day[2]++;
//    }
//    int i = 0;
//    int days = 0;
//    for (i = 0; i < month; i++)
//    {
//        days += day[i];
//    }
//    days += data;
//    printf("%d", days);
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    int m = 0;
//    scanf("%d", &m);
//    int start = m * m - (m - 1);
//    int k = m * m * m;
//    int count = 0;
//    printf("%d", start);
//    while (1)
//    {
//        count += start;
//        if (count == k)
//            break;
//        start += 2;
//        printf("+%d", start);
//    }
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int count_max = 0;
//    int count_min = 0;
//    int m = 0;
//    long double sum = 0;
//    int flag = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &m);
//        if (0 == m)
//            continue;
//        else if (m < 0)
//        {
//            count_min++;
//            continue;
//        }
//        else
//        {
//            count_max++;
//            sum += m;
//            flag = 1;
//        }
//    }
//    long double aver = 0;
//    if (0 == flag)
//    {
//        aver = 0.0;
//    }
//    else
//    {
//        aver = sum / count_max;
//    }
//    printf("%d %.1llf", count_min, aver);
//    return 0;
//}
//
//int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
//    // write code here
//    int left = 0;
//    int right = rotateArrayLen - 1;
//    if (rotateArrayLen == 1)
//        return rotateArray[0];
//    if (rotateArray[left] < rotateArray[right])
//        return rotateArray[0];
//    while (left < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (rotateArray[mid] > rotateArray[right])
//            left = mid + 1;
//        else if (rotateArray[mid] < rotateArray[right])
//            right = mid;
//        else//如果相等的时候，无法判断，右边界缩减，继续判断
//            right--;
//    }
//    return rotateArray[right];
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//    qsort(nums, numsSize, sizeof(nums[0]), cmp);
//    int* arr = malloc(sizeof(int) * 2);
//    *returnSize = 2;
//    int i = 0;
//    if (nums[0] != 1)
//    {
//        arr[1] = 1;
//    }
//    if (nums[numsSize - 1] != numsSize)
//    {
//        arr[1] = numsSize;
//    }
//    int tmp = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        int curr = nums[i];
//        if (tmp == curr)
//        {
//            arr[0] = tmp;
//        }
//        else if (curr - tmp > 1 && nums[0] == 1)
//        {
//            arr[1] = tmp + 1;
//        }
//        tmp = curr;
//    }
//    return arr;
//}
//


#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int n = 0;
//again:
    while (~scanf("%d", &n))
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            char psd[101] = { 0 };
            scanf("%s", psd);
            int flag_low = 0;
            int flag_upp = 0;
            int flag_dig = 0;
            char* left = psd;
            //int* right = psd + (int)strlen(psd) - 1;
            while (*left != '\0')
            {
                if (isupper(*left) || islower(*left) || isdigit(*left))
                {
                    if (isupper(*left))
                        flag_upp = 1;
                    else if (islower(*left))
                    {
                        flag_dig = 1;
                    }
                    else if (isdigit(*left))
                    {
                        flag_low = 1;
                    }
                }
                else
                {
                    printf("NO\n");
                    continue;
                    //goto again;
                }
                left++;
            }
            if (isdigit(psd[0]))
            {
                printf("NO\n");
                //goto again;
                continue;
            }
            if (strlen(psd) < 8)
            {
                printf("NO\n");
                //goto again;
                continue;
            }
            if (flag_dig + flag_low + flag_upp < 2)
            {
                printf("NO\n");
                //goto again;
                continue;
            }
            printf("YES\n");
        }
    }
    return 0;
}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int n = 0;
//    while (~scanf("%d", &n))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            char pwd[101] = { 0 };
//            scanf("%s", pwd);
//            int lower = 0, higher = 0, digit = 0, other = 0;
//            if (pwd[0] >= '0' && pwd[0] <= '9')
//            {
//                printf("NO\n");
//                continue;
//            }//密码不能以数字开头
//            if (strlen(pwd) < 8)
//            {
//                printf("NO\n");
//                continue;
//            }//密码长度至少为8
//            for (int i = 0; pwd[i] != '\0'; i++)
//            {
//                if (pwd[i] >= '0' && pwd[i] <= '9')
//                    digit++;//数字
//                else if (pwd[i] >= 'a' && pwd[i] <= 'z')
//                    lower++;//小写字母
//                else if (pwd[i] >= 'A' && pwd[i] <= 'Z')
//                    higher++;//大写字母
//                else
//                    other++;
//            }
//            if (other != 0)
//            {
//                printf("NO\n");
//                continue;
//            }// 密码只能由大写字母，小写字母，数字构成
//          //大写，小写，数字，必须具有两种以上，而比较运算真则1，假则0
//            if ((lower > 0) + (higher > 0) + (digit > 0) < 2)
//            {
//                printf("NO\n");
//                continue;
//            }//密码只有1种字符
//            printf("YES\n");
//        }
//    }
//    return 0;
//}