#include <stdio.h>

char* strcpy(char* strDest, const char* strSrc)
{
    if((strDest == NULL)||(strSrc == NULL))
    {
        return NULL;
    }
    char* strDestCopy = strDest;
    while((*strDest++ = *strSrc++)!='\0');
    // return strDest-13;     //strDest-len(input_length)
    return strDestCopy;
}

int getStrLen(const char* strSrc)
{
    int len = 0;
    while(*strSrc++ != '\0')
    {
        len++;
    }
    return len;
}

int main()
{
    char strSrc[] = "Hello World!";
    char strDest[20];
    int len = 0;
    char* aa = strcpy(strDest, strSrc);
    len = getStrLen(aa);
    printf("strDest: %s\n", aa);
    printf("Length of strDest: %d\n",len);
}