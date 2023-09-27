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

	//__list_iterator��һ����װ�˵���������
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

		bool operator !=(const __list_iterator<T, Ref>& it) { return _node != it._node; }

		__list_iterator<T, Ref>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

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

		list()
		{
			empty_init();
		}

		// ���������乹�캯��
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

		// �������� - �ִ�д��(����)
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		void push_back(const T& val)
		{
			list_node<T>* newnode = new list_node<T>(val);
			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;

		}

		void insert(iterator pos, const T& val = T())
		{
			list_node<T>* newnode = new list_node<T>(val);
			pos._node->_prev->_next = newnode;
			newnode->_prev = pos._node->_prev;
			newnode->_next = pos._node;
			pos._node->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			//����ɾ���ڱ�λͷ���
			assert(pos != end());

			// ����Ҫɾ���ڵ��next ���� ��ֹ������ʧЧ
			list_node<T>* next = pos._node->_next;
			
			// ɾ��pos�ڵ�
			pos._node->_next->_prev = pos._node->_prev;
			pos._node->_prev->_next = pos._node->_next;
			delete pos._node;

			return next;
		}
		void clear()
		{
			// clear()��������ͷų�ͷ���֮������нڵ�
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}

		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

	private:
		list_node<T>* _head;
	};

	void print(const list<int>& lt)
	{
		for (auto e : lt) cout << e << " ";
		cout << endl;
	}

	//����list��push_back
	void list_test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		//���Զ�ȡ����
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//����insert, erase
		lt.insert(lt.begin(), 10);
		lt.insert(lt.end(), 20);
		for (auto e : lt) cout << e << " ";
		cout << endl;

		lt.erase(lt.begin());
		lt.erase(--lt.end());
		for (auto e : lt) cout << e << " ";
		cout << endl;

		//����const���������
		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);
		lt1.push_back(40);
		print(lt1);
		
	}

	void list_test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int> lt1(lt);
		print(lt1);
		print(lt);

		//���Ե��������乹��
		list<int> lt2(lt.begin(), lt.end());
		print(lt2);
	}
}