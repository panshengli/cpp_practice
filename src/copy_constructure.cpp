#include <iostream> 
using namespace std; 
class Test 
{ 
    public: 
        int a; 
        Test(int x) 
        { 
            a = x; 
        } 
        Test(const Test &test) 
        {	
            //复制构造函数 
            cout << "copy constructor" << endl;
            a = test.a; 
        } 
}; 
void fun1(Test test) 
{	
    //（1）值传递进入函数体 
    cout << "fun1()..." << endl; 
} 
Test fun2() 
{	
    //(2)值传递从函数体返回 
    Test t(2); 
    cout << "fun2()..." << endl;
    return t; 
}

int main()
{ 
    Test t1(1); 
    Test t2 = t1;
    //（3）用t1对t2做初始化 
    cout << "before fun1()..." << endl; 
    fun1(t1); 
    Test t3 = fun2(); 
    cout << "after fun2()..." << endl; 
    return 0; 
}
