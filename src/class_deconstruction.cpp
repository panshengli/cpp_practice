#include <iostream>
class c
{
public:
    c(){ printf("c\n"); }
    ~c(){ printf("~c\n"); }
protected:

private:
};

class b 
{
public:
    b(){ printf("b\n");}
    ~b(){ printf("~b\n");}
protected:
    c C;
private:
};

class a : public b
{
public:
    a(){ printf("a\n"); }
    ~a(){ printf("~a\n"); }
protected:
private:
};

int main()
{
    a A;
    getchar();
}
