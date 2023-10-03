#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
using namespace std;

namespace yzl
{
	template <class T>
	struct less
	{
		bool operator()(const T& x, const T& y) { return x < y; }
	};

	template <class T>
	struct less1
	{
		bool operator()(const T& x, const T& y) { return *x < *y; }
	};

	template <class T>
	struct greater
	{
		bool operator()(const T& x, const T& y) { return x > y; }
	};

	template <class T>
	struct greater1
	{
		bool operator()(const T& x, const T& y) { return *x > *y; }
	};

	template <class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:

		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] <_con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}

		void push(const T& val = T())
		{
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}

		void adjust_down(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1])) ++child;
				//if (_con[child] > _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		T& top()
		{
			assert(!empty());

			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size() { return _con.size(); }

	private:
		Container _con;
	};

	void priority_queue_test1()
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		/*pq.push(27);
		pq.push(18);
		pq.push(13);
		pq.push(23);
		pq.push(25);
		pq.push(16);
		pq.push(29);
		
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}*/

		vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
		for (auto& e : v) pq.push(e);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
	}

	class Date
	{
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}
		bool operator<(const Date& d)const
		{
			return (_year < d._year) ||
				(_year == d._year && _month < d._month) ||
				(_year == d._year && _month == d._month && _day < d._day);
		}
		bool operator>(const Date& d)const
		{
			return (_year > d._year) ||
				(_year == d._year && _month > d._month) ||
				(_year == d._year && _month == d._month && _day > d._day);
		}
		friend ostream& operator<<(ostream& _cout, const Date& d)
		{
			_cout << d._year << "-" << d._month << "-" << d._day;
			return _cout;
		}
	private:
		int _year;
		int _month;
		int _day;
	};

	void priority_queue_test2()
	{
		// 大堆，需要用户在自定义类型中提供<的重载
		priority_queue<Date> q1;
		q1.push(Date(2018, 10, 29));
		q1.push(Date(2018, 10, 28));
		q1.push(Date(2018, 10, 30));
		cout << q1.top() << endl;
		// 如果要创建小堆，需要用户提供>的重载
		priority_queue<Date, vector<Date>, greater<Date>> q2;
		q2.push(Date(2018, 10, 29));
		q2.push(Date(2018, 10, 28));
		q2.push(Date(2018, 10, 30));
		cout << q2.top() << endl;
		
		priority_queue<Date*, vector<Date*>, less1<Date*>> q3;
		q3.push(new Date(2018, 10, 29));
		q3.push(new Date(2018, 10, 28));
		q3.push(new Date(2018, 10, 30));
		cout << *(q3.top()) << endl;
	}

	struct set
	{
		set(int val = int(), int count = int())
			:_val(val)
			, _count(count)
		{}
		int _count;
		int _val;
	};

	class MinStack {
	public:
		MinStack() {}

		void push(int val) {
			if (st2.empty() || val <= st2.top()) st2.push(val);
			st1.push(val);
		}

		// void push(int val){
		//     if (st2.empty()) st2.push(val);
		//     else if (st2.top() < val) st2.push();
		// }

		void pop() {
			if (st1.top() == st2.top()) st2.pop();
			st1.pop();
		}

		int top() {
			return st1.top();
		}

		int getMin() {
			return st2.top();
		}

	private:
		stack<int> st1;
		stack<int> st2;
	};
}