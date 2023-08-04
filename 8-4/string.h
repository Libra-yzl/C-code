#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace jwf
{
	class string
	{
	public:
		friend ostream& operator<<(ostream& out, string& str);

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

		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}

		/*string()
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{}*/
		string(const char* str = "")
			:_size(strlen(str))
		{
			//_capacity = _size == 0 ? 3 : _size;
			_capacity = _size + 1;
			_str = new char[_capacity];
			strcpy(_str, str);
		}

		string(const string& str = "")
			:_size(str._size)
			,_capacity(str._capacity)
		{
			_str = new char[_capacity];
			strcpy(_str, str._str);
		}

		size_t size()const
		{
			return _size;
		}

		string& operator=(const string& str)
		{
			if (*this != str)
			{
				char* tmp = new char[str._capacity];
				strcpy(tmp, str._str);
				delete[] _str;
				_size = str._size;
				_capacity = str._capacity;
				_str = tmp;
				
				////这种情况上来直接释放被赋值对象的原空间 如果new失败会抛异常 但也意味着被赋值对象被破坏
				//_capacity = str._capacity;
				//_size = str._size;
				//delete[] _str;
				//_str = new char[_capacity];
				//strcpy(_str, str._str);
			}
			return *this;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		bool operator==(const string& str) const
		{
			return strcmp(_str, str._str) == 0;
		}

		bool operator!=(const string& str) const
		{
			return !(*this == str);
		}

		bool operator<(const string& str) const 
		{
			return strcmp(_str, str._str) < 0;
		}

		bool operator<=(const string& str) const
		{
			return (*this == str) || (*this < str);
		}

		bool operator>(const string& str)const
		{
			return !(*this <= str);
		}

		bool operator>=(const string& str)const
		{
			return (*this == str) || (*this > str);
		}

		void resize(size_t capacity, char ch = '\0')
		{
			char* tmp = new char[capacity + 1] {ch};
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = _capacity + capacity + 1;

		}

		void reserve(size_t capacity)
		{
			char* tmp = new char[capacity+1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = capacity+1;
		}

		string& push_back(char ch)
		{
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}

		string& append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len >= _capacity)
				reserve(len + _size);
			strcpy(_str + _size, str);
			_size += len;
			return *this;
		}

		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}

		const char* c_str()const
		{
			return _str;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

}

ostream& jwf::operator<<(ostream& out, string& str)
{
	out << str._str;
	return out;
}
