#pragma once

#include <iostream>
using namespace std;
#include <assert.h>

namespace yzl
{
	template <class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{}
	};

	template <class T, class Ref>
	struct __list_iterator
	{
		list_node<T>* _node;

		__list_iterator(list_node<T>* node)
			:_node(node)
		{}

		Ref operator*() { return _node->_val; }
		
		__list_iterator<T, Ref>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!= (const __list_iterator<T, Ref>& lt) { return _node != lt._node; }

	};

	template <class T>
	class list
	{
	public:

		typedef __list_iterator<T, T&> iterator;
		typedef __list_iterator<T, const T&> const_iterator;

		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }

		const_iterator begin() const { return const_iterator(_head->_next); }
		const_iterator end() const { return const_iterator(_head); }

		void empty_init()
		{
			_head = new list_node<T>;
			_head->_next = _head;
			_head->_prev = _head;
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list()
		{
			empty_init();
		}

		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}

		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		list<T>& operator=(const list<T>& lt)
		{
			list<int> tmp(lt.begin(), lt.end());
			swap(tmp);
			return *this;
		}

		void push_back(const T& val = T())
		{
			list_node<T>* newnode = new list_node<T>(val);

			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:

		list_node<T>* _head;
	};

	void print(const list<int>& lt)
	{
		for (auto e : lt) cout << e << " ";
		cout << endl;
	}

	void list_test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		
		/*list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;*/
		print(lt);
		
		list<int> lt1(lt);
		print(lt1);

		list<int> lt2;
		/*lt2.push_back(10);
		lt2.push_back(20);
		lt2.push_back(30);
		lt2.push_back(40);
		lt2.push_back(50);*/
		print(lt2);

		lt2 = lt1;
		print(lt2);
		print(lt1);
	}
}