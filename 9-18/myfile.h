#pragma once
#include <stdio.h>

#define MAX 1024

#define BUFF_LINE 0x1
#define BUFF_ALL 0x2
#define BUFF_NONE 0x3

typedef struct _MYFILE
{
    int fd; //文件描述符
    int flags; //刷新方式
    char outputbuffer[MAX]; //缓冲区
    int current;
}MyFile;

MyFile* myfopen(const char* path, const char* mode);

int myfclose(MyFile* fp);

int my_fflush(MyFile *fp);

size_t myfwrite(const void *ptr, size_t size, size_t nmemb, MyFile *stream);