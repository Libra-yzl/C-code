#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//int main()
//{
//	int a = -10;
//	//-10
//	//ԭ��:10000000000000000000000000001010
//	//����:11111111111111111111111111110101
//	//����:1111 1111 1111 1111 1111 1111 1111 0110
//	//�����ŵ��ǲ��룬��ô�ڴ��д�ŵľ��� fffffff6
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int a = 0x11223344;
//	//�������õ���ʮ�����Ʊ�ʾ
//	//���ڴ��д�ŵľ����⼸������
//	return 0;
//}

//#include <stdio.h>
//
//int check_model()
//{
//	int a = 1;
//	//�������1�Ǿ���С�˴洢ģʽ
//	//�������0�Ǿ��Ǵ�˴洢ģʽ
//	return *(char*)&a;
//}
//
//int main()
//{
//	int ret = check_model();//��װһ���������ݷ���ֵȷ����С��
//	if (1 == ret)
//		printf("С�˴洢ģʽ\n");
//	else
//		printf("��˴洢ģʽ\n");
//	return 0;
//}

#include <stdio.h>

int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("%d %d %d", a, b, c);
	return 0;
}
