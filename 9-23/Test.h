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
			if (n <= _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				size_t i = _size;
				while (i < n)
				{
					_str[i] = ch; 
					++i;
				}
				_size += n;
				_str[i] = '\0';
			}
		}

		void reserve(size_t n)
		{
			if (n > _capacity) {
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
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

		string& insert(size_t pos, char ch='\0')
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity) reserve(_capacity == 0 ? 4 : _capacity * 2);
			
			memmove(_str + pos + 1, _str + pos, _size - pos + 1);
			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str = "")
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity) reserve(_capacity == 0 ? len : _capacity + len);

			memmove(_str + pos + len, _str + pos, _size - pos + 1);
			memcpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos >= 0 && pos <= _size);
			if (len >= _size - pos) len = _size - pos;
			memmove(_str + pos, _str + pos + len, _size - pos - len + 1);

			return *this;
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

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(char ch, size_t pos=0)
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch) return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);

			char* p = strstr(_str+pos, str);
			if (p == nullptr) return npos;
			return p - _str;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* s)
		{
			append(s);
			return *this;
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
		//static const size_t npos = -1;
		static const size_t npos;
	};
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s) {
		for (auto ch : s) out << ch;
		return out;
	}

	istream& operator>>(istream& in, string& s) {
		//输入之前清空
		s.clear();

		char ch = in.get();
		char buff[128] = { 0 };
		size_t i = 0;
		while (ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127) {
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0) {
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

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
		string s1("hello world");
		//std::string s1;
		//cout << s1 << endl;
		cout << s1.c_str() << endl;
		
		//测试尾部
		s1.erase(5,111);
		cout << s1.c_str() << endl;

		s1.erase(0);
		//测试头部
		//s1.erase(0, 155500);
		//cout << s1 << endl;
		cout << s1.c_str() << endl;
	}

	void string_test4()
	{
		string s1("11111111111111111");
		s1.insert(0, 'x');
		cout << s1.c_str() << endl;

		s1.insert(3, 'x');
		cout << s1.c_str() << endl;

		s1.insert(3, "yyy");
		cout << s1.c_str() << endl;

		s1.insert(0, "yyy");
		cout << s1.c_str() << endl;

		s1 += '2';
		cout << s1 << endl;

		cin >> s1;
		cout << s1 << endl;
	}

	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		iterator begin() { return _start; }
		iterator end() { return _finish; }

		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }

		void resize(size_t n, T val = T())
		{
			if (n < size()) _finish = _start + n;
			else {
				if (n > capacity()) reserve(n);

				while (_finish != _start + n) {
					*_finish = val;
					++_finish;
				}
			}
		}

		void reserve(size_t n) {
			if (n > capacity()) {
				//避免缩容

				size_t sz = size(); //提前保存_finish-_start
				T* tmp = new T[n]; //这里不需要'\0' 不是string
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				//_finish = _start + size(); 
				// //这里如果加size()的话 _start已经更新 所以_finish相当于没变化 _finish-_start
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& val)
		{
			if (_finish == _end_of_storage) reserve(capacity() == 0 ? 4 : capacity() * 2); // 扩容
			*_finish = val;
			++_finish;
		}

		void pop_back()
		{
			//assert(!empty());
			assert(_start < _finish); //注意 _finish是开区间

			--_finish;
		}

		void insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage) {
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
		}

		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator start = pos + 1;
			while (start < _finish) {
				*(start - 1) = *start;
				++start;
			}
			--_finish;
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

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty() { return _finish == _start; }

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void Print(const vector<int>& v) {
		for (auto e : v) cout << e << " ";
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);

		for (size_t i = 0; i < v1.size(); ++i) cout << v1[i] << " ";
		cout << endl;

		for (auto e : v1) cout << e << " ";
		cout << endl;

		vector<int> v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		Print(v2);

		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		Print(v2);
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		for (auto e : v) cout << e << " ";
		cout << endl;

		v.resize(100);

		cout << v.size() << endl;
		cout << v.capacity() << endl;
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
		//v.push_back(5);
		Print(v);

		v.insert(v.begin(), 0);
		Print(v);

		vector<int>::iterator pos = find(v.begin(), v.end(), 0);
		if (pos != v.end()) v.erase(pos);
		Print(v);
	}
}