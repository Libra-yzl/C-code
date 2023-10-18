#pragma once
#include <iostream>
using namespace std;

template <class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key = K())
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template <class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		else
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			if (parent->_key < key)
			{
				parent->_right = new Node(key);
			}
			else
			{
				parent->_left = new Node(key);
			}
			return true;
		}
		return false;
	}

	bool Find()
	{
		
	}

	void InOrder()
	{
		_InOrder(_root);
	}

protected:
	void _InOrder(Node* root)
	{
		if (root == nullptr) return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};