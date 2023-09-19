#pragma once
#include <iostream>
#include <assert.h>
#include <iostream>
using namespace std;

namespace yzl
{
	class string
	{
	public:
		/*string()
			:_str(new char[1])
			,_size(0)
			,_capacity(0)
		{
			_str[0] = '\0';
		}*/

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str+_size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const 
		{
			return _str + _size;
		}

		string(const char* str="")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		size_t size() const 
		{
			return _size;
		}

		string(const string& s) 
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (&s != this)
			{
				_size = s._size;
				_capacity = s._capacity;
				char* tmp = new char[_capacity+1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s) const
		{
			return s < *this || s == *this;
		}

		bool operator>(const string& s) const
		{
			return !(s <= *this);
		}

		bool operator>=(const string& s) const
		{
			return !(s < *this);
		}

		bool operator!=(const string& s) const
		{
			return !(s == *this);
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		char& operator[](size_t pos) 
		{
			assert(pos < _size);
			return _str[pos];
		}

		void resize(size_t n, char ch = '\0')
		{
			char* tmp = new char[n + 1] {ch};
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		void reserve(size_t n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		void push_back(const char ch)
		{
			if (_size+1 > _capacity) reserve(_capacity == 0 ? 4 : _capacity * 2);
			_str[_size] = ch;
			_str[++_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size+len >= _capacity) reserve(_capacity == 0 ? len : _capacity + len);
			//strcpy拷贝会将'\0'也拷贝进去
			strcpy(_str + _size, str);
			_size += len;
		}

		void insert(size_t pos, char ch='\0')
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity) reserve(_capacity == 0 ? 4 : _capacity * 2);
			
			memmove(_str + pos + 1, _str + pos, _size - pos + 1);
			_str[pos] = ch;
			++_size;
		}

		void insert(size_t pos = npos, const char* str = " ")
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity) reserve(_capacity == 0 ? len : _capacity + len);

			memmove(_str + pos + len, _str + pos, _size - pos + 1);
			memcpy(_str + pos, str, len);
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos >= 0 && pos <= _size);
			if (len >= _size - pos) len = _size - pos;
			memmove(_str + pos, _str + pos + len, _size - pos - len + 1);
		}

		const char* c_str() {
			return _str;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		//static const size_t npos = -1;
		static const size_t npos;
	};
	const size_t string::npos = -1;

	void Print(const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i) cout << s[i] << " ";
		cout << endl;

		for (auto ch : s) cout << ch << " ";
		cout << endl;
	}

	void string_test1()
	{
		string s1;
		string s2("hello world");
		string s3("hello string");

		cout << s2[0] << s2[1] << s2[2] << s2[3] << endl;

		s2 = s3;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		Print(s3);

		for (auto ch : s3) cout << ch << " ";
		cout << endl;
		string::iterator it = s3.begin();
		//cout << "start" << endl;
		while (it != s3.end())
		{
			(*it)++;
			++it;
		}

		it = s3.begin();
		cout << "start" << endl;
		while (it != s3.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void string_test2()
	{
		string s1;
		cout << s1.c_str() << endl;

		s1.push_back('a');
		s1.push_back('b');
		s1.push_back('c');
		s1.push_back('d');
		s1.push_back('e');

		cout << s1.c_str() << endl;

		string s2;
		s2.append("hello string");
		cout << s2.c_str() << endl;
		s2.append(" hello bit");
		cout << s2.c_str() << endl;

		s1.insert(0, '1');
		s1.insert(0, '1');
		s1.insert(0, '1');
		s1.insert(0, '1');
		s1.insert(0, '1');
		s1.insert(0, '1');
		cout << s1.c_str() << endl;

		string s3;
		s3.insert(0, 'a');
		s3.insert(0, 'b');
		s3.insert(0, 'c');
		s3.insert(0, 'd');
		s3.insert(0, 'e');
		s3.insert(0, 'f');
		s3.insert(3, 'x');
		s3.insert(7, 'y');
		cout << s3.c_str() << endl;

		string s4;
		s4.insert(0, "i am append");
		cout << s4.c_str() << endl;
		s4.insert(0, "continue i am append ");
		cout << s4.c_str() << endl;
		s4.insert(strlen(s4.c_str()), "xxxxxxxxxxxxxxxxxxxxxx");
		cout << s4.c_str() << endl;
	}

	void string_test3()
	{
		std::string s1("hello world");
		//std::string s1;
		//cout << s1 << endl;
		cout << s1.c_str() << endl;
		
		//测试尾部
		s1.erase(10,111);
		
		//测试头部
		//s1.erase(0, 155500);
		//cout << s1 << endl;
		cout << s1.c_str() << endl;
	}
}