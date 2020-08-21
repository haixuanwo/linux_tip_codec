#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * @brief 可变参数
 */
void print1(int count, ...)
{
    va_list valist;
    int value = 0.0;

    printf("count:%d\n", count);

    // count个参数初始化valist
    va_start(valist, count);

    // 访问所有赋给valist的参数
    for (int i = 0; i < count; i++)
    {
        value = va_arg(valist, int);
        printf("%d ", value);
    }
    printf("\n");

    // 清理valist保留的内存
    va_end(valist);
}


/**
 * @brief 可变参数
 */
void print2(const char* fmt, ...)
{
    va_list args;
    char buf[1024] = {0};

    printf("fmt[%s]\n", fmt);

    // 初始化valist
    va_start(args, fmt);
    vsprintf(buf,fmt,args);

    va_end(args);
    printf("buf[%s]\n", buf);
}

int main()
{
    const char *txh = "tanxiaohai";

    print1(5, 1, 2, 3, 4, 5);
    print2("%s", txh);
    return 0;
}

