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
    char str1[] = "abc";
    char str2[] = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    const char* str5 = "abc";
    const char* str6 = "abc";
    char* str7 = "abc";
    char* str8 = "abc";
    int i=10, *p=&i;
    std::cout<< str1<<std::endl;
    std::cout<< str2<<std::endl;
    std::cout<< str3<<std::endl;
    std::cout<< str4<<std::endl;
    std::cout<< str5<<std::endl;
    std::cout<< str6<<std::endl;
    std::cout<< str7<<std::endl;
    std::cout<< str8<<std::endl;
    std::cout<< "p: "<<p<<std::endl;
    return 0;
}
