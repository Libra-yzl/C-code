#define _CRT_SECURE_NO_WARNINGS 1
//��ϰ�ַ������Ŀ⺯����ģ��ʵ��

//ģ��ʵ��strlen��ʵ��

//#include <stdio.h>
//
//size_t my_strlen(const char* str)
//{
//	const char* start = str;
//	const char* end = str;
//	while (*end)
//	{
//		end++;
//	}
//	return (int)(end - start);
//}
//
//int main()
//{
//	char str[] = "hello bit!";
//	int ret = (int)my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}

//ģ��ʵ��strcmp

//#include <stdio.h>
//#include <assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')//�����ַ�����ȣ�����0
//			return 0;
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//
//int main()
//{
//	char str1[] = "abcdef";
//	char str2[] = "abcdgh";
//	int ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);
//	return 0;
//}


//ģ��ʵ��strcmp����
//#include <stdio.h>
//#include <assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char str1[] = "hello bit!";
//	char str2[] = "hello world!";
//	int ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//
//int main()
//{
//	char str1[] = "abcdef";
//	char str2[] = "abcdef";
//	int ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);
//	return 0;
//}


//ģ��ʵ��strcpy����
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)//��srcΪ'\0'ʱ������*dest����ʽ���Ϊ0��ѭ��ֹͣ
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "hello world!\n";
//	char str2[15];
//	printf("%s\n", my_strcpy(str2, str1));
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* s1 = dest;
//	while (*s1++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char str1[] = "hello bit!";
//	char str2[15];
//	/*char* ret = my_strcpy(str2, str1);
//	printf("%s\n", ret);*/
//	printf("%s\n", my_strcpy(str2, str1));
//	return 0;
//}