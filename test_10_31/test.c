#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void TestSList1()
{
	SLTNode* n1 = malloc();
	SLTNode* n2 = malloc();
	n1->next = n2;
}

int main()
{
	TestSList1();
	return 0;
}