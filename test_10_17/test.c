#define _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"

void menu()
{
	printf("**********************************************\n");
	printf("             1.add           2.del            \n");
	printf("             3.search        4.modify         \n");
	printf("             5.show          6.sort           \n");
	printf("                     0.exit                   \n");
	printf("**********************************************\n");
}

enum Options
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			//�����ļ�
			SaveContact(&con);
			//����ͨѶ¼
			DestroyContact(&con);
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}