#pragma once

//#include <iostream>
//using namespace std;
//#include <assert.h>
//
//namespace jwf
//{
//	template <class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//		typedef const T* const_iterator;
//
//		vector()
//			:_start(nullptr)
//			, _finish(nullptr)
//			, _end_of_storage(nullptr)
//		{}
//
//		iterator begin() { return _start; }
//		iterator end() { return _finish; }
//
//		const_iterator begin() const { return _start; }
//		const_iterator end() const { return _finish; }
//
//		void resize(size_t n, T val = T())
//		{
//			if (n < size()) _finish = _start + n;
//			else {
//				if (n > capacity()) reserve(n);
//
//				while (_finish != _start + n) {
//					*_finish = val;
//					++_finish;
//				}
//			}
//		}
//
//		void reserve(size_t n) {
//			if (n > capacity()) {
//				//避免缩容
//
//				size_t sz = size(); //提前保存_finish-_start
//				T* tmp = new T[n]; //这里不需要'\0' 不是string
//				if (_start) {
//					memcpy(tmp, _start, sizeof(T) * size());
//					delete[] _start;
//				}
//				_start = tmp;
//				//_finish = _start + size(); 
//				// //这里如果加size()的话 _start已经更新 所以_finish相当于没变化 _finish-_start
//				_finish = _start + sz;
//				_end_of_storage = _start + n;
//			}
//		}
//
//		void push_back(const T& val)
//		{
//			if (_finish == _end_of_storage) {
//				//扩容
//				reserve(capacity() == 0 ? 4 : capacity() * 2);
//			}
//			*_finish = val;
//			++_finish;
//		}
//
//		void pop_back()
//		{
//			//assert(!empty());
//			assert(_start < _finish); //注意 _finish是开区间
//
//			--_finish;
//		}
//
//		T& operator[](size_t pos)
//		{
//			assert(pos < size());
//			return _start[pos];
//		}
//
//		const T& operator[](size_t pos) const
//		{
//			assert(pos < size());
//			return _start[pos];
//		}
//
//		size_t size() const
//		{
//			return _finish - _start;
//		}
//
//		size_t capacity() const
//		{
//			return _end_of_storage - _start;
//		}
//
//		bool empty() { return _finish == _start; }
//
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _end_of_storage;
//	};
//
//	void Print(const vector<int>& v) {
//		for (auto e : v) cout << e << " ";
//		cout << endl;
//	}
//
//	void test_vector1()
//	{
//		vector<int> v1;
//		v1.push_back(1);
//		v1.push_back(2);
//		v1.push_back(3);
//		v1.push_back(4);
//		v1.push_back(5);
//		v1.push_back(6);
//
//		for (size_t i = 0; i < v1.size(); ++i) cout << v1[i] << " ";
//		cout << endl;
//
//		for (auto e : v1) cout << e << " ";
//		cout << endl;
//
//		//vector<int> v2;
//		//v2.push_back(1);
//		//v2.push_back(2);
//		//v2.push_back(3);
//		//v2.push_back(4);
//		//v2.push_back(5);
//		//Print(v2);
//
//		//v2.pop_back();
//		//v2.pop_back();
//		//v2.pop_back();
//		//v2.pop_back();
//		//v2.pop_back();
//		//Print(v2);
//	}
//
//	//void test_vector2()
//	//{
//	//	vector<int> v;
//	//	v.push_back(1);
//	//	v.push_back(2);
//	//	v.push_back(3);
//	//	v.push_back(4);
//	//	v.push_back(5);
//	//	cout << v.size() << endl;
//	//	cout << v.capacity() << endl;
//	//	for (auto e : v) cout << e << " ";
//	//	cout << endl;
//
//	//	v.resize(10);
//
//	//	cout << v.size() << endl;
//	//	cout << v.capacity() << endl;
//	//	for (auto e : v) cout << e << " ";
//	//	cout << endl;
//	//}
//}

#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
#include "Test1.h"

namespace jwf
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator;

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }

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
				*end = *(end - 1);
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

	void vector_test1()
	{
		//测试反向迭代器
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
		cout << "-----------------------" << endl;

		vector<int>::reverse_iterator rit = v.rbegin();
		while (rit != v.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}
}