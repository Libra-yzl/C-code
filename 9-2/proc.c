#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define TASK_NUM 10

typedef void (*func_t)();
func_t other_task[TASK_NUM] = {NULL};

void sync_disk()
{
    printf("这是一个刷新磁盘的任务\n");
}

void sync_log()
{
    printf("这是一个刷新日志的任务\n");
}

void net_send()
{
    printf("这是一个网络传输的任务\n");
}

int LoadTask(func_t fun)
{
    int i = 0;
    for (; i < TASK_NUM; ++i)
    {
        if (other_task[i] == NULL)
            break;
    }
    if (i == TASK_NUM) return -1;
    else other_task[i] = fun;
    
    return 0;
}

void InitTask()
{
    int i = 0;
    for (; i < TASK_NUM; ++i) other_task[i] = NULL;

    LoadTask(sync_disk);
    LoadTask(sync_log);
    LoadTask(net_send);
}

void RunTask()
{
    int i = 0;
    for (; i < TASK_NUM; ++i)
    {
        if (other_task[i] == NULL) continue;
        other_task[i]();
    }
}

int main()
{
    pid_t id = fork();
    if (0 == id)
    {
        //child
        int cnt = 50;
        while (cnt--)
        {
            printf("我是子进程 我还没有结束 pid: %d\n", getpid());
            sleep(1);
        }
        exit(107);
    }
    //parent
    InitTask();

    while (1)
    {
        int status = 0;
        pid_t ret_id = waitpid(id, &status, WNOHANG);
        if (ret_id < 0)
        {
            printf("wait error\n");
            exit(1);
        }
        else if (ret_id == 0)
        {
            RunTask();
            // printf("我是父进程 我还在等子进程\n");
            sleep(1);
            continue;
        }
        else 
        {
            if (WIFEXITED(status))
            {
                printf("wait sucess child exit code: %d\n", WEXITSTATUS(status));
            }
            else
            {
                printf("wait sucess child exit signal: %d\n", status & 0x7F);
            }
            break;
        }
    }
    return 0;
}
