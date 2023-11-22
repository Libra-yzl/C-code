#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "mythread.hpp"
#include "mymutex.hpp"

using namespace std;

int tickets = 1000;    // 临界资源
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

void threadRoutine(void *name)
{
    string tname = static_cast<const char *>(name);

    while (true)
    {
        // pthread_mutex_lock(&mutex);
        {
            lockGuard lockguard(&mutex);
            if (tickets > 0)
            {
                usleep(2000); // 模拟抢票花费的时间
                cout << tname << " 抢票成功: " << tickets-- << endl;
                // pthread_mutex_unlock(&mutex);
            }
            else
            {
                // pthread_mutex_unlock(&mutex);
                break;
            }
        }

        usleep(1000); // 模拟抢完票之后的动作
    }
}

int main()
{
    Thread t1(1, threadRoutine, (void *)"t1!");
    Thread t2(2, threadRoutine, (void *)"t2!");
    Thread t3(3, threadRoutine, (void *)"t3!");
    Thread t4(4, threadRoutine, (void *)"t4!");

    t1.run();
    t2.run();
    t3.run();
    t4.run();

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}

// int main()
// {
//     pthread_mutex_init(&mutex, nullptr);

//     pthread_t t[4];
//     int n = sizeof(t)/sizeof(t[0]);
//     for(int i = 0; i < n; i++)
//     {
//         char *data = new char[64];
//         snprintf(data, 64, "thread-%d", i+1);
//         pthread_create(t+i, nullptr, threadRoutine, data);
//     }

//     for(int i = 0; i < n; i++)
//     {
//         pthread_join(t[i], nullptr);
//     }

//     pthread_mutex_destroy(&mutex);
//     return 0;
// }