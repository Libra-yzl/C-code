#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX 1024
#define ARGC 32
#define SPE " "

int split(char* commandstr, char* argv[])
{
    assert(commandstr);
    assert(argv);

    argv[0] = strtok(commandstr, SPE);
    if (argv[0] == NULL) return -1;
    int i = 0;
    while (argv[++i] = strtok(NULL, SPE));
    argv[i] = NULL;
    return 0;
}

int main()
{
    while (1)
    {
        printf("[root@cloud currpath]# ");
        fflush(stdout);
        // 获取字符串
        char commandstr[MAX] = "\0";
        char* argv[ARGC] = {NULL};
        char* s = fgets(commandstr, sizeof(commandstr), stdin);
        (void) s;
        // 处理'\n'
        commandstr[strlen(commandstr)-1] = '\0';

        // 处理字符串
        int n = split(commandstr, argv);
        if (n != 0) continue;

        // 添加配色方案
        if (strcmp(argv[0], "ls") == 0){
            // 将字符串最后添加"--color=auto"
            int pos = 0;
            while (argv[pos] != NULL) ++pos;
            argv[pos] = "--color=auto";
            argv[++pos] = NULL;
        }
        // 创建子进程
        pid_t id = fork();
        if (id == 0){
            // 子进程
            execvp(argv[0], argv);
            exit(-1);
        }
        // 父进程
        int status = 0;
        pid_t ret_id = waitpid(id, &status, 0);
        //printf("%s\n", commandstr);
        //sleep(1);
    }
    return 0;
}