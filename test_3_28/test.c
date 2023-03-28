#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	char i = -20;
//	//
//	unsigned char j = 10;
//	printf("i+j = %d\n", i + j);
//	return 0;
//}

#include <stdio.h>

#include <limits.h>
#include <float.h>

//INT_MAX


int main()
{
	int n = 9;
	//00000000 00000000 00000000 00001001  --原码
	//                                     --补码

	float* pf = (float*)&n;

	printf("%d\n", n);      //9

	printf("%f\n", *pf);    //0.000000
	//0  0000000 00000000000000000001001
	//S  E       M
	//(-1)^0 * 0.00000000000000000001001 * 2 ^ -126   约等于0
	//     S     M(只是小数点之后的数字)       E(单精度真实值 + 127  全1和全0除外(特殊))
	//正数S=0 负数S=-1							(双精度真实值 + 1023 全1和全0除外(特殊))

	*pf = 9.0;
	//1001.0 = 1.001 * 2^3
	//(-1)^0 * 1.001 * 2^3
	//S  E                    M
	//0  3+127 = 130
	//0  10000010             00100000000000000000000

	printf("%d\n", n);//
	//0  10000010             00100000000000000000000   --原码、补码（一个很大的正数）
	printf("%f\n", *pf);//9.0

	return 0;
}
