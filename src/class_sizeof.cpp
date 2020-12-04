#include <iostream>

using namespace std;

class Base
{
    char data[3];
    public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() = 0;
};

int i = 0;
int fun( int n )
{
    static int a = 2;
    a++;
    return(a * n);
}
 

int main()
{
    // cout << sizeof(Base)<< endl;
    int k = 5;
    {
        int i = 2;
        k += fun( i );
    }
    k += fun( i );
    cout << k;
    return 0;
}
