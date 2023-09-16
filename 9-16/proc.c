#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>

int main()
{
    pid_t id = fork();
    assert(id >= 0);
    if (id == 0)
    {
        printf("我是子进程 pid:%d ppid:%d\n", getpid(), getppid());
        exit(1);
    }
    else
        printf("我是父进程 pid:%d ppid:%d\n", getpid(), getppid());

    return 0;
}