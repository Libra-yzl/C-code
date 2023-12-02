#include "prod.hpp"
#include <ctime>
#include "task.hpp"

using namespace std;

void* consumer(void* args)
{
    BlockQueue<Task>* bq = static_cast<BlockQueue<Task>*>(args);

    while (true) {
        // 获取数据
        // sleep(1);

        // int res = 0;
        // bq->pop(&res);
        // std::cout << "consumer" << " : " << res << std::endl;

        // 消费问题
        Task t;
        bq->pop(&t); // 取出问题
        t(); // 调用
        cout << pthread_self() << " | 答案: " << t.Arg() << t.Ret() << endl;
    }

    return nullptr;
}

void* productor(void* args)
{
    BlockQueue<Task>* bq = static_cast<BlockQueue<Task>*>(args);

    string ops = "+-*/^%";
    while (true) {
        // 生产数据
        // sleep(1);

        // int data = rand() % 10 + 1; // 1-10的数字充当数据
        // bq->push(data);
        // std::cout << "productor" << " : " << data << std::endl;

        // 生产问题
        int x = rand()%10+1; // 不会出现0
        int y = rand()%50+1;

        Task t(x, y, ops[rand()%ops.size()]);
        bq->push(t);
        cout << pthread_self() << " | 问题: " << t.Arg() << "?" << endl;
    }

    return nullptr;
}

int main()
{
    srand((uint64_t)time(nullptr) ^ getpid());

    // BlockQueue<int>* bq = new BlockQueue<int>();
    BlockQueue<Task>* bq = new BlockQueue<Task>();

    // std::cout << "ok" << std::endl;

    pthread_t c[2], p[3];
    pthread_create(&c[0], nullptr, consumer, bq);
    pthread_create(&c[1], nullptr, consumer, bq);
    pthread_create(&p[0], nullptr, productor, bq);
    pthread_create(&p[1], nullptr, productor, bq);
    pthread_create(&p[2], nullptr, productor, bq);

    pthread_join(c[0], nullptr);
    pthread_join(c[1], nullptr);
    pthread_join(p[0], nullptr);
    pthread_join(p[1], nullptr);
    pthread_join(p[2], nullptr);

    delete bq;
    return 0;
}


// #include "prod.hpp"
// #include "task.hpp"
// #include <pthread.h>
// #include <unistd.h>
// #include <ctime>

// void *consumer(void *args)
// {
//     BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);
//     while (true)
//     {
//         Task t;
//         // 1. 将数据从blockqueue中获取 -- 获取到了数据
//         bq->pop(&t);
//         t();
//         // 2. 结合某种业务逻辑，处理数据！ -- TODO
//         std::cout << pthread_self() << " | consumer data: " << t.formatArg() << t.formatRes() << std::endl;
//     }
// }

// void *productor(void *args)
// {
//     BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);
//     std::string opers = "+-*/%";
//     while (true)
//     {
//         // sleep(1);
//         // 1. 先通过某种渠道获取数据
//         int x = rand() % 20 + 1;
//         int y = rand() % 10 + 1;
//         char op = opers[rand() % opers.size()];
//         // 2. 将数据推送到blockqueue -- 完成生产过程
//         Task t(x, y, op);
//         bq->push(t);
//         std::cout << pthread_self() << " | productor Task: " <<  t.formatArg() << "?" << std::endl;
//     }
// }

// int main()
// {
//     srand((uint64_t)time(nullptr) ^ getpid());
//     // BlockQueue<int> *bq = new BlockQueue<int>();
//     BlockQueue<Task> *bq = new BlockQueue<Task>();
//     // 单生产和单消费 -> 多生产和多消费
//     pthread_t c[2], p[3];
//     pthread_create(&c[0], nullptr, consumer, bq);
//     pthread_create(&c[1], nullptr, consumer, bq);
//     pthread_create(&p[0], nullptr, productor, bq);
//     pthread_create(&p[1], nullptr, productor, bq);
//     pthread_create(&p[2], nullptr, productor, bq);

//     pthread_join(c[0], nullptr);
//     pthread_join(c[1], nullptr);
//     pthread_join(p[0], nullptr);
//     pthread_join(p[1], nullptr);
//     pthread_join(p[2], nullptr);
//     delete bq;
//     return 0;
// }