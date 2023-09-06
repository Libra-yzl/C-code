#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX 1024
#define ARGC 64
#define SEP " "

int split(char* commandstr, char* argv[])
{
    assert(commandstr && argv);

    argv[0] = strtok(commandstr, SEP);
    if (argv[0] == NULL) return -1;
    int pos = 1;
    while (argv[pos++] = strtok(NULL, SEP));
    return 0;
}

void debugPrint(char *argv[])
{
    int i = 0;
    for(; argv[i]; i++)
    {
        printf("%d: %s\n", i, argv[i]);
    }
}

int main()
{
    //命令行
    while (1)
    {
        char commandstr[MAX]={0};
        char* argv[ARGC] = {NULL};
        printf("[user@ cloud curpath]# ");
        fflush(stdout);

        //获取指令字符串
        char* s = fgets(commandstr,sizeof(commandstr),  stdin);
        assert(s);
        //消除'\n'
        commandstr[strlen(commandstr)-1] = '\0';
        //切割字符串
        int ret = split(commandstr, argv);
        if (ret != 0) continue;
        //debugPrint(argv);
        //运行指令
        if (strcmp(argv[0], "cd") == 0)
        {
            if (argv[1] != NULL) chdir(argv[1]);
            continue;
        }

        if (strcmp(argv[0], "ls") == 0){
            int i = 0;
            for (; argv[i]; ++i);
            argv[i++] = "--color=auto";
            argv[i] = NULL;
        }
        //创建子进程去运行指令 父进程等待
        pid_t id = fork();
        assert(id >= 0);

        if (id == 0)
        {
            execvp(argv[0], argv);
            exit(1);
        }
        //父进程
        int status = 0;
        waitpid(id, &status, 0);
        //printf("%s\n", commandstr);
    }
    return 0;
}
