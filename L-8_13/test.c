#include "test.h"

int AddToTop(int top)
{
    printf("Enter AddToTop\n");
    int i = 0;
    int sum = 0;
    for (i = 1; i <= top; ++i)
    {
        sum += i;
    }
    printf("Quit AddToTop\n");
    return sum;
}

int main()
{
    int top = 100;
    int result = AddToTop(top);
    printf("result:%d\n", result);
    return 0;
}
