#define _CRT_SECURE_NO_WARNINGS 1


////找两个单身狗
//
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,1,2,3,4,5,4,6 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//
//	int pos = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			//将第i位相同的位置记录 以便分组
//			pos = i;
//			break;
//		}
//	}
//
//	int num1 = 0;
//	int num2 = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//			num1 ^= arr[i];
//		else
//			num2 ^= arr[i];
//	}
//
//	printf("%d %d", num1, num2);
//	return 0;
//}

//#define N 4
//
//#define Y(n) ((N+2)*n)
//
//#include <stdio.h>
//
//int main()
//{
//
//	int z = 2 * (N + Y(5 + 1));
//	printf("%d", z);
//	return 0;
//}

//#define A 2+2
//#define B 3+3
//#define C A*B
//int main()
//{
//	printf("%d\n", C);
//	return 0;
//}


////offsetof宏
//
//#include <stdio.h>
//#include <stddef.h>
//
//#define OFFSETOF(s,m) (int)&(((s*)0)->m)
//
//struct S
//{
//	char a[10];
//	int b;
//	char c;
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(struct S));
//	/*printf("%zd\n", offsetof(struct S, a));
//	printf("%zd\n", offsetof(struct S, b));
//	printf("%zd\n", offsetof(struct S, c));*/
//
//	//实现OFFSETOF宏
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, b));
//	printf("%d\n", OFFSETOF(struct S, c));
//	return 0;
//}


////写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
//
//#include <stdio.h>
//
//#define SWAP_BIT(x) (((x)&0xaaaaaaaa)>>1)+(((x)&0x55555555)<<1)
//
//int main()
//{
//	int a = 10;
//	printf("%d", SWAP_BIT(2));
//	return 0;
//}

////模拟实现atoi
//
//#include <stdio.h>
//#include <ctype.h>
//#include <limits.h>
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
//	//处理空格
//	while (isspace(*str))
//	{
//		str ++;
//	}
//
//	//处理符号
//	int flag = 1;//不带符号默认为正号
//	if (*str == '+')
//	{
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	//处理数字
//	long long ret = 0;
//	while (isdigit(*str))
//	{
//		ret = ret * 10 + flag * (*str - '0');
//		if (ret < INT_MIN || ret > INT_MAX)
//			return 0;
//		str++;
//	}
//	if (*str == '\0')
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
//	int ret = my_atoi("  -1232222");
//	if (status == VALID)
//		printf("合法转换:%d\n", ret);
//	else
//		printf("非法转换:%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a = 1;
//    int b = 1;
//    int c = a + b;
//    while (1)
//    {
//        if (n == b)
//        {
//            printf("%d\n", 0);
//            break;
//        }
//        else if (n < b)
//        {
//            if (abs(n - a) < abs(b - n))
//            {
//                printf("%d\n", abs(n - a));
//                break;
//            }
//            else
//            {
//                printf("%d\n", abs(b - n));
//                break;
//            }
//        }
//        a = b;
//        b = c;
//        c = a + b;
//    }
//
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[10] = "abcdef";
//	int len = (int)strlen(str);
//	char* p = str + len - 1;
//	char* p1 = str + len - 4;
//	int a = str + len - 1 - p1;
//	printf("%d", a);
//	return 0;
//}

#include <stdio.h>
#include <string.h>


//void replaceSpace(char* str, int length) {
//	char* p1 = str + length - 1;
//	char* p2 = str + length - 1;
//	while (p1 != str)
//	{
//		while (*p1 != ' ')
//		{
//			p1++;
//			p2++;
//		}
//		//移动元素 
//		memmove(p2 + 2, p2, (str + length - 1) - (p2 - 1));
//
//		//替换
//		p1++;
//		*p1 = '%';
//		*(p1 + 1) = '2';
//		*(p1 + 2) = '0';
//		p1++;
//		p2 = p1;
//	}
//}

//class Solution {
//public:
//	void replaceSpace(char* str, int length) {
//		char* p1 = str;
//		while (*p1 != '\0')
//		{
//
//			if (isspace(*p1))
//			{
//				memmove(p1 + 3, p1 + 1, str + length - 1 - p1);
//				//替换
//				*p1 = '%';
//				p1++;
//				*p1 = '2';
//				p1++;
//				*p1 = '0';
//				p1++;
//			}
//
//			//
//			while (*p1 != ' ' && *p1 != '\0')
//			{
//				p1++;
//			}
//
//		}
//	}
//};
//
//int main()
//{
//	char str1[200] = "we are happy";
//	int len = strlen(str1);
//	return 0;
//}

