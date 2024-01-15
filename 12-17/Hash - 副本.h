#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <time.h>

using namespace std;

namespace yzl
{
	template <class K, class T>
	struct HashNode
	{
		HashNode<K, T>* _next;
		pair<K, T> _kv;

		HashNode(const pair<K, T> kv)
			:_next(nullptr)
			, _kv(kv)
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

	template <class K, class T, class Hash = HashFun<K>>
	class HashTable
	{
		typedef HashNode<K, T> Node;
	public:
		bool Insert(const pair<K, T> kv)
		{
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
						size_t hashi = hash(cur->_kv.first) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
				}
				_tables.swap(newtables);
			}

			size_t hashi = hash(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			Hash hash;
			if (_tables.size() == 0) return nullptr;

			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (hash(cur->_kv.first) == hash(key))
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (hash(cur->_kv.first) == hash(key))
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

	void HashTable_test1()
	{
		int a[] = { 3,33,2,13,5,12,1002 };
		HashTable<int, int> hash;
		for (auto e : a)
		{
			hash.Insert(make_pair(e, e));
		}
		hash.Insert(make_pair(15, 15));
		hash.Insert(make_pair(25, 25));
		hash.Insert(make_pair(35, 35));
		hash.Insert(make_pair(45, 45));

		if (hash.Find(45))
			cout << "存在" << endl;
		else
			cout << "不存在" << endl;

		hash.Erase(15);

		if (hash.Find(15))
			cout << "存在" << endl;
		else
			cout << "不存在" << endl;
	}

	struct toStr
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto ch : s)
			{
				hash += ch;
				hash *= 31;
			}
			return hash;
			//return s[0];
		}
	};

	void HashTable_test2()
	{
		int a[] = { 3,33,2,13,5,12,1002 };

		HashTable<string, string> hash;
		hash.Insert(make_pair("sort", "排序"));
		hash.Insert(make_pair("queue", "队列"));
		hash.Insert(make_pair("list", "链表"));
		hash.Insert(make_pair("stack", "栈"));
		hash.Insert(make_pair("", "栈"));
	}

	void HashTable_test3()
	{
		srand(time(0));
		HashTable<int, int> hash;
		size_t N = 1000000;
		for (size_t i = 0; i < N; ++i)
		{
			size_t a = rand() + i;
			hash.Insert(make_pair(a, a));
		}

		cout << hash.MaxSize() << endl;
	}

}