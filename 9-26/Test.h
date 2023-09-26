#pragma once

#include <iostream>
using namespace std;
#include <assert.h>
#include <algorithm>

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

	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;

		node* _node;

		__list_iterator(node* n)
			:_node(n)
		{}

		Ptr operator->() { return &_node->_val; }

		Ref operator*() { return _node->_val; }

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

		bool operator!=(const self& s) { return _node != s._node; }
		bool operator==(const self& s) { return _node == s._node; }
	};

	template <class T>
	class list
	{
		typedef list_node<T> node;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }

		const_iterator begin() const { return const_iterator(_head->_next); }
		const_iterator end() const { return const_iterator(_head); }

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

		//传统版本(创建)
		/*list(const list<T>& lt)
		{
			empty_list();
			for (auto e : lt) push_back(e);
		}*/

		//现代版本(交换)
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		list(const list<T>& lt)
		{
			empty_list();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		list<T>& operator=(const list<T>& lt)
		{
			list<T> tmp(lt);
			swap(tmp);
			return *this;
		}

		void push_back(const T& val = T())
		{
			/*node* newnode = new node(val);
			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			
			insert(end(), val);
		}

		void insert(iterator pos, const T& val)
		{
			node* newnode = new node(val);

			pos._node->_prev->_next = newnode;
			newnode->_prev = pos._node->_prev;
			newnode->_next = pos._node;
			pos._node->_prev = newnode;
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			//提前记下pos._node的next 方便返回这个位置
			node* next = pos._node->_next;

			pos._node->_prev->_next = pos._node->_next;
			pos._node->_next->_prev = pos._node->_prev;
			delete pos._node;

			return iterator(next);
		}

		void pop_back() { erase(--end()); }

		void pop_front() { erase(begin()); }

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				//erase(it++);
			}
		}

	private:
		node* _head;
	};

	void Print(const list<int>& lt)
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

	struct AA
	{
		int _a1;
		int _a2;

		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
	};

	void list_test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//(*it)++;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt) cout << e << " ";
		cout << endl;

		Print(lt);

	}

	void list_test2()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));

		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << it->_a1 << ":" << it->_a2 << endl;
			++it;
		}
		cout << endl;
	}

	void list_test3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		for (auto e : lt) cout << e << " ";
		cout << endl;

		/*list<int>::iterator pos = find(lt.begin(), lt.end(), 3);*/
		list<int>::iterator pos = lt.begin();
		++pos;
		lt.insert(pos, 10);
		for (auto e : lt) cout << e << " ";
		cout << endl;

		lt.push_back(1000);
		lt.push_front(10000);
		for (auto e : lt) cout << e << " ";
		cout << endl;

		pos = lt.begin();
		++pos;
		lt.erase(pos);
		for (auto e : lt) cout << e << " ";
		cout << endl;

		lt.pop_back();
		for (auto e : lt) cout << e << " ";
		cout << endl;

		lt.pop_front();
		for (auto e : lt) cout << e << " ";
		cout << endl;
	}

	void list_test4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);

		auto pos = lt.begin();
		++pos;
		lt.insert(pos, 10);
		for (auto e : lt) cout << e << " ";
		cout << endl;
	}

	void list_test5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		for (auto e : lt) cout << e << " ";
		cout << endl;

		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);
		lt1.push_back(40);
		for (auto e : lt1) cout << e << " ";
		cout << endl;

		//测试赋值重载
		lt1 = lt;
		for (auto e : lt1) cout << e << " ";
		cout << endl;

		for (auto e : lt) cout << e << " ";
		cout << endl;

		lt.clear();
		for (auto e : lt) cout << e << " ";
		cout << endl;
	}
}