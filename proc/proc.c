/*#include "proc.h"

void process()
{
    char bar[102];
    char cir[5] = "|\\-/";
    //初始化数组全为0
    memset(bar, 0, sizeof(bar));
    int i = 0;
    while (i <= 100)
    {
        printf("\033[32m[%-100s][%d%%][%c]\033[0m\r", bar, i, cir[i%4]);
        bar[i++] = STYLE;
        if (i != 100)
            bar[i] = ARR;
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
}*/

#include "proc.h"

void process()
{
    char bar[102];
    char color[] = "\033[42m"; // 设置进度条的颜色为绿色
    char cir[5] = "|\\-/";
    // 初始化数组全为0
    memset(bar, 0, sizeof(bar));
    int i = 0;
    while (i <= 100)
    {
        printf("[%s%-*s\033[0m][%d%%][%c]\r", color, i, bar, i, cir[i % 4]);
        bar[i++] = ' ';
        /*if (i != 100)
            bar[i] = ARR;*/
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
}

