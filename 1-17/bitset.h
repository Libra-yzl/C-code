#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <size_t N>
class bitset
{
public:
	bitset()
	{
		_bits.resize(N / 8 + 1, 0);
	}

	void set(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] |= (1 << j);
	}

	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] &= ~(1 << j);
	}

	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		return _bits[i] & (1 << j);
	}

private:
	vector<char> _bits;
};

void test_bits1()
{
	bitset<100> bs;
	bs.set(10);
	bs.set(11);
	bs.set(12);
	bs.set(15);
	cout << bs.test(10) << endl;
	cout << bs.test(12) << endl;

	cout << "------------" << endl;
	bs.reset(10);
	cout << bs.test(10) << endl;
	cout << bs.test(12) << endl;

	cout << "------------" << endl;
	bs.reset(10);
	bs.reset(12);
	cout << bs.test(10) << endl;
	cout << bs.test(12) << endl;
}

void test_bits2()
{
	bitset<-1> bs1;
	bitset<0xFFFFFFFF> bs2;
}

template <size_t N>
class bitsets
{
public:
	void set(size_t x)
	{
		if (bs1.test(x) == false &&
			bs2.test(x) == false)
		{
			bs2.set(x);
		}
		else if (bs1.test(x) == false &&
			bs2.test(x) == true)
		{
			bs1.set(x);
			bs2.reset(x);
		}

	}

	void print()
	{
		for (int i = 0; i < N; ++i)
		{
			if (bs2.test(i))
			{
				cout << i << endl;
			}
		}
	}
public:
	bitset<N> bs1;
	bitset<N> bs2;
};

void test_bitsets()
{
	int a[] = { 10,10,25,25,1,0,2,5,5,5,2,4,5,5,4,58,85,85,58 };
	bitsets<100> bss;
	for (auto e : a)
	{
		bss.set(e);
	}
	bss.print();
}

template <size_t N>
class bitsetss
{
public:
	void set(size_t x)
	{
		if (bs1.test(x) == false &&
			bs2.test(x) == false)
		{
			bs2.set(x);
		}
		else if (bs1.test(x) == false &&
			bs2.test(x) == true)
		{
			bs1.set(x);
			bs2.reset(x);
		}
		else if (bs1.test(x) == true &&
			bs2.test(x) == false)
		{
			bs1.set(x);
			bs2.set(x);
		}
	}

	void print()
	{
		for (int i = 0; i < N; ++i)
		{
			if ((bs2.test(i) && (!bs1.test(i))) || ((!bs2.test(i)) && bs1.test(i)))
			{
				cout << i << endl;
			}
		}
	}
public:
	bitset<N> bs1;
	bitset<N> bs2;
};

void test_bitsetss()
{
	int a[] = { 10,10,25,25,1,0,2,5,5,5,2,4,5,5,4,58,85,85,58 };
	bitsetss<100> bss;
	for (auto e : a)
	{
		bss.set(e);
	}
	bss.print();
}