#define _CRT_SECURE_NO_WARNINGS 1

//ģ��ʵ��strcat�������ַ�׷�Ӻ�����

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

//ģ��ʵ��strstr����

//#include <stdio.h>
//
////��һ���㷨--KMP�㷨--���ش󺼸�
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
//			return p;//�ҵ���
//		}
//		p++;
//	}
//	return NULL;//û�ҵ�
//}
//
//int main()
//{
//	char str1[] = "abcdefabcdef";
//	char str2[] = "def";
//	char* ret = my_strstr(str1, str2);
//	if (ret != NULL)
//		printf("������\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}
// 
////ģ��ʵ��strstr����
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
//		if (*s2 == '\0')//�ҵ���
//			return (char*)p;
//		p++;
//	}
//	return NULL;//������
//}
//
//int main()
//{
//	char str1[] = "abbbccdef";
//	char str2[] = "bcd";
//	char* ret = my_strstr(str1, str2);
//	if (ret == NULL)
//		printf("������\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}
//ģ��ʵ��memcpy����

//ģ��ʵ��memmove����

