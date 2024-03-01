#include "udp_server.hpp"
#include <iostream>
#include <memory>

using namespace std;
using namespace udp_server;

int main()
{
    unique_ptr<UdpServer> usvr(new UdpServer(8082, "1.1.1.1"));
    usvr->InitServer();
    usvr->Start();
    cout << "hello udp_server" << endl;
    return 0;
}