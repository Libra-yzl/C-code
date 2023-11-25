#include "prod.hpp"
#include <ctime>
using namespace std;

void* consumer(void* args)
{
    BlockQueue<int>* bq = static_cast<BlockQueue<int>*>(args);

    while (true) {
        // 获取数据
        // sleep(1);

        int res = 0;
        bq->pop(&res);
        std::cout << "consumer" << " : " << res << std::endl;
    }

    return nullptr;
}

void* productor(void* args)
{
    BlockQueue<int>* bq = static_cast<BlockQueue<int>*>(args);
    
    while (true) {
        // 生产数据
        sleep(3);

        int data = rand() % 10 + 1; // 1-10的数字充当数据
        bq->push(data);
        std::cout << "productor" << " : " << data << std::endl;
    }

    return nullptr;
}

int main()
{
    srand((uint64_t)time(nullptr) ^ getpid());

    BlockQueue<int>* bq = new BlockQueue<int>();

    // std::cout << "ok" << std::endl;

    pthread_t c, p;
    pthread_create(&c, nullptr, consumer, bq);
    pthread_create(&p, nullptr, productor, bq);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    delete bq;
    return 0;
}