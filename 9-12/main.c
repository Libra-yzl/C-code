#include "mystdio.h"

int main()
{
    MYFILE* mf = my_fopen("log.txt", "w");
    if (mf == NULL) return -1;
    
    my_fclose(mf);
    mf = NULL;
    return 0;
}