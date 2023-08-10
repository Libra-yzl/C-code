#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	v.reserve(100);
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
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
				if (vv[i][j] != 1)
				{
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				}
			}
		}
		return vv;
	}
};

void test_vector1()
{
	int numRows = 5;
	vector<vector<int>> vv;
	vv.resize(numRows, vector<int>());

	for (size_t i = 0; i < vv.size(); ++i) {
		vv[i].resize(i + 1, 0);
	}

	/*for (size_t i = 0; i < vv.size(); ++i) {
		vv.resize(i + 1, 0);
		vv[i][0] = vv[i][vv.size() - 1] = 1;
	}*/
}

void test_sol1()
{
	Solution sol;
	auto vv = sol.generate(5);
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}

}

class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (size_t i = 0; i < 32; ++i)
		{
			int sum = 0;
			for (auto num : nums)
			{
				sum += (num >> i) & 1;
			}
			if (sum % 3 != 0)
				ans |= (1 << i);
		}
		return ans;
	}
};

void test_vector2()
{
	vector<int> v;
	vector<int>::iterator it = v.begin();
}

void test_sol2()
{
	Solution1 sol;
	vector<int> v;
	v.resize(10,0);
	v[0] = v[1] = v[2] = 3;
	v[3] = v[4] = v[5] = 5;
	v[6] = v[7] = v[8] = 2;
	v[9] = 10;

	cout << sol.singleNumber(v) << endl;
}

class Solution2 {
	string _numToStr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

public:
	void Combinations(const string& digits, int di, string combine_str, vector<string>& strV)
	{
		if (di == digits.size())
		{
			strV.push_back(combine_str);
			return;
		}
		int num = digits[di] - '0';
		string str = _numToStr[num];
		for (auto ch : str)
		{
			Combinations(digits, di + 1, combine_str + ch, strV);
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> str;
		if (digits.size() == 0)
			return str;
		Combinations(digits, 0, "", str);
		return str;
	}
};

void test_sol3()
{
	Solution2 sol;
	string str("2345");
	vector<string> vs = sol.letterCombinations(str);
	for (size_t i = 0; i < vs.size(); ++i)
	{
		/*for (size_t j = 0; j < vs[i].size(); ++j)
		{
			cout << vs[i][j];
		}*/
		for (auto s : vs[i])
		{
			cout << s;
		}
		cout << " " << i << endl;
	}
}

int main()
{
	//test_vector1();
	//test_vector2();
	//TestVectorExpand();
	//test_sol2();
	test_sol3();
	return 0;
}