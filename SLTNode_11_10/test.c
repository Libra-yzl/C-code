#define _CRT_SECURE_NO_WARNINGS 1

#include "SLTNode.h"

void TestSLTNode1()
{
	SLTNode* n1 = BuyNewNode(1);
	SLTNode* n2 = BuyNewNode(2);
	SLTNode* n3 = BuyNewNode(3);
	SLTNode* n4 = BuyNewNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
}

void TestSLTNode2()
{
	SLTNode* plist = CreateNewNode(5);
	SLTPrint(plist);
}

void TestSLTNode3()
{
	//SLTNode* plist = CreateNewNode(5);
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 200);
	SLTPushBack(&plist, 300);
	SLTPrint(plist);
}

void TestSLTNode4()
{
	SLTNode* plist = CreateNewNode(5);
	/*SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 200);
	SLTPushBack(&plist, 300);*/
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	//SLTPopBack(&plist);
	SLTPrint(plist);
}

void TestSLTNode5()
{
	//SLTNode* plist = CreateNewNode(5);
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 100);
	SLTPushFront(&plist, 200);
	SLTPushFront(&plist, 300);
	SLTPrint(plist);
}

void TestSLTNode6()
{
	SLTNode* plist = CreateNewNode(5);
	//SLTPushFront(&plist, 100);

	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
}

int main()
{
	//TestSLTNode1();
	//TestSLTNode2();
	//TestSLTNode3();//测试链表的尾插
	TestSLTNode4();//测试链表的尾删
	//TestSLTNode5();//测试链表的头插
	//TestSLTNode6();//测试链表的头删
	return 0;
}