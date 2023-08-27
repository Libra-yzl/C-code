#pragma once

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

namespace yzl
{
	template <class T>
	struct less
	{
		bool operator()(const T& v1, const T& v2)
		{
			return v1 < v2;
		}
	};

	template <class T>
	struct greater
	{
		bool operator()(const T& v1, const T& v2)
		{
			return v1 > v2;
		}
	};

	template <class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (Compare()(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}

		void adjust_down(size_t parent)
		{
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() &&  Compare()(_con[child], _con[child + 1]))
				{
					child++;
				}
				if (Compare()(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);				
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}

		void push(int x)
		{
			_con.push_back(x);
			adjust_up(_con.size()-1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		const T& top()
		{
			return _con.front();
		}

	private:
		Container _con;
	};
}