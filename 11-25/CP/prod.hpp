#pragma once

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <queue>

using namespace std;

const int gcap = 5;

template <class T>
class BlockQueue
{
public:
    BlockQueue(const int cap=gcap): _cap(cap)
    {
        pthread_mutex_init(&_mutex, nullptr);
        pthread_cond_init(&_consumerCond, nullptr);
        pthread_cond_init(&_productorCond, nullptr);
    }

    bool isfull() { return _q.size() == _cap; }

    bool isempty() { return _q.empty(); }
    
    void push(const T& in)
    {
        // 访问临界资源
        pthread_mutex_lock(&_mutex);

        // while循环确保在任何时候 只有符合条件才能继续执行
        while (isfull())
        {
            pthread_cond_wait(&_productorCond, &_mutex);
        }
        _q.push(in);
        // 唤醒消费者 可以加例如生产1/2之后在唤醒
        pthread_cond_signal(&_consumerCond);

        pthread_mutex_unlock(&_mutex);
    }

    void pop(T* out)
    {
        pthread_mutex_lock(&_mutex);

        while (isempty())
        {
            pthread_cond_wait(&_consumerCond, &_mutex);
        }
        // 获得数据
        *out = _q.front();
        _q.pop();

        // 唤醒生产者
        pthread_cond_signal(&_productorCond);

        pthread_mutex_unlock(&_mutex);
    }

    ~BlockQueue()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_consumerCond);
        pthread_cond_destroy(&_productorCond);
    }

private:
    std::queue<T> _q;
    int _cap; // 队列容量
    pthread_mutex_t _mutex;
    pthread_cond_t _consumerCond; // 消费者的条件变量
    pthread_cond_t _productorCond; // 生产者的条件变量
};