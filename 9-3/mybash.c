#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX 1024
#define ARGC 64
#define SEP " "

int split(char* commandstr, char* argv[])
{
    assert(commandstr && argv);
    
    argv[0] = strtok(commandstr, SEP);
    if (argv[0] == NULL) return -1;
    int i = 1;
    while (1)
    {
        argv[i] = strtok(NULL, SEP);
        if (argv[i] == NULL) break;
        ++i;
    }
    return 0;
}

void debugArgv(char* argv[])
{
    int i = 0;
    for (; argv[i]; ++i)
    {
        printf("%d: %s\n", i, argv[i]);
    }
}

int main()
{
    char myenv[16][256] = {0};
    int env_index = 0;
    int last_exit = 0;
    while (1)
    {
        char commandstr[MAX] = {0};
        char* argv[ARGC] = {NULL};

        printf("[yzl@newcloud curpath]# ");
        fflush(stdout);
        char* s = fgets(commandstr, sizeof(commandstr), stdin);
        assert(s);
        //void (s);
        //去掉输入的回车键
        commandstr[strlen(commandstr)-1] = '\0';
        //切割字符串
        int n = split(commandstr, argv);
        if (n != 0) continue;

        if (strcmp(argv[0], "cd") == 0)
        {
            if (argv[1] != NULL) chdir(argv[1]);
            continue;
        }
        else if (strcmp(argv[0], "export") == 0)
        {
            if (argv[1] != NULL)
            {
                strcpy(myenv[env_index], argv[1]);
                putenv(myenv[env_index++]);
            }
            continue;
        }
        else if (strcmp(argv[0], "echo") == 0)
        {
            const char* target_env = NULL;
            if (argv[1][0] == '$')
            {
                if (argv[1][1] == '?')
                {
                    printf("%d\n", last_exit);
                    continue;
                }
                else 
                {
                    target_env = getenv(argv[1]+1);
                }
                if (target_env != NULL) printf("%s\n", target_env);
            }
            continue;
        }

        if (strcmp(argv[0], "ls") == 0)
        {
            int pos = 0;
            while (argv[++pos]);
            argv[pos++] = "--color=auto";
            argv[pos] = NULL;
        }
        //debugArgv(argv);
        //sleep(1);
        pid_t id = fork();
        assert(id >= 0);
        if (id == 0)
        {
            //child
            execvp(argv[0], argv);
            exit(1);
        }
        //father
        int status = 0;
        pid_t ret_id = waitpid(id, &status, 0);
        if (ret_id > 0) last_exit = WEXITSTATUS(status);
        //procintf("%s\n", commandstr);
    }
    return 0;
}
