#pragma once

#include "Hash.h"

namespace yzl
{
	template <class K>
	class unordered_set
	{
	public:

		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		typedef typename OpenHash::HashTable<K, K, SetKeyOfT>::iterator iterator;

	public:
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		OpenHash::HashTable<K, K, SetKeyOfT> _ht;
	};

	void unorderset_test1()
	{
		int a[] = { 3,33,2,13,5,12,1002 };
		unordered_set<int> s;
		for (auto e : a)
		{
			s.insert(e);
		}
		s.insert(1);
		s.insert(2);
		s.insert(3);

		auto it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}