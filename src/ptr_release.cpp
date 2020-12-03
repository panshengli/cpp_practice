// #include <iostream>
// #include <memory>
// using namespace std;

// int main()
// {
    
//     shared_ptr<int> a1 = make_shared<int>(10);
//     shared_ptr<int> a2 = make_shared<int>(10);
//     //weak_ptr<int> b1(a1);
//     //weak_ptr<int> b2(a2);
//     a1 = a2;
//     a2 = a1;
//     //delete b1;
//     //delete b2;
//     return 0;
// }
#include <iostream>
#include <memory>
 
using namespace std;
 
class Parent;
class Child; 
 
typedef shared_ptr<Parent> parent_ptr;
typedef shared_ptr<Child> child_ptr; 
 
class Parent
{
public:
       ~Parent() { 
              cout << "~Parent()" << endl; 
       }
public:
       child_ptr children;
};
 
class Child
{
public:
       ~Child() { 
              cout << "~Child()" << endl; 
       }
public:
       weak_ptr<Parent> parent; 
};
 
int main()
{
    parent_ptr father(new Parent);
    child_ptr son(new Child);
    
    // 父子互相引用
    father->children = son;
    son->parent = father;
    
    cout << father.use_count() << endl;  // 引用计数为2
    cout << son.use_count() << endl;     // 引用计数为2


    shared_ptr<int> a1 = make_shared<int>(10);
    shared_ptr<int> a2 = make_shared<int>(10);
    //weak_ptr<int> b1(a1);
    //weak_ptr<int> b2(a2);
    a1 = a2;
    a2 = a1;
    //delete b1;
    //delete b2;
 
  return 0;
}