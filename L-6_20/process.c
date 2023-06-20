#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>

int main()
{
    pid_t ret = fork();
    assert(ret != -1);

    if (ret == 0)
    {
//        printf("这是子进程\n");
        while (1)
        {
            printf("子进程: 我的PID是: %d, 我的PPID是: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else if (ret > 0)
    {
        //printf("这是父进程\n");
        while (1)
        {
            printf("父进程: 我的PID是: %d, 我的PPID是: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {}
    return 0;
}

//
//int main()
//{
//    while (1)
//    {
//        printf("hello process, my PID:%d, my PPID:%d\n", getpid(), getppid());
//        sleep(1);
//    }
//    return 0;
//}
