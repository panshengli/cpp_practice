#include<stdio.h>
#include<iostream>
int main()
{
    int a[5] = {1,2,3,4,5};
    // &a+1:代表的是加上整个数组的大小，这里数组尺寸是5，所以+1代表的是地址加上5x4.
    // more details: https://blog.csdn.net/eastmoon502136/article/details/8630790
    int *ptr = (int*)(&a + 1);
    printf("%d\n",*(a+2));
    printf("%d\n",*(ptr-1));
    return 0;
}