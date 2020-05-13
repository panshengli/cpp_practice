#include <iostream>

using namespace std;

struct CLS
{
    int m_i;
    CLS(int i):m_i(i)
    {
        cout << __FUNCTION__ << __LINE__ << ": " << this->m_i << endl;
    }
    CLS()
    {
        CLS(0);
        // 只是在stack上生成了一个临时对象
        cout << __FUNCTION__ << __LINE__ << ": " << this->m_i << endl;
        print();
    }
    void print()
    {
        cout << __FUNCTION__ << __LINE__ << ": " << this << endl;
    }
};

int main()
{
    CLS obj;
    cout << "&obj = " << &obj << endl;
    cout << obj.m_i << endl;
    return 0;
}