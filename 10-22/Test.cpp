#include "Test.h"


//int main()
//{
//	BSTree<int> bt;
//	int arr1[] = { 6,7,8,3,4,5,2 };
//	int arr2[] = { 10,6,7,8,1,3,4,5,2,9 };
//
//	for (auto e : arr1) bt.Insert(e);
//	bt.InOrder();
//	cout << endl;
//	cout << "-------------------" << endl;
//
//	for (auto e : arr1) bt.InsertR(e);
//	bt.InOrder();
//	cout << endl;
//	cout << "-------------------" << endl;
//
//	for (auto e : arr2) {
//		cout << bt.Find(e) << " ";
//	}
//	cout << endl;
//	cout << "-------------------" << endl;
//
//	for (auto e : arr2) {
//		cout << bt.FindR(e) << " ";
//	}
//	cout << endl;
//	cout << "-------------------" << endl;
//	bt.PreOrder();
//	cout << endl;
//	cout << "-------------------" << endl;
//
//	//for (auto e : arr1) {
//	//	bt.Erase(e);
//	//	bt.InOrder();
//	//	cout << endl;
//	//}
//	//cout << endl;
//	//cout << "-------------------" << endl;
//
//	//for (auto e : arr1) {
//	//	bt.EraseR(e);
//	//	bt.InOrder();
//	//	cout << endl;
//	//}
//	//cout << endl;
//	//cout << "-------------------" << endl;
//
//	BSTree<int> bt1(bt);
//	bt1.InOrder();
//	cout << endl;
//	cout << "-------------------" << endl;
//
//	BSTree<int> bt2;
//	bt2 = bt1;
//	bt2.InOrder();
//	cout << endl;
//	cout << "-------------------" << endl;
//
//	BSTree<int> bt3;
//	bt3.InOrder();
//	cout << endl;
//	cout << "-------------------" << endl;
//
//	return 0;
//}

#include <string>

void TestBSTree1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::BSTree<int> t1;

	for (auto e : a)
	{
		t1.Insert(e);
	}

	//t1.InOrder(t1.GetRoot());
	t1.InOrder();
	cout << endl;

	/*t1.Erase(4);
	t1.InOrder();

	t1.Erase(14);
	t1.InOrder();

	t1.Erase(3);
	t1.InOrder();*/

	t1.Erase(8);
	t1.InOrder();
	cout << endl;

	for (auto e : a)
	{
		t1.Erase(e);
		t1.InOrder();
		cout << endl;
	}

	t1.InOrder();
	cout << endl;
}

void TestBSTree2()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::BSTree<int> t1;

	for (auto e : a)
	{
		t1.InsertR(e);
	}
	t1.InOrder();

	t1.EraseR(10);
	t1.EraseR(14);
	t1.EraseR(13);
	t1.InOrder();


	for (auto e : a)
	{
		t1.EraseR(e);
		t1.InOrder();
	}

	t1.InOrder();
}

void TestBSTree3()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::BSTree<int> t1;
	for (auto e : a)
	{
		t1.InsertR(e);
	}

	t1.InOrder();

	key::BSTree<int> t2(t1);
	t2.InOrder();
}

void TestBSTree4()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("Æ»¹û", "apple");
	dict.Insert("Ïã½¶", "banana");
	dict.Insert("²¤ÂÜ", "Pineapple");
	dict.Insert("³È×Ó", "orange");
	dict.Insert("ÆÏÌÑ", "grape");
	dict.Insert("ÄûÃÊ", "Lemon");
	dict.Insert("Î÷¹Ï", "watermelon");
	dict.Insert("Ó£ÌÒ", "cherry");

	string str;
	while (cin >> str)
	{
		key_value::BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "ÎÞ´Ëµ¥´Ê" << endl;
		}
	}
}

int main()
{
	//TestBSTree1();
	//TestBSTree2();
	//TestBSTree3();
	TestBSTree4();
	return 0;
}
