#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkList.h"

void TestLList1()
{
	/*SLTNode* n1 = BuySLTNode(1);
	SLTNode* n2 = BuySLTNode(2);
	SLTNode* n3 = BuySLTNode(3);
	SLTNode* n4 = BuySLTNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;*/

	int n = 5;
	SLTNode* plist = CreateLList(n);
	PrintLList(plist);
}

void TestLList2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 200);
	SLTPushBack(&plist, 300);

	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	//SLTPopBack(&plist);

	PrintLList(plist);

}

void TestLList3()
{
	SLTNode* plist = NULL;

	SLTPushFront(&plist, 100);
	SLTPushFront(&plist, 200);
	SLTPushFront(&plist, 300);

	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	//SLTPopFront(&plist);
	SLTPushFront(&plist, 100);
	SLTPushFront(&plist, 200);
	SLTPushFront(&plist, 300);
	SLTPushFront(&plist, 400);
	SLTPushFront(&plist, 500);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);


	PrintLList(plist);
}

int main()
{
	//TestLList1();
	//TestLList2();//≤‚ ‘Œ≤≤ÂŒ≤…æ
	TestLList3();//≤‚ ‘Õ∑≤ÂÕ∑…æ
	return 0;
}