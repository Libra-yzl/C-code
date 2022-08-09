#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}
//#include <string.h>
//
//
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}

//猜名次
#include <stdio.h>

int main()
{
	int A = 0;
	int B = 0; 
	int C = 0;
	int D = 0;
	int E = 0;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if ((B == 2) + (A == 3) == 1 &&
							(B == 2) + (E == 4) == 1 &&
							(C == 1) + (D == 2) == 1 &&
							(C == 5) + (D == 3) == 1 &&
							(E == 4) + (A == 1) == 1)
						{
							if ((A * B * C * D * E) != (1 * 2 * 3 * 4 * 5))
								continue;
							else
							{
								printf("A是第%d名\n", A);
								printf("B是第%d名\n", B);
								printf("C是第%d名\n", C);
								printf("D是第%d名\n", D);
								printf("E是第%d名\n", E);
							}

						}
					}
				}
			}
		}
	}
	return 0;
}

//日本嫌疑人
//#include <stdio.h>
//
//int main()
//{
//	int x = 0; //假设凶手是x
//	for (x = 'A'; x <= 'D'; x++)
//	{
//		//不是A 是C 是D 不是D
//		//三个人真(1) 即返回3
//		if (3 == ((x != 'A') + (x == 'C') + (x == 'D') + (x != 'D')))
//			printf("凶手是%c\n", x);
//	}
//	return 0;
//}
// 
////杨辉三角
//
//#include <stdio.h>
//#define LINE 10
//
//int main()
//{
//	int i = 0;
//	int arr[LINE][LINE] = { 0 };
//	//计算杨辉三角
//	for (i = 0; i < LINE; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			//杨辉三角每行两边都是1
//			if (j ==0 || j == i)
//				arr[i][j] = 1;
//			//杨辉三角中的其他值等于 上一行该数字所在列 与 该数字所在列-1 的值之和
//			else
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	//打印杨辉三角
//	for (i = 0; i < LINE; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}