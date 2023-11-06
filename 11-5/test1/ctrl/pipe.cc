#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include "Task.hpp"


using namespace std;

const int g_num = 5;
Task t;


class EndPoint
{
public:
    pid_t _child_id;
    int _write_fd;
public:
    EndPoint(pid_t child_fd, int write_fd)
        :_child_id(child_fd)
        ,_write_fd(write_fd)
    {}
};

void WaitCommand()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(command));
        if (n == sizeof(int))
        {
            t.Execute(command);
        }
        else if (n == 0) 
        {
            cout << "父进程让我退出 pid: " << getpid() << endl;
            break;
        }
        else {
            break;
        }
    }
}

int ShowBoard()
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "|               0. 打印任务               |" << std::endl;
    std::cout << "|               1. 日志任务               |" << std::endl;
    std::cout << "|               2. 网络任务               |" << std::endl;
    std::cout << "|               3. 退出任务               |" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "请选择# ";
    int command = 0;
    std::cin >> command;
    return command;
}

void CreateProcess(vector<EndPoint>& end_points)
{
    for (int i = 0; i < g_num; ++i)
    {
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        assert(n == 0);
        (void)n;
        
        // 创建进程
        pid_t id = fork();
        assert(id != -1);
        if (id == 0) 
        {
            close(pipefd[1]);

            dup2(pipefd[0], 0);

            // 等待命令
            WaitCommand();

            close(pipefd[0]);
            exit(0);
        }

        close(pipefd[0]);

        // 父进程写
        end_points.push_back(EndPoint(id, pipefd[1]));
    }
}

void CtrlProcess(vector<EndPoint>& end_points)
{
    int num = 0;
    int cnt = 0;
    while (true)
    {
        int command = ShowBoard();
        if (command == 3) break;
        if (command > 2 || command < 0) continue;

        int index = cnt++;
        cnt %= end_points.size();

        write(end_points[index]._write_fd, &command, sizeof(int));
        sleep(1);
    }
}

void waitProcess(vector<EndPoint>& end_points)
{
    for (const auto &ep : end_points)
    {
        cout << "子进程退出:" << ep._child_id << endl;
        close(ep._write_fd);
    }
    for (const auto &ep : end_points)
    {
        waitpid(ep._child_id, nullptr, 0);
        cout << "回收子进程:" << ep._child_id << endl;
    }
    sleep(2);
}

int main()
{
    vector<EndPoint> end_points;

    CreateProcess(end_points);

    CtrlProcess(end_points);

    waitProcess(end_points);

    return 0;
}