#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork();
    if (id == 0){
        // 子进程
        int cnt = 5;
        while (cnt--){
            printf("我是子进程, 我的pid是: %d, 我的ppid是: %d\n", getpid(), getppid());
            sleep(1);
            // int* ptr = NULL;
            // *ptr = 10;
            // if (1) exit(111);
        }
    }
    else {
        // 父进程
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, 0);
//         printf("我是父进程 等待子进程成功 pid: %d ppid: %d ret_id: %d child_exit_code: %d,\
// child_exit_signal: %d\n", \
//         getpid(), getppid(), ret_id, (status>>8)&0xff, status&0x7f);

        while (1){
            int status = 0;
            pid_t ret_id = waitpid(id, &status, WNOHANG);
            
            if (ret_id == 0){
                printf("子进程还未完成, 我做一些自己的事情...\n");
                sleep(1);
                continue;
            }
            else if (ret_id > 0){
                printf("我是父进程 等待子进程成功 pid: %d ppid: %d ret_id: %d child_exit_code: %d,\
child_exit_signal: %d\n", \
                getpid(), getppid(), ret_id, (status>>8)&0xff, status&0x7f);
                    break;
            }
            else {
                printf("waitpid eror\n");
                exit(-1);
            }
            // printf("我是父进程, 我的pid是: %d, 我的ppid是: %d\n", getpid(), getppid());
        }
        // while (1) {
        //     printf("我是父进程, 我的pid是: %d, 我的ppid是: %d\n", getpid(), getppid());
        //     sleep(1);
        // }
    }
    return 0;
}