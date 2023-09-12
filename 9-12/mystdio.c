#include "mystdio.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <assert.h>

MYFILE* my_fopen(const char *path, const char *mode)
{
    //识别标志位
    int flag = 0;
    if (strcmp(mode, "r") == 0) flag |= O_RDONLY;
    else if (strcmp(mode, "w") == 0) flag |= (O_CREAT | O_WRONLY | O_TRUNC);
    else if (strcmp(mode, "a") == 0) flag |= (O_CREAT | O_WRONLY | O_APPEND);

    //打开文件
    mode_t m = 0666;
    int fd = 0;
    if (flag & O_CREAT) open(path, flag, m);
    else fd = open(path, flag);

    if (fd < 0) return NULL;

    //返回
    MYFILE* mf = (MYFILE*)malloc(sizeof(MYFILE));
    if (mf == NULL) {
        close(fd);
        return NULL;
    }

    mf->fd = fd;
    mf->flag = 0;
    memset(mf->outputbuffer, '\0', sizeof(mf->outputbuffer));
    mf->current = 0;

    return mf;
}

size_t my_fwrite(const void *ptr, size_t size, size_t nmemb,MYFILE *stream)
{
    return 0;
}

int my_fclose(MYFILE *fp)
{
    assert(fp);

    if (fp->current > 0) my_fflush(fp);

    //关闭文件
    close(fp->fd);

    free(fp);
    fp = NULL;

    return 0;
}

int my_fflush(MYFILE *fp)
{
    return 0;
}