#include "BSTree.h"

void test_insert()
{
	int arr[] = { 5,8,4,9,7,3,2 };
	BSTree<int> bt;
	for (auto e : arr) bt.Insert(e);

	bt.InOrder();
	cout << endl;
	bt.PreOrder();
	cout << endl;
	bt.PostOrder();
	cout << endl;

	int arr_test[] = { 1,5,8,16,4,9,7,3,2,10 };

	for (auto e : arr_test) cout << bt.Find(e) << " ";

}

void test_erase()
{
	int arr[] = { 5,8,4,9,7,3,2 };
	BSTree<int> bt;
	for (auto e : arr) bt.Insert(e);

	bt.Erase(4);
	bt.Erase(7);
	bt.Erase(3);
	bt.Erase(2);
	bt.Erase(8);
	bt.Erase(9);
	//bt.Erase(5);

	bt.InOrder();
	cout << endl;
}

int main()
{
	test_erase();
	return 0;
}