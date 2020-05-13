#include <iostream>
#include <string.h>
using namespace std;
ostream& operator << (ostream &mylog, string &s)
{
    for(int i =0 ; i < s.size(); ++i)
    {
        mylog << s[i];
    }
    return mylog;
}
 
int main()
{
    string str = "hello mylog";
    cout << str << "sssss"<<5;
}