#include <stdio.h>
#include <assert.h>

// void *可以指向任何类型的数据
void *memcpy2(void *memTo, const void * memFrom, size_t size)
{
    assert((memTo != NULL)&&(memFrom != NULL));
    char *tempFrom = (char *)memFrom;
    char *tempTo = (char*)memTo;
    while(size-- >0)
    {
        *tempTo++ = *tempFrom++;
    }
    return memTo;
}


char *memcpy3(char *memTo, const char * memFrom, size_t size)
{
    assert((memTo != NULL)&&(memFrom != NULL));
    // char *tempFrom = (char *)memFrom;
    char *tempTo = (char*)memTo;
    // while(size-- >0)
    // {
    //     *tempTo++ = *tempFrom++;
    // }
    // return memTo;

    char *tempFrom = (char *)memFrom;
    while(size-- >0)
    {
        *tempTo++ = *tempFrom++;
    }
    return tempFrom;
}

int main(char argc, char * agrv[])
{
    char strSrc[] = "Hello World";
    char strDest[20];

    memcpy2(strDest, strSrc,4);
    strDest[4] = '\0';
    printf("strDest: %s\n", strDest);

    for(unsigned char i=0; i<=265;i++)
    {
        printf("i: %u\n", i);
    }
    return 0;
}