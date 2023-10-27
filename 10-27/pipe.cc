#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <sys/wait.h>

using namespace std;

int main()
{
    // 1.创建管道
    int pipefd[2] = {0};

    int n = pipe(pipefd);

    char buff[1024] = {0};
    int cnt = 0;
    const char *msg = "hello pipe";
    // 2.创建子进程
    pid_t id = fork();

    // 子进程
    if (id == 0)
    {
        // 3.关闭不需要的端口
        close(pipefd[0]);
        while (1)
        {
            // 1.子进程写的慢 父进程读得快
            // snprintf(buff, sizeof(buff), "%s %d\n", msg, cnt++);
            // write(pipefd[1], buff, strlen(buff));
            // sleep(5);

            // 2.子进程写得快 父进程读的慢
            // snprintf(buff, sizeof(buff), "%s %d\n", msg, cnt++);
            // write(pipefd[1], buff, strlen(buff));
            // sleep(1);

            // 3.子进程写一次之后停止写入 父进程一直读
            // --- Linux观察到进程状态 子进程成为僵尸状态 父进程一直在读取
            // snprintf(buff, sizeof(buff), "%s %d\n", msg, cnt++);
            // write(pipefd[1], buff, strlen(buff));
            // sleep(1);
            // break;

            // 4.子进程一直写 父进程读取一次后停止读取
            snprintf(buff, sizeof(buff), "%s %d\n", msg, cnt++);
            write(pipefd[1], buff, sizeof(buff)-1);
            sleep(1);
        }

        close(pipefd[1]);
        exit(0);
    }

    // 父进程
    // 3.关闭不需要的端口
    char line[1024] = {0};
    close(pipefd[1]);
    while (1)
    {
        int n = read(pipefd[0], line, sizeof(line) - 1);
        if (n > 0)
        {
            line[n] = '\0';
            cout << "我读到了msg:" << line << endl;
        }
        // else if (n == 0) {
        //     cout << "我读到了文件结尾" << endl;
        //     break;
        // }
        // else {
        //     cout << "我读取异常了" << endl;
        //     break;
        // }
        sleep(1);
        close(pipefd[0]);
        break;
        // sleep(5);
    }
    // 查看第四种情况
    int status = 0;
    waitpid(id, &status, 0);
    cout << "child exit singal: " << (status & 0x7f) << endl;

    sleep(5);
    return 0;
}