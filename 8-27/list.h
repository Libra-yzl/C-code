#pragma once

#include <iostream>
#include "iterator.h"
using namespace std;
#include <assert.h>

namespace yzl
{
	template <class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;

		T _data;

		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(val)
		{}
	};

	/*template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr> self;
		node* _node;

		list_iterator(node* n)
			:_node(n)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;

			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;

			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};*/

	template <class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr> self;

		node* _node;

		list_iterator(node* n)
			:_node(n)
		{}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;

			return tmp;
		}


		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

	};

	/*template <class T>
	struct list_const_iterator
	{
		typedef list_node<T> node;
		typedef list_const_iterator<T> self;

		node* _node;

		list_const_iterator(node* n)
			:_node(n)
		{}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		const T& operator*() const
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

	};*/

	//template<class T>
	//class list
	//{
	//	typedef list_node<T> node;
	//public:
	//	typedef list_iterator<T, T&, T*> iterator;
	//	typedef list_iterator<T, const T&, const T*> const_iterator;

	//	//typedef __list_const_iterator<T> const_iterator;

	//	iterator begin()
	//	{
	//		//iterator it(_head->_next);
	//		//return it;
	//		return iterator(_head->_next);
	//	}

	//	const_iterator begin() const
	//	{
	//		return const_iterator(_head->_next);
	//	}

	//	iterator end()
	//	{
	//		return iterator(_head);
	//	}

	//	const_iterator end() const
	//	{
	//		//iterator it(_head->_next);
	//		//return it;
	//		return const_iterator(_head);
	//	}

	//	void empty_init()
	//	{
	//		_head = new node;
	//		_head->_next = _head;
	//		_head->_prev = _head;
	//	}

	//	list()
	//	{
	//		empty_init();
	//	}

	//	template <class Iterator>
	//	list(Iterator first, Iterator last)
	//	{
	//		empty_init();

	//		while (first != last)
	//		{
	//			push_back(*first);
	//			++first;
	//		}
	//	}

	//	// lt2(lt1)
	//	/*list(const list<T>& lt)
	//	{
	//	empty_init();
	//	for (auto e : lt)
	//	{
	//	push_back(e);
	//	}
	//	}*/
	//	void swap(list<T>& tmp)
	//	{
	//		std::swap(_head, tmp._head);
	//	}

	//	list(const list<T>& lt)
	//	{
	//		empty_init();

	//		list<T> tmp(lt.begin(), lt.end());
	//		swap(tmp);
	//	}

	//	// lt1 = lt3
	//	list<T>& operator=(list<T> lt)
	//	{
	//		swap(lt);
	//		return *this;
	//	}

	//	~list()
	//	{
	//		clear();
	//		delete _head;
	//		_head = nullptr;
	//	}

	//	void clear()
	//	{
	//		iterator it = begin();
	//		while (it != end())
	//		{
	//			//it = erase(it);
	//			erase(it++);
	//		}
	//	}

	//	void push_back(const T& x)
	//	{
	//		/*node* tail = _head->_prev;
	//		node* new_node = new node(x);

	//		tail->_next = new_node;
	//		new_node->_prev = tail;
	//		new_node->_next = _head;
	//		_head->_prev = new_node;*/

	//		insert(end(), x);
	//	}

	//	void push_front(const T& x)
	//	{
	//		insert(begin(), x);
	//	}

	//	void pop_back()
	//	{
	//		erase(--end());
	//	}

	//	void pop_front()
	//	{
	//		erase(begin());
	//	}

	//	void insert(iterator pos, const T& x)
	//	{
	//		node* cur = pos._node;
	//		node* prev = cur->_prev;

	//		node* new_node = new node(x);

	//		prev->_next = new_node;
	//		new_node->_prev = prev;
	//		new_node->_next = cur;
	//		cur->_prev = new_node;
	//	}

	//	iterator erase(iterator pos)
	//	{
	//		assert(pos != end());

	//		node* prev = pos._node->_prev;
	//		node* next = pos._node->_next;

	//		prev->_next = next;
	//		next->_prev = prev;
	//		delete pos._node;

	//		return iterator(next);
	//	}
	//private:
	//	node* _head;
	//};

	template <class T>
	class list
	{
		typedef list_node<T> node;

	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<iterator, const T&, const T*> const_reverse_iterator;

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		iterator begin()
		{
			//iterator it(_head->_next);
			//return it;
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			//iterator it(_head->_next);
			//return it;
			return const_iterator(_head);
		}

		void empty_list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_list();
		}

		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			empty_list();

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		/*list(const list<T>& lt)
		{
			empty_list();
			for (auto e : lt)
			{
				push_back(e);	
			}
		}*/

		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}

		list(const list<T>& lt)
		{
			empty_list();

			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void push_back(const T& val)
		{
			node* newnode = new node(val);

			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			node* prev = pos._node->_prev;
			node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;

			return iterator(next);
		}

		/*iterator erase(iterator pos)
		{
			assert(pos != end());

			node* prev = pos._node->_prev;
			node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;

			return iterator(next);
		}*/

		void print() const
		{
			node* tmp =_head->_next;
			while (tmp != _head)
			{
				cout << tmp->_data << " ";
				tmp = tmp->_next;
			}
			cout << endl;
		}

		/*void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}*/

		/*~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}*/

	private:
		node* _head;
	};

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//(*it) *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list1()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		//lt.print();

		/*cout << typeid(lt.begin()).name() << endl;
		list<int>::iterator it = lt.begin();
		cout << typeid(it).name() << endl;
		cout << typeid(lt.end()).name() << endl;*/

		auto it = lt.begin();
		/*cout << typeid(it).name() << endl;
		cout << typeid(lt._head).name() << endl;*/
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		print_list(lt);

		
	}

	void test_list2()
	{
		const struct AA
		{

			int _a1;
			int _a2;

			AA(int a1 = 0, int a2 = 0)
				:_a1(a1)
				, _a2(a2)
			{}
		};

		const list<AA> lt1;
		/*lt1.push_back(AA(1, 1));
		lt1.push_back(AA(2, 2));
		lt1.push_back(AA(3, 3));*/

		list<AA>::const_iterator it = lt1.begin();
		/*cout << typeid(it).name() << endl;
		cout << typeid(lt1.begin()).name() << endl;
		cout << typeid(lt1.end()).name() << endl;*/

		while (it != lt1.end())
		{
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			//it->_a1 = 10;
			cout << it->_a1 << ":" << it->_a2 << endl;
			cout << it.operator->()->_a1 << ":" << it.operator->()->_a1 << endl;
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		lt1.push_back(5);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;


		/*list<int> lt(++lt1.begin(), lt1.end());

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1 = lt;
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;*/
		
		lt1.erase(lt1.begin());
		lt1.erase(lt1.begin());
		lt1.erase(lt1.begin());
		lt1.erase(lt1.begin());
		lt1.erase(lt1.begin());
		//lt1.erase(lt1.begin());
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list4()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		l1.push_back(6);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		list<int>::reverse_iterator rit = l1.rbegin();
		while (rit != l1.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}
}