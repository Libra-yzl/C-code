#define _CRT_SECURE_NO_WARNINGS 1


#include "SLinkList.h"

void TestSLL1()
{
	SLT* plist = NULL;
	
	int n = 0;
	//scanf("%d", &n);
	plist = CreateSLT(n);

	PushBack(&plist, 100);
	PushBack(&plist, 200);
	PushBack(&plist, 300);

	PopBack(&plist);
	PopBack(&plist);
	PopBack(&plist);
	//PopBack(&plist);
	PushBack(&plist, 100);


	Print(plist);

	SLTDestroy(&plist);

}

void TestSLT2()
{
	SLT* plist = NULL;

	PushFront(&plist, 100);
	PushFront(&plist, 200);
	PushFront(&plist, 300);

	PopFront(&plist);
	PopFront(&plist);
	PopFront(&plist);

	PushFront(&plist, 300);

	Print(plist);

	SLTDestroy(&plist);

}

void TestSLTNode3()
{
	SLT* plist = NULL;

	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);

	SLT* pos = SLTFind(plist, 3);
	/*if (!plist)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了【%d|%p】\n", plist->data, plist);
	}*/
	InsertAfter(pos, 100);

	pos = SLTFind(plist, 3);
	//InsertAfter(pos, 200);
	EraseAfter(pos);
	Print(plist);

	SLTDestroy(&plist);

}

void TestSLTNode4()
{
	SLT* plist = NULL;

	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);

	Print(plist);

	/*SLT* pos = SLTFind(plist, 3);
	Insert(&plist, pos, 100);
	pos = SLTFind(plist, 1);
	Insert(&plist, pos, 500);
	Print(plist);*/

	/*Erase(&plist, pos);
	pos = SLTFind(plist, 100);
	pos = SLTFind(plist, 100);
	pos = SLTFind(plist, 100);
	pos = SLTFind(plist, 100);
	pos = SLTFind(plist, 100);*/

	SLT* pos = SLTFind(plist, 1);
	Erase(&plist, pos);
	pos = SLTFind(plist, 2);
	Erase(&plist, pos);
	pos = SLTFind(plist, 3);
	Erase(&plist, pos);
	pos = SLTFind(plist, 4);
	Erase(&plist, pos);
	pos = SLTFind(plist, 5);
	Erase(&plist, pos);
	//Erase(&plist, pos);

	Print(plist);

	SLTDestroy(&plist);
}

int main()
{
	//TestSLL1();
	//TestSLT2();
	//TestSLTNode3();//测试查找
	TestSLTNode4();
	return 0;
}