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

		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}

		}

		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}

		}

		template <class Iterator>
		vector(Iterator first, Iterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		/*vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			memcpy(_start, v._start, sizeof(T) * v.size());
			_finish = _start + v.size();
		}*/

		/*vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}*/


		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); ++i)
			{
				//这里需要进行赋值运算符的重载 否则只是复制了内层数组的指针
				//并没有创建新的内存来存储实际元素的副本
				_start[i] = v._start[i];
			}

			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		vector& operator=(const vector<T>& v) {
			if (this != &v) {
				delete[] _start;

				_start = new T[v.capacity()];
				for (size_t i = 0; i < v.size(); ++i)
				{
					_start[i] = v._start[i];
				}
				_finish = _start + v.size();
				_end_of_storage = _start + v.capacity();
			}
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

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
					//memcpy(tmp, _start, sizeof(T) * size());
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
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

		iterator insert(iterator pos, const T& val)
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

			return pos;
		}

		iterator erase(iterator pos)
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

			return pos;
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

		//删除偶数
		v.insert(v.begin(), 10);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if ((*it) % 2 == 0)
				it = v.erase(it);
			else
				++it;
		}
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v1(10, 1);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2(10, 2);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v3(v2.begin(), v2.end());
		for (auto e : v3)
		{
			cout << e << " ";
		}
	}

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows, vector<int>());
			for (size_t i = 0; i < vv.size(); ++i)
			{
				vv[i].resize(i + 1, 0);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			return vv;
		}
	};

	//class Solution {
	//public:
	//	vector<vector<int>> generate(int numRows) {
	//		vector<vector<int>> vv;
	//		vv.reserve(numRows);

	//		for (size_t i = 0; i < numRows; ++i) {
	//			vector<int> row(i + 1, 0);
	//			row[0] = row[i] = 1;

	//			if (i >= 2) {
	//				for (size_t j = 1; j < row.size() - 1; ++j) {
	//					row[j] = vv[i - 1][j - 1] + vv[i - 1][j];
	//				}
	//			}

	//			vv.push_back(row);
	//		}

	//		return vv;
	//	}
	//};


	void test_vector4()
	{
		vector<std::string> v(5, "1111111");
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.insert(v.end(), "2222222222222222222");
		v.insert(v.end(), "5555555555555555555555555555555555555555555555555555555555");
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		/*vector<int> v1(10, 5);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2(v1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<std::string> v3(3, "111111111111111111111");
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<std::string> v4(v3);
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;

		v4.push_back("2222222222222222222");
		v4.push_back("2222222222222222222");
		v4.push_back("2222222222222222222");
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;*/

		vector<vector<int>> ret = Solution().generate(5);
		for (size_t i = 0; i < ret.size(); ++i)
		{
			for (size_t j = 0; j < ret[i].size(); ++j)
			{
				cout << ret[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}