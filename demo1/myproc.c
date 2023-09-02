#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork();
    assert(id >= 0);
    if (id == 0)
    {
    //    printf("begin..............\n");
    //    printf("begin..............\n");
    //    printf("begin..............\n");
    //    printf("begin..............\n");
    //   
    //    execl("/bin/ls", "ls", "-a", "-l", NULL);
    //    printf("end................\n");
    //    printf("end................\n");
    //    printf("end................\n");
    //    printf("end................\n");
        char* const argv[] = {
            "lssdja",
            "-a",
            "-l",
            NULL
        };
       // execv("/bin/lsiha", argv);
        //execvp("lsdjia", argv);
        //execl("/bin/ls", "-a", "-l", "-lsdan");
        char* const myenv[] = {
            "MYENV=YouCanSeeMe",
            NULL
        };
        extern char** environ;
        //execle("../other/test", "test", NULL, myenv);
        execle("../other/test", "test", NULL, environ);
        printf("我是子进程, pid: %d\n", getpid());
        exit(3);
    }
    //father
    sleep(1);
    int status = 0;
    printf("我是父进程, %d\n", getpid());
    waitpid(id, &status, 0);
    printf("child exit code: %d\n", WEXITSTATUS(status));
    return 0;
}
