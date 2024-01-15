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

template <class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;
	T _data;

	RBTreeNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(RED)
	{}
};

template <class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> self;
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	__RBTreeIterator(const __RBTreeIterator<T, T&, T*>& s)
		:_node(s._node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;
	}

	self& operator++()
	{
		// 右不为空
		if (_node->_right)
		{
			// 找右树最左节点
			Node* cur = _node->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}
			// 如果左不存在 就该自身
			_node = cur;
		}
		else /* 右树为空 */
		{
			// 找孩子是父亲左的祖先
			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			// 找到
			_node = parent;
		}
		return *this;
	}

	self& operator--()
	{
		// 左不为空
		if (_node->_left)
		{
			Node* cur = _node->_left;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_node = cur;
		}
		else /* 左为空 */
		{
			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
};

template <class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;

public:
	
	/*RBTree(const RBTree<K, T, KeyOfT>& rbtree)
	{
		_root = _clone(rbtree._root, nullptr);
	}*/

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}
	
	iterator end()
	{
		return iterator(nullptr);
	}

	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

	Node* Find(const K& key)
	{
		KeyOfT kot;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	pair<iterator, bool> Insert(const T& data)
	{
		KeyOfT kot;
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);

			}
		}

		cur = new Node(data);
		Node* node = cur;
		if (kot(parent->_data) < kot(data))
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
		return make_pair(iterator(node), true);
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

		Node* newroot = new Node(root->_data);
		newroot->_parent = parent;
		newroot->_left = _clone(root->_left, newroot);
		newroot->_left = _clone(root->_right, newroot);
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
