#include <iostream>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if (str.size() == 0) return 0;
        int flag = 1; // Ĭ��������
        size_t len = str.size() - 1;
        int res = 0; // ��Ž��
        for (size_t i = 0; i < str.size(); ++i) {
            // �����һ�ν��� �������� ��ôֱ��continue ������Ƿ�����
            if (i == 0 && (str[i] == '+' || str[i] == '-')) {
                --len;
                if (str[i] == '-') flag = -flag;
                continue;
            }
            if ((str[i]) < '0' || str[i] > '9') return 0; // ������������ֱ�ӽ���

            // ֻ�����ֲŻ����������
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