#pragma once
#include <iostream>
using namespace std;

namespace yzl
{
	class string {
	public:
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
	
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}