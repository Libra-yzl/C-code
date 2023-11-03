#include <iostream>
#include "dec.hpp"


using namespace std;

//2.
int main()
{
    shmInit sit(CLIENT);
    char c = 'A';
    char* start = sit.retStart();
    while (c <= 'Z')
    {
        start[c-'A'] = c;
        cout << start << endl;
        ++c;
        start[c-'A'] = 0;
        sleep(1);
    }

    return 0;
}

// 1.
// int main()
// {
//     // 1.创建key
//     key_t k = getKey();
//     cout << "client key: " << toHex(k) << endl;

//     // 2.获取共享内存
//     int id = getShm(k, g_size);
//     cout << "client shmid: " << id << endl;

//     // 3.将自己和共享内存关联起来
//     char* start = attachShm(id);

//     // 通信
//     char c = 'A';
//     while (c <= 'Z')
//     {
//         start[c-'A']=c;
//         ++c;
//         start[c-'A']=0;
//         sleep(1);
//     }

//     // 4.取消关联
//     detachShm(start);

//     return 0;
// }