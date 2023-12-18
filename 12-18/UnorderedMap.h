#pragma once

#include "Hash.h"

namespace yzl
{
	template <class K, class V>
	class unordered_map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename OpenHash::HashTable<K, pair<const K, V>, MapKeyOfT>::iterator iterator;

	public:

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

	private:
		OpenHash::HashTable<K, pair<const K, V>, MapKeyOfT> _ht;
	};

	void unordermap_test1()
	{
		unordered_map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(2, 1));
		m.insert(make_pair(3, 1));

		unordered_map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << " : " << it->second << endl;
			++it;
		}
		cout << endl;
	}
}