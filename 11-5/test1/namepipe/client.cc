#include <iostream>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <cassert>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "comm.hpp"

int main()
{
    int fd = open(fifoname.c_str(), O_WRONLY);
    if (fd < 0)
    {
        std::cerr << errno << ":" << strerror(errno) << std::endl;
        return 1;
    }
    // std::cout << fd << std::endl;
    char buff[NUM];
    while (true)
    {
        std::cout << "请输入消息:";
        char* msg = fgets(buff, sizeof(buff), stdin);
        assert(msg);
        (void)msg;
        
        ssize_t n = write(fd, buff, sizeof(buff)-1);
        assert(n >= 0);
        (void)n;
    }

    close(fd);
    return 0;
}