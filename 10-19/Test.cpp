#include "Test.h"


void test_insert()
{
	int arr[] = { 6,7,8,4,5,2,3 };
	BSTree<int> bt;
	for (auto e : arr) bt.Insert(e);

	bt.InOrder();
}

void test_erase()
{
	int arr[] = { 6,7,8,4,5,2,3 };
	BSTree<int> bt;
	for (auto e : arr) bt.Insert(e);
	bt.InOrder();
	cout << endl;
	//bt.Erase(8);
	//bt.InOrder();
	//bt.Erase(6);
	//bt.InOrder();
	for (auto e : arr)
	{
		bt.Erase(e);
		bt.InOrder();
		cout << endl;
	}
}

void test_insertR()
{
	int arr[] = { 6,7,8,4,5,2,3 };
	BSTree<int> bt;
	for (auto e : arr) bt.InsertR(e);

	bt.InOrder();
}

void test_FindR()
{
	int arr[] = { 6,7,8,4,5,2,3 };
	BSTree<int> bt;
	for (auto e : arr) bt.InsertR(e);

	bt.InOrder();
	cout << endl;

	int seh[] = { 10,6,7,9,8,4,11,5,2,3,1 };
	for (auto e : seh) cout << bt.FindR(e) << " ";
	cout << endl;
}

void test_eraseR()
{
	int arr[] = { 6,7,8,4,5,2,3 };
	BSTree<int> bt;
	for (auto e : arr) bt.Insert(e);
	bt.InOrder();
	cout << endl;
	//bt.Erase(8);
	//bt.InOrder();
	//bt.Erase(6);
	//bt.InOrder();
	for (auto e : arr)
	{
		bt.EraseR(e);
		bt.InOrder();
		cout << endl;
	}
}

void test_bstree()
{
	int arr1[] = { 6,7,8,4,5,2,3 };
	int arr2[] = { 8,9,10,7,4,5,2,3,1 };
	BSTree<int> bt1;
	for (auto e : arr1) bt1.Insert(e);
	bt1.InOrder();
	cout << endl;
	cout << "----------------------------" << endl;

	BSTree<int> bt2(bt1);
	bt2.InOrder();
	cout << endl;
	for (auto e : arr1)
	{
		bt2.EraseR(e);
		bt2.InOrder();
		cout << endl;
	}
	for (auto e : arr2) bt2.Insert(e);
	bt2.InOrder();
	cout << endl;
	for (auto e : arr2)
	{
		bt2.EraseR(e);
		bt2.InOrder();
		cout << endl;
	}
	cout << "----------------------------" << endl;
	
	BSTree<int> bt3;
	bt3 = bt1;
	bt3.InOrder();
	cout << endl;
}

int main()
{
	//test_insert();
	//test_erase();
	//test_insertR();
	//test_FindR();
	//test_eraseR();
	test_bstree();
	return 0;
}