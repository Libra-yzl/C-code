#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>


// 僵尸进程 子进程已经退出 父进程未退出
// int main() {
//     pid_t id = fork();
//     int cnt = 0;

//     if (id == 0) {
//         // 子进程
//         while (1) {
//             printf("我是子进程 我的pid是 %d 我的ppid是 %d cnt:%d\n", getpid(), getppid(), cnt++);
//             sleep(1);
//             exit(-1);
//         }
//     } 
//     // 父进程
//     while (1) {
//         printf("我是父进程 我的pid是 %d 我的ppid是 %d cnt:%d\n", getpid(), getppid(), cnt++);
//         sleep(50);
//         // if (cnt == 5) {
//         //     exit(0);
//         // }
//     }
//     return 0;
// }

// 模拟孤儿进程
int main()
{
    // 创建进程
    pid_t id = fork();
    int cnt = 0;
    if (id == 0) {
        // 子进程
        while (1) {
            printf("我是子进程 我的pid是 %d 我的ppid是 %d cnt:%d\n", getpid(), getppid(), cnt++);
            sleep(1);
        }
    }
    // 父进程
    while (1) {
        printf("我是父进程 我的pid是 %d 我的ppid是 %d cnt:%d\n", getpid(), getppid(), cnt++);
        if (cnt == 10) break;
        sleep(1);
    }
    return 0;
}