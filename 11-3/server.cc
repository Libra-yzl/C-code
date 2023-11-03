#include <iostream>
#include "dec.hpp"

using namespace std;

//2.
int main()
{
    shmInit sit(SERVER);
    int cnt = 0;
    char *start = sit.retStart();
    while (cnt < 30)
    {
        cout << "msg:" << start << endl;
        sleep(1);
        ++cnt;
    }

    return 0;
}

// 1. 
// int main()
// {
//     // 1.创建key
//     key_t k = getKey();
//     cout << "server key: " << toHex(k) << endl;

//     // 2.创建共享内存
//     int id = createShm(k, g_size);
//     cout << "server shmid: " << id << endl;

//     // 3.将自己和共享内存关联起来
//     char* start = attachShm(id);

//     // 通信
//     int cnt = 0;
//     while (cnt < 26)
//     {
//         cout << "msg:" << start << endl;
//         sleep(1);
//         ++cnt;
//     }

//     // 4.取消关联
//     detachShm(start);

//     // 5.释放共享内存
//     deleteShm(id);
//     return 0;
// }