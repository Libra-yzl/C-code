#pragma once
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

	template <class T>
	struct __list_node_iterator
	{
		typedef list_node<T> node;
		typedef __list_node_iterator<T> self;
		typedef __list_node_iterator<T>* iterator;

		node* _node;

		__list_node_iterator(node* n)
			:_node(n)
		{}

		T& operator*() { return _node->_val; }
		self& operator++() { 
			_node = _node->_next;
			return *this;
		}
		bool operator!=(const self& s) { return _node != s._node; }
	};

	template <class T>
	class list
	{
	public:
		typedef list_node<T> node;
		typedef __list_node_iterator<T> iterator;

		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& val)
		{
			node* newnode = new node(val);
			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		node* _head;
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
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}