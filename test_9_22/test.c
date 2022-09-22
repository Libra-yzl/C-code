#define _CRT_SECURE_NO_WARNINGS 1

//模拟实现strcat函数（字符追加函数）

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* s1 = dest;
//	while ( *s1)
//	{
//		s1++;
//	}
//	while (*s1++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char str1[10] = "hello ";
//	char str2[] = "bit";
//	//printf("%s\n", strcat(str1, str2));
//	printf("%s\n", my_strcat(str1, str2));
//	return 0;
//}

//模拟实现strstr函数

//#include <stdio.h>
//
////有一种算法--KMP算法--比特大杭哥
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* ps1 = str1;
//	char* ps2 = str2;
//	char* p = str1;
//	while (*p)
//	{
//		ps1 = p;
//		ps2 = str2;
//		while (*ps1 == *ps2 && *ps1 != '\0' && *ps2 != '\0')
//		{
//			ps1++;
//			ps2++;
//		}
//		if (*ps2 == '\0')
//		{
//			return p;//找到了
//		}
//		p++;
//	}
//	return NULL;//没找到
//}
//
//int main()
//{
//	char str1[] = "abcdefabcdef";
//	char str2[] = "def";
//	char* ret = my_strstr(str1, str2);
//	if (ret != NULL)
//		printf("不存在\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}
// 
////模拟实现strstr函数
//#include <stdio.h>
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//找到了
//			return (char*)p;
//		p++;
//	}
//	return NULL;//不存在
//}
//
//int main()
//{
//	char str1[] = "abbbccdef";
//	char str2[] = "bcd";
//	char* ret = my_strstr(str1, str2);
//	if (ret == NULL)
//		printf("不存在\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}
//模拟实现memcpy函数

//模拟实现memmove函数

