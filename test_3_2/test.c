#define _CRT_SECURE_NO_WARNINGS 1

//���1-100������

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}


#include <stdio.h>

int main()
{
	char password[20];
	char a = 0;
	printf("����������:");
	scanf("%s", password);
	while ((a = getchar()) != '\n');
	printf("��ȷ������ Y/N:");
	int ch = getchar();
	if (ch == 'Y')
		printf("ȷ�ϳɹ�\n");
	else
		printf("ȷ��ʧ��\n");
	return 0;
}