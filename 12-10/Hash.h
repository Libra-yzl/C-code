#pragma once

#include <iostream>
#include <map>
#include <vector>


using namespace std;

namespace CloseHash
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

		/*HashData(const pair<K, V>& kv)
			:_kv(kv)
			,_state(EMPTY)
		{}*/
	};

	template <class K, class V>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;
			/* 载荷因子 / 散列表长度 -- 反馈哈希表存储数据量的百分比
			   α越大 表示存储的数量越多 冲突的可能性越大 反之亦然
			*/
			// 负载因子超过0.7就扩容
			/* if (_n / _tables.size() > 0.7) // 这是错误的 整型的计算还是整型 */
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t len = _tables.size() == 0 ? 10 : _tables.size() * 2;
				/*
				_tables.resize(len == 0 ? 10 : len * 2); // 这里需要扩size 而不是capacity 所以不使用reserve
				// 注意扩容之后每个元素的映射关系可能会发生变化 所以需要开辟新空间 在新空间中重新计算存储
				// 所以使用在原表上 resize 不可行
				*/

				//vector<HashData<K, V>> _newtable(len);
				//// 遍历旧表 重新映射到新表
				//for (auto& data : _tables)
				//{
				//	if (data._state == EXIST)
				//	{
				//		// 重新计算在表中的位置

				//	}
				//}
				//_tables.swap(newtable);

				HashTable<K, V> newht;
				newht._tables.resize(len);
				for (auto& data : _tables)
				{
					newht.Insert(data._kv);
				}
				_tables.swap(newht._tables);
			}

			/* 这里 %_tables.size() 很关键 %_capacity() 会报错 因为vector中会对[]做越界检查 */
			size_t hashi = kv.first % _tables.size(); // 除留余数法
			// size为0呢 vector满了呢
			
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state == EXIST) // 如果存在就找下一个位置（线性探测）
			{
				index = hashi + i;
				index %= _tables.size(); // 如果超出size 就从头开始
				++i;
			}
			_tables[index]._kv = kv;
			_tables[index]._state = EXIST;
			_n++;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0) return nullptr;

			size_t hashi = key % _tables.size();
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXIST && _tables[index]._kv.first == key)
				{
					return &_tables[index];
				}

				index = hashi + i;
				index %= _tables.size();
				++i;

				// 如果走完一轮 就结束
				if (index == hashi) break;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE; // 标记删除
				--_n;
				return true;
			}
			return false;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; // 有效数据的个数
		/*HashData* _tables;
		size_t _size;
		size_t _capacity;*/
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

namespace OpenHash
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

		bool Insert(const pair<K, V>& kv)
		{
			// 负载因子==1时扩容
			if (_n == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtable(newsize, nullptr);
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = cur->_kv.first % newtable.size();
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

	private:
		vector<Node*> _tables;
		size_t _n = 0; // 存储的有效数据
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