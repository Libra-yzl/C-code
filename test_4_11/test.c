#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __DATE__);
//
//	system("pause");
//	return 0;
//}

//#define MAX(x,y) ((x)>(y)?(x):(y))
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int m = MAX(a, b);
//	printf("%d\n", m);
//	return 0;
//}

//#define M 10
//
//#define PRINT(val, format) printf("the value of "#val" is "format"\n", val)
////#define PRINT(...)       printf("the value of ""val" is "format"\n")
//
//int main()
//{
//	int a = 10;
//	PRINT(a, "%d");
//	//printf("the value of a is %d\n", a);
//
//	int b = 20;
//	//printf("the value of b is %d\n", b);
//	PRINT(b, "%d");
//
//	float f = 3.5f;
//	//printf("the value of f is %.1f\n", f);
//	PRINT(f, "%.2f");
//
//	return 0;
//}

#define CAT(A,B) A##B

int main()
{
	int Class107 = 100;
	printf("%d", CAT(Class, 107));
	return 0;
}