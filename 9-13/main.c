#include "myfile.h"
#include <string.h>


int main()
{
    //open
    MyFile* mf = myfopen("log.txt", "w");
    if (mf == NULL) return -1;
    
    //option
    const char* str = "hello world";
    int cnt = 10;
    while (cnt)
    {
        char buffer[1024] = {0};
        snprintf(buffer, sizeof(buffer), "%s %d\n", str, cnt--);
        size_t n = myfwrite(buffer, strlen(buffer), 1, mf);
        sleep(1);
        printf("成功写入了%d个字节\n", n);
    }

    //close
    myfclose(mf);
    mf = NULL;
    return 0;
}