#define _CRT_SECURE_NO_WARNINGS 1

#include "vector.h"
//#include <vector>
//#include <iostream>
//using namespace std;

//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv;
//		vv.resize(numRows, vector<int>());
//		for (size_t i = 0; i < vv.size(); ++i)
//		{
//			vv[i].resize(i + 1, 0);
//			vv[i][0] = vv[i][vv[i].size() - 1] = 1;
//		}
//
//		for (size_t i = 0; i < vv.size(); ++i)
//		{
//			for (size_t j = 0; j < vv[i].size(); ++j)
//			{
//				if (vv[i][j] == 0)
//				{
//					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//				}
//			}
//		}
//
//		return vv;
//	}
//};

int main()
{
	//jwf::test_vector1();
	//jwf::test_vector2();
	//jwf::test_vector3();
	//jwf::test_vector4();
	jwf::test_vector5();

	/*vector<vector<int>> ret = Solution().generate(5);
	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	return 0;
}