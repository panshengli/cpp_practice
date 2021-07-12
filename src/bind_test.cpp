#include <iostream>     // std::cout
#include <functional>   // std::bind

int fun(int a, int b,int c,int d,int e)
{    
    return a + b + c + d - e; 
}   

int main() {
   int x=1,y=2,z=3;
   auto g1 = std::bind(fun,x,y,std::placeholders::_2,z,std::placeholders::_1);
   std::cout << "g1: " << g1(2,3)<<std::endl;
   auto g2 = std::bind(fun,x,y,std::placeholders::_1,z,std::placeholders::_2);
   std::cout << "g2: " << g2(2,3)<<std::endl;
   return 0;
}