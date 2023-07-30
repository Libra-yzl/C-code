#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//	string s1;
//	string s2("hello bit");
//	string s3(s2, 6);
//	cout << s1 << endl << s2 << endl << s3 << endl;
//	cout << s2.max_size() << endl;
//	cout << s2.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	s1.append(" world!");
//	s1 += " world";
//	cout << s1 << endl;
//	cout << sizeof(size_t) << endl;
//	return 0;
//}

class Solution1 {
public:
    int firstUniqChar(string s) {
        int Count[52] = { 0 };
        //计数排序思想
        //统计字母出现的次数
        size_t i = 0;
        for (auto ch : s)
        {
            Count[ch - 'A']++;
        }

        for (i = 0; i < s.size(); ++i)
        {
            if (Count[s[i] - 'A'] == 1)
                return i;
        }
        return -1;
    }
};

class Solution2 {
public:
    string reverseOnlyLetters(string s) {
        //快排思想
        size_t begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isalpha(s[begin]))
                ++begin;
            while (begin < end && !isalpha(s[end]))
                --end;
            swap(s[begin++], s[end--]);
        }
        return s;
    }
};

int main()
{
    Solution1 solution1;
    cout << solution1.firstUniqChar("HelloHeoL") << endl;

    Solution2 solution2;
    cout << solution2.reverseOnlyLetters("leet-code") << endl;
    return 0;
}