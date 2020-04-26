#include <iostream>
#include <string.h>
using namespace std;
class A
{
    public:
        int i;
};
class B
{
    public:
        char ch;
};
class C
{
    public:
        int i;
        short j;
};
class D
{
    public:
        int i;
        short j;
        char ch;
};
class D1
{
    public:
        short j;
        int i;
        char ch;
};
class E
{
    public:
        int i;
        int ii;
        short j;
        char ch;
        char chr;
};
class F
{
    public:
        int i;
        int ii;
        int iii;
        short j;
        char ch;
        char chr;
};
void printSizeof(char str[])
{
    cout << "The length of sizeof str is " << sizeof(str)/sizeof(str[0]) << endl;
    cout << "The length of sizeof str[0] is " << sizeof(str[0]) << endl;
    cout << "The length of strlen str is " << strlen(str) << endl;
}
#pragma pack(1)
struct test
{
    short s1;
    int i;
    char c;
    short s2;
    
};
int main()
{
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << endl;
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;
    cout << "sizeof(D) = " << sizeof(D) << endl;
    cout << "sizeof(D1) = " << sizeof(D1) << endl;
    cout << "sizeof(E) = " << sizeof(E) << endl;
    cout << "sizeof(F) = " << sizeof(F) << endl;


    char str[] = "aBCdE";
    int *p = nullptr;
    cout << "The length of sizeof int* is " << sizeof(p) << endl;
    cout << "The length of sizeof str is " << sizeof(str)/sizeof(str[0]) << endl;
    cout << "The length of strlen str is " << strlen(str) << endl;
    printSizeof(str);
    cout << "The length of struct of test is " << sizeof(test) << endl;
    return 0;
}