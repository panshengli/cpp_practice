#pragma once
#include <iostream>

struct Example
{
    int n_e1;
    std::string s_e2;
    double d_e3;
};
template <typename T>
void printExample(int a, T e)
{
    std::cout << "a: " << a << std::endl;
    std::cout << "e.n_e1: " << e.n_e1 << std::endl;
}


