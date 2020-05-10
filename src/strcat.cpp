#include <iostream>
#include <string.h>
int main()
{
    char* str1 = "hello";
    char* str2 = " China";
    char* str3 = NULL;
    // str3 = new char[strlen(str1)+strlen(str2)+1];
    str3[0] = '\n';
    strcat(str3,str1);
    strcat(str3,str2);
    std::cout << str3 <<std::endl;
    delete [] str3;
    str3 = NULL;
    return 0;
}
