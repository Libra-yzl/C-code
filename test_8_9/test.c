#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}
//#include <string.h>
//
//
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}

//������
#include <stdio.h>

int main()
{
	int A = 0;
	int B = 0; 
	int C = 0;
	int D = 0;
	int E = 0;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if ((B == 2) + (A == 3) == 1 &&
							(B == 2) + (E == 4) == 1 &&
							(C == 1) + (D == 2) == 1 &&
							(C == 5) + (D == 3) == 1 &&
							(E == 4) + (A == 1) == 1)
						{
							if ((A * B * C * D * E) != (1 * 2 * 3 * 4 * 5))
								continue;
							else
							{
								printf("A�ǵ�%d��\n", A);
								printf("B�ǵ�%d��\n", B);
								printf("C�ǵ�%d��\n", C);
								printf("D�ǵ�%d��\n", D);
								printf("E�ǵ�%d��\n", E);
							}

						}
					}
				}
			}
		}
	}
	return 0;
}

//�ձ�������
//#include <stdio.h>
//
//int main()
//{
//	int x = 0; //����������x
//	for (x = 'A'; x <= 'D'; x++)
//	{
//		//����A ��C ��D ����D
//		//��������(1) ������3
//		if (3 == ((x != 'A') + (x == 'C') + (x == 'D') + (x != 'D')))
//			printf("������%c\n", x);
//	}
//	return 0;
//}
// 
////�������
//
//#include <stdio.h>
//#define LINE 10
//
//int main()
//{
//	int i = 0;
//	int arr[LINE][LINE] = { 0 };
//	//�����������
//	for (i = 0; i < LINE; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			//�������ÿ�����߶���1
//			if (j ==0 || j == i)
//				arr[i][j] = 1;
//			//��������е�����ֵ���� ��һ�и����������� �� ������������-1 ��ֵ֮��
//			else
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	//��ӡ�������
//	for (i = 0; i < LINE; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}