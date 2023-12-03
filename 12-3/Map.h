#pragma once
#include "RBTree.h"

namespace yzl
{
	template <class K, class V>
	class map
	{
		struct MapOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<const K, V>, MapOfT> _t;
	};

	void map_test1()
	{
		map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(2, 1));
		m.insert(make_pair(3, 1));
	}
}