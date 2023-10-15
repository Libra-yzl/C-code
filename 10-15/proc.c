#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 1024
#define ARGC 32

#define SPE " "

int splitStr(char* commandStr, char* argv[])
{
    assert(commandStr);
    assert(argv);

    argv[0] = strtok(commandStr, SPE);
    if (argv[0] == NULL) return -1;
    int pos = 1;
    while ((argv[pos] = strtok(NULL, SPE)) != NULL){
        ++pos;
    }
    argv[pos] = NULL;
    return 0;
}

int main()
{
    while (1){
        // 存放分割的字符串
        char* argv[ARGC] = {NULL};
        char commandStr[MAX] = {0};
        printf("[root@machine currpath]# ");
        fflush(stdout);

        // 获取用户输入
        char* s = fgets(commandStr, sizeof(commandStr), stdin);
        (void)s;

        commandStr[strlen(commandStr)-1] = '\0';
        // 分割字符串
        int n = splitStr(commandStr, argv);
        if (n != 0) continue;

        // 添加ls的配色
        if(strcmp(argv[0], "ls") == 0){
            int pos = 0;
            while(argv[pos]) pos++;
            argv[pos++] = (char*)"--color=auto";
            argv[pos] = NULL; // 比较安全的做法
        }

        pid_t id = fork();
        if (id == 0){
            execvp(argv[0], argv);
            exit(-1);
        }

        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        // if (ret < 0){
        //     perror("error\n");
        //     exit(-1);
        // }
        // else{
        //     continue;
        // }

        //printf("%s\n", commandStr);
        //sleep(1);

    }
    return 0;
}