#include "RingQueue.hpp"
#include <iostream>
#include <pthread.h>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <memory>


using namespace std;


void* custmorRountine(void* args)
{
    RingQueue<int>* rq = static_cast<RingQueue<int>*>(args);
    while (true)
    {
        int data = 0;
        rq->pop(&data);
        cout << "custmor done." << data << endl;
        sleep(1);
    }
}

void* proctorRountine(void* args)
{
    RingQueue<int>* rq = static_cast<RingQueue<int>*>(args);
    while (true)
    {
        int data = rand() % 100 + 1;
        rq->push(data);
        cout << "proctor done." << data << endl;
    }
}

int main()
{
    srand(time(nullptr));
    RingQueue<int>* rq = new RingQueue<int>();
    // 单生产消费
    // pthread_t c, p;
    // pthread_create(&c, nullptr, custmorRountine, rq);
    // pthread_create(&p, nullptr, proctorRountine, rq);

    // pthread_join(c, nullptr);
    // pthread_join(p, nullptr);

    pthread_t c[3], p[2];
    for (int i = 0; i < 3; ++i)
        pthread_create(c+i, nullptr, custmorRountine, rq);
    for (int i = 0; i < 2; ++i)
        pthread_create(p+i, nullptr, proctorRountine, rq);

    for (int i = 0; i < 3; ++i)
        pthread_join(c[i], nullptr);   
    for (int i = 0; i < 2; ++i)
        pthread_join(p[i], nullptr);

    return 0;
}