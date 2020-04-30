#pragma once
#include <iostream>
template < typename T >
class Logic
{
  public:
    void impl()
    {
        std::cout << "Impl:" << std::endl;
        specific_impl_.specificImpl();
    }

  private:
    T specific_impl_;
};
