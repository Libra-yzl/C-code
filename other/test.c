#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    int i = 0;
    for (; i < 5; ++i)
    {
        printf("---------------------------------------------------------------------------------------------------\n");

        printf("我是另一个程序 我的pid是: %d\n", getpid());
        printf("MYENV: %s\n", getenv("MYENV"));
        printf("PATH: %s\n", getenv("PATH"));

        printf("----------------------------------------------------------------------------------------------------\n");
        sleep(1);
    }
    return 0;
}
