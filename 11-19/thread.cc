#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <vector>



using namespace std;

#define NUM 10

class Thread
{
public:
    Thread(const char* name, int id, uint64_t create_time)
        :_name(name), _id(id), _create_time(create_time)
    {}

    ~Thread()
    {}

    const char* name() { return _name.c_str(); }
    const int id() { return _id; }
    const uint64_t create_time() { return _create_time; }

private:
    string _name;
    int _id;
    uint64_t _create_time;
};

// void* thread_func(void* arg)
// {
//     const char* name = (const char*)arg;

//     int cnt = 5;
//     while (cnt--) {
//         cout << name << "正在运行" << " myid:" << pthread_self() << endl;
//         sleep(1);
//     }

//     pthread_exit((void*)107);
//     // return nullptr;
// }

// int main()
// {
//     pthread_t t1;
//     pthread_create(&t1, nullptr, thread_func, (void*)"t1");

//     void* ret = nullptr;
//     pthread_join(t1, &ret);
//     cout << "t1 return:" << (int64_t)ret << " 退出的thread:" << t1 << endl;
//     return 0;
// }

void* thread_func(void* arg)
{
    Thread* td = static_cast<Thread*>(arg);
    
    while (true)
    {
        cout << "线程正在运行 name:" << td->name() << " time:" << td->create_time() << " id:" << td->id() << endl;
        sleep(5);
        
        break;
    }
    
    pthread_exit(static_cast<void*>(td));
    // return nullptr;
}

int main()
{
    pthread_t thread[NUM];
    // vector<pthread_t> thread;

    // 创建线程
    for (int i = 0; i < NUM; i++) {
        char tname[64] = {0};
        snprintf(tname, 64, "thread-%d", i+1);
        Thread* td = new Thread(tname, i+1, time(nullptr));
        pthread_create(thread+i, nullptr, thread_func, td);

        sleep(1);
    }

    // 回收线程
    void* ret = nullptr;
    for (int i = 0; i < NUM; ++i) {
        int n = pthread_join(thread[i], &ret); // 线程等待
        if (n != 0) cerr << "pthread_join error" << endl;
        Thread *td = static_cast<Thread*>(ret);
        delete td;
    }
    cout << "所有线程已经退出" << endl;

    return 0;
}