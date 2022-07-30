#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[10][10] = { 0 };
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d ", &arr[i][j]);
//        }
//    }
//    int sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            if (j < i)
//            {
//                sum += arr[i][j];
//            }
//        }
//    }
//    if (sum == 0)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//    return 0;
//}
//#include <stdio.h>
//void print(int n)
//{
//    if (n > 5)
//    {
//        print(n / 6);
//    }
//    printf("%d", n % 6);
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    print(n);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int arr[60] = {0};
//    int k = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d ", &arr[i]);
//    }
//    scanf("%d", &k);
//    for (i = 0; i < n; i++)
//    {
//        if (k == arr[i])
//        {
//            continue;
//        }
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//最大公约数
//#include <stdio.h>
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &n, &m);
//	int r = 0;
//	/*if (n < m)
//	{
//		int tmp = n;
//		n = m;
//		m = tmp;
//	}*/
//	while (1)
//	{
//		r = n % m;
//		if (r == 0)
//			break;
//		n = m;
//		m = r;
//	}
//	printf("%d", m);
//
//	return 0;
//}
//#include <stdio.h>
//
//long long div(int n, int m)//最大公约数
//{
//    int r = 0;
//    if (n < m)
//    {
//        int tmp = n;
//        n = m;
//        m = tmp;
//    }
//    while (1)
//    {
//        r = n % m;
//        if (r == 0)
//            break;
//        n = m;
//        m = r;
//    }
//    return m;
//}
//long long mul(long long n, long long m)
//{
//    int r = div(m, n);
//    return m * n / r;
//}
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    long long big = div(n, m);
//    long long small = mul(n, m);
//    long long sum = big + small;
//    printf("%lld", sum);
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
//    int c = a + b;
//    if (n <= 2)
//        printf("%d", n);
//    else
//    {
//        for (int i = 2; i < n; i++)
//        {
//            a = b;
//            b = c;
//            c = a + b;
//
//        }
//        printf("%d", c);
//    }
//    return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n == 0)
//		{
//			break;
//		}
//		int i = 32;
//		printf("二进制序列:> ");
//		while (i > 0)
//		{
//			i--;
//			printf("%d ", (n >> i) & 1);
//		}
//		printf("\n偶数序列:>   ");
//		for (i = 30; i >= 0; i -= 2)
//		{
//			printf("%d ", (n >> i) & 1);
//		}
//		printf("\n奇数序列:>   ");
//		for (i = 31; i >= 1; i -= 2)
//		{
//			printf("%d ", (n >> i) & 1);
//		}
//		printf("\n");
//	}
//	return 0;
//}
