#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//int main()
//{
//    char str[10000] = { 0 };
//    while (scanf("%s", str) != EOF)
//    {
//        char* ptr = str;
//        int count = 0;
//        int count_A = 0;
//        while (*ptr)
//        {
//            if (*ptr == '0')
//                break;
//            count++;
//            if (*ptr == 'A')
//                count_A++;
//            ptr++;
//        }
//        if (count_A > (count - count_A))
//            printf("A\n");
//        else if (count_A < (count - count_A))
//            printf("B\n");
//        else
//            printf("E\n");
//    }
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    double grade[7] = { 0 };
//    int i = 0;
//    double max = 0;
//    double min = 100;
//    double sum = 0;
//    for (i = 0; i < 7; i++)
//    {
//        scanf("%lf", &grade[i]);
//        if (grade[i] > max)
//            max = grade[i];
//        if (grade[i] < min)
//            min = grade[i];
//        sum += grade[i];
//    }
//    printf("%.2lf\n", (sum - max - min) / 5.0);
//    return 0;
//}


//模拟实现strlen()函数
#include <stdio.h>
#include <string.h>

int my_strlen(char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char str[] = "hello bit!";
	int len = (int)strlen(str);
	int my_len = my_strlen(str);
	printf("len = %d\nmy_len = %d\n", len, my_len);
	return 0;
}