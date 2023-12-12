#pragma once

#include <iostream>
#include <map>
#include <vector>

using namespace std;
namespace closeHash
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template <class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template <class K, class V>
	class HashTable
	{
	public:
		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;
			size_t hashi = key % _tables.size();
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXIST && _tables[index]._kv.first == key)
					return &_tables[index];
				index = hashi + i;
				index %= _tables.size();
				++i;

				if (index == hashi)
					break;
			}
			return nullptr;
		}

		bool Insert(const pair<K, V> kv)
		{
			if (Find(kv.first)) return false;

			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t len = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newtables;
				newtables._tables.resize(len);
				for (auto& data : _tables)
				{
					newtables.Insert(data._kv);
				}
				_tables.swap(newtables._tables);
			}

			size_t hashi = kv.first % _tables.size();
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state == EXIST)
			{
				index = hashi + i;
				index %= _tables.size();
				++i;
			}
			_tables[index]._kv = kv;
			_tables[index]._state = EXIST;
			++_n;
			return true;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			return false;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; // 存储的有效数据个数
	};

	void hashtable_test1()
	{
		int a[] = { 3,33,2,13,5,12,1002 };
		HashTable<int, int> hash;
		for (auto e : a)
		{
			hash.Insert(make_pair(e, e));
		}
		hash.Insert(make_pair(15, 15));
		hash.Insert(make_pair(16, 16));

		if (hash.Find(15))
			cout << "存在" << endl;
		else
			cout << "不存在" << endl;

		hash.Erase(15);

		if (hash.Find(15))
			cout << "存在" << endl;
		else
			cout << "不存在" << endl;
	}
}

namespace openHash
{
	template <class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
			:_next(nullptr)
			,_kv(kv)
		{}
	};

	template <class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		~HashTable()
		{
			for (auto& cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				cur = nullptr;
			}
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;
			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
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

		bool Insert(const pair<K, V>& kv)
		{
			if (_n == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtable(newsize, nullptr);
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = cur->_kv.first % _tables.size();
						cur->_next = newtable[hashi];
						newtable[hashi] = cur;
						cur = next;
					}
				}
				_tables.swap(newtable);

			}
			size_t hashi = kv.first % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			return true;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;
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

		hash.Erase(13);

		if (hash.Find(15))
			cout << "存在" << endl;
		else
			cout << "不存在" << endl;
	}
}