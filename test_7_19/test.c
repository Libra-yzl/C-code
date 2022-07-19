#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() 
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)  //switch允许嵌套使用
		{
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d, n = %d", m, n); 
	return 0;


}//练习 
//判断一个数是否为奇数，输出1-100之间的奇数
//int main()
//{
//	int i = 1;
//	int num;
//	printf("输入一个数字:");
//	scanf("%d", &num);
//	if (num % 2 != 0)
//		printf("%d为奇数\n", num);
//	else
//		printf("%d为偶数\n", num);
//	printf("1 - 100之间的奇数:");
//	while (i <= 100) {
//		
//		if (i % 2 == 1)
//			printf("%d ", i);
//		i++;
//	}
	//int num = 5;
	//if (num % 2 == 0)
	//	printf("%d为偶数\n", num);
	//else
	//	printf("%d为奇数\n", num);
	//return 0;
//}