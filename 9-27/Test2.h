#pragma once
#include <iostream>
using namespace std;
#include <list>

namespace yzl
{
	template <class T, class Container = list<T>>
	class queue
	{
	public:

		void push(const T& val) { _con.push_back(val); }
		void pop() { _con.pop_front(); }

		const T& front() { return _con.front(); }
		const T& back() { return _con.back(); }

		size_t size() { return _con.size(); }
		bool empty() { return _con.empty(); }

	private:
		Container _con;
	};

	void queue_test1()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}