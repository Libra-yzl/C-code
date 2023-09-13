#include "myfile.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <assert.h>
#include <unistd.h>

MyFile* myfopen(const char* path, const char* mode)
{
    //打开文件
    int flags = 0;
    if (strcmp(mode, "a") == 0) flags |= (O_CREAT | O_WRONLY | O_APPEND);
    else if (strcmp(mode, "r") == 0) flags |= O_RDONLY;
    else if (strcmp(mode, "w") == 0) flags |= (O_CREAT | O_WRONLY | O_TRUNC);

    mode_t m = 0666;
    int fd = 0;
    if (flags & O_CREAT) fd = open(path, flags, m);
    else fd = open(path, flags);

    //option
    MyFile* mf = (MyFile*)malloc(sizeof(MyFile));
    if (mf == NULL) 
    {
        close(fd);
        return NULL;
    }

    mf->fd = fd;
    mf->flag = BUFF_LINE;
    memset(mf->outputbuffer, '\0', sizeof(mf->outputbuffer));
    mf->current = 0;

    return mf;
}

int myfclose(MyFile* fp)
{
    assert(fp);
    if (fp->current > 0) my_fflush(fp);
    close(fp->fd);
    free(fp);

    return 0;
}

size_t myfwrite(const void *ptr, size_t size, size_t nmemb,MyFile *stream)
{
    //如果缓冲区已满 直接刷新
    if (stream->current == MAX) my_fflush(stream);

    size_t user_size = size * nmemb;
    size_t my_size = MAX - stream->current;
    //返回 写入的字节数
    size_t writen = 0;
    if (my_size >= user_size)
    {
        memcpy(stream->outputbuffer+stream->current, ptr, user_size);
        //更新计数器字段
        stream->current += user_size;
        writen = user_size;
    }
    else{
        memcpy(stream->outputbuffer+stream->current, ptr, my_size);
        //计数器
        stream->current += my_size;
        writen = my_size;
    }
    //刷新策略
    if (stream->flag & BUFF_ALL) {
        if (stream->current == MAX) my_fflush(stream);
    }
    else if (stream->flag & BUFF_LINE){
        if (*(stream->outputbuffer+stream->current-1)=='\n') my_fflush(stream);
    }
    else{
        ;
    }
    return writen;
}

int my_fflush(MyFile *fp)
{
    assert(fp);
    
    //系统调用
    write(fp->fd, fp->outputbuffer, fp->current);
    fp->current = 0;

    fsync(fp->fd);

    return 0;
}