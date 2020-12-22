#include "singleton.cpp"
int main()
{
  string log1 = "farewell kobe";
  string log2 = "hello 2021";
  while(true)
  {
    Singleton::Instance().printLog(log1);
    Singleton::Instance().printLog(log2);
  }
  
}
