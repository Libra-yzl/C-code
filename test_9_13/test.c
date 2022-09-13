#define _CRT_SECURE_NO_WARNINGS 1

//模拟实现strlen函数
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//size_t my_strlen(const char* arr)
//{
//	assert(arr);
//	const char* p1 = arr;
//	const char* p2 = arr;
//	while (*p1)
//	{
//		p1++;
//	}
//	return  p1 - p2;
//}
//
//int main()
//{
//	char arr[] = "abcdefghi j";
//	int len = (int)strlen(arr);
//	int my_len = (int)my_strlen(arr);
//	printf("len = %d\nmy_len = %d\n", len, my_len);
//	return 0;
//}

//模拟实现strcpy
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*src)
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "hello bit";
//	char str2[20] = { 0 };
//	char str3[20] = { 0 };
//	strcpy(str2, str1);
//	my_strcpy(str3, str1);
//	printf("%s\n", str2);
//	printf("%s\n", str3);
//	return 0;
//}

////模拟实现strcmp
//#include <stdio.h>
//#include <string.h>
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
//	/*char str1[] = "hello bit!";
//	char str2[] = "hello world!";*/
//	char str1[] = "abcdef";
//	char str2[] = "abbcdefg";
//	int ret1 = strcmp(str1, str2);
//	int ret2 = my_strcmp(str1, str2);
//	printf("ret1 = %d\n", ret1);
//	printf("ret2 = %d\n", ret2);
//	return 0;
//}

//模拟实现strcat--->字符追加函数
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* tmp = dest;
//	while (*++tmp)
//	{
//		;
//	}
//	while (*tmp++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char str1[10] = "abc";
//	char str2[] = "abc";
//	char str3[10] = "abc";
//	char str4[] = "abc";
//	strcat(str1, str2);
//	my_strcat(str3, str4);
//	printf("%s\n", str1);
//	printf("%s\n", str3);
//	return 0;
//}

//模拟实现strstr

#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && (* s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//s2为0的时候就找说明找到了子串
			return (char*)p;
		p++;
	}
	return NULL;
}

int main()
{
	char str1[] = "abcdabcd";
	char str2[] = "bcd";
	char* ret = strstr(str1, str2);
	char* my_ret = my_strstr(str1, str2);
	//if (ret == NULL)
	if(my_ret == NULL)
	{
		printf("不存在\n");
	}
	else
	{
		//printf("%s\n", ret);
		printf("%s\n", my_ret);
	}
	return 0;
}