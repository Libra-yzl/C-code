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
	SLPushBack(&s3, 3);
	SLPushBack(&s3, 4);
	//SLPushBack(&s3, 5);

	SLInsert(&s3, 2, 0);

	SLDelete(&s3, 2);
	SLDelete(&s3, 1);

	SLPrint(&s3);
	SLDestroy(&s3);
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();
	return 0;
}