#include <iostream>
using namespace std;
class A
{
    private:
        int num;
    public:
        A()
        {
            cout<<"Default constructor"<<endl;
        }
        ~A()
        {
            cout<<"Deconstructor"<<endl;
            cout<<num<<endl;
        }
        A(const A &a)
        {
            cout<<"Copy constructor"<<endl;
        }
        void operator = (const A &a)
        {
            cout<<"Overload operator"<<endl;
        }
        void SetNum(int n)
        {
            num = n;
        }
};
int main()
{
    A a1;
    A a2(a1);
    A a3=a1;
    A &a4=a1;
    A a5;
    // a5 = a1;
    a1.SetNum(1);
    a2.SetNum(2);
    a3.SetNum(3);
    a4.SetNum(4);
    a5.SetNum(5);


    return 0;
}