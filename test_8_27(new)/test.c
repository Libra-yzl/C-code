#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int fun(unsigned int x)
//{
//	int n = 0;
//	while (x + 1)
//	{
//		n++;
//		x = x | (x + 1);
//	} 
//		return n;
//}
//
//int main()
//{
//	printf("%d", fun(2014));
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5 };
//	//int* x = (& arr[0])++; //err
//	//printf("%d", *x);
//	int* p1 = NULL;
//	int* p2 = NULL;
//	if (p1 == p2)
//		return 1;
//	return 0;
//}

 //#include <stdio.h>

 //int rab_count(int n)
 //{
 //    if (n <= 2)
 //        return 1;
 //    else
 //        return rab_count(n - 1) + rab_count(n - 2);
 //}

 //int main()
 //{
 //    int n = 0;
 //    scanf("%d", &n);
 //    int count = rab_count(n);
 //    printf("%d\n", count);
 //    return 0;
 //}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a = 1;
//    int b = 1;
//    int c = 1;
//    while (n > 2)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//        n--;
//    }
//    printf("%d", b);
//    return 0;
//}

#include <stdio.h>
#include <math.h>

int main()
{
    double n = 0;
    int m = 0;
    while (scanf("%lf %d", &n, &m) != EOF)
    {
        int i = 0;
        double sum = 0;
        for (i = 1; i <= m; i++)
        {
            sum += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}

// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     double m, n;
//     while(~scanf("%lf %lf", &n, &m)) {
//         double sum=0;
//         while(m-- > 0) 
//         {
//             sum += n;//从自身开始以及每次的平方根进行求和
//             n = sqrt(n);//n成为当前自身的平方根
//         } 
//         printf("%.2lf\n", sum);
//     } 
//     return 0;
// }
