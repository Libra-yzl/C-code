#pragma once

#include <iostream>
#include <assert.h>


template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf; // balance factor
	pair<K, V>_kv;

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
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		cur->_parent = parent;

		// balance factor
		while (parent) {
			if (cur == parent->_right) {
				parent->_bf++;
			}
			else {
				parent->_bf--;
			}

			if (parent->_bf == 1 || parent->_bf == -1) {
				// 更新
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				// 旋转

				break;
			}
			else if (parent->_bf == 0) {
				// 不需要调整 结束
				break;
			}
			else {
				assert(false);
			}
		}

		return true;
	}
private:
	void rotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* ppnode = parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (ppnode == nullptr) {
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else {
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}

		// 更新平衡因子
		parent->_bf = subR->_bf = 0;
	}

	void rotateR(Node* parent)
	{
		Node* subL = parent->_right;
		Node* subLR = subL->_left;

		parent->_right = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* ppnode = parent;
		subL->_left = parent;
		parent->_parent = subL;
		if (ppnode == nullptr) {
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else {
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}

		// 更新平衡因子
		parent->_bf = subL->_bf = 0;
	}

	void rotateLR(Node* parent)
	{

	}

	void rotateRL(Node* parent)
	{

	}

private:
	Node* _root = nullptr;
};