#define _CRT_SECURE_NO_WARNINGS 1


#include "SeqList.h"

void TestSeqList1()
{
	SL s1;
	SLInit(&s1);

	SLPushBack(&s1, 5);
	SLPushBack(&s1, 6);
	SLPushBack(&s1, 7);
	SLPushBack(&s1, 8);
	SLPushBack(&s1, 9);
	SLPushBack(&s1, 10);
	SLPushBack(&s1, 1);


	SLPrint(&s1);
	SLDestroy(&s1);
}

void TestSeqList2()
{
	SL s2;
	SLInit(&s2);

	SLPushBack(&s2, 1);
	SLPushBack(&s2, 2);
	SLPushBack(&s2, 3);
	SLPushBack(&s2, 4);

	SLPopBack(&s2);
	SLPopBack(&s2);
	SLPopBack(&s2);
	SLPopBack(&s2);
	SLPopBack(&s2);

	SLPushBack(&s2, 1);

	SLPrint(&s2);
	SLDestroy(&s2);
}

void TestSeqList3()
{
	SL s3;
	SLInit(&s3);

	SLPushBack(&s3, 1);
	SLPushBack(&s3, 2);
	SLPushBack(&s3, 7);
	SLPushBack(&s3, 4);
	SLPushBack(&s3, 5);
	SLPushBack(&s3, 7);
	SLPushBack(&s3, 6);
	SLPushBack(&s3, 7);

	/*SLInsert(&s3, 2, 5);
	SLInsert(&s3, 2, 6);
	SLInsert(&s3, 2, 7);
	SLInsert(&s3, 6, 7);
	SLInsert(&s3, 0, 7);*/

	/*SLDelete(&s3, 2);
	SLDelete(&s3, 1);
	SLDelete(&s3, 1);
	SLDelete(&s3, 1);*/

	//删除所有指定数字
	int pos = SLFind(&s3, 7, 0);
	while (pos != -1)
	{
		SLDelete(&s3, pos);
		pos = SLFind(&s3, 7, pos);
	}
	//SLDelete(&s3, 0);

	
	SLPrint(&s3);
	SLDestroy(&s3);
}

void TestSeqList4()
{
	SL s4;
	SLInit(&s4);

	SLPushFront(&s4, 5);
	SLPushFront(&s4, 4);
	SLPushFront(&s4, 3);
	SLPushFront(&s4, 2);
	SLPushFront(&s4, 1);

	SLPopFront(&s4);
	SLPopFront(&s4);
	SLPopFront(&s4);
	SLPopFront(&s4);
	SLPopFront(&s4);
	SLPopFront(&s4);

	SLPrint(&s4);
	SLDestroy(&s4);
}

#define M 3
#define N 3
void OJTest1()
{
	int nums1[10] = { 1,2,3,0,0,0 };
	int nums2[10] = { 2,5,6 };
	int tmp[M+N] = {0};
	int i1 = M-1;
	int i2 = N-1;
	int j = 0;
	while (i1 >= 0 && i2 >= 0)
	{
		if (nums1[i1] < nums2[i2])
		{
			tmp[j++] = nums1[i1--];
		}
		else
		{
			tmp[j++] = nums2[i2--];
		}
	}
	while (i2 >= 0)
	{
		tmp[j++] = nums2[i2--];
	}
	while (i1 >= 0)
	{
		tmp[j++] = nums1[i1--];
	}
	for (int i = 0; i < M+N; i++)
	{
		nums1[i] = tmp[i];
	}
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	OJTest1();
	return 0;
}