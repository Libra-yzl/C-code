#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    int year = 0;
//    int month = 0;
//    int date = 0;
//    scanf("%d%d%d", &year, &month, &date);
//    int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//    {
//        day[1]++;
//    }
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < month - 1; i++)
//    {
//        count += day[i];
//    }
//    count += date;
//    printf("%d", count);
//    return 0;
//}

//#include <string.h>
//#include<stdio.h>
//
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%zd\n", strlen(s));
//	return 0;
//}

//#include <stdio.h>
//#define N 2
//#define M N + 1
//#define NUM (M + 1) * M / 2
//int main()
//{
//	printf("%d\n", N);
//	printf("%d\n", M);
//	printf("%d\n", NUM);
//	return 0;
//}

//#include <stdio.h>
//
//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//}
//
//int main()
//{
//	int ret = f(1);
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int arr[1000];
//    int k = 2;
//    int sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        arr[i] = k;
//        k += 3;
//        sum += arr[i];
//    }
//    printf("%d", sum);
//    return 0;
//}
//
//
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    printf("%d", (n * 2 + n * (n - 1) / 2 * 3));
//    return 0;
//}

//#include <stdio.h>
//int i;
//void prt()
//{
//	for (i = 5; i < 8; i++)
//		printf("%c", '*');
//	printf("\t");
//} 
//int main()
//{
//	for (i = 5; i <= 8; i++)
//		prt();
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 3;
//	printf("%d\n", (a += a -= a * a));
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int i = 0;
//        int arr[1000];
//        int count = 0;
//        double sum = 0.0;
//        int flag = 0;
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d", &arr[i]);
//            if (arr[i] < 0)
//            {
//                count++;
//            }
//            else if (arr[i] > 0)
//                sum += arr[i];
//            else if (arr[i] == 0)
//            {
//                flag++;
//            }
//        }
//        if (flag == n || count == n)
//            sum = 0.0;
//        printf("%d %.1lf", count, sum / n);
//        return 0;
//    }
//}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int i = 0;
//        int arr[1000];
//        int count = 0;
//        double sum = 0.0;
//        int flag = 0;
//        int count_pos = 0;
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d", &arr[i]);
//            if (arr[i] < 0)
//            {
//                count++;
//            }
//            else if (arr[i] > 0)
//            {
//                sum += arr[i];
//                count_pos++;
//            }
//
//            else if (arr[i] == 0)
//            {
//                flag++;
//            }
//        }
//        double aver = 0.0;
//        aver = sum / count_pos;
//        if (flag == n)
//            aver = 0.0;
//        printf("%d %.1lf", count, aver);
//        return 0;
//    }
//}

int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
    // write code here
    int min = *rotateArray;
    int* start = rotateArray;
    int i = 0;
    for (i = 0; i < rotateArrayLen; i++)
    {
        if (*start < min)
            min = *start;
        start++;
    }
    return min;
}