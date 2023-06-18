#include "proc.h"

void process()
{
    char bar[102];
    //初始化数组全为0
    memset(bar, 0, sizeof(bar));
    int i = 0;
    while (i <= 100)
    {
        printf("[%-100s]\r", bar);
        bar[i++] = STYLE;
        if (i != 100)
            bar[i] = ARR;
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
}
