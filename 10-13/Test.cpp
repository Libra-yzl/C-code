#include "Test.h"

int main()
{
	BSTree<int> bt;
	int arr[] = { 8,10,3,5,9,6,13,4 };
	for (auto e : arr) {
		bt.Insert(e);
	}
	bt.InOrder();
	cout << endl;

	cout << bt.Find(13) << endl;
	return 0;
}