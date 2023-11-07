#include <iostream>
#include <signal.h>
#include <cassert>
#include <unistd.h>

using namespace std;

static void printPending(const sigset_t& pending)
{
    cout << "进程pending位图 : ";
    for (int i = 1; i <= 31; ++i) {
        if (sigismember(&pending, i)) cout << "1";
        else cout << '0';
    }
    cout << endl;
}

void handler(int signo)
{
    cout << signo << "号信号捕捉" << endl;
    sigset_t pending;
    sigemptyset(&pending);
    sigpending(&pending);
    printPending(pending);
    sleep(1);
}

int main()
{
    sigset_t set, oset;
    signal(2, handler);

    // 初始化
    sigemptyset(&set);
    sigemptyset(&oset);

    // 将2号信号添加到set中
    sigaddset(&set, 2);

    // 将新的信号屏蔽字设置进程
    sigprocmask(SIG_BLOCK, &set, &oset);

    // 获取pending表位图
    int cnt = 0;
    while (true) 
    {
        // 获取pending信号集
        sigset_t pending;
        sigemptyset(&pending);

        int n = sigpending(&pending);
        assert(n==0);
        (void)n;

        // 打印
        printPending(pending);
        sleep(1);
        if (cnt++ == 10) {
            cout << "解除对2号信号的屏蔽" << endl;
            sigprocmask(SIG_SETMASK, &oset, nullptr);
        }
    }

    return 0;
}