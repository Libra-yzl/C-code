#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>


using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

const int num = 5;

void* func(void* args)
{
    string name = static_cast<const char*>(args);

    while (true)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        cout << name << "活动..." << endl;
        pthread_mutex_unlock(&mutex);
    }
    
    return nullptr;
}

int main()
{
    pthread_t ts[num];
    for (int i = 0; i < num; ++i)
    {
        char* name = new char[64];
        snprintf(name, 64, "thread-%d", i+1);
        pthread_create(ts+i, nullptr, func, name);
    }

    sleep(3);

    while (true) {
        cout << "主线程唤醒线程" << endl;
        // pthread_cond_broadcast(&cond); // 全部唤醒
        pthread_cond_signal(&cond);
        sleep(1);
    }

    for (int i = 0; i < num; ++i)
    {
        pthread_join(ts[i], nullptr);
    }
    return 0;
}


// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// void* func(void* args)
// {
//     cout << " 我是新进程 " << endl;

//     pthread_mutex_lock(&mutex);
//     cout << " 我申请了锁 " << endl;

//     pthread_mutex_lock(&mutex);
//     cout << " 我又申请锁了 " << endl;

//     return nullptr;
// }

// int main()
// {
//     pthread_t t;
    
//     pthread_create(&t, nullptr, func, nullptr);

//     sleep(3);

//     cout << " 主线程开始解锁... " << endl;
//     pthread_mutex_unlock(&mutex);
//     cout << " 主线程解锁完成... " << endl;

//     sleep(3);
//     pthread_join(t, nullptr);

//     return 0;
// }