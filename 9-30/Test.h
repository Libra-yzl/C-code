#pragma once
#include <iostream>
using namespace std;
#include <assert.h>
#include <vector>


namespace yzl
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin() { return _start; }
		iterator end() { return _finish; }

		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); ++i) _start[i] = v._start[i];
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		size_t capacity() const { return _end_of_storage - _start; }

		size_t size() const { return _finish - _start; }

		vector<T>& operator=(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); ++i) _start[i] = v._start[i];
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
			return *this;
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size()) _finish = _start + n;
			else
			{
				if (n > capacity()) reserve(n);
				while (_finish != _end_of_storage)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t len = size();
				for (size_t i = 0; i < size(); ++i) tmp[i] = _start[i];
				delete[] _start;
				_start = tmp;
				_finish = _start + len;
				_end_of_storage = _start + n;
			}
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		// Î²²å
		void push_back(const T& val)
		{
			if (_finish == _end_of_storage) reserve(capacity() == 0 ? 4 : capacity() * 2); 
			*_finish = val;
			++_finish;
		}

		void pop_back()
		{
			assert(size());
			--_finish;
		}

	private:
		T* _start;
		T* _finish;
		T* _end_of_storage;
	};

	void print(const vector<int>& v)
	{
		for (auto e : v) cout << e << " ";
		cout << endl;
	}

	void vector_test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		for (auto e : v) cout << e << " ";
		cout << endl;

		vector<int> v1(v);
		print(v1);
		
		cout << "v: " << v.size() << " " << v.capacity() << endl;
		v.resize(3, 0);
		cout << "v: " << v.size() << " " << v.capacity() << endl;
		print(v);

	}

	void vector_test2()
	{
		vector<vector<int>> vv;
		vv.resize(5, vector<int>());
		for (size_t i = 0; i < vv.size(); ++i) {
			vv[i].resize(i + 1, 0);
			vv[i][0] = vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i) {
			for (size_t j = 0; j < vv[i].size(); ++j) {
				vv[i][j] = vv[i][j] == 0 ? vv[i - 1][j] + vv[i - 1][j - 1] : 1;
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		//vector<vector<int>> vv2(vv);
		vector<vector<int>> vv2;
		vv2 = vv;
		for (size_t i = 0; i < vv2.size(); ++i) {
			for (size_t j = 0; j < vv2[i].size(); ++j) {
				cout << vv2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		/*std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::vector<int> v1;
		v1.push_back(10);
		v1.push_back(20);
		v1.push_back(30);
		v1.push_back(40);
		v1.push_back(50);
		for (auto e : v) cout << e << " ";
		cout << endl;
		for (auto e : v1) cout << e << " ";
		cout << endl;
		v = v1;
		for (auto e : v) cout << e << " ";
		cout << endl;
		for (auto e : v1) cout << e << " ";
		cout << endl;*/
	}
}