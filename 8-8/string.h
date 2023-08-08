#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

namespace yzl
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		iterator begin() const
		{
			return _str;
		}

		iterator end() const
		{
			return _str + _size;
		}

		/*string()
			:_str(new char[1])
			,_size(0)
			,_capacity(0)
		{
			_str[0] = '\0';
		}*/

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string(const string& s)
			:_size(s._size)
			,_capacity(s._capacity)
		{
			_str = new char[_capacity+1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (*this != s) 
			{
				char* tmp = new char[s._capacity+1];
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
				strcpy(_str, s._str);
			}
			return *this;
		}

		size_t size() const 
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
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

		const char* c_str()
		{
			return _str;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n > _capacity)
			{
				reserve(n);
				while (_size < n)
				{
					_str[_size] = ch;
					++_size;
				}
				_str[_size] = '\0';
			}
			else if (n < _capacity)
			{
				_size = n;
				_str[_size] = ch;
			}
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(_capacity == 0 ? 2 : _capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* s)
		{
			size_t len = strlen(s);
			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, s);
			_size += len;
		}

		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size + 1 > _capacity)
			{
				reserve(_capacity == 0 ? 2 : _capacity * 2);
			}
			//if (_size == 0)
			//{
			//	_str[_size] = ch;
			//	++_size;
			//	_str[_size] = '\0';
			//}
			//else
			//{
			//	/*size_t end = _size;
			//	while (end > pos)
			//	{
			//		_str[end + 1] = _str[end];
			//		--end;
			//	}
			//	_str[end + 1] = _str[end];
			//	_str[pos] = ch;
			//	++_size;*/
			//	size_t end = _size + 1;
			//	while (end > pos)
			//	{
			//		_str[end] = _str[end-1];
			//		--end;
			//	}
			//	_str[pos] = ch;
			//	++_size;
			//}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			//if (_size == 0)
			//{
			//	strcpy(_str, str);
			//}
			//else
			//{
			//	size_t end = _size + len;
			//	while (end != pos)
			//	{
			//		_str[end] = _str[end - len];
			//		end--;
			//	}
			//	//_str[end + len] = _str[end];
			//	strncpy(_str + pos, str, len);
			//	_size += len;
			//}
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				end--;
			}
			//_str[end + len] = _str[end];
			strncpy(_str + pos, str, len);
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len >= _size - pos)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				/*size_t tmp = pos;
				while (_str[tmp + len] != '\0')
				{
					_str[tmp] = _str[tmp + len];
					++tmp;
				}
				_str[tmp] = '\0';
				_size -= len;*/

				strcpy(_str + pos, _str + len + pos);
				_size -= len;
			}
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(char ch, size_t pos = 0) const 
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				const char* p = strstr(_str + i, str);
				if (p != nullptr)
					return p - _str;
			}
			return npos;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos = -1;
		//static const size_t npos;
	};

	//static const size_t npos = -1;

	void Print(const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			cout << s[i] << endl;
		}
		
		cout << endl;
		for (auto& ch : s)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test1()
	{
		string s1("hello world");
		Print(s1);
	}

	void test2()
	{
		string s1("hello bit");
		string s2("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto& ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;

		cout << (s1 > s2) << endl;
		cout << (s1 < s2) << endl;
		cout << (s1 == s2) << endl;
	}

	void test3()
	{
		string s1;
		string s2("hello world");

		/*s1.push_back('x');
		s2.push_back('x');
		cout << s2.c_str() << endl;
		s2.append("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");*/
		s1 += 'x';
		cout << s1.c_str() << endl;
		s1 += 'o';
		s2 += "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}

	void test4()
	{
		string s1;
		string s2("hello world");

		s1.insert(0, 'x');
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;

		s1.insert(0, "hello world");
		cout << s1.c_str() << endl;
		
		s2.insert(0, 'x');
		cout << s2.c_str() << endl;

		s2.insert(6, 'x');
		cout << s2.c_str() << endl;

		s2.insert(s2.size(), "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		cout << s2.c_str() << endl;
		cout << s2.size() << " " << s2.capacity() << endl;
	}

	void test5()
	{
		string s1("xxxxxxxxxxxxxx");
		string s2("yyyyyyy");

		s1.resize(30, 'a');
		s2.resize(5, 'x');

		cout << s1.capacity() << endl;
		cout << s2.capacity() << endl;

		/*cout << s1.size() << endl;
		cout << s1.c_str() << endl;

		s1.erase(1, 1);
		cout << s1.size() << endl;
		cout << s1.c_str() << endl;*/
	}

	void test_string1()
	{
		string s1("hello worldxxxxxxxxx");
		cout << s1.capacity() << endl;
		s1.reserve(10);
		cout << s1.capacity() << endl;
	}

	void test_string2()
	{
		/*std::string s1;
		s1.resize();*/
		string s1("0123456789");
		cout << s1.c_str() << endl;
		
		s1.erase(2, 3);
		cout << s1.c_str() << endl;

		s1.erase(4, 100);
		cout << s1.c_str() << endl;

		s1.erase(2);
		cout << s1.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		string s2("hello bit");

		s1.swap(s2);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}

	void test_string4()
	{
		string s1("abcdxxcdaaaxxxxxaaax");
		string s2("hello world");
		cout << s1.find("xx", 7) << endl;
		cout << s2.find('l', 20) << endl;
	}

	ostream& operator<<(ostream& out, string& s)
	{
		for (auto ch : s)
		{
			cout << ch;
		}
		return out;
	}

	/*istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}*/

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}

	void test_string5()
	{
		string s1("hello world");
		string s2("hello bit");

		//cout << s1 << endl << s2 << endl;

		cin >> s1;
		cout << s1 << endl;
		cin >> s2;
		cout << s2 << endl;
	}
}