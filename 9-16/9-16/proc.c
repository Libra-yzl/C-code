#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>

// int main()
// {
//     pid_t id = fork();
//     assert(id >= 0);
//     if (id == 0)
//     {
//         printf("我是子进程 pid:%d ppid:%d\n", getpid(), getppid());
//         exit(1);
//     }
//     else
//         printf("我是父进程 pid:%d ppid:%d\n", getpid(), getppid());

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // 创建子进程
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // 子进程
        printf("子进程正在运行\n");
        sleep(2);  // 子进程休眠2秒
        printf("子进程结束\n");
    } else {
        // 父进程
        printf("父进程正在运行，子进程的PID为 %d\n", child_pid);
        // 父进程不等待子进程结束
    }

    return 0;
}