#define _CRT_SECURE_NO_WARNINGS 1

//8-1
////�����ݺ��·� �������
//#include <stdio.h>
//
//int main()
//{
//	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	int y = 0;
//	int m = 0;
//	while (scanf("%d %d", &y, &m) != EOF)
//	{
//		int day = days[m];
//		//�ж�����
//		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0) && m == 2)
//			day++;
//		printf("%d\n", day);
//	}
//	return 0;
//}


////�ж��ǲ�����ĸ
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char ch = 0;
//
//	while (scanf("%c", &ch) != EOF)
//	{
//		if (isalpha(ch))
//			printf("%c is alphabet\n", ch);
//		else
//			printf("%c is not alphabet\n", ch);
//
//		//����������\n
//		getchar();
//	}
//	return 0;
//}


////��ĸ��Сдת��
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char ch = 0;
//
//	while (scanf("%c", &ch) != EOF)
//	{
//		if (islower(ch))
//			printf("%c\n", toupper(ch));
//		else if (isupper(ch))
//			printf("%c\n", tolower(ch));
//	}
//	return 0;
//}


////ʹ��ָ���ӡ����
//#include  <stdio.h>
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print(arr,sz);
//	return 0;
//}
//


////дһ�������������ַ���
//
//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* str)
//{
//	int len = (int)strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char str[20];
//	printf("�������ַ���:>");
//	scanf("%[^\n]", str);
//	printf("����ǰ�ַ���:%s\n", str);
//
//	reverse(str);
//	printf("������ַ���:%s\n", str);
//	return 0;
//}


////ˮ�ɻ���
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10000; i++)
//	{
//		//����λ��
//		int count_i = 1;//��λ��ȫ��������
//		int tmp = i;
//		while (tmp /= 10)
//		{
//			count_i++;
//		}
//
//		//����
//		int sum = 0;
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, count_i);
//			tmp /= 10;
//		}
//
//		//�ж�
//		if (i == sum)
//			printf("%d ", i);
//	}
//	return 0;
//}


////��a��ǰn��� �� a+aa+aaa+aaaa+aaaaa+...
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int n = 0;
//	int a = 0;
//	scanf("%d %d", &a, &n);
//
//	int sum = 0;
//	int k = 0;
//	for (int i = 0; i < n; i++)
//	{
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//
//	for (int i = 0; i < line)
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    double price = 0;
//    int m = 0;
//    int d = 0;
//    int flag = 0;
//    scanf("%lf %d %d %d", &price, &m, &d, &flag);
//
//    if (m == 11 && d == 11)
//    {
//        price = price * 0.7 - flag * 50;
//    }
//    else if (m == 12 && d == 12)
//    {
//        price = price * 0.8 - flag * 50;
//    }
//    if (price < 0.0)
//        price = 0.0;
//    printf("%.2lf\n", price);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//
//	//��ӡ�ϰ벿��
//	for (int i = 0; i < line; i++)
//	{
//		//��ӡ�ո�
//		for (int j = 0; j < line - i - 1; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (int j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	//��ӡ�°벿��
//	for (int i = 0; i < line - 1; i++)
//	{
//		//��ӡ�ո�
//		for (int j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (int j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

