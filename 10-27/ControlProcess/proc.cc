#include <iostream>
#include <unistd.h>
#include <cassert>
#include <vector>
#include "Task.hpp"
using namespace std;

const int g_num = 5;
Task t;

class EndPonit
{
public:
    EndPonit(int id, int fd)
        :_child_id(id)
        ,_write_fd(fd)
    {}

    ~EndPonit()
    {}

public:
    pid_t _child_id;
    int _write_fd; 
};

// 子进程要执行的方法
void WaitCommand()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(int));
        if (n == sizeof(int))
        {
            t.Execute(command);
        }
        else if (n == 0)
        {
            break;
        }
        else
        {
            break;
        }
    }
}

void CreatProcess(vector<EndPonit>& end_points)
{
    for (int i = 0; i < g_num; ++i)
    {
        // 1.创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        assert(n != -1);

        // 2.创建子进程
        pid_t id = fork();
        assert(id != -1);

        if (id == 0)
        {
            // 子进程
            // 3.关闭不用的端口
            close(pipefd[1]);
            // 所有子进程都从标准输入流中读取数据
            dup2(pipefd[0], 0);
            // 子进程获取命令
            WaitCommand();
            close(pipefd[0]);
            exit(0);
        }

        // 父进程
        // 3.关闭不用的管道
        close(pipefd[0]);

        // 4.将新的子进程和管道写端口 构建对象
        end_points.push_back(EndPonit(id, pipefd[1]));
    }
}

int main()
{
    // 1. 先进行构建控制结构, 父进程写入，子进程读取 
    vector<EndPonit> end_points;
    CreatProcess(end_points);

    int num = 0;
    while (1)
    {
        // 1.选任务
        int command = COMMAND_LOG;
        // 2.选进程
        int index = rand()%end_points.size();
        // 3.下发任务
        write(end_points[index]._write_fd, &command, sizeof(command));
        sleep(1);
    }

    return 0;
}