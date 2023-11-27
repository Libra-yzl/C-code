#pragma once

#include <iostream>
#include <map>
#include <assert.h>
#include <time.h>

using namespace std;

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf; // balance factor -- 平衡因子

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
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

		// 创建节点并链接
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				--parent->_bf;
			}
			else
			{
				++parent->_bf;
			}

			if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 需要继续更新
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 0)
			{
				// 不需要处理
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 需要旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					rotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					rotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					rotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					rotateLR(parent);
				}
				else
				{
					assert(false);
				}

				break;
			}
			else
			{
				// 此时如果出现问题证明之前的就已经有问题了
				assert(false);
			}
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool isBalance()
	{
		return _isBalance(_root);
	}

	int Height()
	{
		return _Height(_root);
	}

private:
	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int left = _Height(root->_left);
		int right = _Height(root->_right);

		return left > right ? left + 1 : right + 1;
	}

	bool _isBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);
		
		// 判断平衡因子
		if (rightH - leftH != root->_bf)
		{
			cout << root->_kv.first << " 这个节点平衡因子异常" << endl;
			return false;
		}

		return abs(leftH - rightH) < 2 && _isBalance(root->_left) && _isBalance(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
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
		parent->_bf = subR->_bf = 0;
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
		subL->_bf = parent->_bf = 0;
	}

	void rotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		rotateR(parent->_right);
		rotateL(parent);

		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;
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

void AVLTree_test1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		/*	if (e == 14)
			{
			int x = 0;
			}*/
		/*if (e == 4)
		{
			int x;
		}*/

		t1.Insert(make_pair(e, e));
		cout << e << "插入：" << t1.isBalance() << endl;
	}
	cout << endl;

	t1.InOrder();
	cout << endl;
	cout << t1.isBalance() << endl;
}

void AVLTree_test2()
{
	srand((unsigned int)time(nullptr));
	const size_t N = 5000000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.isBalance() << endl;
	cout << t.Height() << endl;
}