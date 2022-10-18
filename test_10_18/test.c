#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    int ret = 0;
    while (x > ret)
    {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    if (x == ret || x == ret / 10)
        return true;
    return false;
}
int main()
{
    int x = 0;
    scanf("%d", &x);
    bool ret = isPalindrome(x);
    printf("%d\n", ret);
	return 0;
}

