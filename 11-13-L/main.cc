#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* func1(void* para)
{
    while (true) {
        cout << "我是t1线程 pid:" << getpid() << endl;
        sleep(1);
    }
}

void* func2(void* para)
{
    while (true) {
        sleep(5);
        cout << "我是t2线程 pid:" << getpid() << endl;
        char* str = "hello";
        *str = 'H';
    }
}

int main()
{
    pthread_t t1, t2, t3;
    pthread_create(&t1, nullptr, func1, nullptr);
    pthread_create(&t2, nullptr, func2, nullptr);

    while (true) {
        cout << "我是主线程 pid:" << getpid() << endl;
        sleep(1);
    }
    return 0;
}