#include <iostream>
#include <pthread.h>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <string>

// #include <thread>   
using namespace std;

// string toHex(pthread_t id)
// {
//     char buffer[128] = {0};
//     snprintf(buffer, sizeof buffer, "0x%x", id);
//     return buffer;
// }

// void* thread_func(void* names)
// {
//     string tname = static_cast<const char*>(names);

//     while (true) {
//         // cout << tname << " : " << pthread_self() << endl;
//         cout << tname << " : " << toHex(pthread_self()) << endl;
//         sleep(1);
//     }
//     return nullptr;
// }

// int main()
// {
//     pthread_t t;
//     pthread_create(&t, nullptr, thread_func, (void*)"th 1");

//     int n = pthread_join(t, nullptr);
//     if (n != 0)
//     {
//         cerr << n << " : " << strerror(n) << endl;
//     }
//     return 0;
// }

// void run1()
// {
//     while(true)
//     {
//         cout << "thread 1" << endl;
//         sleep(1);
//     }
// }
// void run2()
// {
//     while(true)
//     {
//         cout << "thread 2" << endl;
//         sleep(1);
//     }
// }
// void run3()
// {
//     while(true)
//     {
//         cout << "thread 3" << endl;
//         sleep(1);
//     }
// }


// int main()
// {
//     thread th1(run1);
//     thread th2(run2);
//     thread th3(run3);

//     th1.join();
//     th2.join();
//     th3.join();

//     return 0;
// }


// 共享资源 临界资源
int tickets = 10000;

// 申请锁
pthread_mutex_t mutex;

void* ticket(void* name)
{
    string tname = static_cast<const char*>(name);
    while (true) {
        // 加锁
        pthread_mutex_lock(&mutex);
        if (tickets > 0) {
            // 抢票
            usleep(1000);
            cout << tname << " : " << tickets-- << endl;
            pthread_mutex_unlock(&mutex);
        }
        else {
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    return nullptr;
}

int main()
{
    // 创建三个线程进行模拟抢票
    pthread_t t[3];
    for (int i = 0; i < sizeof(t) / sizeof(t[0]); ++i) {
        char* name = new char[64];
        snprintf(name, 64, "thread-%d", i+1);
        pthread_create(t+i, nullptr, ticket, name);
    }

    // 等待线程
    for (int i = 0; i < sizeof(t) / sizeof(t[0]); ++i) {
        pthread_join(t[i], nullptr);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}