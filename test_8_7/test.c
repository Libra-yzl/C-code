#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void rev(char* left,char*right)
//{
//    assert(left && right);
//    int left1 = 0;
//    int right1 = *right - *left;
//    while (left < right)
//    {
//        /*if (*left == '.')
//        {
//            *(str + len) = *left;
//        }
//        else if (*right == '.')
//        {
//            *(str + len) = *right;
//        }*/
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//int main()
//{
//    char str[101] = { 0 };
//    scanf("%[^\n]", str);
//    int len = (int)strlen(str);
//    char* left = str;
//    char* right = str + len - 1;
//   /* int count = 0;
//    while (left <= right)
//    {
//        if (*left >= '!' && *left <= '.')
//        {
//            count++;
//            char tmp = *left;
//            *left = *right;
//            *right = tmp;
//        }
//        left++;
//    }*/
//    /*left = str;
//    right = str + len - cou;*/
//    rev(left, right);
//    //*(str + len - 1) = *(str + len);
//    left = str;
//    right = str;
//    while (*left != '\0')
//    {
//        while (*right != ' ' && *right != '\0')
//        {
//            right++;
//        }
//        rev(left, right - 1);
//        left = right + 1;
//        right = left;
//    }
//    printf("%s", str);
//    return 0;
//}

#include <stdio.h>

void rev()
{
	char arr[101];
	if (scanf("%s", arr) != EOF)
	{
		rev(arr);
		printf("%s ", arr);
	}
}
int main()
{
	rev();
	return 0;
}