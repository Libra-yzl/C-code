#pragma once
#include "RBTree.h"

namespace yzl
{
	template <class K>
	class set
	{
		struct SetOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetOfT> _t;
	};

	void set_test1()
	{
		set<int> s;
		s.insert(1);
		s.insert(2);
		s.insert(3);
		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			//++it;
			break;
		}
		cout << endl;
	}
}