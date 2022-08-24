#define _XOPEN_SOURCE_EXTENDED 1
#include <unistd.h>
#include "debug.h"

/* 
int main(void)
{
    TESTn(ttyslot())
    return 0;
}
 */

#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fdr = open("buf.txt", O_RDONLY);
    int fdw = open("buf.txt", O_WRONLY);
    TESTn(fdr)
    TESTn(fdw)
    dup2(fdr, STDIN_FILENO);
    dup2(fdw, STDOUT_FILENO);
    dup2(fdw, STDERR_FILENO);
    TESTn(ttyslot())
    return 0;
}
