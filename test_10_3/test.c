#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int n = 2;
//	printf("%d\n",(++n + 1));
//	return 0;
//}

#include <stdio.h>

void menu()
{
	printf("**********************************\n");
	printf("***********0.exit  1.add**********\n");
	printf("***********2.sub   3.mul**********\n");
	printf("***********4.div        **********\n");
	printf("**********************************\n");
}

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int (*pf[5]) (int, int) = {0, add, sub, mul, div};
	do
	{
		menu();
		printf("��ѡ��>;");
		scanf("%d", &input);
		if (0 == input)
		{
			printf("�˳�������\n");
			break;
		}
		if (input >= 1 && input <= 4)
		{
			printf("����������������>:");
			scanf("%d %d", &x, &y);
			ret = pf[input](x, y);
			printf("%d\n", ret);
		}
		else
			printf("ѡ�����������ѡ��\n");
	} while (input);
	return 0;
}