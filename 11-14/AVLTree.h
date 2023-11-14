#pragma once
#include <assert.h>

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	pair<K, V> _kv;

	AVLTreeNode(const pair<K,V>& kv)
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

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv._first)
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
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 1 || parent->_bf == -1)
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

private:
	void RotateL(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

	}

private:
	Node* _root = nullptr;
};