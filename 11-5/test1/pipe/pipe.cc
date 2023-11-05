#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <cerrno>
#include <string.h>

using namespace std;

int main()
{
    // 创建管道
    int pipefd[2] = {0};
    int n = pipe(pipefd);
    if (n < 0) {
        cout << "pipe error:" << errno << ":" << strerror(errno) << endl;
        return 1;
    }


    // 创建字进程
    pid_t id = fork();
    if (id == 0) {
        // 子进程写 父进程读
        close(pipefd[0]);
        char buffer[1024] = {0};
        int cnt = 0;
        const char* msg = "hello i am child";
        while (1) 
        {
            snprintf(buffer, sizeof(buffer), "%s %d\n", msg, cnt++);
            write(pipefd[1], buffer, strlen(buffer));
            sleep(1);
        }
        exit(0);
    }
    // 父进程
    close(pipefd[1]);
    char line[1024] = {0};
    while (true) 
    {
        n = read(pipefd[0], line, sizeof(line)-1);
        if (n > 0) 
        {
            line[n] = '\0';
            cout << "我是父进程 child give me msg: " << line << endl;
        }
    }

    return 0;
}