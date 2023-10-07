#include <iostream>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if (str.size() == 0) return 0;
        int flag = 1; // 默认是正数
        size_t len = str.size() - 1;
        int res = 0; // 存放结果
        for (size_t i = 0; i < str.size(); ++i) {
            // 如果第一次进来 是正负号 那么直接continue 做个标记分正负
            if (i == 0 && (str[i] == '+' || str[i] == '-')) {
                --len;
                if (str[i] == '-') flag = -flag;
                continue;
            }
            if ((str[i]) < '0' || str[i] > '9') return 0; // 遇到不是数字直接结束

            // 只有数字才会接着往下走
            res += (str[i] - '0') * pow(10, len--) * flag;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.StrToInt("##") << endl;
}