// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

int main () {
  // using std::find with array and pointer:
  int myints[] = { 10, 20, 30, 40 };
  int * p;
  // using std::find with vector and iterator:
  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 50);
  if (it == myvector.end())
  {
    myvector.push_back(50);
    std::cout << "Element: " << *it << '\n';
  }
  else
    std::cout << "Element not found in myvector: "<< '\n';

  return 0;
}

