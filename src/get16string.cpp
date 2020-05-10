#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get16String(long num)
{
    char * buffer = (char*)malloc(11);
    char* temp;
    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[10] = '\0';
    temp = buffer + 2;

    for (int i=0;i<8;i++)
    {
        // 左移4i位 去掉高位的4i 右移28位 去掉右边的 这就获得4个bit
        // 第一次是最高位32-29 4个bit 第二次 28-25 4个bit
        temp[i] = (char) (num<<4*i>>28);
        // 它可能是个有符号的数 所以加上16 吧这个数变成0～15之间的正数
        temp[i] = temp[i] >= 0 ? temp[i] : temp[i] + 16;
        printf("temp[]: %u\n",temp[i]);
        // temp[i]<10 就是变成字符‘０’～‘９’　所以加上４８，　如果＞＝１０　那就要用　'A'～'F'来表示
        temp[i] = temp[i] < 10 ? temp[i] + 48 : temp[i] + 55;
    }
    return buffer;
}

int main()
{
    char *p = nullptr;
    char *q = nullptr;
    int num = 0;

    printf("imput num: ");
    scanf("%d",&num);
    p = get16String(num);
    printf("%s\n",p);
    return 0;
}
