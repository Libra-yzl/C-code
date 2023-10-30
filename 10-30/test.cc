#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
  pid_t id = fork();
  if (id == 0)
  {
    cout << "你好 我是子进程" << endl;
    cout << "我没有进行程序替换" << endl;
    exit(107);
  }
  cout << "你好 我是父进程" << endl;
  int status = 0;
  waitpid(id, &status, 0);
  cout << "exit signal: " << (status & 0x7f) << "  exit code: " << ((status >> 8) & 0xff) << endl;
  return 0;
}
