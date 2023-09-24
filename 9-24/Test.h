#pragma once
#include <iostream>
using namespace std;
#include <assert.h>
#include <vector>
#include <string>

namespace yzl {
	template <class T>
	class vector {

	public:
		typedef const T* const_iterator;
		typedef T* iterator;

		iterator begin() { return _start; }
		iterator end() { return _finish; }

		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i) push_back(val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		/*vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto e : v) push_back(e);
		}*/

		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			//memcpy(_start, v._start, sizeof(T)*v.size());
			for (size_t i = 0; i < v.size(); ++i) _start[i] = v._start[i];
			_finish = _start + v.size();
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		
		size_t capacity() const {
			return _end_of_storage - _start;
		}

		size_t size() const {
			return _finish - _start;
		}
		
		T& operator[](size_t pos) {
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const {
			assert(pos < size());

			return _start[pos];
		}

		vector<T>& operator=(const vector<T>& v)
		{
			//_start = new T[v.capacity()];
			reserve(v.capacity());
			for (size_t i = 0; i < v.size(); ++i) _start[i] = v._start[i];
			_finish = _start + v.size();
			//_end_of_storage = _start + v.capacity();
			return *this;
		}

		void resize(size_t n, const T& val = T()) {
			//resize不缩容 缩小的情况下只会改变size()
			if (n < capacity()) _finish = _start + n;
			else {
				if (n > capacity()) reserve(n);

				while (_finish != _start + n) {
					*_finish = val;
					++_finish;
				}
			}
		}

		void reserve(size_t n) {
			//为防缩容 只在n > capacity()时扩容
			if (n > capacity()) {
				size_t len = _finish - _start;
				T* tmp = new T[n];
				//memcpy(tmp, _start, sizeof(T) * size());
				for (size_t i = 0; i < len; ++i) tmp[i] = _start[i];
				delete[] _start;
				_start = tmp;
				_finish = _start + len;
				//_finish = _start + size(); //err
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& val)
		{
			if (_finish == _end_of_storage) reserve(capacity() == 0 ? 4 : capacity() * 2);
			*_finish = val;
			++_finish;
		}

		void insert(iterator pos, const T& val = T()) {
			assert(pos <= _finish);
			assert(pos >= _start);

			if (empty()) reserve(capacity() == 0 ? 4 : capacity() * 2);
			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
		}

		void erase(iterator pos) {
			assert(pos < _finish);
			assert(pos >= _start);

			iterator start = pos + 1;
			while (start != _finish)
			{
				*(start - 1) = *start;
				++start;
			}
			--_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		bool empty() {
			return _finish == _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void vector_test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(5);
		cout << "capacity():" << v.capacity() << " size():" << v.size() << endl;
		for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;

		v.pop_back();
		cout << "capacity():" << v.capacity() << " size():" << v.size() << endl;
		for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;
		/*v.pop_back();
		cout << "capacity():" << v.capacity() << " size():" << v.size() << endl;
		for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;
		v.pop_back();
		cout << "capacity():" << v.capacity() << " size():" << v.size() << endl;
		for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;
		v.pop_back();
		cout << "capacity():" << v.capacity() << " size():" << v.size() << endl;
		for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;
		v.pop_back();
		cout << "capacity():" << v.capacity() << " size():" << v.size() << endl;
		for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;
		v.pop_back();
		cout << "capacity():" << v.capacity() << " size():" << v.size() << endl;
		for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;*/	
	}
	void vector_test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		cout << "v.size():" << v.size() << "   v.capacity():" << v.capacity() << endl;
		v.resize(10);
		cout << "v.size():" << v.size() << "  v.capacity():" << v.capacity() << endl;
		v.resize(5);
		cout << "v.size():" << v.size() << "   v.capacity():" << v.capacity() << endl;
	}

	void Print(const vector<int>& v)
	{
		/*for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;*/

		for (auto e : v) cout << e << " ";
		cout << endl;
	}

	void vector_test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (auto e : v) cout << e << " ";
		cout << endl;
		//Print(v);

		/*vector<int>::iterator pos = find(v.begin(), v.end(), 1);
		v.insert(pos, 0);
		Print(v);

		pos = find(v.begin(), v.end(), 5);
		v.insert(v.end(), 10);
		Print(v);*/

		//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
		//v.erase(pos);
		//Print(v);

		////pos = find(v.begin(), v.end(), 5);
		//v.erase(v.end());
		//Print(v);

		v.erase(v.end()-1);
		for (auto e : v) cout << e << " ";
		cout << endl;

		v.erase(v.begin());
		for (auto e : v) cout << e << " ";
		cout << endl;
	}

	void vector_test4()
	{
		vector<int> v(10u, 5);
		for (auto e : v) cout << e << " ";
		cout << endl;

		std::string s("hello world");
		vector<int> v1(++s.begin(), --s.end());
		for (auto e : v1) cout << e << " ";
		cout << endl;
	}

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows, vector<int>());
			for (size_t i = 0; i < vv.size(); ++i) {
				vv[i].resize(i + 1, 0);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i) {
				for (size_t j = 0; j < vv[i].size(); ++j) {
					vv[i][j] = vv[i][j] == 0 ? vv[i - 1][j] + vv[i - 1][j - 1] : 1;
				}
			}

			return vv;
		}
	};

	void vector_test5()
	{
		vector<vector<int>> ret = Solution().generate(10);
		for (size_t i = 0; i < ret.size(); ++i)
		{
			for (size_t j = 0; j < ret[i].size(); ++j) cout << ret[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	void vector_test6()
	{
		//vector<std::string> v(3, "1111111111");
		//for (auto e : v) cout << e << " ";
		//cout << endl;

		//v.push_back("111111111111");
		////v.push_back("111111111111");
		////v.push_back("111111111111");
		////v.push_back("111111111111");
		////v.push_back("111111111111");
		////v.push_back("111111111111");
		////v.push_back("111111111111");
		//for (auto e : v) cout << e << " ";
		//cout << endl;
		


		//vector<int> v(3);
		//for (auto e : v) cout << e << " ";
		//cout << endl;
		
		//vector<vector<int>> vv1;
		vector<vector<int>> vv;
		vv.resize(5, vector<int>());
		for (size_t i = 0; i < vv.size(); ++i) {
			vv[i].resize(i + 1, 0);
			vv[i][0] = vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i) {
			for (size_t j = 0; j < vv[i].size(); ++j) {
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		/*for (size_t i = 0; i < vv1.size(); ++i) {
			for (size_t j = 0; j < vv1[i].size(); ++j) cout << vv1[i][j] << " ";
			cout << endl;
		}
		cout << endl;*/
		
		vector<vector<int>> vv2(vv);
		for (size_t i = 0; i < vv2.size(); ++i) {
			for (size_t j = 0; j < vv2[i].size(); ++j) {
				cout << vv2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
 	}
}