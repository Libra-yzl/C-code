#pragma once

#include <iostream>
#include <vector>


typedef void(*func_t)();

void print_task()
{
    std::cout << "我是打印任务" << std::endl;
}

void log_task()
{
    std::cout << "我是日志任务" << std::endl;
}

void net_task()
{
    std::cout << "我是网络任务" << std::endl;
}

#define COMMAND_PRINT 0
#define COMMAND_LOG 1
#define COMMAND_NET 2

class Task
{
public:
    Task()
    {
        funcs.push_back(print_task);
        funcs.push_back(log_task);
        funcs.push_back(net_task);
    }

    void Execute(int command)
    {
        if (command >= 0 && command < funcs.size()) funcs[command]();
    }
public:
    std::vector<func_t> funcs;
};