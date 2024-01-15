//#include <iostream>
//#include "Map.h"
//#include "Set.h"
//
//
//using namespace std;
//
//int main()
//{
//	//yzl::map_test2();
//	//yzl::map_test3();
//	yzl::map_test4();
//	//yzl::set_test1();
//	return 0;
//}

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <time.h>
using namespace std;

//void unordered_set_test1()
//{
//	unordered_set<int> s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(2);
//
//	unordered_set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void unordered_map_test1()
//{
//	string str[] = { "香蕉","香蕉","梨","苹果","橘子","苹果","葡萄" };
//	map<string, int> countMap;
//	for (auto& e : str)
//	{
//		countMap[e]++;
//	}
//
//	for (auto& kv : countMap)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//}
//
//int main()
//{
//	unordered_set_test1();
//	unordered_map_test1();
//
//	return 0;
//}
//
int main()
{
	const size_t N = 5000000;

	unordered_set<int> us;
	set<int> s;

	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		//v.push_back(rand());
		v.push_back(rand()+i);
		//v.push_back(i);
	}

	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();
	cout << "set insert:" << end1 - begin1 << endl;

	size_t begin2 = clock();
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();
	cout << "unordered_set insert:" << end2 - begin2 << endl;


	size_t begin3 = clock();
	for (auto e : v)
	{
		s.find(e);
	}
	size_t end3 = clock();
	cout << "set find:" << end3 - begin3 << endl;

	size_t begin4 = clock();
	for (auto e : v)
	{
		us.find(e);
	}
	size_t end4 = clock();
	cout << "unordered_set find:" << end4 - begin4 << endl << endl;

	cout << s.size() << endl;
	cout << us.size() << endl << endl;;

	size_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	size_t end5 = clock();
	cout << "set erase:" << end5 - begin5 << endl;

	size_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	size_t end6 = clock();
	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;

	return 0;
}