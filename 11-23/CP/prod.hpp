#pragma once

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <queue>


template <class T>
class BlockQueue
{
public:
    BlockQueue()
    {}

    void push()
    {}

    void pop()
    {}

    ~BlockQueue()
    {}

private:
    std::queue<T> _q;
    int _cap; // 队列容量
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
};