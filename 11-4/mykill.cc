#include <iostream>
#include <unistd.h>


int main()
{
    while (true)
    {
        std::cout << "我的pid是:" << getpid() << std::endl;
        sleep(1);
    }
    return 0;
}