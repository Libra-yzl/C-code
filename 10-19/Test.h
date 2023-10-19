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

	/*BSTree()
		:_root(nullptr)
	{}*/

	BSTree() = default;

	BSTree(const BSTree<K>& bt)
		:_root(nullptr)
	{
		_root = _Copy(bt._root);
	}

	BSTree<K>& operator=(BSTree<K> bt)
	{
		swap(_root, bt._root);
		return *this;
	}

	~BSTree()
	{
		Destroy(_root);
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
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

	bool Find(const K& key)
	{
		if (_root == nullptr)
		{
			return false;
		}
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
	}

	bool Erase(const K& key)
	{
		if (_root == nullptr)
		{
			return false;
		}
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
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_key < key)
						{
							parent->_right = cur->_right;
						}
						else
						{
							parent->_left = cur->_right;
						}
					}
					delete cur;
					return true;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_key < key)
						{
							parent->_right = cur->_left;
						}
						else
						{
							parent->_left = cur->_left;
						}
					}
					delete cur;
					return true;
				}
				else
				{
					Node* maxleft = cur->_left;
					Node* Pmaxleft = cur;
					while (maxleft->_right)
					{
						Pmaxleft = maxleft;
						maxleft = maxleft->_right;
					}
					cur->_key = maxleft->_key;
					if (Pmaxleft->_left == maxleft)
					{
						Pmaxleft->_left = maxleft->_left;
					}
					else
					{
						Pmaxleft->_right = maxleft->_left;
					}
					delete maxleft;
					return true;
				}
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}

protected:

	void Destroy(Node*& root)
	{
		if (root == nullptr)
		{
			return;
		}
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
		root = nullptr;
	}

	Node* _Copy(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* newroot = new Node(root->_key);
		newroot->_left = _Copy(root->_left);
		newroot->_right = _Copy(root->_right);
	
		return newroot;
	}

	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else
		{
			Node* del = root;
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* maxleft = root->_left;
				while (maxleft->_right)
				{
					maxleft = maxleft->_right;
				}
				swap(root->_key, maxleft->_key);

				return _EraseR(root->_left, key);
			}
			delete del;
			return true;
		}
	}

	bool _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key == key) return true;

		if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else
		{
			return _FindR(root->_left, key);
		}
	}

	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};