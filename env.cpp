#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PATH_ENV "PATH"
#define TXH "/home/tanxiaohai"
#define THF "/home/tanhuifang"

#define BUF_SIZE 2048

int main()
{
    char *env = NULL;
    char buf[BUF_SIZE] = {0};

    env = getenv(PATH_ENV);
    printf("1 --- env:%s\n", env);

    snprintf(buf, sizeof(buf), "%s:%s", env, TXH);
    setenv(PATH_ENV, buf, 1);

    env = getenv(PATH_ENV);
    printf("2 --- env:%s\n", env);

    snprintf(buf, sizeof(buf), "%s=%s:%s", PATH_ENV, env, THF);
    putenv(buf);

    env = getenv(PATH_ENV);
    printf("3 --- env:%s\n", env);

    return 0;
}

