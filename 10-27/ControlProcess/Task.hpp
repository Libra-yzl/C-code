#pragma once
#include <iostream>
#include <vector>  

using namespace std;

typedef void(*fun_t)();

void PrintLog()
{
    cout << "打印日志任务 正在被执行..." << endl;
}

void InsertMySQL()
{
    cout << "数据库任务 正在被执行..." << endl;
}

void NetRequest()
{
    cout << "网络请求任务 正在被执行..." << endl;
}

#define COMMAND_LOG 0
#define COMMAND_MYSQL 1
#define COMMAND_REQEUST 2


class Task
{
public:
    Task()
    {
        funcs.push_back(PrintLog);
        funcs.push_back(InsertMySQL);
        funcs.push_back(NetRequest);
    }

    void Execute(int command)
    {
        if (command >= 0 && command <= funcs.size()) funcs[command]();
    }

    ~Task()
    {}

public:
    std::vector<fun_t> funcs;
};