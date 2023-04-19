#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

////na1 + n*(n-1)*d / 2
////�Ȳ�����-�������
//
//int missingNumber(int* nums, int numsSize)
//{
//    int sum = 0;
//    //�������
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    int ret = (numsSize + 1) * numsSize / 2 - sum;
//    return ret;
//}

////�������
//int missingNumber(int* nums, int numsSize)
//{
//    int num = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        num ^= nums[i];
//    }
//    for (int i = 0; i < numsSize + 1; i++)
//    {
//        num ^= i;
//    }
//    return num;
//}
//
//int main()
//{
//    int arr[9] = { 0,1,3,5,4,6,7,9,8 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int ret = missingNumber(arr, sz);
//    printf("%d\n", ret);
//	return 0;
//}

#include "g.h"

void menu()
{
	printf("                       1.play\n");
	printf("                       0.exit\n");
}

enum Options
{
	EXIT,
	PLAY
};

void game()
{
	//���
	char board[ROW][COL];

	//��ʼ��
	InitBoard(board, ROW, COL);

	//��ӡ
	PrintBoard(board, ROW, COL);

	char ret = 0;
	while (1)
	{
		//����
		MovePlayer(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = Win(board, ROW, COL);
		if (ret != 'C')
			break;

		MoveComputer(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = Win(board, ROW, COL);
		if (ret != 'C')
			break;
	}

	//��ʤ
	if (ret == '*')
		printf("���ʤ\n");
	else if (ret == '#')
		printf("����ʤ\n");
	else if (ret == 'Q')
		printf("ƽ��\n");
	//PrintBoard(board, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("����ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("�˳�\n");
			break;
		case PLAY:
			game();
			break;
		default:
			printf("����ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}