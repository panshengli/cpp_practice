#include <iostream>  
  
/* 
@file 学习CRTP (Curiously recurring template pattern). 
一种实现多态(polymorphism) 的方式，与虚函数的不同在于，CRTP的函数绑定是在编译期间完成的，因而执行效率更高。 
CRTP通过 子类 继承 以子类为模板参数的父类 来实现。 
共用代码的函数可以直接在父类中实现。 
而对于不同子类需要不同实现的函数，只需要在父类的该函数中将父类静态转换为子类（父类转为子类没问题，因为我们用的总是子类！），并调用子类的该方法即可。 
需要说明的一点是：对于需要多态的方法，由于父类的方法体只是一个函数调用，因而编译时是可以inline的。运行时完全没有额外的开销！ 
@link http://en.wikipedia.org/wiki/Curiously_Recurring_Template_Pattern 
*/  
  
///基类  
template<typename Derived> class Base 
{  
    public:  
        inline void interfaceMethod() 
        {  
            std::cout << __FUNCTION__ << std::endl;  
            std::cout << "    ";  
            //静态转换后调用子类的方法  
            static_cast<Derived*> (this)->implementationMethod();  
        }  
    
        static void static_func()    
        {  
            std::cout << __FUNCTION__ << std::endl;  
            std::cout << "    ";  
    
            Derived::static_sub_func(); //注意这里必须为静态方法！！  
        }  
};  
  
///一个完好的子类的示例  
class DerivedClass : public Base<DerivedClass> 
{  
    public:  
        void implementationMethod() 
        {  
            std::cout << __FUNCTION__ << std::endl;  
        }  
        static void static_sub_func() 
        {  
            std::cout << __FUNCTION__ << std::endl;  
        }  
};  
  
///没有实现所需方法的子类  
class FalseDerivedClass : public Base<FalseDerivedClass> {  
      
};  
  
///虽然实现了所需方法，但不是基类的子类  
class NotDerivedClass 
{  
public:  
    void implementationMethod() 
    {  
        std::cout << __FUNCTION__ << std::endl;  
    }  
    static void static_sub_func() 
    {  
        std::cout << __FUNCTION__ << std::endl;  
    }  
};  
  
int main() 
{  
    Base<FalseDerivedClass> base;  
    // base.interfaceMethod(); //FalseDerivedClass 没实现该方法，编译自然就通不过  
  
    Base<NotDerivedClass> baseNot;  
    //baseNot.interfaceMethod(); //NotDerivedClass 不是Base的子类，实现了该方法编译也通不过  
  
    DerivedClass derived;  
    derived.interfaceMethod();  
    derived.static_func();  
    return 0;
}  
