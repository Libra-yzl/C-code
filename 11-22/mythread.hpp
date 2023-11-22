#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <cstdlib>

class Thread
{
typedef void (*func_t)(void* args);
enum Status { NOT=0, RUNNED, EXITED};

public:
    Thread(int num, func_t func, void *args)
        :_id(0)
        ,_func(func)
        ,_args(args)
        ,_status(NOT)
    {
        char name[64];
        snprintf(name, 64, "thread-%d", num);
        _name = name;
    }

    ~Thread()
    {}

    pthread_t thread_id() 
    {
        if (_status == RUNNED) 
            return _id;
        else 
            return 0; 
    }
    std::string thread_name() { return _name; }
    int status() { return _status; }

    // 注意这里有个隐含的形参this指针 与需要调用执行方法的参数不匹配 -加static
    // 加上static之后 无法访问类内属性 因此在传参时传this
    static void* threadRoutine(void* args)
    {
        Thread* ts = static_cast<Thread*>(args);
        ts->_func(ts->_args);

        return nullptr;
    }

    void run()
    {
        int n = pthread_create(&_id, nullptr, threadRoutine, this);
        if (n != 0) 
        {
            std::cerr << "name: " << _name << " create error" << std::endl;
            exit(-1);
        }

        _status = RUNNED;
    }

    void join()
    {
        int n = pthread_join(_id, nullptr);
        if ( n != 0) 
        {
            std::cerr << "name: " << _name << " join error" << std::endl;
            exit(-1);
        }
        _status = EXITED;
    }

private:
    std::string _name; // 线程名
    pthread_t _id; // 线程id
    Status _status;
    func_t _func; // 执行流要执行的回调函数
    void* _args; // 参数
};