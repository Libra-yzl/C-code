#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

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
		_bits[i] &= (~(1 << j));
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

void test_bitset1()
{
	bitset<100> bst;
	bst.set(10);
	bst.set(20);
	bst.set(30);
	bst.set(40);
	bst.set(50);
	cout << bst.test(10) << endl;
	cout << bst.test(20) << endl;
	cout << "---------------" << endl;

	bst.reset(10);
	cout << bst.test(10) << endl;
	cout << bst.test(20) << endl;
	cout << "---------------" << endl;

	bst.reset(10);
	bst.reset(20);
	cout << bst.test(10) << endl;
	cout << bst.test(20) << endl;
}

struct BKDRHash
{
	size_t operator()(const string& str)
	{
		register size_t hash = 0;
		for (auto ch : str)
		{
			hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313 ... 
			// 有人说将乘法分解为位运算及加减法可以提高效率，
			// 如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;  
		}
		return hash;
	}
};

struct SDBMHash
{
	size_t operator()(const string& str)
	{
		register size_t hash = 0;
		for (auto ch : str)
		{
			hash = 65599 * hash + ch;
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}
		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (long i = 0; i < str.size(); i++)
		{
			size_t ch = str[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

template <size_t N,
	class K = string,
	class Hash1 = BKDRHash,
	class Hash2 = SDBMHash,
	class Hash3 = APHash>
class bloomfilter
{
public:
	void set(const K& key)
	{
		size_t len = N * _H;
		size_t hash1 = Hash1()(key) % len;
		_bs.set(hash1);

		size_t hash2 = Hash2()(key) % len;
		_bs.set(hash2);

		size_t hash3 = Hash3()(key) % len;
		_bs.set(hash3);
	}

	bool test(const K& key)
	{
		size_t len = N * _H;
		size_t hash1 = Hash1()(key) % len;
		if (!_bs.test(hash1))
			return false;


		size_t hash2 = Hash2()(key) % len;
		if (!_bs.test(hash2))
			return false;

		size_t hash3 = Hash3()(key) % len;
		if (!_bs.test(hash3))
			return false;

		return true;
	}

private:
	static const size_t _H = 6;
	bitset<N * _H> _bs;
};

void test_bloomfilter1()
{
	bloomfilter<100> bf;
	bf.set("left");
	bf.set("bloom");
	bf.set("jintian nikaixinlema");
	bf.set("test");
	bf.set("etst");

	cout << bf.test("left") << endl;
	cout << bf.test("bloom") << endl;
	cout << bf.test("jintian nikaixinlema") << endl;
	cout << bf.test("etst") << endl;
	cout << bf.test("test") << endl;
	cout << bf.test("orst") << endl;
	cout << bf.test("tors") << endl;
}

// 测试判错率
void test_bloomfilter2()
{
	srand(time(nullptr));
	//const size_t N = 1000000; // release (_H=5) 相似字符串误判率:0.078057 不相似字符串误判率:0.049282
	//const size_t N = 100000; // release (_H=5) 相似字符串误判率:0.04917 不相似字符串误判率:0.05099
	//const size_t N = 1000000; // release (_H=6) 相似字符串误判率:0.05497 不相似字符串误判率:0.036255
	const size_t N = 100000; // release (_H=6) 相似字符串误判率:0.03099 不相似字符串误判率:0.03044


	bloomfilter<N> bf;

	std::vector<std::string> v1;
	std::string url = "https://www.baidu.com";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2跟v1是相似字符串集，但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.leetcode.com";
		url += std::to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "https://www.cctalk.com/m/statistics/live/16845432622875";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}