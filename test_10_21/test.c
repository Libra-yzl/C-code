#define _CRT_SECURE_NO_WARNINGS 1

//����ˢ��

//#include <stdio.h>
//#include <limits.h>
//#include <ctype.h>
//
//
//enum Status
//{
//	VALID,
//	INVALID
//};
//
//enum Status status = INVALID;
//
//int my_atoi(const char* str)
//{
//	if (str == NULL)
//		return 0;
//	if (*str == '\0')
//		return 0;
//	while (isspace(*str))
//	{
//		str++;
//	}
//	int flag = 1;//δ������Ĭ��������
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	long long ret = 0;
//	while (isdigit(*str))
//	{
//		ret = ret * 10 + flag * (*str - '0');
//		if (ret < INT_MIN || ret > INT_MAX)
//		{
//			return 0;
//		}
//		str++;
//	}
//	if (*str == '\0')
//	{
//		status = VALID;
//		return (int)ret;
//	}
//	else
//	{
//		return (int)ret;
//	}
//}
//#include <stdlib.h>
//
//int main()
//{
//	int tmp = atoi("   -123");
//	printf("%d\n", tmp);
//	int ret = my_atoi("   -123");
//	if (status == VALID)
//		printf("��Ч�����:%d\n", ret);
//	else
//		printf("��Ч�����:%d\n", ret);
//	return 0;
//}


//ģ��ʵ��atoi����

//#include <stdio.h>
//#include <ctype.h>
//#include <limits.h>
//
//enum Status
//{
//	VALID,
//	INVALID
//}status = INVALID;
//
//int my_atoi(const char* s)
//{
//	if (s == NULL)
//		return 0;
//	if (*s == '\0')
//		return 0;
//	while (isspace(*s))
//	{
//		s++;
//	}
//	int flag = 1;
//	if (*s == '+')
//	{
//		s++;
//	}
//	else if (*s == '-')
//	{
//		flag = -1;
//		s++;
//	}
//	long long ret = 0;
//	while (isdigit(*s))
//	{
//		ret = ret * 10 + flag * (*s - '0');
//		if (ret < INT_MIN || ret > INT_MAX)
//			return 0;
//		s++;
//	}
//	if (*s == '\0')
//	{
//		status = VALID;
//		return (int)ret;
//	}
//	else
//		return (int)ret;
//}
//
//int main()
//{
//	int ret = my_atoi("-123abc");
//	if (status == VALID)
//	{
//		printf("��Ч�����:%d\n", ret);
//	}
//	else
//	{
//		printf("��Ч�����:%d\n", ret);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[100];
//	printf("������һ����������:>");
//	scanf("%s", str);
//	int len = (int)strlen(str);
//	int RomanNum[26] = { 0 };
//	RomanNum['I' - 'A'] = 1;
//	RomanNum['V' - 'A'] = 5;
//	RomanNum['X' - 'A'] = 10;
//	RomanNum['L' - 'A'] = 50;
//	RomanNum['C' - 'A'] = 100;
//	RomanNum['D' - 'A'] = 500;
//	RomanNum['M' - 'A'] = 1000;
//	int num = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		int tmp = RomanNum[str[i] - 'A'];
//		if (i < len - 1 && tmp < RomanNum[str[i + 1] - 'A'])
//			num -= tmp;
//		else
//			num += tmp;
//	}
//	printf("��������%sת���ɹ�:>%d\n", str, num);
//	return 0;
//}

//13.