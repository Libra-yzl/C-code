#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//#include <math.h>
//
//int isPalindrome(int x) {
//    // if (x < 0 || (x % 10 == 0 && x != 0))
//    //     return false;
//    // int tmp = 0;
//    // while (tmp < x)
//    // {
//    //     tmp = tmp * 10 + x % 10;
//    //     x /= 10;
//    // }
//    // if (tmp == x || tmp/10 == x)
//    //     return true;
//    // else
//    //     return false;
//
//    char arr[100] = {0};
//    int i = 0;
//    int tmp = x;
//    int count = 0;
//    while (tmp)
//    {
//        arr[i] = tmp % 10;
//        i++;
//        tmp /= 10;
//        count++;
//    }
//    tmp = 0;
//    int count_pow = count;
//    for (i = 0; i < count; i++)
//    {
//        tmp += arr[i] * (int)pow(10, count_pow-1);
//        count_pow--;
//    }
//    if (tmp == x)
//        return 1;
//    return 0;
//}
//
//int main()
//{
//    int x = 0;
//    scanf("%d", &x);
//    printf("%d\n", isPalindrome(x));
//	return 0;
//}

//#include <stdio.h>
//#include <limits.h>
//#include <ctype.h>
//
//
//int myAtoi(char* s) {
//    while (isspace(*s))
//    {
//        s++;
//    }
//    //默认是正数
//    int flag = 1;
//    if (*s == '+')
//    {
//        s++;
//    }
//    else if (*s == '-')
//    {
//        flag = -1;
//        s++;
//    }
//    //处理数字
//    long ret = 0;
//    while (isdigit(*s))
//    {
//        ret = ret * 10 + flag * (*s - '0');
//        if (ret < INT_MIN)
//            ret = INT_MIN;
//        else if (ret > INT_MAX)
//            ret = INT_MAX;
//        s++;
//    }
//
//    return ret;
//}
//
//int main()
//{
//    printf("%d", myAtoi("123"));
//    return 0;
//}