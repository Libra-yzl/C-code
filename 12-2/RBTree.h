#pragma once
#include <iostream>
#include <map>
#include <assert.h>
#include <time.h>


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
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
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
			Node* grandf = parent->_parent;
			if (grandf->_left == parent)
			{
				Node* uncle = grandf->_right;
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;
					grandf->_col = RED;

					cur = grandf;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_right == cur)
					{
						//     g                 g              c   
						//  p     u    ->     c     u   ->   p     g    
						//     c           p                          u
						//
						rotateL(parent);
						rotateR(grandf);
						grandf->_col = RED;
						cur->_col = BLACK;
					}
					else
					{
						rotateR(grandf);
						parent->_col = BLACK;
						grandf->_col = RED;
					}

					break;
				}
			}
			else
			{
				Node* uncle = grandf->_left;
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;
					grandf->_col = RED;

					cur = grandf;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_right == cur)
					{
						rotateL(grandf);
						parent->_col = BLACK;
						grandf->_col = RED;
					}
					else
					{
						rotateR(parent);
						rotateL(grandf);
						cur->_col = BLACK;
						grandf->_col = RED;
					}

					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool isBalance()
	{
		// 检查根节点颜色
		if (_root && _root->_col == RED)
		{
			cout << "根节点颜色是红色" << endl;
			return false;
		}

		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}

		// 连续红色节点
		return _check(_root, 0, benchmark);
	}

private:
	bool _check(Node* root, int blackNum, int benchmark)
	{
		// 检查每条路径的黑色节点数量
		if (root == nullptr)
		{
			if (benchmark != blackNum)
			{
				cout << "黑色节点数量不正确" << endl;
				return false;
			}
			return true;
		}

		if (root->_col == BLACK)
		{
			blackNum++;
		}

		// 检查是否存在连续的红色节点
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		return _check(root->_left, blackNum, benchmark) && _check(root->_right, blackNum, benchmark);
	}

	void rotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		
		Node* ppnode = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
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

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* ppnode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
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

private:
	Node* _root = nullptr;
};

void RBTree_test1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	RBTree<int, int> t1;
	for (auto e : a)
	{

		t1.Insert(make_pair(e, e));
		cout << e << "插入：" << t1.isBalance() << endl;
	}

	t1.InOrder();
	cout << t1.isBalance() << endl;
}

void RBTree_test2()
{
	srand(time(0));
	const size_t N = 5000000;
	RBTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
	}

	cout << t.isBalance() << endl;
}