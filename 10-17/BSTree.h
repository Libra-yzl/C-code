#pragma once

#include <iostream>
using namespace std;

template <class K>
struct BSTNode 
{
	BSTNode<K>* _left;
	BSTNode<K>* _right;
	K _key;

	BSTNode(const K& key = K())
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template <class K>
class BSTree
{
	typedef BSTNode<K> Node;
public:

	bool Insert(const K& key)
	{
		if (_root == nullptr) {
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
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
		if (parent->_key < key) {
			parent->_right = new Node(key);
		}
		else {
			parent->_left = new Node(key);
		}
		return true;
	}

	bool Find(const K& key)
	{
		if (_root == nullptr) {
			return false;
		}
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

	bool Erase(const K& key)
	{
		if (_root == nullptr) {
			return false;
		}
		Node* cur = _root;
		Node* parent = _root;
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
				// 删除
				// 1.左为空
				if (cur == _root) {
					_root = _root->_right;
				}
				else {

					if (cur->_left == nullptr) {
						if (parent->_left == cur) {
							parent->_left = cur->_right;
						}
						else {
							parent->_right = cur->_right;
						}
						delete cur;
						return true;
					}
				}
				// 2.右为空
				else if (cur->_right == nullptr) {
					if (cur == _root) {
						_root = _root->_right;
					}
					else {
						if (parent->_left == cur) {
							parent->_left = cur->_left;
						}
						else {
							parent->_right = cur->_left;
						}
					}
					delete cur;
					return true;
				}
				// 3.左右都不为空
				else {
					// 找左树的最大节点或者右树的最小节点 

					Node* Pmaxleft = cur;
					Node* maxleft = cur->_left;
					while (maxleft->_right) {
						Pmaxleft = maxleft;
						maxleft = maxleft->_right;
					}
					cur->_key = maxleft->_key;
					
					if (Pmaxleft->_left == maxleft)
					{
						Pmaxleft->_left = maxleft->_right;
					}
					else
					{
						Pmaxleft->_right = maxleft->_right;
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

	void PreOrder()
	{
		_PreOrder(_root);
	}

	void PostOrder()
	{
		_PostOrder(_root);
	}
	
protected:
	void _InOrder(Node* root) 
	{
		if (root == nullptr) {
			//cout << "#" << " ";
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void _PreOrder(Node* root) 
	{
		if (root == nullptr) {
			cout << "#" << " ";
			return;
		}
		cout << root->_key << " ";
		_PreOrder(root->_left);
		_PreOrder(root->_right);
	}

	void _PostOrder(Node* root)
	{
		if (root == nullptr) {
			cout << "#" << " ";
			return;
		}
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_key << " ";
	}

private:
	Node* _root = nullptr;
};