#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[10001] = { 0 };//�ַ����10000
//	int row = 0;
//	while (gets(str) > 0) 
//	{
//		char* ptr = str;
//		char* word[10000] = { NULL };
//		while (*ptr != '\0') 
//		{
//			//����Ǹ���ĸ�ַ������ǵ��ʵ���ʼ�ַ�
//			if (('z' >= *ptr && *ptr >= 'a') || ('Z' >= *ptr && *ptr >= 'A')) 
//			{
//				word[row++] = ptr;//����ÿ�����ʵ���ʼ��ַ
//				//�ѱ��εĵ�����ĸ�ַ����ֱ꣬����������ĸ�ַ�
//				while (*ptr != '\0' && (('z' >= *ptr && *ptr >= 'a') || ('Z' >= *ptr && *ptr >= 'A'))) 
//				{
//					ptr++;
//				} 
//				continue;//���ܼ������£���Ϊ�±ߵ�ptr++��������ǰ�ķ���ĸ�ַ�
//			} 
//			*ptr = '\0';//�ѷ���ĸ������ȫ���滻Ϊ��β��־
//			ptr++;
//		}
//		for (int i = row - 1; i >= 0; i--)
//		{
//			printf("%s ", word[i]);//������е��ʵ���ʼ��ַ����ʼ��ӡ����
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
    //�ж��ǲ�����ĸ���������ĸ�������һ����ĸ�ĵ�ַ
    while (*ptr != 0)
    {
        if (isalpha(*ptr))
        {
            word[row++] = ptr;
            //��ʣ�µ���ĸ���ֱ꣬����������ĸ
            while (*ptr != '\0' && isalpha(*ptr))
            {
                ptr++;
            }
            continue;
        }
        //��������ĸ��ȫ��ת��Ϊ��β��־
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
    //    //�ж��ǲ�����ĸ���������ĸ�������һ����ĸ�ĵ�ַ
    //    while (*ptr != 0)
    //    {
    //        if (isalpha(*ptr))
    //        {
    //            word[row++] = ptr;
    //            //��ʣ�µ���ĸ���ֱ꣬����������ĸ
    //            while (*ptr != '\0' && isalpha(*ptr))
    //            {
    //                ptr++;
    //            }
    //            continue;
    //        }
    //        //��������ĸ��ȫ��ת��Ϊ��β��־
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