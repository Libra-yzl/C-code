#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

namespace jwf
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				//删除数据
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _end_of_storage)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void reserve(size_t n)
		{
			//只需要判断扩容 如果n小于容量 不需要缩容
			if (n > capacity())
			{
				iterator tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				//扩容
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void insert(iterator pos, const T& val)
		{
			assert(pos <= _finish && pos >= _start);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			//插入
			iterator end = _finish;
			while (end != pos)
			{
				*end = *(end-1);
				--end;
			}
			*pos = val;
			++_finish;
		}

		void erase(iterator pos)
		{
			assert(!empty());
			assert(pos < _finish && pos >= _start);

			iterator end = pos + 1;
			while (end < _finish)
			{
				*(end - 1) = *end;
				++end;
			}
			--_finish;
		}

		void pop_back()
		{
			assert(!empty());

			--_finish;
		}

		bool empty() const
		{
			return _finish == _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void f(const vector<int>& v)
	{
		/*v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.pop_back();
		v.pop_back();
		v.pop_back();*/
		//v.pop_back();

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	//void test_vector2()
	//{
	//	int i = int();
	//	int j = int(1);
	//	//int* p = int*(nullptr);
	//}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.pop_back();
		v.pop_back();
		//v.pop_back();
		//v.pop_back();

		v.resize(10, 1);
		f(v);

		v.resize(1);
		f(v);
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = find(v.begin(), v.end(), 1);
		v.insert(pos, 30);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		//pos = find(v.begin(), v.end(), 10);
		v.erase(v.begin());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}