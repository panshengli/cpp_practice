#include<stdio.h>
#include<iostream>
#include <typeinfo> 
int main()
{
    const char *node1 = "abc";
    char* const node2 = "abc";
    // char c = "xyz";

    // node1[2] = 'k';
    // *node1[2] = 'k';
    // node1 = &c;
    node1 = "xyz";

    // node2[2] = 'k';
    // *node2[2] = 'k';
    // *node2 = c;s
    // node2 = "xyz";
    return 0;
}
