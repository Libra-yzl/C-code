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
//
//int split(char *commandstr, char *argv[])
//{
//    assert(commandstr);
//    assert(argv);
//
//    argv[0] = strtok(commandstr, SEP);
//    if(argv[0] == NULL) return -1;
//    int i = 1;
//    while((argv[i++] = strtok(NULL, SEP)));
//    //int i = 1;
//    //while(1)
//    //{
//    //    argv[i] = strtok(NULL, SEP);
//    //    if(argv[i] == NULL) break;
//    //    i++;
//    //}
//    return 0;
//}

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

//void showEnv()
//{
//    extern char** environ;
//    int i = 0;
//    for (; environ[i]; ++i) printf("%d:%s\n", i, environ[i]);
//}
//
//int main()
//{
//    //当我们在进行env查看的时候，我们想查的是谁的环境变量列表？父进程bash的环境变量列表
//    int last_exit = 0;
//    char myenv[32][256];
//    int env_index = 0;
//    while(1)
//    {
//        char commandstr[MAX] = {0};
//        char *argv[ARGC] = {NULL};
//        printf("[zhangsan@mymachine currpath]# ");
//        fflush(stdout);
//        // cat Makefile > log.txt
//        // cat Makefile >> log.txt
//        // cat Makefile < log.txt
//        // 
//        char *s = fgets(commandstr, sizeof(commandstr), stdin);
//        assert(s);
//        (void)s; // 保证在release方式发布的时候，因为去掉assert了，所以s就没有被使用，而带来的编译告警, 什么都没做，但是充当一次使用
//        // abcd\n\0
//        commandstr[strlen(commandstr)-1] = '\0';
//
//        // "ls -a -l" -> "ls" "-a" "-l"
//        int n = split(commandstr, argv);
//        if(n != 0) continue;
//        //debugPrint(argv);
//        // cd .. / cd /: 让bash自己执行的命令，我们称之为 内建命令/内置命令
//        if(strcmp(argv[0], "cd") == 0)
//        {
//            //说到底，cd命令，重要的表现就如同bash自己调用了对应的函数
//            if(argv[1] != NULL) chdir(argv[1]);
//            continue;
//        }
//        else if(strcmp(argv[0], "export") == 0) // 其实我们之前学习到的所有的(几乎)环境变量命令，都是内建命令
//        {
//            if(argv[1] != NULL){
//                strcpy(myenv[env_index], argv[1]);
//                putenv(myenv[env_index++]);
//            }
//            continue;
//        }
//        else if(strcmp(argv[0], "env") == 0)
//        {
//            showEnv();
//            continue;
//        }
//        else if(strcmp(argv[0], "echo") == 0)
//        {
//            // echo $PATH
//            const char *target_env = NULL;
//            if(argv[1][0] == '$') 
//            {
//                if(argv[1][1] == '?'){
//                    printf("%d\n", last_exit);
//                    continue;
//                }
//                else target_env = getenv(argv[1]+1); // "abcdefg
//                
//                if(target_env != NULL) printf("%s=%s\n", argv[1]+1, target_env);
//            }
//            continue;
//        }
//        //version2: 说明几个细节
//        if(strcmp(argv[0], "ls") == 0)
//        {
//            int pos = 0;
//            while(argv[pos]) pos++;
//            argv[pos++] = (char*)"--color=auto";
//            argv[pos] = NULL; // 比较安全的做法
//        }
//        // version 1
//        pid_t id = fork();
//        assert(id >= 0);
//        (void)id;
//
//        if(id == 0)
//        {
//            //child
//            execvp(argv[0], argv);
//            exit(1);
//        }
//        int status = 0;
//        pid_t ret = waitpid(id, &status, 0);
//        if(ret > 0){
//            last_exit = WEXITSTATUS(status);
//        }
//        //printf("%s\n", commandstr);
//    }
//}

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
            command[i] = '\0';
            break;
        }
        else if (command[i] == '>'){
            //判断是追加还是普通
            if (command[i+1] == '>')
            {
                *redir_type = REDIR_APPEND;
                command[i] = '\0';
                command[i+1] = '\0';
                break;
            }
            *redir_type = REDIR_OUTPUT;
            command[i] = '\0';
            break;
        }

    }
    if (command[i] != '\0'){
        //复制文件名
        for (; i < len; ++i){
            //跳过空格
            if (command[i] == ' ') continue;
            filename[i] = command[i];
        }
        return filename;
    }
    return NULL;
}

int main()
{
    char myenv[32][256];
    int env_index = 0;
    while (1){
        //打印主机名
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
        //printf("%s\n", command);
    }
    return 0;
}
