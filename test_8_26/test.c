#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* str)
//{
//    int len = (int)strlen(str);
//    char* left = str;
//    char* right = str + len - 1;
//    while (left < right)
//    {
//        char tmp = 0;
//        tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//
//int main()
//{
//    char str[32] = { 0 };
//    while (scanf("%s", str) != EOF)
//    {
//        reverse(str);
//        printf("%s\n", str);
//    }
//    return 0;
//}

#include <stdio.h>
#include <string.h>

void reverse(char* str)
{
    int len = (int)strlen(str);
    char tmp = *str;
    *str = *(str + len - 1);
    *(str + len - 1) = '\0';
    if (*(str + 1) > 1)
        reverse(str + 1);
    *(str + len - 1) = tmp;
}

int main()
{
    char num[32] = { 0 };
    while (scanf("%s", num) != EOF)
    {
        reverse(num);
        printf("%s\n", num);
    }
    return 0;
}