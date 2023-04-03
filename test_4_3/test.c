#define _CRT_SECURE_NO_WARNINGS 1

//字符串函数

////模拟实现strlen
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	const char* start = str;
//	const char* end = str;
//	while (*end)
//	{
//		end++;
//	}
//	return end - start;
//}
//
//int main()
//{
//	const char* str = "";
//	printf("%d\n", (int)strlen(str));
//	printf("%d\n", (int)my_strlen(str));
//	return 0;
//}

////strcpy
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcpy(char* str1, const char* str2)
//{
//	assert(str1 && str2);
//
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return str1;
//}
//
//int main()
//{
//	char str1[20] = { 0 };
//	const char* str2 = "abcdef";
//	my_strcpy(str1, str2);
//	printf("%s\n", str1);
//	return 0;
//}

////strcat
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//
//	char* start = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return start;
//}
//
//int main()
//{
//	char str[20] = "abcdef";
//	const char* str1 = "ghi";
//	printf("%s\n", my_strcat(str, str1));
//	return 0;
//}

////strcmp
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//
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
//	const char* str1 = "";
//	const char* str2 = "";
//	if (my_strcmp(str1, str2) > 0)
//		printf("str1 > str2\n");
//	else if (my_strcmp(str1, str2) < 0)
//		printf("str1 < str2\n");
//	else
//		printf("str1 = str2\n");
//	return 0;
//}

////strncpy
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	size_t count = num;
//	char* start = dest;
//	while (count && (*dest++ = *src++))
//	{
//		count--;
//	}
//	if (count)
//	{
//		while (count)
//		{
//			count--;
//			*dest++ = '\0'; //用0填充
//		}
//	}
//	return start;
//}
//
//int main()
//{
//	char str1[20] = {0};
//	const char* str2 = "abcdef";
//	my_strncpy(str1, str2, 17);
//	printf("%s\n", str1);
//	return 0;
//}

////strncmp
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//int my_strncmp(const char* str1, const char* str2, size_t num)
//{
//	if (!num)
//		return 0;
//
//	size_t count = num;
//
//	while (count && (*str1 == *str2))
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//		count--;
//	}
//	return *str1 - *str2;
//}
//
//int main()
//{
//	const char* str1 = "abcd   f   gghi";
//	const char* str2 = "abcd   f   gg k";
//
//	if (my_strncmp(str1, str2, 15) > 0)
//		printf(">");
//	else if (my_strncmp(str1, str2, 15) < 0)
//		printf("<");
//	else
//		printf("=");
//	return 0;
//}

////strncat
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//
//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//
//	char* start = dest;
//	if (!num)
//		return start;
//
//	size_t count = num;
//	while (*dest)
//	{
//		dest++;
//	}
//
//	while (count && (*dest++ = *src++))
//	{
//		count--;
//	}
//	if (count)
//	{
//		while (count)
//		{
//			count--;
//			*dest = '\0';
//		}
//	}
//	else
//	{
//		*dest = '\0';
//	}
//
//	return start;
//}
//
//int main()
//{
//	//char str1[20] = "abcdefg\0qq";
//	char str1[20] = "abcd";
//	const char* str2 = "hijk";
//	my_strncat(str1, str1, 4);
//	printf("%s\n", str1);
//	return 0;
//}


