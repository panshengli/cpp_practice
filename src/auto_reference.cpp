#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

 
int main()
{

	std::vector<int> arr(5, 100);
	for(std::vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	cout<<"auto&: ";
	// & 启用了引用
	for(auto &i : arr)
	{    
		std::cout << i << std::endl;
	}

	cout<<"auto: ";
	for(auto i : arr)
	{    
		std::cout << i << std::endl;
	}
	cout << endl;
	return 0;
}
