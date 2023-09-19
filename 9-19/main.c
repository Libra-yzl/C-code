#include "myfile.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    MyFile* pf = myfopen("log.txt", "w");
    if (pf == NULL){
        perror("myfopen");
        exit(-1);
    }

    const char* msg = "Hello World";
    int cnt = 10;
    while (cnt)
    {
        char buf[1024] = {0};
        snprintf(buf,sizeof(buf),"%s %d\n", msg, cnt--);
        size_t n = myfwrite(buf, strlen(buf), 1, pf);
        sleep(1);
        printf("写入了%d字节\n", n);
    }

    myfclose(pf);
    pf = NULL;
    return 0;
}