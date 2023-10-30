#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAX 1024
#define ARGC 32
#define SPE " "

typedef enum REDIR_TYPE
{
    NONE=0,
    INPUT_TYPE,
    OUTPUT_TYPE,
    APPEND_TYPE
}REDIR_TYPE;


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

char* GetFile(char* commandstr, REDIR_TYPE* redir)
{
    char* name = (char*)malloc(sizeof(commandstr));
    assert(commandstr);
    // 遍历字符串 如果出现 '<' '<<' '>' 切分字符串
    int pos = 0;
    char* filename = NULL;
    int flag = 0;
    while (commandstr[pos]) {
        if (commandstr[pos] == '<') {
            // 输入重定向
            *redir = INPUT_TYPE;
            // 分割字符串 保存文件名
            flag = 1;
            break;
        }
        else if (commandstr[pos] == '>') {
            // 输出重定向
            flag = 1;
            *redir = OUTPUT_TYPE;
            if (commandstr[++pos] == '>') {
                // 追加重定向
                *redir = APPEND_TYPE;
            }
            break;
        }
        ++pos;
    }
    pos = 0;
    int name_index = 0;
    int len = 0;
    if (flag) {
        // 如果flag为真 说明一定出现了重定向符号
        // 这里保存文件名 切割字符串
        while (commandstr[pos]) {
            if (commandstr[pos] == '<' || commandstr[pos] == '>') {
                ++pos;
                if (commandstr[pos] == '>') ++pos;
                // 记录遇到符号的位置
                len = pos;
                while (commandstr[pos] != '\0') {
                    if (commandstr[pos] == ' ') {
                        ++pos;
                        continue;
                    }
                    name[name_index++] = commandstr[pos++]; 
                }
                // 切分字符串
                if (len-1 > 0) {
                    commandstr[len-1] = '\0';
                    if (commandstr[len-1-1] == '>') commandstr[len-1-1] = '\0';
                }
                name[name_index] = '\0';
                return name;
            }
            ++pos;
        }
    }
    return NULL;
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

        // 这里处理字符串中的几种重定向
        REDIR_TYPE redir = NONE;
        char* filename = GetFile(commandstr, &redir);
        // if (filename == NULL) continue;

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
            if (redir == INPUT_TYPE) {
                int fd = open(filename, O_RDONLY);
                dup2(0, fd);
            }
            else if (redir == OUTPUT_TYPE) {
                int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
                dup2(fd, 1);
            }
            else if (redir == APPEND_TYPE) {
                int fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666);
                dup2(fd, 1);
            }
            else {
                ;
            }
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