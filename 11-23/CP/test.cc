#include "prod.hpp"


void* consumer(void* args)
{
    BlockQueue<int>* bq = static_cast<BlockQueue<int>*>(args);

    while (true) {
        // 获取数据
    }

    return nullptr;
}

void* productor(void* args)
{
    BlockQueue<int>* bq = static_cast<BlockQueue<int>*>(args);
    
    while (true) {
        // 生产数据
    }

    return nullptr;
}

int main()
{
    BlockQueue<int>* bq = new BlockQueue<int>();

    pthread_t c, p;
    pthread_create(&c, nullptr, consumer, nullptr);
    pthread_create(&p, nullptr, productor, nullptr);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    delete bq;
    return 0;
}