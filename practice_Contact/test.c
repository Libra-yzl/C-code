#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//�˵�����
void menu()
{
	printf("******************************************\n");
	printf("********  1.add             2.del  *******\n");
	printf("********  3.search          4.modify  *******\n");
	printf("********  5.show            6.clear*******\n");
	printf("********  7.sort            0.exit *******\n");
	printf("******************************************\n");

}

int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		case 0:
			printf("�˳�ͨѶ¼\n");
			break;
		case 1:
			add_Contact(&con);
			break;
		case 2:
			del_contact(&con);
			break;
		case 3:
			search_contact(&con);
			break;
		case 4:
			modify_contact(&con);
			break;
		case 5:
			show_contact(&con);
			break;
		case 6:
			clear_contact(&con);
			break;
		case 7:
			sort_contact(&con);
			break;
		}
	} while (input);
	return 0;
}