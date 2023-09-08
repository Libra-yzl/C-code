#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//#define LOG "log.txt"

int main()
{
    //int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
    int fd = open("log.txt", O_RDONLY);
    int cnt = 5;
    const char* buf = "hello world";
    char line[128];
    ssize_t n = read(fd, line, sizeof(line)-1);
    if (n > 0)
    {
        line[n] = '\0';
        printf("%s\n", line);
    }
    while (cnt--)
    {
        //umask(0);
        //const char* mesg = "Hello World\n";
        //write(fd, mesg, strlen(mesg));
    }

    close(fd);
    return 0;
}

//#include <stdio.h>
//#include <errno.h>
//#include <string.h>
//
//int main()
//{
//    //C语言--文件操作
//    FILE* pf = fopen("log.txt", "w");
//    if (pf == NULL) printf("errno:%d, strerror:%s\n", errno, strerror(errno));
//    else{
//        printf("errno:%d, strerror:%s\n", errno, strerror(errno));
//        
//        char buf[128];
//        while (1)
//        {
//            static int i = 0;
//            if (i == 5) break;
//            ++i;    
//        }
//        int cnt = 5;
//        while (cnt--)
//        {
//            //char buff[128];
//            //fputs(buff, pf);
//            //printf("%s, %d", buff, cnt);
//            const char* mesg = "Hello World\n";
//            //fprintf(pf, "%s %d\n", mesg, cnt);
//            //snprintf(buf, strlen(mesg), "%s\n", mesg);
//            fputs(mesg, pf);
//        }
//        //printf("%s\n", buf);
//
//        fclose(pf);
//        pf = NULL;
//    }
//    return 0;
//}
