#pragma once
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>


#define MAX 1024

#define BUFF_LINE 0x1
#define BUFF_ALL 0x2
#define BUFF_NONE 0x4

typedef struct MY_FILE
{
    int fd;
    int flag;
    char outputbuffer[MAX];
    int current;
}MyFile;

MyFile *myfopen(const char *path, const char *mode);

int myfclose(MyFile *fp);

size_t myfwrite(const void *ptr, size_t size, size_t nmemb, MyFile *stream);

int myfflush(MyFile *stream);