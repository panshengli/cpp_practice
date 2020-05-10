#include <iostream>
#include <string.h>
int main()
{
    char* str1 = "hello";     // valid in C, invalid in C++
    // 会跳出警告：warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
    // char* str1 = (char*)"hello";    // OK
    char* str2 = (char*)" China";
    char* str3 = NULL;
    str3 = new char[strlen(str1)+strlen(str2)+1];
    // str3 = (char*)malloc (256);
    str3[0] = '\n';
    strcat(str3,str1);
    strcat(str3,str2);
    std::cout << str3 << std::endl;
    delete [] str3;
    str3 = NULL;
    return 0;
}
