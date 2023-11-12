#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int g_val = 0;

void* func1(void* args)
{
    while (true)
    {
        sleep(1);
        cout << "t1..." << getpid()  << " &g_val: " << &g_val << " , g_val: " << g_val++ << endl;
    }
}

void* func2(void* args)
{
    while (true)
    {
        sleep(1);
        cout << "t2..." << getpid()  << " &g_val: " << &g_val << " , g_val: " << g_val << endl;
    }
}

int main()
{
    pthread_t t1, t2, t3;
    pthread_create(&t1, nullptr, func1, nullptr);
    pthread_create(&t2, nullptr, func2, nullptr);
    while (true)
    {
        sleep(1);
        cout << "main thread..." << getpid()  << " &g_val: " << &g_val << " , g_val: " << g_val << endl;
    }
    return 0;
}