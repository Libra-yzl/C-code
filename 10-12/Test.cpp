#include "Test.h"


void TestBSTree()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t1;

	for (auto e : a)
	{
		t1.Insert(e);
	}

	t1.InOrder();
}

int main()
{
	TestBSTree();

	return 0;
}