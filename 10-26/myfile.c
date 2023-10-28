#include "myfile.h"

MyFile *myfopen(const char *path, const char *mode)
{
    int flags = 0;
    if (strcmp(mode, "r") == 0) flags |= O_RDONLY;
    else if (strcmp(mode, "w") == 0) flags = flags | O_WRONLY | O_CREAT | O_TRUNC;
    else if (strcmp(mode, "a") == 0) flags = flags | O_WRONLY | O_CREAT | O_APPEND;
    else {;}
    mode_t m = 0666;
    int fd = -1;
    if (flags & O_CREAT) {
        fd = open(path, flags, m);
    }
    else {
        fd = open(path, flags);
    }
    if (fd < 0) return NULL;

    MyFile* mf = (MyFile*)malloc(sizeof(MyFile));
    if (mf == NULL) {
        close(fd);
        return NULL;
    }
    mf->fd = fd;
    mf->flag = BUFF_LINE;
    memset(mf->outputbuffer, '\0', sizeof(mf->outputbuffer));
    mf->current = 0;

    return mf;
}


size_t myfwrite(const void *ptr, size_t size, size_t nmemb, MyFile *stream)
{
    // 如果满了直接刷新出去
    if (stream->current == MAX) myfflush(stream);

    size_t user_size = size * nmemb;
    size_t my_size = MAX - stream->current;
    int writen = 0;
    if (my_size >= user_size) {
        memcpy(stream->outputbuffer+stream->current, ptr, user_size);
        stream->current += user_size;
        writen += user_size;
    }
    else {
        memcpy(stream->outputbuffer+stream->current, ptr, my_size);
        stream->current += my_size;
        writen += my_size;
    }

    // 刷新方式
    if (stream->flag & BUFF_ALL) {
        if (stream->current == MAX) myfflush(stream);
    }
    else if (stream->flag & BUFF_LINE) {
        if (stream->outputbuffer[stream->current-1] == '\n') myfflush(stream);
    }

    return writen;
}


int myfclose(MyFile *fp)
{
    assert(fp);
    // 关闭之前需要冲刷缓冲区
    if (fp->current != 0) myfflush(fp);
    fp->current = 0;
    close(fp->fd);
    free(fp);
    fp = NULL;
}


int myfflush(MyFile *stream)
{
    assert(stream);
    write(stream->fd, stream->outputbuffer, stream->current);
    stream->current = 0;

    // fsync(stream->fd);
    return 0;
}