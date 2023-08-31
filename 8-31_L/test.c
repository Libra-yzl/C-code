#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork();
    
    //子进程
    if (id == 0)
    {
        int cnt = 5;
        while (1)
        {
            printf("我是子进程 我还没有死 我还有%dS pid: %d ppid: %d\n", cnt--, getpid(), getppid());
            sleep(1);
           // exit(107);
        }
    }
    else if (id > 0)
    {
        //父进程
        while (1)
        {
            int status = 0;
            pid_t ret_id = waitpid(id, &status, WNOHANG);
            if (ret_id < 0)
            {
                printf("waitpid error!\n");
                exit(1);
            }
            else if (ret_id == 0)
            {
                sleep(1);
                continue;
            }
            else
            {        
                printf("我是父进程 等待子进程成功 pid:%d ppid:%d ret_id:%d child_exit_code: %d child_exit_single: %d\n", getpid(), getppid(), ret_id, (status>>8)&0xff, status&0x7f);
                break;
            }
        }
    }
    return 0;
}
