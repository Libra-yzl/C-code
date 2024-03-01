#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <cstdlib>

namespace udp_server
{
    enum UDP_ERR
    {
        SOCKET_ERR = 1,
        BIND_ERR
    };

    class UdpServer
    {
    public:
        UdpServer(uint16_t port, std::string ip):_port(port), _ip(ip)
        {

        }
        void InitServer()
        {
            // 1.创建socket接口
            _sock = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sock < 0)
            {
                std::cerr << "创建socket失败: " << strerror(errno) << std::endl;
                exit(SOCKET_ERR);
            }
            std::cout << "创建socket成功: " << _sock << " (文件描述符)" << std::endl;

            // 2.给服务器指明IP和Port
            struct sockaddr_in local;
            bzero(&local, sizeof(local));

            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            local.sin_addr.s_addr = inet_addr(_ip.c_str()); // 将_ip转化为int 将本地序列抓换为网络序列

            if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
            {
                std::cerr << "绑定失败: " << strerror(errno) << std::endl;
                exit(BIND_ERR);
            }
            std::cout << "绑定成功: " << _sock << " (文件描述符)" << std::endl;
        }

        void Start()
        {

        }
        ~UdpServer(){}

    private:
        int _sock;
        uint16_t _port;
        std::string _ip;
    };
}