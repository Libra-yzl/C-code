#pragma once

#include <iostream>
#include <map>
#include <assert.h>
#include <time.h>

using namespace std;

enum colour
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
	colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
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
			_root->_col = BLACK; // 根节点是黑色
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

		while (parent && parent->_col == RED)
		{
			Node* grandf = parent->_parent;
			if (grandf->_left == parent)
			{
				Node* uncle = grandf->_right;
				if (uncle && uncle->_col == RED)
				{
					// uncle存在且为红色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandf->_col = RED;

					// 此时可能会出现grandf->_parent为红色节点 需要继续调整
					cur = grandf;
					parent = cur->_parent;
				}
				else
				{
					// uncle不存在 或者存在且为黑色
					// 此时需要 变色+旋转

				}
			}
			else // grandf->_right == parent
			{
				Node* uncle = grandf->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandf->_col = RED;

					// 继续调整
					cur = grandf;
					parent = cur->_parent;
				}
				else
				{
					// 情况2+3
				}
			}
		}
		// 置根节点为黑色
		_root->_col = BLACK;

		return true;
	}

private:
	Node* _root = nullptr;
};