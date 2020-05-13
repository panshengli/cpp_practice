#include <iostream>
#include <string.h>
using namespace std;

class Base
{
    public:
        Base(char* className)
        {
            name = new char[strlen(className)];
            strcpy(name, className);
        }
        ~Base()
        {
            delete name;
        }
        char *copyName()
        {
            char* newname = new char[strlen(name)];
            // char newname[10] = "";  // new name: (null)
            // char* newname = NULL;      //Segmentation fault (core dumped)
            strcpy(newname, name);
            return newname;
        }
        char* getName()
        {
            return name;
        }
    private:
        char *name;
};
class SubClass : public Base 
{
    public:
        SubClass(char* className) : Base(className)
        {

        }
};

int main(char argc, char* argv[])
{
    Base *pBase = new SubClass("test");
    printf("name: %s\n",pBase->getName());
    printf("new name: %s\n",pBase->copyName());
    return 0;
}