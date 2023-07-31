#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		*it += 1;
//		cout << *it++;
//	}
//	cout << endl;
//
//	//s1.at(100);
//	cout << s1[0] << endl;
//	return 0;
//}

//int main()
//{
//	//insert和erase不推荐常用 存在挪动数据 效率低下
//	string s1("world");
//	s1.insert(0, "hello ");
//	cout << s1 << endl;
//	string s2("hello world");
//	//s2.erase(5, 1);
//	s2.erase(s2.begin() + 5);
//	cout << s2 << endl;
//
//	s2.erase(5);
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello wold I love you");
//	size_t pos = s1.find(' ');
//	while (pos != string::npos)
//	{
//		s1.replace(pos, 1, "%20");
//		pos = s1.find(' ');
//	}
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello world i love you");
//	//提前计算出空格 （可以先直接扩容）
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//			++num;
//	}
//	s1.reserve(s1.size() + 2 * num);
//
//	size_t pos = s1.find(' ');
//	while (pos != string::npos)
//	{
//		s1.replace(pos, 1, "%20");
//		pos = s1.find(' ', pos + 3);
//	}
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	//string s1("hello world i love you");
//	////提前计算出空格 （可以先直接扩容）
//	//size_t num = 0;
//	//for (auto ch : s1)
//	//{
//	//	if (ch == ' ')
//	//		++num;
//	//}
//	//s1.reserve(s1.size() + 2 * num);
//
//	//size_t pos = s1.find(' ');
//	//while (pos != string::npos)
//	//{
//	//	s1.replace(pos, 1, "%20");
//	//	pos = s1.find(' ', pos + 3);
//	//}
//	//cout << s1 << endl;
//
//	string s1("hello world I love you");
//	string newStr;
//
//	//提前扩容
//	size_t num = 0;
//	for (auto ch : newStr)
//	{
//		if (ch == ' ')
//			++num;
//	}
//	newStr.reserve(newStr.size() + 2 * num);
//
//	for (auto ch : s1)
//	{
//		if (ch != ' ')
//			newStr += ch;
//		else
//			newStr += "%20";
//	}
//
//	cout << s1 << endl;
//	s1 = newStr;
//	cout << s1 << endl;
//	cout << newStr << endl;
//
//	return 0;
//}


//class Solution {
//public:
//    bool isPalindrome(string s) {
//        string newStr;
//        newStr.reserve(s.size());
//        for (auto ch : s)
//        {
//            if (isalnum(ch))
//            {
//                if (isupper(ch))
//                    ch = tolower(ch);
//                newStr += ch;
//            }
//        }
//        if (!newStr.empty())
//        {
//            string tmp_str = newStr;
//            reverse(tmp_str.begin(), tmp_str.end());
//            if (newStr == tmp_str)
//                return true;
//            else
//                return false;
//        }
//        else
//            return true;
//    }
//};


//class Solution {
//public:
//    bool isPalindrome(string s) {
//        int begin = 0, end = (int)s.size() - 1;
//        for (auto& ch : s)
//        {
//            if (isupper(ch))
//                ch = tolower(ch);
//        }
//        while (begin < end)
//        {
//            while (begin < end && !isalnum(s[begin]))
//                ++begin;
//            while (begin < end && !isalnum(s[end]))
//                --end;
//            if (s[begin++] != s[end--])
//                return false;
//        }
//        return true;
//    }
//};

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        string ret;
//        ret.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
//        int next = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int val = val1 + val2 + next;
//            if (val > 9)
//            {
//                next = 1;
//                val -= 10;
//            }
//            else
//                next = 0;
//            ret += val + '0';
//            end1--;
//            end2--;
//        }
//        if (next == 1)
//            ret += '1';
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};

//class Solution {
//public:
//    string reverseStr(string s, int k) {
//    int count = 2 * k - 1;
//    while (count < s.size())
//    {
//        int pos_begin = count / 2 - k + 1;
//        int pos_end = count / 2;
//    }
//
//    }
//};
//
//int main()
//{
//    Solution sol;
//    //cout << sol.isPalindrome("race a car") << endl;
//    //cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
//    //cout << sol.isPalindrome(" ") << endl;
//    cout << sol.addStrings("123", "10") << endl;
//    return 0;
//}


//class Solution {
//public:
//    string reverseWords(string s) {
//        int space_pos = s.find(' ');
//        int i = 0;
//        while (space_pos != string::npos)
//        {
//            reverse(s.begin() + i, s.begin() + space_pos);
//            i = space_pos + 1;
//            space_pos = s.find(' ', i);
//        }
//        space_pos = s.rfind(' ');
//        reverse(s.begin() + space_pos + 1, s.end());
//        return s;
//    }
//};

//int main()
//{
//	/*string s("hello bit");
//	size_t pos = s.find(' ');
//	cout << pos << endl;*/
//
//    Solution sol;
//    cout << sol.reverseWords("hello world i love you") << endl;
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string str;
//    getline(cin, str);
//    int countA[26] = { 0 };
//    for (auto ch : str)
//    {
//        countA[ch - 'a']++;
//    }
//
//    int n = str.size();
//    for (int i = 0; i < n; ++i)
//    {
//        if (countA[str[i] - 'a'] == 1)
//        {
//            cout << str[i] << endl;
//            return 1;
//        }
//    }
//    cout << -1 << endl;
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int countA[26] = { 0 };
    for (auto ch : str)
    {
        countA[ch - 'a']++;
    }

    int n = str.size();
    int flag = 1;
    for (int i = 0; i < n; ++i)
    {
        if (countA[str[i] - 'a'] == 1)
        {
            cout << str[i] << endl;
            flag = 0;
            break;
        }
    }
    if (1 == flag)
        cout << -1 << endl;
    return 0;
}