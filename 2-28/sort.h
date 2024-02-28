#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace yzl
{
	template <class T>
	struct Less
	{
		bool operator()(const T& v1, const T& v2)
		{
			return v1 < v2;
		}
	};

	template <class T>
	struct Greater
	{
		bool operator()(const T& v1, const T& v2)
		{
			return v1 > v2;
		}
	};

	template <class T, class Comp = yzl::Less<T>>
	class sort
	{
	public:
		void bubble_sort(vector<T>& v)
		{
			Comp comp;
			for (int i = 0; i < v.size() - 1; ++i)
			{
				for (int j = 0; j < v.size() - 1 - i; ++j)
				{
					if (comp(v[j], v[j + 1]))
					{
						T tmp = v[j];
						v[j] = v[j + 1];
						v[j + 1] = tmp;
					}
				}
			}
		}

		void insert_sort(vector<T>& v)
		{
			Comp comp;
			size_t n = v.size();
			for (size_t i = 1; i < n; ++i)
			{
				T tmp = v[i];
				int j = i - 1;
				while (j >= 0 && comp(v[j], tmp))
				{
					v[j + 1] = v[j];
					--j;
				}
				v[j + 1] = tmp;
			}
		}

		void shell_sort(vector<T>& v)
		{
			Comp comp;
			size_t gap = v.size();
			gap /= 2;
			while (gap > 0)
			{
				for (int i = gap; i < v.size(); i += gap)
				{
					T tmp = v[i];
					int j = i - gap;
					while (j >= 0 && comp(v[j], tmp))
					{
						v[j + gap] = v[j];
						j -= gap;
					}
					v[j + gap] = tmp;
				}
				gap /= 2;
			}
		}

		void select_sort(vector<T>& v)
		{
			size_t n = v.size();
			for (size_t i = 0; i < n; ++i)
			{
				size_t min_index = i;
				size_t min = v[i];
				for (int j = i + 1; j < n; ++j)
				{
					if (Comp()(min, v[j]))
					{
						min_index = j;
						min = v[j];
					}
				}
				swap(v[min_index], v[i]);
			}
		}

		void print(vector<T>& v)
		{
			for (auto& e : v)
			{
				cout << e << " ";
			}
			cout << endl;
		}
	};
	void test_bubble_sort()
	{
		vector<int> v1 = { 1,5,3,6,8,2,4,9,7 };
		yzl::sort<int, Greater<int>> sort1;
		yzl::sort<int> sort2;
		sort1.bubble_sort(v1);
		sort1.print(v1);
		sort2.bubble_sort(v1);
		sort2.print(v1);
	}

	void test_insert_sort()
	{
		vector<int> v = { 1,5,3,6,5,8,5,2,4 };
		sort<int, Greater<int>> sort1;
		sort<int> sort2;
		sort1.insert_sort(v);
		sort1.print(v);
		sort2.insert_sort(v);
		sort2.print(v);
	}

	void test_shell_sort()
	{
		vector<int> v = { 1,5,3,6,8,2,4,9,7 };
		sort<int, Greater<int>> sort1;
		sort<int> sort2;
		sort1.shell_sort(v);
		sort1.print(v);
		sort2.shell_sort(v);
		sort2.print(v);
	}

	void test_select_sort()
	{
		vector<int> v = { 1,5,3,6,8,2,4,9,7 };
		sort<int, Greater<int>> sort1;
		sort<int> sort2;
		sort1.select_sort(v);
		sort1.print(v);
		sort2.select_sort(v);
		sort2.print(v);
	}
}