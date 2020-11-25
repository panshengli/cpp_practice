#include<iostream>
using namespace std;
int main()
{
    char str1[] = "Farewell Kobe";
    char str2[] = "Farewell Kobe";
    char* str3 = "Farewell Kobe";
    char* str4 = "Farewell Kobe";
    int x = 5;
    x+=x-=x*x;
    std::cout<<"x+=x-=x*x: "<<x<<std::endl;
    if(str1 == str2)
        cout<< "same"<< endl;
    else
    {
        cout << "not same" <<&str1<<endl;
    }
    if(str3 == str4)
    {
        cout << "same" <<&str3<<endl;
    }
    else
    {
        cout << "not same" <<endl;
    }
    return 0;
}
