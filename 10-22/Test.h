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

	BSTree() = default;

	BSTree(const BSTree<K>& bt)
		:_root(nullptr)
	{
		_root = _copy(bt._root);
	}

	BSTree<K>& operator=(BSTree<K> bt)
	{
		swap(_root, bt._root);
		return *this;
	}

	Node* _copy(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* newroot = new Node(root->_key);
		newroot->_left = _copy(root->_left);
		newroot->_right = _copy(root->_right);
		return newroot;
	}

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
	}

	bool Find(const K& key)
	{
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
		return false;
	}

	bool Erase(const K& key)
	{
		if (_root == nullptr)
		{
			return false;
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
					// 找到要删除的元素
					// 开始删除
					// 1.左为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = _root->_right;
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
						// 2.右为空
						if (cur == _root)
						{
							_root = _root->_left;
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
						// 3.左右都不为空
						Node* pmaxleft = cur;
						Node* maxleft = cur->_left;
						while (maxleft->_right)
						{
							pmaxleft = maxleft;
							maxleft = maxleft->_right;
						}
						cur->_key = maxleft->_key;
						if (pmaxleft->_left == maxleft)
						{
							pmaxleft->_left = maxleft->_left;
						}
						else
						{
							pmaxleft->_right = maxleft->_left;
						}
						delete maxleft;
						return true;
					}
				}
			}
			return false;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	void PreOrder()
	{
		_PreOrder(_root);
	}

	bool InsertR(const K& key)
	{
		return _Insert(_root, key);
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}

	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	~BSTree()
	{
		Destroy(_root);
	}

protected:

	void _PreOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		cout << root->_key << " ";
		_PreOrder(root->_left);
		_PreOrder(root->_right);
	}

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

	bool _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key == key)
		{
			return true;
		}
		else if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else
		{
			return _FindR(root->_left, key);
		}
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
				swap(maxleft->_key, root->_key);
				return _EraseR(root->_left, key);
			}
			delete del;
			return true;
		}
	}

	bool _Insert(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
		}
		if (root->_key < key)
		{
			return _Insert(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _Insert(root->_left, key);
		}
		else
		{
			return false;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};

namespace key
{
	template <class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key = K())
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template <class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:

		BSTree() = default;

		BSTree(const BSTree<K>& bt)
			:_root(nullptr)
		{
			_root = _copy(bt._root);
		}

		BSTree<K>& operator=(BSTree<K> bt)
		{
			swap(_root, bt._root);
			return *this;
		}

		Node* _copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* newroot = new Node(root->_key);
			newroot->_left = _copy(root->_left);
			newroot->_right = _copy(root->_right);
			return newroot;
		}

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
		}

		bool Find(const K& key)
		{
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
			return false;
		}

		bool Erase(const K& key)
		{
			if (_root == nullptr)
			{
				return false;
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
						// 找到要删除的元素
						// 开始删除
						// 1.左为空
						if (cur->_left == nullptr)
						{
							if (cur == _root)
							{
								_root = _root->_right;
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
							// 2.右为空
							if (cur == _root)
							{
								_root = _root->_left;
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
							// 3.左右都不为空
							Node* pmaxleft = cur;
							Node* maxleft = cur->_left;
							while (maxleft->_right)
							{
								pmaxleft = maxleft;
								maxleft = maxleft->_right;
							}
							cur->_key = maxleft->_key;
							if (pmaxleft->_left == maxleft)
							{
								pmaxleft->_left = maxleft->_left;
							}
							else
							{
								pmaxleft->_right = maxleft->_left;
							}
							delete maxleft;
							return true;
						}
					}
				}
				return false;
			}
		}

		void InOrder()
		{
			_InOrder(_root);
		}

		void PreOrder()
		{
			_PreOrder(_root);
		}

		bool InsertR(const K& key)
		{
			return _Insert(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		~BSTree()
		{
			Destroy(_root);
		}

	protected:

		void _PreOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			cout << root->_key << " ";
			_PreOrder(root->_left);
			_PreOrder(root->_right);
		}

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

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key == key)
			{
				return true;
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return _FindR(root->_left, key);
			}
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
					swap(maxleft->_key, root->_key);
					return _EraseR(root->_left, key);
				}
				delete del;
				return true;
			}
		}

		bool _Insert(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
			}
			if (root->_key < key)
			{
				return _Insert(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _Insert(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};
}

namespace key_value
{
	template <class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}
	};

	template <class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:

		BSTree() = default;

		BSTree(const BSTree<K, V>& bt)
			:_root(nullptr)
		{
			_root = _copy(bt._root);
		}

		BSTree<K, V>& operator=(BSTree<K, V> bt)
		{
			swap(_root, bt._root);
			return *this;
		}

		Node* _copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* newroot = new Node(root->_key);
			newroot->_left = _copy(root->_left);
			newroot->_right = _copy(root->_right);
			return newroot;
		}

		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
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
					parent->_right = new Node(key, value);
				}
				else
				{
					parent->_left = new Node(key, value);
				}
				return true;
			}
		}

		Node* Find(const K& key)
		{
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
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			if (_root == nullptr)
			{
				return false;
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
						// 找到要删除的元素
						// 开始删除
						// 1.左为空
						if (cur->_left == nullptr)
						{
							if (cur == _root)
							{
								_root = _root->_right;
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
							// 2.右为空
							if (cur == _root)
							{
								_root = _root->_left;
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
							// 3.左右都不为空
							Node* pmaxleft = cur;
							Node* maxleft = cur->_left;
							while (maxleft->_right)
							{
								pmaxleft = maxleft;
								maxleft = maxleft->_right;
							}
							cur->_key = maxleft->_key;
							if (pmaxleft->_left == maxleft)
							{
								pmaxleft->_left = maxleft->_left;
							}
							else
							{
								pmaxleft->_right = maxleft->_left;
							}
							delete maxleft;
							return true;
						}
					}
				}
				return false;
			}
		}

		void InOrder()
		{
			_InOrder(_root);
		}


		~BSTree()
		{
			Destroy(_root);
		}

	protected:

		void _PreOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			cout << root->_key << " ";
			_PreOrder(root->_left);
			_PreOrder(root->_right);
		}

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


		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " " << ":" << " " << root->_value << endl;
			_InOrder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};
}