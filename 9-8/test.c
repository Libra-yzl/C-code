#include <stdio.h>
#include <string.h>

int main()
{
    int a = 0;
    printf("%d\n", ~a);
    const char* mesg = "Hello World";
    printf("%d\n",(int)strlen(mesg));
    char buf[] = {'H','E','L','L','O', '1', '2'};
    printf("%d\n", sizeof(buf));
    printf("%d\n", (int)strlen(buf));
}
