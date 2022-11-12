#define _CRT_SECURE_NO_WARNINGS 1

#include "func.h"

void TestSList1()
{
	SL ps;
	//初始化
	SLInit(&ps);
	
	SLPushBack(&ps, 100);
	SLPushBack(&ps, 200);
	SLPushBack(&ps, 300);

	SLPopBack(&ps);
	SLPopBack(&ps);
	SLPopBack(&ps);
	SLPopBack(&ps);

	SLPrint(&ps);
	//销毁
	SLDestroy(&ps);
}

void TestSList2()
{
	SL ps;
	SLInit(&ps);

	//头插
	SLPushFront(&ps, 100);
	SLPushFront(&ps, 200);
	SLPushFront(&ps, 300);
	SLPushFront(&ps, 400);
	SLPushFront(&ps, 500);

	PopFront(&ps);
	PopFront(&ps);
	PopFront(&ps);
	PopFront(&ps);
	PopFront(&ps);
	PopFront(&ps);

	SLPrint(&ps);
	//释放
	SLDestroy(&ps);
}

void TestSList3()
{
	SL ps;
	SLInit(&ps);

	//中间数据插入
	SLInsert(&ps, 0, 100);
	SLInsert(&ps, 1, 200);
	SLInsert(&ps, 2, 300);
	SLInsert(&ps, 3, 400);
	SLInsert(&ps, 4, 500);
	SLPrint(&ps);

	SLErase(&ps, 1); //100 300 400 500
	//SLErase(&ps, 1);
	SLErase(&ps, 2); //100 300 500
	SLErase(&ps, 0); //300 500

	SLPrint(&ps);
	SLDestroy(&ps);
}

void TestSLTNode1()
{
	SLTNode* plist = CreateNewNode(5);

	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 200);
	SLTPushBack(&plist, 300);
	SLTPushBack(&plist, 400);
	SLTPushBack(&plist, 500);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	//SLTPopBack(&plist);
	SLTPrint(plist);
}

void TestSLTNode2()
{
	//SLTNode* plist = CreateNewNode(5);
	SLTNode* plist = NULL;

	SLTPushFront(&plist, 100);
	SLTPushFront(&plist, 200);
	SLTPushFront(&plist, 300);
	SLTPrint(plist);

	/*SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPrint(plist);*/
}

int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
	//TestSLTNode1();
	TestSLTNode2();
	return 0;
}