#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//菜单函数
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
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		default:
			printf("选择错误，请重新选择\n");
			break;
		case 0:
			printf("退出通讯录\n");
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