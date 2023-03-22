#define _CRT_SECURE_NO_WARNINGS 1

//写一个函数返回参数中二进制中1的个数
//#include <stdio.h>

//int count_bit(int n)
//{
//	int count = 0; //计数器--统计1的个数
//
//	for (int i = 0; i < 32; i++)
//	{
//		if (1 == ((n >> i) & 1))
//			count++;
//	}
//	return count;
//}

//int count_bit(int n)
//{
//	int count = 0; //计数器--统计1的个数
//
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	printf("输入一个数字:>");
//	scanf("%d", &n);
//	printf("%d\n", count_bit(n));
//	return 0;
//}


////求两个数二进制中不同位的个数
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	printf("请输入两个数字:>");
//	scanf("%d %d", &n, &m);
//	int count = 0; //计数器
//
//	int ret = n ^ m;
//	while (ret)
//	{
//		ret &= (ret - 1);
//		count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}



//获取整数 打印整数二进制位中的奇数位和偶数位 （分别打印）

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个整数:>");
//	scanf("%d", &n);
//
//	//偶数位
//	printf("打印的二进制偶数位:>");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//
//	//奇数位
//	printf("\n打印的二进制奇数位:>");
//	for (int i = 31; i > 0; i-=2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//
//	return 0;
//}


//将一个十进制数字转换为六进制
//#include <stdio.h>
//#include <math.h>

//int Dec_Hex(int n)
//{
//	int m = n % 6;
//	int ret = 1;
//	static int i = 0;//静态变量 保留相当于递归次数 计算次方
//	if (n)
//	{
//		ret = (int)pow((int)10, (int)i++);
//		return Dec_Hex(n / 6) + m * ret;
//	}
//	else
//		return 0;
//}

//int Dec_Hex(int n)
//{
//	int m = 0;
//	int ret = 0;
//	int i = 0;
//	if (n > 5)
//	{
//		while (n)
//		{
//			m = n % 6;
//			ret += m * (int)pow((int)10, (int)i);
//			i++;
//			n /= 6;
//		}
//		return ret;
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个十进制整数:>");
//	scanf("%d", &n);
//
//	//将十进制转换为六进制
//	int ret = Dec_Hex(n);
//	printf("%d", ret);
//	return 0;
//}


////删除一个整数序列中的数字 
//
//#define N 10
//
//#include <stdio.h>
//
//int main()
//{
//	int arr[N];
//	//输入
//	printf("请输入%d个数字:>", N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	printf("原数组:>");
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	int del = 0;
//	printf("请指定要删除的数字:>");
//	scanf("%d", &del);
//
//	//删除数组中的元素
//	for (int i = 0; i < N; i++)
//	{
//		if (arr[i] == del)
//		{
//			while (i < N)
//			{
//				arr[i] = arr[i + 1];
//				i++;
//			}
//			//删除元素后跳出循环
//			break;
//		}
//	}
//
//	printf("删除指定数字后的数组:>");
//	for (int i = 0; i < N - 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//求两个数二进制中不同位的个数

#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	printf("请输入两个数字:>");
	scanf("%d %d", &n, &m);

	int i = 0;
	int count = 0; //计数器 -- 统计不同位个数
	while (i < 32)
	{
		if (((n >> i) & 1) != ((m >> i) & 1))
			count++;
		i++;
	}
	printf("%d和%d的二进制中不同位有%d个\n", n, m, count);
	return 0;
}



//写一个函数返回参数中二进制中1的个数

////求两个数二进制中不同位的个数

////删除一个整数序列中的数字 

//将一个十进制数字转换为六进制

//获取整数 打印整数二进制位中的奇数位和偶数位 （分别打印）

