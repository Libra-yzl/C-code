#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() 
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)  //switch����Ƕ��ʹ��
		{
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d, n = %d", m, n); 
	return 0;


}//��ϰ 
//�ж�һ�����Ƿ�Ϊ���������1-100֮�������
//int main()
//{
//	int i = 1;
//	int num;
//	printf("����һ������:");
//	scanf("%d", &num);
//	if (num % 2 != 0)
//		printf("%dΪ����\n", num);
//	else
//		printf("%dΪż��\n", num);
//	printf("1 - 100֮�������:");
//	while (i <= 100) {
//		
//		if (i % 2 == 1)
//			printf("%d ", i);
//		i++;
//	}
	//int num = 5;
	//if (num % 2 == 0)
	//	printf("%dΪż��\n", num);
	//else
	//	printf("%dΪ����\n", num);
	//return 0;
//}