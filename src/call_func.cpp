#include<stdlib.h>
#include<stdio.h>
void fn1(void);
void fn2(void);

int main()
{
    atexit(fn1);
    atexit(fn2);
    printf("main exit ...\n");
    return 0;
}
void fn1()
{
    printf("calling fn1...\n");
}

void fn2()
{
    printf("calling fn2...\n");
}