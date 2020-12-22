#include "singleton.cpp"
int main()
{
  string log1 = "hello 1012";
  string log2 = "fareware 2020";
  while(true)
  {
    Singleton::Instance().printLog(log1);
    Singleton::Instance().printLog(log2);
  }
}
