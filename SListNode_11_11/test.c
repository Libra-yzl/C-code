#define _CRT_SECURE_NO_WARNINGS 1

#include "SLTNode.h"

//void TestSLTNode1()
//{
//	SLTNode* n1 = BuyNewNode(1);
//	SLTNode* n2 = BuyNewNode(2);
//	SLTNode* n3 = BuyNewNode(3);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = NULL;
//}

void TestSLTNode1()
{
	SLTNode* plist = CreateNewNode(5);
	SLTPrint(plist);
}

void TestSLTNode2()
{
	/*SLTNode* plist = CreateNewNode(5);
	SLTPrint(plist);*/

	SLTNode* plist = NULL;

	SLTPushBack(&plist, 100);
	SLTPrint(plist);
	SLTPushBack(&plist, 200);
	SLTPrint(plist);
	SLTPushBack(&plist, 300);
	SLTPrint(plist);

	/*SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPrint(plist);*/
}

void TestSLTNode3()
{
	/*SLTNode* plist = CreateNewNode(5);
	SLTPrint(plist);*/
	
	SLTNode* plist = NULL;

	SLTPushFront(&plist, 100);
	SLTPrint(plist);
	SLTPushFront(&plist, 200);
	SLTPrint(plist);
	SLTPushFront(&plist, 300);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	//SLTPopFront(&plist);
}

int main()
{
	//TestSLTNode1(); 
	//TestSLTNode2();
	TestSLTNode3();
	return 0;
}