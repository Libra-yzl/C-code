#pragma once
#include <stdio.h>

#define MAX 1024
#define BUFF_LINE 0x1
#define BUFF_ALL 0x2
#define BUFF_NONE 0x0

typedef struct _MY_FILE
{
    //文件描述符
    int fd;
    int flag; //刷新方式
    char outputbuffer[MAX];
    int current;
}MYFILE;

MYFILE *my_fopen(const char *path, const char *mode);
size_t my_fwrite(const void *ptr, size_t size, size_t nmemb,MYFILE *stream);
int my_fclose(MYFILE *fp);
int my_fflush(MYFILE *fp);