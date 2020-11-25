#include <stdio.h>
class CPerson
{
public:
    virtual void Whoami() = 0;
    // because of do not define deconstruct function
    // ~CPerson(){printf("person is destroy!\r\n");}
};

class CStudent : public CPerson
{
public:
    CStudent(){printf("student is created!\r\n");}
    virtual ~CStudent(){printf("student is destroy!\r\n");}
    virtual void Whoami(){printf("student!\r\n");}
};

class CTeacher : public CPerson
{
public:
    CTeacher(){printf("teacher is created!\r\n");}
    virtual ~CTeacher(){printf("teacher is destroy!\r\n");}
    virtual void Whoami(){printf("teacher!\r\n");}
};

int main()
{
    CPerson *pLily = new CTeacher();
    pLily->Whoami();
    delete (CTeacher *)pLily;

    CPerson *pLucy = new CStudent();
    pLucy->Whoami();
    delete pLucy;
    return 0;
}
