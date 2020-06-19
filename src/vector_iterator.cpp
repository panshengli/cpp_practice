#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    for (vector<int>::size_type i = array.size()-1; i >= 0; --i)
    {
        cout << array[i] << endl;
    }
    return 0;
}