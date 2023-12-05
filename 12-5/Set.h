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
		typedef typename RBTree<K, K, SetOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetOfT>::const_iterator const_iterator;

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

		pair<iterator, bool> insert(const K& key)
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
		int i = 1;
		while (it != s.end())
		{
			cout << *it << " ";
			//*it = 2; /* err ²»ÔÊĞí */
			++it;
			//--it;
		}
		cout << endl;
	}
}