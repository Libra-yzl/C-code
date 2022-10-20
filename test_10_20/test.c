#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[50] = "hello   world";
//	int length = (int)strlen(str);
//	char* s1 = str;
//	char* s2 = str;
//	while (*s1)
//	{
//		if (*s1 == ' ')
//		{
//			int len = (int)strlen(s1);
//			memmove(s1 + 3, s1 + 1, len);
//			*++s1 = ' ';
//			*++s1 = ' ';
//		}
//		s1++;
//	}
//	while (*s2)
//	{
//		if (*s2 == ' ')
//		{
//			*s2 = '%';
//			s2++;
//			*s2 = '2';
//			s2++;
//			*s2 = '0';
//		}
//		s2++;
//	}
//	printf("%s\n", str);
//	return 0;
//}

//#include <stdio.h>
//#include <stddef.h>
//
//#define OFFSETOF(type, member) (int)&(((type*)0)->member)
//
//struct tag
//{
//	int i;
//	char c;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", (int)offsetof(struct tag, i));
//	printf("%d\n", (int)offsetof(struct tag, c));
//	printf("%d\n", (int)offsetof(struct tag, d));
//	printf("%d\n", OFFSETOF(struct tag, i));
//	printf("%d\n", OFFSETOF(struct tag, c));
//	printf("%d\n", OFFSETOF(struct tag, d));
//	return 0;
//}

//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。

//#include <stdio.h>
//
//#define SWAP_BIT(n) n = ((n&0xaaaaaaaa)>>1) + ((n&(~0xaaaaaaaa))<<1)
//
//int main()
//{
//	int n = 10;
//	SWAP_BIT(n);
//	printf("%d\n", n);
//	return 0;
//}

//模拟实现atoi函数


#include <stdio.h>

int main()
{
	char str[100];
	scanf("%s", str);

	switch()
	return 0;
}