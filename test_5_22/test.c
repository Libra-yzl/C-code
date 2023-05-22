#define _CRT_SECURE_NO_WARNINGS 1


#include "review.h"

//void TestSLNode1()
//{
//	SL s;
//	SLInit(&s);
//
//	SLPushBack(&s, 1);
//	SLPushBack(&s, 2);
//	SLPushBack(&s, 3);
//	SLPushBack(&s, 4);
//	SLPushBack(&s, 5);
//	SLPrint(&s);
//
//	SLPopBack(&s);
//	SLPopBack(&s);
//	SLPopBack(&s);
//	SLPopBack(&s);
//	SLPopBack(&s);
//	//SLPopBack(&s);
//	SLPrint(&s);
//
//	SLDestroy(&s);
//}
//
//void TestSLNode2()
//{
//	SL s;
//	SLInit(&s);
//
//	SLPushFront(&s, 1);
//	SLPushFront(&s, 2);
//	SLPushFront(&s, 3);
//	SLPushFront(&s, 4);
//	SLPushFront(&s, 5);
//	SLPrint(&s);
//
//	SLPopFront(&s);
//	SLPopFront(&s);
//	SLPopFront(&s);
//	SLPopFront(&s);
//	SLPopFront(&s);
//	//SLPopFront(&s);
//	SLPrint(&s);
//
//	SLDestroy(&s);
//}
//
//void TestSLNode3()
//{
//	SL s;
//	SLInit(&s);
//
//	SLInsert(&s, 0, 1);
//	SLInsert(&s, 0, 2);
//	SLInsert(&s, 0, 3);
//	SLInsert(&s, 0, 4);
//	SLInsert(&s, 0, 5);
//	SLPrint(&s);
//	SLPushBack(&s, 100);
//	SLPrint(&s);
//
//	SLErase(&s, 2);
//	/*SLErase(&s, 2);
//	SLErase(&s, 2);
//	SLErase(&s, 2);
//	SLErase(&s, 1);
//	SLErase(&s, 0);*/
//	SLPrint(&s);
//
//	int ret = SLFind(&s, 4, 1);
//	if (ret == -1)
//	{
//		printf("没有找到\n");
//	}
//	else
//	{
//		printf("找到了 下标是:%d\n值是:%d\n", ret, s.a[ret]);
//	}
//
//	SLDestroy(&s);
//}
//


////链表
//void TestSLTNode1()
//{
//	SLTNode* plist = NULL;
//	//plist = CreateSList(10);
//
//	SLTPrint(plist);
//	SLTPushBack(&plist, 100);
//	SLTPushBack(&plist, 200);
//	SLTPushBack(&plist, 300);
//	SLTPushBack(&plist, 400);
//	SLTPrint(plist);
//
//	SLTPopBack(&plist);
//	SLTPopBack(&plist);
//	
//	//SLTPopBack(&plist);
//	SLTPrint(plist);
//
//	SLTDestroy(&plist);
//}
//
//void TestSLTNode2()
//{
//	SLTNode* plist = NULL;
//
//	SLTPushFront(&plist, 100);
//	SLTPushFront(&plist, 200);
//	SLTPushFront(&plist, 300);
//	SLTPushFront(&plist, 400);
//	SLTPushFront(&plist, 500);
//	SLTPrint(plist);
//
//	SLTDestroy(&plist);
//}
//
//void TestSLTNode3()
//{
//	SLTNode* plist = BuySLTNode(10);
//
//	SLTNode* ret = SLTFind(plist, 10);
//	SLTInsertAfter(ret, 100);
//	SLTInsertAfter(ret, 200);
//	SLTPrint(plist);
//
//	SListInsert(&plist, ret, 300);
//	SLTPrint(plist);
//
//	SListErase(&plist, ret);
//	ret = SLTFind(plist, 100);
//	SListErase(&plist, ret);
//	SLTPrint(plist);
//
//
//	SLTDestroy(&plist);
//}

void TestLTNode1()
{
	LTNode* phead = LTInit();
	LTPushBack(phead, 10);
	LTPushBack(phead, 20);
	LTPushBack(phead, 30);
	LTPushBack(phead, 40);
	LTPushBack(phead, 50);
	LTPushBack(phead, 60);
	LTPrint(phead);

	LTPopBack(phead);
	LTPopBack(phead);
	LTPopBack(phead);
	LTPrint(phead);

	LTPushFront(phead, 40);
	LTPushFront(phead, 50);
	LTPushFront(phead, 60);
	LTPrint(phead);

	LTPopFront(phead);
	LTPopFront(phead);
	LTPopFront(phead);
	LTPrint(phead);
	
	LTNode* pos = LTFind(phead, 10);
	LTInsert(pos, 100);
	LTInsert(pos, 200);
	LTInsert(pos, 300);
	LTPrint(phead);

	LTErase(pos);
	pos = LTFind(phead, 100);
	LTErase(pos);
	//LTErase(pos);
	LTPrint(phead);

	printf("isEmpty:%d\n", Empty(phead));
	printf("Size:%d\n", LTSize(phead));

	LTDestroy(phead);
}

int main()
{
	//TestSLNode1();
	//TestSLNode2();
	//TestSLNode3();

	//TestSLTNode1();
	//TestSLTNode2();
	//TestSLTNode3();

	TestLTNode1();
	return 0;
}