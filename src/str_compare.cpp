#include<iostream>
using namespace std;
int main()
{
    char str1[] = "Farewell Kobe";
    char str2[] = "Farewell Kobe";
    char* str3 = "Farewell Kobe";
    char* str4 = "Farewell Kobe";
    if(str1 == str2)
        cout<< "same"<< endl;
    else
    {
        cout << "not same, str1: " <<&str1<<endl;
        cout << "not same, str2: " <<&str2<<endl;
    }
    if(str3 == str4)
    {
        cout << "same, str3: " <<&str3<<endl;
        cout << "same, str4: " <<&str4<<endl;
    }
    else
    {
        cout << "not same" <<endl;
    }
    return 0;
}
