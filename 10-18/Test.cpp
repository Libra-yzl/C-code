#include "BSTree.h"

void test_insert()
{
	int arr[] = { 6,7,8,5,4,3,2 };
	BSTree<int> bt;
	for (auto e : arr) bt.Insert(e);
	bt.InOrder();
	cout << endl;
}

int main()
{
	test_insert();
	return 0;
}