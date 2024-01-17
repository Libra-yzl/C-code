#pragma once

#include <iostream>
#include <vector>
#include <semaphore.h>

static const int N = 5;

template <class T>
class RingQueue
{
private:
    void P(sem_t &s)
    {
        sem_wait(&s);
    }
    void V(sem_t &s)
    {
        sem_post(&s);
    }

public:
    RingQueue(int n = N)
        :_capacity(n)
        ,_ring(n)
    {
        sem_init(&_data_sem, 0, 0);
        sem_init(&_space_sem, 0, n);
        _p_index = _c_index = 0; // 初始化为0
        pthread_mutex_init(&_p_mutex, nullptr);
        pthread_mutex_init(&_c_mutex, nullptr);
    }

    void push(const T& data)
    {
        // 生产
        // P
        P(_space_sem);
        pthread_mutex_lock(&_p_mutex);
        // 申请失败阻塞
        _ring[_p_index++] = data;
        _p_index %= _capacity;
        // V
        V(_data_sem);
        pthread_mutex_unlock(&_p_mutex);
    }

    void pop(T* out)
    {
        P(_data_sem);
        pthread_mutex_lock(&_c_mutex);
        *out = _ring[_c_index++];
        _c_index %= _capacity;
        V(_space_sem);
        pthread_mutex_unlock(&_c_mutex);
    }

    ~RingQueue()
    {
        sem_destroy(&_data_sem);
        sem_destroy(&_space_sem);
    }

private:
    std::vector<T> _ring;
    sem_t _data_sem; // 资源
    sem_t _space_sem; // 空间
    int _capacity; // 容器大小

    int _p_index; // 生产者位置
    int _c_index; // 消费者位置

    pthread_mutex_t _p_mutex;
    pthread_mutex_t _c_mutex;
};