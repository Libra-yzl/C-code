#pragma once
#include <iostream>
#include <assert.h>
#include <map>

using namespace std;

enum Colour
{
	RED,
	BLACK
};

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(RED)
	{}
};

template <class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	RBTree(const RBTree<K, V>& rbtree)
		:_root(nullptr)
	{
		_root = _clone(rbtree._root, nullptr);
	}

	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
		}
		Node* parent = nullptr;
		Node* cur = _root;
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

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_left == cur)
					{
						rotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						rotateL(parent);
						rotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_left == cur)
					{
						rotateR(parent);
						rotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						rotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	
	bool IsRBTree()
	{
		if (_root && _root->_col == RED)
		{
			cout << "根节点颜色为红色" << endl;
			return false;
		}

		int benchmark = 0; // 基准值
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}

		return _check(_root, 0, benchmark);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	Node* _clone(Node* root, Node* parent)
	{
		if (root == nullptr)
			return nullptr;

		Node* newroot = new Node(root->_kv);
		newroot->_parent = parent;
		newroot->_left = _clone(root->_left, newroot);
		newroot->_right = _clone(root->_right, newroot);
		return newroot;
	}

	void _Destroy(Node* root)
	{
		if (root == nullptr)
			return;

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	void rotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (ppnode == nullptr)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
	}

	void rotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* ppnode = parent->_parent;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (ppnode == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	bool _check(Node* root, int blackcnt, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark != blackcnt)
			{
				cout << "存在黑色节点数量不相等" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == BLACK)
			++blackcnt;

		if (root->_col == RED && root->_parent && root->_parent->_col == RED) // 检查连续红色节点
		{
			cout << "存在连续红色节点" << endl;
			return false;
		}

		return _check(root->_left, blackcnt, benchmark) && _check(root->_right, blackcnt, benchmark);
	}

private:
	Node* _root = nullptr;
};

void rb_tree_test1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
		cout << e << "插入：" << t1.IsRBTree() << endl;
	}

	t1.InOrder();
	cout << t1.IsRBTree() << endl;

	//
	cout << "测试拷贝构造" << endl;
	RBTree<int, int>t2(t1);
	/*for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;*/
	t2.InOrder();
	cout << endl;
}

void rb_tree_test2()
{
	srand(time(0));
	const size_t N = 5000000;
	RBTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.IsRBTree() << endl;
}