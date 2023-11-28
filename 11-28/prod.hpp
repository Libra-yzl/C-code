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


// #pragma once

// #include <iostream>
// #include <queue>
// #include <pthread.h>

// const int gcap = 5;

// // 不要认为，阻塞队列只能放整数字符串之类的
// // 也可以放对象
// template <class T>
// class BlockQueue
// {
// public:
//     BlockQueue(const int cap = gcap):_cap(cap)
//     {
//         pthread_mutex_init(&_mutex, nullptr);
//         pthread_cond_init(&_consumerCond, nullptr);
//         pthread_cond_init(&_productorCond, nullptr);
//     }
//     bool isFull(){ return _q.size() == _cap; }
//     bool isEmpty() { return _q.empty(); }
//     void push(const T &in)
//     {
//         pthread_mutex_lock(&_mutex);
//         // 细节1：一定要保证，在任何时候，都是符合条件，才进行生产
//         while(isFull()) // 1. 我们只能在临界区内部，判断临界资源是否就绪！注定了我们在当前一定是持有锁的！
//         {
//             // 2. 要让线程进行休眠等待，不能持有锁等待！
//             // 3. 注定了，pthread_cond_wait要有锁的释放的能力！
//             pthread_cond_wait(&_productorCond, &_mutex); // 我休眠(切换)了，我醒来的时候，在哪里往后执行呢？
//             // 4. 当线程醒来的时候，注定了继续从临界区内部继续运行！因为我是在临界区被切走的！
//             // 5. 注定了当线程被唤醒的时候，继续在pthread_cond_wait函数出向后运行，又要重新申请锁，申请成功才会彻底返回
//         }
//         // 没有满的，就要让他进行生产
//         _q.push(in);
//         // 加策略
//         // if(_q.size() >= _cap/2) 
//         pthread_cond_signal(&_consumerCond);
//         pthread_mutex_unlock(&_mutex);
//         // pthread_cond_signal(&_consumerCond);
//     }
//     void pop(T *out)
//     {
//         pthread_mutex_lock(&_mutex);
//         while(isEmpty()) 
//         {
//             pthread_cond_wait(&_consumerCond, &_mutex);
//         }
//         *out = _q.front();
//         _q.pop();
//         // 加策略
//         pthread_cond_signal(&_productorCond);
//         pthread_mutex_unlock(&_mutex);
//     }
//     ~BlockQueue()
//     {
//         pthread_mutex_destroy(&_mutex);
//         pthread_cond_destroy(&_consumerCond);
//         pthread_cond_destroy(&_productorCond);
//     }
// private:
//     std::queue<T> _q;
//     int _cap;
//     // 为什么我们的这份代码，只用一把锁呢，根本原因在于，
//     // 我们生产和消费访问的是同一个queue&&queue被当做整体使用！
//     pthread_mutex_t _mutex; 
//     pthread_cond_t _consumerCond;   // 消费者对应的条件变量，空，wait
//     pthread_cond_t _productorCond;  // 生产者对应的条件变量，满，wait
// };