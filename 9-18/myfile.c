#include "myfile.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>
#include <assert.h>


MyFile* myfopen(const char* path, const char* mode){
    //识别打开方式
    int flag = 0;
    if (strcmp(mode, "r") == 0) flag |= O_RDONLY;
    else if (strcmp(mode, "w") == 0) flag |= (O_CREAT | O_WRONLY | O_TRUNC);
    else if (strcmp(mode, "a") == 0) flag |= (O_CREAT | O_WRONLY | O_APPEND);

    //返回文件描述符
    mode_t m = 0666; // 默认创建的文件权限
    int fd = 0;
    if (flag & O_CREAT) fd =  open(path, flag, m);
    else fd = open(path, flag);

    //创建
    MyFile* mf = (MyFile*)malloc(sizeof(MyFile));
    if (mf == NULL){
        close(fd);
        return NULL;
    }
    //初始化
    mf->fd = fd;
    mf->flags = BUFF_LINE;
    memset(mf->outputbuffer, '\0', sizeof(mf->outputbuffer));
    mf->current = 0;
}

int myfclose(MyFile* fp){
    assert(fp);

    if (fp->current > 0) my_fflush(fp);

    close(fp->fd);
    free(fp);
    fp = NULL;
    return 0;
}

int my_fflush(MyFile *fp){
    assert(fp);

    write(fp->fd, fp->outputbuffer, fp->current);
    // 写入后清除current
    fp->current = 0;
    fsync(fp->fd);
}

size_t myfwrite(const void *ptr, size_t size, size_t nmemb, MyFile *stream){
    //如果缓冲区已经满了那么直接刷新
    if (stream->current == MAX) my_fflush(stream);

    //要输入的大小
    size_t usersize = size * nmemb;
    //剩余大小
    size_t mysize = MAX - stream->current;
    size_t writen = 0; // 返回写入的字节数
    if (usersize <= mysize){
        //如果空间足够直接写入
        memcpy(stream->outputbuffer+stream->current, ptr, usersize);
        //刷新计数器
        stream->current += usersize;
        writen = usersize;
    }
    else{
        //空间不够写满就行
        memcpy(stream->outputbuffer+stream->current, ptr, mysize);
        stream->current += mysize;
        writen = mysize;
    }

    // 刷新策略
    if (stream->flags & BUFF_ALL) {
        if (stream->current == MAX) my_fflush(stream);
    }
    else if (stream->flags & BUFF_LINE) {
        if (*(stream->outputbuffer+stream->current-1)=='\n') my_fflush(stream);
    }

    return writen;
}