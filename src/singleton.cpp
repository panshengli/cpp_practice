#include <iostream>
using namespace std;

class Singleton
{
  public:
    static Singleton& Instance()
    {
      static Singleton singleton;
      return singleton;
    }
    void printLog(string _log)
    {
      cout<<_log<<endl;
    }
  private:
    Singleton(){}
    ~Singleton(){}
    Singleton(Singleton const &){}
    Singleton & operator=(Singleton const &){}
};
