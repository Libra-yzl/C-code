#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
using std::cout;
using std::endl;


int main()
{
    int pipefd[2] = {0};
    // 1.创建管道
    int n = pipe(pipefd);
    if (n < 0) {
        cout << "pipe error" << " : " << strerror(errno) << endl;
        return 1;
    }
    
    cout << "pipefd[0]: " << pipefd[0] << endl; 
    cout << "pipefd[1]: " << pipefd[1] << endl; 

    // 2.创建子进程
    pid_t id = fork();
    if (id < 0) {
        cout << "fork error" << " : " << strerror(errno) << endl;
    }
    else if (id == 0) {
        // 子进程
        // 3.关闭没用的fd (子进程写入 父进程读取)
        close(pipefd[0]);
        // 4.写入
        const std::string str1 = "hello I am child!";
        int cnt = 0;
        char buffer[1024];
        while (1)
        {
            // 写入过程
            snprintf(buffer, sizeof(buffer), "%s 计数器:%d pid:%d\n", str1.c_str(), cnt++, getpid());
            write(pipefd[1], buffer, strlen(buffer));
            sleep(1);
        }
        exit(-1);
    }
    else {
        // 3.关闭没用的fd
        close(pipefd[1]);
        // 4.读取
        char buffer[1024] = {0};
        int cnt = 0;
        while (1) {
            int n = read(pipefd[0], buffer, sizeof(buffer)-1);
            if (n > 0) {
                buffer[n] = '\0';
                cout << "我是父进程 子进程给我的信息: " << buffer << endl;
            }
            else if (n == 0) {
                cout << "我是父进程 我读到了信息结束" << endl;
                break;
            }
            else {
                cout << "我是父进程 我读取异常了" << endl;
            }
        }

        int status = 0;
        pid_t ret_id = waitpid(id, &status, 0);
        cout << "child exit code:" << ((status << 8) & 0xff) << endl;
    }

    return 0;
}