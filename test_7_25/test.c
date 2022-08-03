#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int Print(int num)
//{
//    printf("%d",num % 10);
//    if (num > 9)
//    {
//        Print(num / 10);
//    }
//    return 0;
//}
//int main()
//{
//    int num;
//    scanf("%d", &num);
//    Print(num);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int grades[5] = { 0 };
//    int i = 0;
//    float sum = 0;
//    for (i = 0; i < 5; i++)
//    {
//        scanf("%d", &grades[i]);
//        sum += grades[i];
//    }
//    float average = sum / 5.0;
//    printf("%.1f", average);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c, d, e;
//	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
//	float aver = (a + b + c + d + e) / 5.0;
//	printf("%.1f", aver);
//	return 0;
//}

#include <stdio.h>

int main()
{
    int i = 0;
    int num1, num2;
    for (i = 0; i < 3; i++)
    {
        scanf("%d %d", &num1, &num2);
        if (num1 == num2)
        {
            printf("%d=%d\n", num1, num2);
        }
        else if (num1 > num2)
        {
            printf("%d>%d\n", num1, num2);
        }
        else
            printf("%d<%d\n", num1, num2);
    }
    return 0;
}