#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>

using std::cout;
using std::endl;

void Help(std::string proc)
{
    std::cout << "\tUsage: \n\t";
    std::cout << proc << " 信号编号 目标进程\n" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        Help(argv[0]);
        exit(2);
    }

    int sig = atoi(argv[1]);
    int pid = atoi(argv[2]);
    int n = kill(pid, sig);
    if (n != 0)
    {
        std::cerr << "error:" << errno << strerror(errno) << endl;
    }
    return 0;
}

// void func_t(int signum)
// {
//     cout << "我是" << signum << "号信号" << endl;
// }


// int main()
// {

//     // 2-- SIGINT
//     signal(SIGINT, func_t);
//     //signal(SIGQUIT, func_t);

//     // for(int i = 1; i <= 31; i++)
//     // {
//     //     signal(i, handler);
//     // }

//     while(true)
//     {
//         std::cout << "我是一个进程，我正在运行 ..., pid: " << getpid() << std::endl;
//         sleep(1);
//     }

//     return 0;
// }