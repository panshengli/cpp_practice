# CPP Notes

- [2020.11.25]
  1. **c++哪些可以重载？**
    - 除了类属关系运算符"."、成员指针运算符".*"、作用域运算符"::"、sizeof运算符和三目运算符"?:"
    - 以外，c++中的所有运算符都可以重载
    - 但=、()、[]、->这四个不能重载为类的友元函数
  2. **有100MB的内存，对1GB数据进行排序，最合适的算法是？**
  　　- (r) 归并排序
  3. **gcc 中-fPIC的作用**
  - 编译阶段，告诉编译器产生与位置无关代码(Position-Independent Code), 则产生的代码中，没有绝对地址，全部使用相对地址，故而代码可以被加载器加载到内存的任意位置，都以正确的执行
  - 如果不加-fPIC,则加载.so文件的代码段时,代码段引用的数据对象需要重定位, 重定位会修改代码段的内容,这就造成每个使用这个.so文件代码段的进程在内核里都会生成这个.so文件代码段的copy.每个copy都不一样,取决于 这个.so文件代码段和数据段内存映射的位置.
  4. **c++为什么用右值引用**
  - 移动语义：避免空间浪费，直接使用降低构造成本；
  - 完美转发：拷贝构造为左值引用，移动构造为右值引用，利用move将左值变为右值
  5. **TCP/IP原理**
  - 三次握手：
    - 客->服：链接建立的请求。SYN = 1，SYN包；
    - 服->客：确认服务器请求链接。SYN = 1, ACK = 1,SYN-ACK包。
    - 客->服：服务器上一个报文确认报文。ACK ＝ １，ACK包。
  - 四次握手：
    - 客->服：链接断开的请求。FIN = 1，FIN包；
    - 服->客：确认断开链接请求。ACK = 1,ACK包。
    - 服->客：服务器发送断开链接申请。FIN = 1，FIN包；
    - 客->服：确认服务器上一个报文断开连接确认。ACK ＝ １，ACK包

- [2020.12.17]
  1. **c++11新特性**
    - nullptr. nullptr出现的目的是为了替代NULL, C++会把NULL、0视为同一种东西
    - 类型推导 auto（c++11不能用于函数传参）
    - 区间迭代 启用了auto&
    - 初始化列表 类的初始化，如：A a {1, 1.1};
    - 模板增强 尖括号>, 传统C++，>>当做右移处理
    - Lambda 表达式
    - 无序容器 unordered_map/unordered_multimap 和 unordered_set/unordered_multiset
    - 右值引用和move语义
  2. **虚函数表**
    - 单继承情况
      - 若类有虚函数，构造函数编译器会自动为类的实例在内存的首部增添一个虚函数表指针vfptr,指向该类的虚函数表
      - 虚函数表中会存放该类所有的虚函数地址，普通函数则不会被放入其中
      - 子类重写了父类的虚函数，被重写的虚函数的地址被子类的虚函数替换
      - 父类指针BaseClass* base指向一个子类对象DerivedClass时，base->vfptr->virtualFunc，父类指针调用实际子类的成员函数
    - 多继承情况
      - todo
  3. **原子操作与mutex对比**
     - mutex函数:是一套专门用于线程同步锁机制的函数
     - 原子操作:新标准C++11，引入了原子操作,提供比mutex等锁机制更好的性能
     - 对于多线程的情况下,单个基础数据类型的数据共享安全,尽量使用原子操作代替锁机制
     - 当需要对代码块进行数据安全保护的时候,就需要选择使用锁机制了

- [2020.12.18]
  1. **不能用于声明虚函数**
     - 普通函数
     - 构造函数
     - 内联函数
     - 静态成员函数(不能被继承)
     - 友元函数(非成员函数)
  2. **智能指针的多线程安全**
     - shared_ptr指针类有两个成员变量，一个是指向变量的指针，一个是资源被引用的次数
     - 智能指针shared_ptr本身（底层实现原理是引用计数,内部自动加锁解锁）是线程安全的
     - **指向对象的指针**不是线程安全的，对象的读写则不是
       - 使用**智能指针访问资源**不是线程安全的，需要**手动加锁解锁**
       - 智能指针的赋值/拷贝也不是线程安全的
         - 首先拷贝指向对象的指针，再使引用次数加减操作
         - 但是指针拷贝并不是原子操作，线程不安全，需要手动加锁解锁

- [2020.12.23]
  1. 手写一个智能指针接口及实现
  ```cpp
  #include <iostream>
  template <typename T>
  class SmartPointer
  {
      public:
          SmartPointer(T* ptr);  // 用普通指针初始化智能指针
          SmartPointer(SmartPointer<T>& sptr);  // 指针拷贝构造函数，新建一个指向已有对象的智能指针
          SmartPointer<T> & operator = (SmartPointer<T>& sptr);  // 赋值构造函数

          ~SmartPointer();
          T* operator->();  // 自定义指针运算符
          T& operator*();  // 自定义解引用运算符
          T getCount();  // 获取计数

      private:
          int* ref_count_;  // 引用计数
          T* ref_;  // 智能指针底层保管的指针
  };

  template <typename T>  // 用普通指针初始化时，将该指针进行封装，引用计数初始化为1
  SmartPointer<T>::SmartPointer(T* ptr)
      : ref_count_(new int(1)),
        ref_(ptr)
  {
  }

  template <typename T>  // 对普通指针拷贝，引用计数器加1，对参数进行修改，不能将参数声明为const
  SmartPointer<T>::SmartPointer(SmartPointer<T>& sptr)
      : ref_count_(&(++*sptr.ref_count_)),
        ref_(sptr.red_)
  {
  }

  template <typename T>  // rewrite "="，修改指针的指向
  SmartPointer<T>& SmartPointer<T>::operator = (SmartPointer<T>& sptr)
  {
      if(this == &sptr)  // 同一个指针，直接返回
      {
          return *this;
      }
      if(--*ref_count_ == 0)  //旧对象的引用计数为1，删除旧对象
      {
          delete ref_count_;
          delete ref_;
          ref_count_ = nullptr;
          ref_ = nullptr;
      }
      ref_ = sprt.ref_;
      ref_count_ = sptr.ref_count_;
      ++(*ref_count);  // 指针计数+1
      return *this;
  }

  template <typename T>
  SmartPointer<T>::~SmartPointer()
  {
      if(--*ref_count_ == 0)
      {
          delete ref_count_;
          delete ref_;
          ref_count_ = nullptr;
          ref_ = nullptr;
      }
  }

  template <typename T>
  T* SmartPointer<T>::operator->()
  {
      return ref_;
  }

  template <typename T>  // 定义解引用运算符，直接返回底层指针的引用
  T& SmartPointer<T>::operator*()
  {
      return *ref_;
  }

  T SmartPointer<T>::getCount()
  {
      return static_cast<T>(*ref_count_);
  }

  class A
  {
      public:
          A() { cout << "A::A()" << endl; }
          ~A() { cout << "A::~A()" << endl; }
          void fun() { cout << "A::fun()" << endl; }
  };

  int main()
  {
      SmartPointer<A> temp(new A());
      (*temp).fun(); //通过对象调用成员函数
      temp->fun(); //通过指针调用成员函数
  }

  ```
  - [2020.12.24]
  1. 模板使用typename和class的区别
     - typename和class在作为参数类型时用法一样, 没有区别
     - typename主要用于对嵌套依赖类型进行提取. 而class没有这样的功能
       - 嵌套类型依赖, 
         - 如果声明class, C++标准会让编译器会把const_iterator做为一个静态变量处理
         - **typename显式的告诉编译器T::const_iterator是一个类型**, 而**不是一个静态变量乘以x**
          ```cpp
          template < typename T>
          void print2nd( const T& container)
          {
            T::const_iterator * x;
          }
          ```

  2. c++模板的特化:
     - 全特化：特化为绝对类型(直接为某个特定类型做特化)
       - ```template<>　class Example<float>```
     - 偏特化：特化为引用，指针类型　(只是对类型做了某些限定, 如Ｔ*,　偏特化为float*, double*等)
       - ```template<typename T> class Example<T*>```
     - 特化为另外一个类模板
  
  - [2020.12.31]
  1. 单例模式的多线程安全
     - 单例模式主要解决一个**全局使用的类频繁的创建和销毁**的问题
     - 单例模式有三个要素:
       1. 某个类只能有一个实例
       2. 必须自行创建这个实例
       3. 必须自行向整个系统提供这个实例
    - 单例模式两种模式：懒汉和饿汉模式
      - 饿汉式：**避免多线程的同步**问题，instance在类装载时就实例化，**可能会产生垃圾对象**
      ```cpp
      class Singleton
      {
          public:
              // 该类中唯一一个public方法
              static Singleton& getInstance()
              {
                  return singleton_;
              }
              void doSomething(){}
          private:
              // private构造，保证其他类对象不能new一个对象的实例
              Singleton();
              // 直接初始化一个示例对象
              static Singleton singleton_ = new Singleton();
      }
      ```
      - 饿汉式：**双重锁机制**实现线程安全
      ```cpp
      #include <mutex>
      std::mutex mt;
      class Singleton
      {
          public:
             static Singleton& getInstance()
             {
                if(singleton_ == nullptr)
                {
                    mt.lock();
                    if(singleton_ == nullptr)
                    {
                        singleton_ = new Singleton();
                        mt.unlock();
                        return singleton_;
                    }
                }
                mt.unlock();
                return singleton_;
             } 
      }
      ```
      - **Meyers singleton(目前最推荐Ｃ++单例写法)**
      ```cpp
      #include <iostream>
      using namespace std;

      class Singleton
      {
          public:
              //　返回为引用和或指针类型
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

      int main()
      {
          string log1 = "farewell kobe";
          string log2 = "hello 2021";
          Singleton::Instance().printLog(log1);
          Singleton::Instance().printLog(log2);
      }
      ```
  2. 举例其他设计模式
     - 工厂模式：工厂模式主要**解决接口选择**的问题
        - 创建对象的接口，让其**子类自己决定实例化哪一个工厂类**，使其创建过程延迟到子类进行
        - **解耦，代码复用，更改功能容易**
     - 观察者模式：定义对象间的一种一对多的依赖关系
        - 当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新
     - 装饰器模式：对已经存在的某些类进行装饰，以此来**扩展一些功能**，从而动态的为一个对象**增加新的功能**
        - 扩展一个类的功能、动态增加功能，动态撤销
  3. OOP的设计模式的五项原则
     - 单一职责原则
        - 避免相同的职责分散到不同的类中
        - 避免一个类承担太多职责
        - **减少类的耦合**，提高类的复用性
     - 接口隔离原则
        - **多个专门的接口**比使用单个接口好很多
        - 一个类对另外一个类的依赖性应当是建立在最小的接口上
        - 客户端程序不应该依赖它不需要的接口方法
     - 开放封闭原则
        - 在**扩展性方面应该是开放**的
        - 在**更改性方面应该是封闭**的
        - 核心思想就是对抽象编程，而不对具体编程
     - 替换原则
        - 子类型必须能够替换掉他们的父类型、并出现在父类能够出现的任何地方
        - **父类的方法都要在子类中实现或者重写**
        - 派生类只实现其抽象类中生命的方法，而不应当给出多余的,方法定义或实现
        - 客户端程序中只应该使用父类对象而不应当直接使用子类对象，这样可以实现运行期间绑定
     - 依赖倒置原则
        - **父类不能依赖子类**，他们都要依赖抽象类
        - 抽象不能依赖于具体，具体应该要依赖于抽象
  4. c++变量存储的位置
     - **栈区** stack
       - 由编译器自动分配释放
       - 存放函数的参数值, 局部变量的值
       - 类似于数据结构中的栈
         - 如，递归是借助栈来实现，自动变量是存储在栈里面的
     - **堆区** heap
       - 一般由程序员分配释放, 若程序员不释放, 程序结束时可能由OS回收
       - 与数据结构中的堆是两回事, 分配方式类似于链表
     - **全局区**(静态区) static
       - 全局变量和静态变量的存储是放在一块的
       - 初始化的全局变量和静态变量在一块区域
       - 未初始化的全局变量和静态变量又放在相邻的另一块区域中
       - 由系统释放
     - **文字常量区**
       - 常量字符串放在这里
       - 由系统释放
     - **程序代码区**
       - 存放函数体的2进制代码
     ```cpp
     // main.cpp 
     int a = 0; 全局初始化区
     char *p1; 全局未初始化区

     int main()
     {

       int b; // 栈
       char s[] = "abc"; // 栈
       char *p2; // 栈
       char *p3 = "123456"; // 123456\0";在常量区，p3在栈上
       static int c = 0； // 全局（静态）初始化区
       // 分配得来得10和20字节的区域就在堆区
       p1 = (char *)malloc(10);
       p2 = (char *)malloc(20);
       // 123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方
       strcpy(p1, "123456");
       return 0;
　　　　}
  - [2021.01.10]
  1. static关键字作用
     - 全局静态变量
       - 自动初始化为0,静态存储区
       - 作用域: 其他文件不可见, 文件定义开始至结尾
     - 局部静态变量
       - 局部静态变量, 静态存储区
       - 作用域: 函数定义开始到作用域结束, 作用域结束, 仍在内存中, 不能访问
     - 静态函数
       - 静态函数, 定义和声明在默认情况下都是extern的, 声明后只在本文件可见其他文件不可见
     - 类的静态成员
       - 静态成员可以实现多个对象之间的数据共享
       - 对多个对象来说, 静态数据成员只存储一处, 供所有对象共用
     - 类的静态函数
       - 只能访问静态成员变量和静态成员函数
       - 调用静态成员函数使用如下格式：<类名>::<静态成员函数名>(<参数表>)
  2. 重载和重写
     - 重载：两个函数名相同，但是参数列表不同（个数，类型）,返回值类型没有要求，在同一作用域中
     - 重写：子类继承了父类，父类中的函数是虚函数，在子类中重新定义了这个虚函数
  3. 多态
     - 多态的实现主要分为静态多态和动态多态
       - 静态多态: 主要是重载，在编译的时候就已经确定
       - 动态多态: 是用虚函数机制实现的，在运行期间动态绑定
  - [2021.01.11]
  1. 关于多线程问题
     - look_guard:
       - `std::lock_guard<std::mutex> lock(*m3x);`
       - 构造自动锁定互斥量，退出作用域后**析构自动解锁**，避免忘记unlock操作
       - 缺点：没有提供加锁和解锁的接口
     - unique_guard:
       - 内部提供unlock()和lock()机制，但需要维护锁的状态，效率比look_guar些
       - 析构时也会自动解锁
       - unique_lock()可以进行std::move()
     - condition_variable
       - 能用于阻塞一个/多个线程，直至另一线程修改共享变量（条件）并通知 condition_variable
       - 获得std::mutex(常通过 std::lock_guard/unique_lock)
       - 在保有锁时进行修改
       - 在std::condition_variable上执行notify_one或notify_all(不需要为通知保有锁)
