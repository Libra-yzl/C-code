#pragma once
#include <iostream>
#include <assert.h>
#include <map>
#include <time.h>

using namespace std;

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
		,_kv(kv)
	{}
};

template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent)
		{
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					rotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					rotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					rotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					rotateRL(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	int TreeHeight()
	{
		return _TreeHeight(_root);
	}

private:
	int _TreeHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftH = _TreeHeight(root->_left);
		int rightH = _TreeHeight(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftH = _TreeHeight(root->_left);
		int rightH = _TreeHeight(root->_right);
		
		/*if (rightH - leftH != root->_bf)
		{
			cout << root->_kv.first << "这里出现问题" << endl;
			return false;
		}*/

		return abs(rightH - leftH) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	void rotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* pparent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;

		if (pparent == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
			subL->_parent = pparent;
		}
		subL->_bf = parent->_bf = 0;
	}

	void rotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* pparent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
			subR->_parent = pparent;
		}
		subR->_bf = parent->_bf = 0;
	}

	void rotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		rotateR(parent->_right);
		rotateL(parent);

		if (bf == -1)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void rotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		rotateL(parent->_left);
		rotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

private:
	Node* _root = nullptr;
};

void AVL_test1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		/*	if (e == 14)
			{
			int x = 0;
			}*/

		t.Insert(make_pair(e, e));
		cout << e << "插入：" << t.IsBalance() << endl;
	}

	t.InOrder();
	cout << endl;
	cout << t.IsBalance() << endl;
}

template<class T>
struct BNode
{
	BNode<T>* _left;
	BNode<T>* _right;
	T _val;

	BNode(const T& val = T())
		:_left(nullptr)
		,_right(nullptr)
		,_val(val)
	{}
};

//template <class T>
//class Tree
//{
//	typedef BNode<T> Node;
//
//private:
//	Node* _root;
//};

void pre(BNode<int>* root)
{
	if (root == nullptr) {
		cout << "null" << " ";
		return;
	}
	
	cout << root->_val << " ";
	pre(root->_left);
	pre(root->_right);
}

void in(BNode<int>* root)
{
	if (root == nullptr)
		return;

	in(root->_left);
	cout << root->_val << " ";
	in(root->_right);
}

void post(BNode<int>* root)
{
	if (root == nullptr){
		cout << "null" << " ";
		return;
	}

	post(root->_left);
	post(root->_right);
	cout << root->_val << " ";
}

void test2()
{

	BNode<int>* node1 = new BNode<int>(1);
	BNode<int>* node2 = new BNode<int>(2);
	BNode<int>* node3 = new BNode<int>(3);
	BNode<int>* node4 = new BNode<int>(4);

	/*node1->_left = node2;
	node2->_left = node3;
	node3->_left = node4;*/

	node1->_right = node2;
	node2->_right = node3;
	node3->_right = node4;

	cout << "先序" << endl;
	pre(node1);
	cout << endl;

	/*cout << "中序" << endl;
	pre(node1);
	cout << endl;*/

	cout << "后序" << endl;
	post(node1);
	cout << endl;
}

void AVL_test2()
{
	srand(time(0));
	const size_t N = 1000000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	cout << t.IsBalance() << endl;
	cout << t.TreeHeight() << endl;
}