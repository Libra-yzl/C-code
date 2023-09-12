#define _CRT_SECURE_NO_WARNINGS 0

#pragma once
#include <iostream>
using namespace std;
#include <assert.h>

namespace yzl
{
	class string
	{
	public:
		/*string()
			:_str(new char[1])
			,_size(0)
			,_capacity(0)
		{}*/

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin() { 
			return _str; 
		}

		iterator end() { 
			return _str + _size; 
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
		{
			size_t n = strlen(str);
			_capacity = _size;
			_str = new char[n + 1];
			strcpy(_str, str);
		}

		string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		void reserve(size_t n) {
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			_capacity = n + 1;
			delete[] _str;
			_str = tmp;
		}

		void push_back(const char x = '\0') {
			if (_size  >= _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = x;
			_str[++_size] = '\0';
		}

		void append(const char* s = " ")
		{
			size_t len = strlen(s);
			if (len + _size > _capacity) {
				reserve(_capacity == 0 ? (len + 1) : (len + _capacity));
			}
			strcpy(_str + _size, s);
			_size += len;
		}

		void insert(const char val = '\0', size_t pos = npos)
		{
			assert(pos <= _size);

			if (_size + 1 >= _capacity) reserve(_capacity == 0 ? 4 : 2 * _capacity);
			int end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = val;
			++_size;
		}

		void insert(const char* str = "", size_t pos = npos)
		{
			assert(pos <= _size);

			size_t len = strlen(str);

			if (_size + len >= _capacity) reserve(_capacity == 0 ? (len + 1) : (len + _capacity));
			int end = _size + len;
			while (end > pos)
			{
				_str[end] = _str[end - len];
				--end;
			}
			memcpy(_str + pos, str, strlen(str));
			_size += len;
		}

		char operator[](const size_t i)
		{
			return _str[i];
		}

		const char operator[](const size_t i) const
		{
			return _str[i];
		}

		size_t size() const
		{
			return _size;
		}

		string& operator=(const string& s)
		{
			if (&s != this)
			{
				char* tmp = new char[s._capacity + 1];
				_size = s._size;
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		bool operator<(const string& s) {
			return (strcmp(_str, s._str) < 0);
		}

		bool operator==(const string& s) {
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s) {
			return *this < s || *this == s;
		}

		bool operator>(const string& s) {
			return !(*this <= s);
		}

		bool operator>=(const string& s) {
			return !(*this < s);
		}

		bool operator!=(const string& s) {
			return !(*this == s);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() {
			return _str;
		}

		void Print(const string& s)
		{
			for (size_t i = 0; i < s.size(); ++i)
			{
				cout << s[i] << " ";
			}
			cout << endl;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		//static const size_t npos = -1;
		static const size_t npos;
	};
	const size_t string::npos = -1;

	void test_string1()
	{
		string s1;
		string s2("hello world");
		string s3(s2);

		cout << s2[2] << endl;

		s1 = s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		string s2("hi");

		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;

		string::iterator it = s1.begin();
		while (it != s1.end()) {
			(*it)++;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		string s2("hello c++");
		string s3("hello Linux");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		cout << (s1 < s2) << endl;
		cout << (s1 > s2) << endl;
		cout << (s1 != s2) << endl;
		cout << (s1 == s2) << endl;
	}
	
	void test_string4()
	{
		string s1;
		cout << s1.c_str() << endl;

		s1.push_back('a');
		cout << s1.c_str() << endl;

		s1.append("111111111111111111111111111111111");
		cout << s1.c_str() << endl;

		s1.push_back('a');
		cout << s1.c_str() << endl;

		string s2;
		cout << s2.c_str() << endl;

		s2.append("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		cout << s2.c_str() << endl;

		s2.push_back('1');
		cout << s2.c_str() << endl;
	}

	void test_string5()
	{
		string s1;
		cout << s1.c_str() << endl;
		s1.insert('a', 0);
		s1.insert('b', 0);
		s1.insert('c', 0);
		s1.insert('d', 0);
		s1.insert('e', 0);
		s1.insert('e', 0);
		s1.insert('e', 0);
		s1.insert('e', 0);
		s1.insert('e', 0);
		s1.insert('e', 0);
		s1.insert('1', 10);
		s1.insert('1', 11);
		s1.insert('1', 12);
		s1.insert('1', 13);
		cout << s1.c_str() << endl;
	}

	void test_string6()
	{
		string s1;
		s1.insert("1111111111111111111", 0);
		cout << s1.c_str() << endl;
		s1.insert("2222222", s1.size());
		cout << s1.c_str() << endl;
	}

}