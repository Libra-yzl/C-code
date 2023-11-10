#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


// //volatile int quit = 0; // 保证内存可见性
// int quit = 0;

// void handler(int signo)
// {
//     printf("change quit from 0 to 1\n");
//     quit = 1;
//     printf("quit : %d\n", quit);
// }

// int main()
// {
//     signal(2, handler);

//     while(!quit); //quit只会被检测

//     printf("main quit 正常\n");

//     return 0;
// }


pid_t id;

void waitProcess(int signo)
{
    printf("捕捉到一个信号: %d, who: %d\n", signo, getpid());
    sleep(5);

    // 5个退出，5个没退
    while (1)
    {
        pid_t res = waitpid(-1, NULL, WNOHANG);
        if (res > 0)
        {
            printf("wait success, res: %d, id: %d\n", res, id);
        }
        else break; // 如果没有子进程了？
    }

    printf("handler done...\n");
}

int main()
{
    // signal(SIGCHLD, waitProcess);

    signal(SIGCHLD, SIG_IGN);

    int i = 1;
    for (; i <= 10; i++)
    {
        id = fork();
        if (id == 0)
        {
            // child
            int cnt = 5;
            while (cnt)
            {
                printf("我是子进程, 我的pid: %d, ppid: %d\n", getpid(), getppid());
                sleep(1);
                cnt--;
            }

            exit(1);
        }
    }
    // 如果你的父进程没有事干，你还是用以前的方法
    // 如果你的父进程很忙，而且不退出，可以选择信号的方法
    while (1)
    {
        sleep(1);
    }

    return 0;
}