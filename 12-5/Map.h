#pragma once
#include "RBTree.h"
#include <string>

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
		typedef typename RBTree<K, pair<const K, V>, MapOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		const_iterator begin() const
		{
			return _t.begin();
		}

		const_iterator end() const
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
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

	void map_test2()
	{
		map<std::string, int> m;
		std::string str[] = {"香蕉","香蕉","梨","苹果","橘子","苹果","葡萄"};
		for (auto e : str)
		{
			m.insert(make_pair(e, 1));
		}

		for (auto e : m)
		{
			cout << e.first << ":" << e.second << endl;
		}
	}

	void map_test3()
	{
		map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("count", "计数"));
		dict.insert(make_pair("string", "字符串"));
		dict.insert(make_pair("string", "（字符串）"));

		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			//it->first = "1111";
			it->second = "1111";

			++it;
		}
		cout << endl;

		for (auto& kv : dict)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}

	void map_test4()
	{
		std::string str[] = { "香蕉","香蕉","梨","苹果","橘子","苹果","葡萄" };
		map<string, int> countMap;
		for (auto& e : str)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}