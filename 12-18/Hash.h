#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <time.h>

using namespace std;

namespace OpenHash
{
	template <class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
	};

	template <class K>
	struct HashFun
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	// 模板特化
	template <>
	struct HashFun<string>
	{
		size_t operator()(const string & s)
		{
			size_t hash = 0;
			for (auto ch : s)
			{
				hash += ch;
				hash *= 31;
			}
			return hash;
		}

	};

	template <class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template <class K, class T, class KeyOfT, class Hash>
	struct __HashIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef __HashIterator<K, T, KeyOfT, Hash> self;

		Node* _node;
		HT* _ht;

		__HashIterator(Node* node, HT* ht)
			:_node(node)
			,_ht(ht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		self& operator++()
		{
			if (_node->_next != nullptr)
			{
				_node = _node->_next;
			}
			else
			{
				// 找下一个不为空的桶
				KeyOfT kot;
				Hash hash;
				size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size(); // 当前桶的位置
				++hashi; // 下一个桶
				while (hashi < _ht->_tables.size())
				{
					if (_ht->_tables[hashi])
					{
						_node = _ht->_tables[hashi];
						break;
					}
					else
					{
						++hashi;
					}
				}
				// 没有找到返回空
				if (hashi == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}

	};

	template <class K, class T, class KeyOfT, class Hash = HashFun<K>>
	class HashTable
	{
		// 友元
		template <class K, class T, class KeyOfT, class Hash>
		friend struct __HashIterator;

		typedef HashNode<T> Node;
	public:
		typedef __HashIterator<K, T, KeyOfT, Hash>iterator;

		iterator begin()
		{
			Node* cur = nullptr;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				cur = _tables[i];
				if (cur)
				{
					break;
				}
			}
			return iterator(cur, this);

		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		bool Insert(const T& data)
		{
			KeyOfT kot;

			if (Find(kot(data)))
				return false;

			Hash hash;
			if (_n == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtables(newsize, nullptr);
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash(kot(cur->_data)) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
				}
				_tables.swap(newtables);
			}

			size_t hashi = hash(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			if (_tables.size() == 0) return nullptr;

			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

		size_t MaxSize()
		{
			size_t max = 0;

			for (size_t i = 0; i < _tables.size(); ++i)
			{
				size_t count = 0;
				Node* cur = _tables[i];
				while (cur)
				{
					++count;
					cur = cur->_next;
				}
				//printf("[%d]->%d\n", i, count);
				max = max > count ? max : count;
			}
			return max;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0; // 存储的有效数据的个数
	};

	//void HashTable_test1()
	//{
	//	int a[] = { 3,33,2,13,5,12,1002 };
	//	HashTable<int, int> hash;
	//	for (auto e : a)
	//	{
	//		hash.Insert(make_pair(e, e));
	//	}
	//	hash.Insert(make_pair(15, 15));
	//	hash.Insert(make_pair(25, 25));
	//	hash.Insert(make_pair(35, 35));
	//	hash.Insert(make_pair(45, 45));

	//	if (hash.Find(45))
	//		cout << "存在" << endl;
	//	else
	//		cout << "不存在" << endl;

	//	hash.Erase(15);

	//	if (hash.Find(15))
	//		cout << "存在" << endl;
	//	else
	//		cout << "不存在" << endl;
	//}

	//struct toStr
	//{
	//	size_t operator()(const string& s)
	//	{
	//		size_t hash = 0;
	//		for (auto ch : s)
	//		{
	//			hash += ch;
	//			hash *= 31;
	//		}
	//		return hash;
	//		//return s[0];
	//	}
	//};

	//void HashTable_test2()
	//{
	//	int a[] = { 3,33,2,13,5,12,1002 };

	//	HashTable<string, string> hash;
	//	hash.Insert(make_pair("sort", "排序"));
	//	hash.Insert(make_pair("queue", "队列"));
	//	hash.Insert(make_pair("list", "链表"));
	//	hash.Insert(make_pair("stack", "栈"));
	//	hash.Insert(make_pair("", "栈"));
	//}

	//void HashTable_test3()
	//{
	//	srand(time(0));
	//	HashTable<int, int> hash;
	//	size_t N = 1000000;
	//	for (size_t i = 0; i < N; ++i)
	//	{
	//		size_t a = rand() + i;
	//		hash.Insert(make_pair(a, a));
	//	}

	//	cout << hash.MaxSize() << endl;
	//}

}