#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[10001] = { 0 };//字符串最长10000
//	int row = 0;
//	while (gets(str) > 0) 
//	{
//		char* ptr = str;
//		char* word[10000] = { NULL };
//		while (*ptr != '\0') 
//		{
//			//如果是个字母字符，则是单词的起始字符
//			if (('z' >= *ptr && *ptr >= 'a') || ('Z' >= *ptr && *ptr >= 'A')) 
//			{
//				word[row++] = ptr;//保存每个单词的起始地址
//				//把本次的单词字母字符走完，直到遇到非字母字符
//				while (*ptr != '\0' && (('z' >= *ptr && *ptr >= 'a') || ('Z' >= *ptr && *ptr >= 'A'))) 
//				{
//					ptr++;
//				} 
//				continue;//不能继续向下，因为下边的ptr++会跳过当前的非字母字符
//			} 
//			*ptr = '\0';//把非字母的数据全部替换为结尾标志
//			ptr++;
//		}
//		for (int i = row - 1; i >= 0; i--)
//		{
//			printf("%s ", word[i]);//针对所有单词的起始地址逆序开始打印即可
//		}
//		printf("\n");
//	}
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[10001] = { 0 };
    int row = 0;
    scanf("%[^\n]", str);
    char* word[10001] = { NULL };
    char* ptr = str;
    //判断是不是字母，如果是字母，保存第一个字母的地址
    while (*ptr != 0)
    {
        if (isalpha(*ptr))
        {
            word[row++] = ptr;
            //将剩下的字母走完，直到遇到非字母
            while (*ptr != '\0' && isalpha(*ptr))
            {
                ptr++;
            }
            continue;
        }
        //遇到非字母，全部转换为结尾标志
        *ptr = '\0';
        ptr++;
    }
    int i = 0;
    for (i = row - 1; i >= 0; i--)
    {
        printf("%s ", word[i]);
    }
    printf("\n");
    ////while (gets(str) > 0)
    //{
    //    char* word[10001] = { NULL };
    //    char* ptr = str;
    //    //判断是不是字母，如果是字母，保存第一个字母的地址
    //    while (*ptr != 0)
    //    {
    //        if (isalpha(*ptr))
    //        {
    //            word[row++] = ptr;
    //            //将剩下的字母走完，直到遇到非字母
    //            while (*ptr != '\0' && isalpha(*ptr))
    //            {
    //                ptr++;
    //            }
    //            continue;
    //        }
    //        //遇到非字母，全部转换为结尾标志
    //        *ptr = '\0';
    //        ptr++;
    //    }
    //    int i = 0;
    //    for (i = row - 1; i >= 0; i--)
    //    {
    //        printf("%s ", word[i]);
    //    }
    //    printf("\n");
    //}
    return 0;
}