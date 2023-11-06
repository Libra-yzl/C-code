#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// 2.要求：

// 2.1代码创建子进程， 父进程调用wait/waitpid函数进行等待， 
// 子进程打印“i am child process”之后，等待5s钟结束子进程；

// 2.2 父进程在等待到子进程之后， 分析子进程的退出信号， coredump标志位以及退出码

// int main()
// {
//     pid_t id = fork();
//     int cnt = 0;

//     if (id == 0) {
//         printf("i am child process\n");
//         sleep(5);
//         exit(107);
//     }

//     int status = 0;
//     pid_t ret_id = waitpid(id, &status, 0);
//     printf("child exit code:%d child exit singal:%d\n", (status>>8)&0xff, status&0x7f);
//     return 0;
// }


// 1.考察进程程序替换函数簇的函数，利用任一一个进程程序替换函数完成代码。

// 理解进程程序替换的本质， 在深层次的理解程序员在 命令行当中启动一个程序， 
// 本质上是bash程序启动了一个子进程， 子进程程序替换成为程序员启动的程序

// 2.要求： 将启动程序替换成为“ls”程序， 并且要给“ls”程序指定命令行参数， “-l”和“-a”

int main()
{
    printf("####################################\n");
    printf("####################################\n");
    printf("####################################\n");
    printf("####################################\n");
    printf("####################################\n");
    char *args[] = {"ls", "-a", "-l", NULL};
    execvp("ls", args);
    printf("************************************\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("************************************\n");
    return 0;
}