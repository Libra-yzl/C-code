#include "mythread.hpp"

using namespace std;

void thread_func(void* args)
{
    string msg = static_cast<const char*>(args);
    int cnt = 10;
    while (cnt)
    {
        cout << "我是一个线程, " << msg << ", cnt: " << cnt-- << endl;
        sleep(1);
    }
}

int main()
{
    Thread t1(1, thread_func, (void*)"hello world!");
    Thread t2(2, thread_func, (void*)"你好 未来!");
    Thread t3(3, thread_func, (void*)"你好 世界!");
    

    cout << "name: " << t1.thread_name() << ", thread_id: " << t1.thread_id() << ", thread_status: " << t1.status() << endl;
    cout << "name: " << t2.thread_name() << ", thread_id: " << t2.thread_id() << ", thread_status: " << t2.status() << endl;
    cout << "name: " << t3.thread_name() << ", thread_id: " << t3.thread_id() << ", thread_status: " << t3.status() << endl;
    
    t1.run();
    t2.run();
    t3.run();

    cout << "name: " << t1.thread_name() << ", thread_id: " << t1.thread_id() << ", thread_status: " << t1.status() << endl;
    cout << "name: " << t2.thread_name() << ", thread_id: " << t2.thread_id() << ", thread_status: " << t2.status() << endl;
    cout << "name: " << t3.thread_name() << ", thread_id: " << t3.thread_id() << ", thread_status: " << t3.status() << endl;  
    
    t1.join();
    t2.join();
    t3.join();
    
    cout << "name: " << t1.thread_name() << ", thread_id: " << t1.thread_id() << ", thread_status: " << t1.status() << endl;
    cout << "name: " << t2.thread_name() << ", thread_id: " << t2.thread_id() << ", thread_status: " << t2.status() << endl;
    cout << "name: " << t3.thread_name() << ", thread_id: " << t3.thread_id() << ", thread_status: " << t3.status() << endl;

    return 0;
}