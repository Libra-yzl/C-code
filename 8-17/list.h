#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

namespace jwf
{
	template <class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;

		T _data;

		list_node(const T& val = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(val)
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

		Ref operator*()
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator++(int)
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

		self& operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const self& s) const
		{
			return _node == s._node;
		}

		Ptr operator->()
		{
			return &(_node->data);
		}

	};

	//template <class T>
	//struct __list_iterator
	//{
	//	typedef list_node<T> node;
	//	typedef __list_iterator<T> self;

	//	node* _node;

	//	__list_iterator(node* n)
	//		:_node(n)
	//	{}

	//	T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	self& operator++(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	self& operator--(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	bool operator!=(const self& s) const 
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const self& s) const
	//	{
	//		return _node == s._node;
	//	}
	//	
	//	T* operator->()
	//	{
	//		return &_node;
	//	}

	//};

	/*template <class T>
	struct __list_const_iterator
	{
		typedef list_node<T> node;
		typedef __list_const_iterator<T> self;

		node* _node;

		__list_const_iterator(node* n)
			:_node(n)
		{}

		const T& operator*()
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator++(int)
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

		self& operator--(int)
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
		
		T* operator->()
		{
			return &_node;
		}

	};*/

	template <class T>
	class list
	{
		typedef list_node<T> node;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		//typedef __list_const_iterator<T> const_iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;


		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			_head->_data = 0;
		}

		void push_back(const T& val)
		{
			/*node* newnode = new node(val);

			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val = T())
		{
			node* newnode = new node(val);

			pos._node->_prev->_next = newnode;
			newnode->_prev = pos._node->_prev;
			newnode->_next = pos._node;
			pos._node->_prev = newnode;
		}

		void erase(iterator pos)
		{
			assert(pos != end());

			pos._node->_next->_prev = pos._node->_prev;
			pos._node->_prev->_next = pos._node->_next;
			delete pos._node;
		}

		void print()
		{
			node* tmp = _head->_next;
			while (tmp != _head)
			{
				cout << tmp->_data << " ";
				tmp = tmp->_next;
			}
			cout << endl;
		}

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

		lt.print();

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.insert(lt.begin(), 30);
		lt.insert(lt.begin(), 30);
		lt.insert(lt.begin(), 30);
		lt.insert(lt.begin(), 30);
		lt.insert(lt.end(), 3000);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.erase(lt.begin());
		lt.erase(lt.begin());
		lt.erase(--lt.end());
		print_list(lt);

		lt.pop_back();
		print_list(lt);

		lt.pop_front();
		print_list(lt);
	}
}

