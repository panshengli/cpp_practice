#include <iostream>
#include "crtp_class1.h"


class Imple
{
  public:
    void specificImpl() { std::cout << "specificImpl" << std::endl; }
};

class Ros
{
  public:
    void process()
    {
        logic_.impl();
    }

  private:
    Logic<Imple> logic_;

};

int main()
{
    Ros ros;
    ros.process();

    return 0;
}

