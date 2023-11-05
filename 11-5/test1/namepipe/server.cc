#include <iostream>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "comm.hpp"


using std::cout;
using std::endl;

int main()
{
    umask(0);
    int n = mkfifo(fifoname.c_str(), mode);
    if (n != 0) 
    {
        cout << errno << ":" << strerror(errno) << endl;
        exit(-1);
    }
    std::cout << "create fifo file success" << std::endl;
    int fd = open(fifoname.c_str(), O_RDONLY);
    if (fd < 0) 
    {
        cout << errno << ":" << strerror(errno) << endl;
        exit(-1);
    }
    std::cout << "open fifo success, begin ipc" << std::endl;

    char buff[NUM] = {0};
    while (true)
    {
        ssize_t n = read(fd, buff, sizeof(buff)-1);
        if(n > 0)
        {
            buff[n] = 0;
            //std::cout << "client# " << buffer << std::endl;
            printf("%s\n", buff);
            //fflush(stdout);
        }
        else if(n == 0)
        {
            std::cout << "客户端退出 我也退出" << std::endl;
            break;
        }
        else 
        {
            std::cout << errno << " : " << strerror(errno) << std::endl;
            break;
        }
    }
    // 关闭不要的fd
    // close(fd);

    // unlink(fifoname.c_str());
    return 0;
}