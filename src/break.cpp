#include<iostream>
using namespace std;
int main()
{
    int count = 0;
    for(int i = 0; i <= 3;i++)
    {
        while(i)
        {
            cout<<"i: "<<i<<endl;
            i =0;
            cout<<"i: "<<i<<endl;
            ++count;
        }
    }
    return count;
}
