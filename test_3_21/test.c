#define _CRT_SECURE_NO_WARNINGS 1

//дһ���������ز����ж�������1�ĸ���
//#include <stdio.h>

//int count_bit(int n)
//{
//	int count = 0; //������--ͳ��1�ĸ���
//
//	for (int i = 0; i < 32; i++)
//	{
//		if (1 == ((n >> i) & 1))
//			count++;
//	}
//	return count;
//}

//int count_bit(int n)
//{
//	int count = 0; //������--ͳ��1�ĸ���
//
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	printf("����һ������:>");
//	scanf("%d", &n);
//	printf("%d\n", count_bit(n));
//	return 0;
//}


////���������������в�ͬλ�ĸ���
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	printf("��������������:>");
//	scanf("%d %d", &n, &m);
//	int count = 0; //������
//
//	int ret = n ^ m;
//	while (ret)
//	{
//		ret &= (ret - 1);
//		count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}



//��ȡ���� ��ӡ����������λ�е�����λ��ż��λ ���ֱ��ӡ��

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	printf("������һ������:>");
//	scanf("%d", &n);
//
//	//ż��λ
//	printf("��ӡ�Ķ�����ż��λ:>");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//
//	//����λ
//	printf("\n��ӡ�Ķ���������λ:>");
//	for (int i = 31; i > 0; i-=2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//
//	return 0;
//}


//��һ��ʮ��������ת��Ϊ������
//#include <stdio.h>
//#include <math.h>

//int Dec_Hex(int n)
//{
//	int m = n % 6;
//	int ret = 1;
//	static int i = 0;//��̬���� �����൱�ڵݹ���� ����η�
//	if (n)
//	{
//		ret = (int)pow((int)10, (int)i++);
//		return Dec_Hex(n / 6) + m * ret;
//	}
//	else
//		return 0;
//}

//int Dec_Hex(int n)
//{
//	int m = 0;
//	int ret = 0;
//	int i = 0;
//	if (n > 5)
//	{
//		while (n)
//		{
//			m = n % 6;
//			ret += m * (int)pow((int)10, (int)i);
//			i++;
//			n /= 6;
//		}
//		return ret;
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	printf("������һ��ʮ��������:>");
//	scanf("%d", &n);
//
//	//��ʮ����ת��Ϊ������
//	int ret = Dec_Hex(n);
//	printf("%d", ret);
//	return 0;
//}


////ɾ��һ�����������е����� 
//
//#define N 10
//
//#include <stdio.h>
//
//int main()
//{
//	int arr[N];
//	//����
//	printf("������%d������:>", N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	printf("ԭ����:>");
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	int del = 0;
//	printf("��ָ��Ҫɾ��������:>");
//	scanf("%d", &del);
//
//	//ɾ�������е�Ԫ��
//	for (int i = 0; i < N; i++)
//	{
//		if (arr[i] == del)
//		{
//			while (i < N)
//			{
//				arr[i] = arr[i + 1];
//				i++;
//			}
//			//ɾ��Ԫ�غ�����ѭ��
//			break;
//		}
//	}
//
//	printf("ɾ��ָ�����ֺ������:>");
//	for (int i = 0; i < N - 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//���������������в�ͬλ�ĸ���

#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	printf("��������������:>");
	scanf("%d %d", &n, &m);

	int i = 0;
	int count = 0; //������ -- ͳ�Ʋ�ͬλ����
	while (i < 32)
	{
		if (((n >> i) & 1) != ((m >> i) & 1))
			count++;
		i++;
	}
	printf("%d��%d�Ķ������в�ͬλ��%d��\n", n, m, count);
	return 0;
}



//дһ���������ز����ж�������1�ĸ���

////���������������в�ͬλ�ĸ���

////ɾ��һ�����������е����� 

//��һ��ʮ��������ת��Ϊ������

//��ȡ���� ��ӡ����������λ�е�����λ��ż��λ ���ֱ��ӡ��

