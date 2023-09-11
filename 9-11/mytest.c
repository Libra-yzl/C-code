#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MAX 1024
#define ARGC 64
#define SEP " "


void debugPrint(char *argv[])
{
    int i = 0;
    for(; argv[i]; i++)
    {
        printf("%d: %s\n", i, argv[i]);
    }
}

void showEnv()
{
    extern char **environ;
    int i = 0;
    for(; environ[i]; i++) printf("%d:%s\n", i, environ[i]);
}

int split(char command[], char* argv[])
{
    assert(command && argv);
    //切割字符串
    argv[0] = strtok(command, SEP);
    int pos = 1;
    while (argv[pos++] = strtok(NULL, SEP));
    return 0;
}

enum redir{
    REDIR_NONE=0,
    REDIR_INPUT,
    REDIR_OUTPUT,
    REDIR_APPEND
};

char* checkDir(char command[],enum redir* redir_type)
{
    assert(command);
    char* filename = (char*)malloc(sizeof(char)*MAX);
    //遍历字符串
    int len = strlen(command);
    int i = 0;
    for (; i < len; ++i)
    {
        if (command[i] == '<'){
            //输入重定向
            //返回文件名 < -> '\0'
            *redir_type = REDIR_INPUT;
            //
            //command[i] = '\0';
            break;
        }
        else if (command[i] == '>'){
            //判断是追加还是普通
            if (command[i+1] == '>')
            {
                *redir_type = REDIR_APPEND;
                //复制文件名
                int j = i;
                int m = 0;
                for (; j < len; ++j)
                {
                    //跳过空格
                    if (command[j] == ' ') continue;
                    filename[m++] = command[j];
                }
                command[i] = '\0';
                //command[i+1] = '\0';
                return filename;
            }
            *redir_type = REDIR_OUTPUT;
            int j = i+1;
            int m = 0;
            for (; j < len; ++j)
            {
                //跳过空格
                if (command[j] == ' ') continue;
                filename[m++] = command[j];
            }
            command[i] = '\0';
            return filename;
        }

    }
    // if (command[i] != '\0'){
    //     //复制文件名
    //     for (; i < len; ++i){
    //         //跳过空格
    //         if (command[i] == ' ') continue;
    //         filename[i] = command[i];
    //     }
    //     return filename;
    // }
    return NULL;
}

int main()
{
    char myenv[32][256];
    int env_index = 0;
    while (1){
        //打印主机名
        umask(0);
        enum redir redir_type = REDIR_NONE;

        printf("[yzl@ Cloud curpath]#");
        fflush(stdout);
        char command[MAX]= {0};
        char* argv[ARGC] = {NULL};
        fgets(command, sizeof(command), stdin);
        //去掉输入的'\n'
        command[strlen(command)-1]='\0';
        
        //检查 > >> < 并返回文件名 log.txt
        char* filename = checkDir(command, &redir_type);

        int n = split(command, argv);
        if (n != 0) continue;
    
        if(strcmp(argv[0], "export") == 0) // 其实我们之前学习到的所有的(几乎)环境变量命令，都是内建命令
        {
            if(argv[1] != NULL){
                strcpy(myenv[env_index], argv[1]);
                putenv(myenv[env_index++]);
            }
            continue;
        }
        else if (strcmp(argv[0], "env") == 0){
            showEnv();
            continue;
        }

        if (strcmp(argv[0], "ls") == 0){
            int pos = 0;
            while (argv[pos]) ++pos;
            argv[pos] = (char*)"--color=auto";
            argv[++pos] = NULL;
        }

        int id = fork();
        if (id == 0){
            if (filename != NULL){
                //重定向
                if (redir_type == REDIR_INPUT)
                {
                    //输入重定向
                    close(0);
                    open(filename, O_RDONLY);
                    //fscanf(0, "%s");
                }
                else if (redir_type == REDIR_OUTPUT)
                {
                    close(1);
                    open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                    
                }
                else if (redir_type == REDIR_APPEND)
                {
                    close(1);
                    open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
                }
                else 
                {
                    ;
                }
            }
            execvp(argv[0], argv);
            exit(1);
        }
        free(filename);
        //父进程
        int status = 0;
        waitpid(id, &status, 0);
    }
    return 0;
}
