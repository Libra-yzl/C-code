#define _CRT_SECURE_NO_WARNINGS 1

////�����Ǿ����ж�
//#define n 3
//
//#include <stdio.h>
//
//int main()
//{
//    //int n = 0;
//    //scanf("%d", &n);
//    int arr[n][n];
//    //����
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//            //printf("%d ", arr[i][j]);
//        }
//        //printf("\n");
//    }
//
//    //�ж�
//    int flag = 1;//�������Ǿ���
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (arr[i][j] != 0)
//            {
//                printf("NO\n");
//                flag = 0;
//                goto end;//���������Ǿ���ֱ������˫��ѭ��
//            }
//        }
//    }
//end:
//
//    if (1 == flag)
//    {
//        printf("YES\n");
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    long long n = 0;
//    scanf("%d", &n);
//
//    //����ת��
//    long long sum = 0;
//
//    long long i = 0;
//    while (n)
//    {
//        long long m = n % 6;
//        sum += (m * (long long)pow((long long)10, (long long)i));
//        i++;
//        n /= 6;
//    }
//
//    printf("%lld", sum);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    //int sum = 0;
//
//    //���Լ��
//    int tmp_n = n;
//    int tmp_m = m;
//    int r = 1;
//    while (tmp_n % tmp_m)
//    {
//        r = tmp_n % tmp_m;
//        tmp_n = tmp_m;
//        tmp_m = r;
//    }
//
//    //sum += m + n * m / r;
//    printf("%d", tmp_m + n * m / tmp_m);
//    return 0;
//}

//#define n 10
//
//#include <stdio.h>
//
//int main()
//{
//    //int n = 0;
//    //scanf("%d", &n);
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    int del = 0;
//    scanf("%d", &del);
//
//    //ɾ��
//    int flag1 = 1;//��ɾ��Ԫ��
//    int flag2 = 1;
//    int count = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] == del)
//        {
//            count++;
//            flag1 = 0;//��ɾ��Ԫ��
//            flag2 = 0;
//            int tmp = i;
//            while (tmp < n)
//            {
//                arr[tmp] = arr[tmp + 1];
//                tmp++;
//            }
//            //break; //ɾ��Ԫ�غ�����ѭ��
//        }
//        if (0 == flag2)
//        {
//            i = 0;
//            flag2 = 1;
//        }
//    }
//
//    //��ӡ
//    if (1 == flag1)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            printf("%d ", arr[i]);
//        }
//    }
//    else
//    {
//        for (int i = 0; i < n - count; i++)
//        {
//            printf("%d ", arr[i]);
//        }
//    }
//}

//#define n 10
//#include <stdio.h>
//
//int main()
//{
//    /*int n = 0;
//    scanf("%d", &n);*/
//    int arr[n];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    //ɾ��
//    int del = 0;
//    scanf("%d", &del);
//    int fast = 0;//��ָ��--����Ҫɾ����Ԫ��
//    int slow = 0;
//    while (fast < n)
//    {
//        if (arr[fast] != del)
//        {
//            arr[slow] = arr[fast];
//            fast++;
//            slow++;
//        }
//        else
//        {
//            fast++;
//        }
//    }
//    for (int i = 0; i < slow; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//���ַ�����ģ��ʵ��strlen()

//1.

#include <stdio.h>

//int my_strlen(char* str)
//{
//	int count = 0;//������
//
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
// 

////2.�ݹ�
//
//int my_strlen(char* str)
//{
//	//int count = 0;
//
//	if (*str == '\0')
//		return 0;
//	else
//		return my_strlen(str + 1)+1;
//}
// 

////3.ָ��-ָ��
//
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*start)
//		start++;
//	return (int)(start - str);
//}
//
//int main()
//{
//	char str[] = "abcdefgh";
//	int ret = my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int* p = &a;
//	int** pp = &p;
//	*pp = 200;
//	*p = 10;
//	printf("%d", a);
//	return 0;
//}