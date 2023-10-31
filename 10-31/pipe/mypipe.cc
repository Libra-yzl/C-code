#include <iostream>
#include <string>
#include <cerrno>
#include <cassert>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // 让不同的进程看到同一份资源！！！！
    // 任何一种任何一种进程间通信中，一定要 先 保证不同的进程之间看到同一份资源
    int pipefd[2] = {0};
    //1. 创建管道
    int n = pipe(pipefd);
    if(n < 0)
    {
        std::cout << "pipe error, " << errno << ": " << strerror(errno) << std::endl;
        return 1;
    }
    std::cout << "pipefd[0]: " << pipefd[0] << std::endl; // 读端， 0->嘴巴->读书
    std::cout << "pipefd[1]: " << pipefd[1] << std::endl; // 写端， 1->笔->写东西的

    //2. 创建子进程
    pid_t id = fork();
    assert(id != -1); //正常应该用判断，我这里就断言：意料之外用if，意料之中用assert

    if(id == 0)// 子进程
    {
        //3. 关闭不需要的fd，让父进程进行读取，让子进程进行写入
        close(pipefd[0]);

        //4. 开始通信 -- 结合某种场景
        // const std::string namestr = "hello， 我是子进程";
        // int cnt = 1;
        // char buffer[1024];
        int cnt = 0;
        while(true)
        {
            char x = 'X';
            write(pipefd[1], &x, 1);
            std::cout << "Cnt: " << cnt++<<std::endl;
            sleep(1);
            // break;

            // snprintf(buffer, sizeof buffer, "%s, 计数器: %d, 我的PID: %d", namestr.c_str(), cnt++, getpid());
            // write(pipefd[1], buffer, strlen(buffer));
        }

        close(pipefd[1]);
        exit(0);
    }

    //父进程
    //3. 关闭不需要的fd，让父进程进行读取，让子进程进行写入
    close(pipefd[1]);

    //4. 开始通信 -- 结合某种场景
    char buffer[1024];
    int cnt = 0;
    while(true)
    {
        // sleep(10);
        // sleep(1);
        int n = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if(n > 0)
        {
            buffer[n] = '\0';
            std::cout << "我是父进程, child give me message: " << buffer << std::endl;
        }
        else if(n == 0)
        {
            std::cout << "我是父进程, 读到了文件结尾" << std::endl;
            break;
        }
        else 
        {
            std::cout << "我是父进程, 读异常了" << std::endl;
            break;
        }
        sleep(1);
        if(cnt++ > 5) break;
    }
    close(pipefd[0]);

    int status = 0;
    waitpid(id, &status, 0);
    std::cout << "sig: " << (status & 0x7F) << std::endl;

    sleep(100);

    return 0;
}