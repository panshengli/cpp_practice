#include "template_funct.hpp"

int main()
{
    Example *e = new Example();
    e->n_e1 = 8;
    e->s_e2 = "Kobe";
    e->d_e3 = 24.0;
    printExample<Example>(2,*e);
    return 1;
}

