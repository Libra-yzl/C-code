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
		if (_root == nullptr) {
			_root = new Node(key);
			return true;
		}
		
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_key < key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key) {
			parent->_right = cur;
		}
		else{
			parent->_left = cur;
		}

		return true;
	}

	void InOrder() {
		_InOrder(_root);
	}

	void _InOrder(Node* root) {
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur) {
			if (cur->_key < key) {
				cur = cur->_right;
			}
			else if (cur->_key > key) {
				cur = cur->_left;
			}
			else {
				return true;
			}
		}
		return false;
	}

	/*bool Erase(const K& key) {
		
	}*/

private:
	Node* _root = nullptr;
};