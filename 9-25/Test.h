#pragma once

#include <iostream>
using namespace std;

namespace yzl
{
	template <class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val)
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{}
	};

	template <class T>
	class list
	{
		typedef list_node<T> node;
	public:
		list(const T& val)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			_head->_val = val;
		}
	private:
		node* _head;
	};
}