#define _CRT_SECURE_NO_WARNINGS 1
//复习字符操作的库函数的模拟实现

//模拟实现strlen的实现

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

//模拟实现strcmp

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
//		if (*s1 == '\0')//两个字符串相等，返回0
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


//模拟实现strcmp函数
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


//模拟实现strcpy函数
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)//当src为'\0'时，传给*dest后表达式结果为0，循环停止
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