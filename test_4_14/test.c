#define _CRT_SECURE_NO_WARNINGS 1

//bool isPalindrome(int x) {
//    if (x < 0 || (x % 10 == 0 && x != 0))
//        return false;
//    int tmp = 0;
//    while (tmp < x)
//    {
//        tmp = tmp * 10 + x % 10;
//        x /= 10;
//    }
//    if (tmp == x || tmp / 10 == x)
//        return true;
//    return false;
//}

//int romanToInt(char* s) {
//    int RomanNum[26] = { 0 };
//    RomanNum['I' - 'A'] = 1;
//    RomanNum['V' - 'A'] = 5;
//    RomanNum['X' - 'A'] = 10;
//    RomanNum['L' - 'A'] = 50;
//    RomanNum['C' - 'A'] = 100;
//    RomanNum['D' - 'A'] = 500;
//    RomanNum['M' - 'A'] = 1000;
//    int i = 0;
//    int ret = 0;
//    for (i = 0; i < strlen(s); i++)
//    {
//        if (i < strlen(s) - 1 && RomanNum[s[i] - 'A'] < RomanNum[s[i + 1] - 'A'])
//            ret -= RomanNum[s[i] - 'A'];
//        else
//            ret += RomanNum[s[i] - 'A'];
//    }
//    return ret;
//}

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    for (i = 0; i < strlen(strs[0]); i++)
    {
        int j = 0;
        for (j = 1; j < strsSize; j++)
        {
            if (strs[0][i] != strs[j][i])
            {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}