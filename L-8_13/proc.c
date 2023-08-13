#include "proc.h"

#define SIZE 101
#define SHAPE '#'
void Proc()
{
    char bar[SIZE];
    const char *STYLE = "/|-\\";
    memset(bar, '\0', sizeof(bar));
    int i = 0;
    while (i <= 100)
    {
        bar[i++] = SHAPE;
        printf("[%-100s][%d%%][%c]\r", bar, i-1, STYLE[i%4]);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
}
