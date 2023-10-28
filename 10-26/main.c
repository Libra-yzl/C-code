#include "myfile.h"

int main()
{
    MyFile* pf = myfopen("log.txt", "w");
    if (!pf) {
        perror("file open error");
        exit(-1);
    }

    char buff[1024] = {0};
    const char* msg = "hello myfile";
    int cnt = 0;
    while (1) {
        // snprintf(buff, sizeof(buff), "%s %d\n", msg, cnt++);
        // size_t n = myfwrite(buff, strlen(buff), 1, pf);
        // printf("成功写入了%d字节\n", n);
        // sleep(1);
        char buffer[1024];
        snprintf(buffer, sizeof(buffer), "%s:%d\n", msg, cnt++);
        //snprintf(buffer, sizeof(buffer), "%s:%d", str, cnt++);
        size_t size = myfwrite(buffer, strlen(buffer), 1, pf);
        sleep(1);
        printf("当前成功写入: %lu个字节\n", size);
        //my_fflush(fp);

        // if(cnt % 5 == 0)
        //     myfwrite("\n", strlen("\n"), 1, pf);
    }

    myfclose(pf);
    return 0;
}