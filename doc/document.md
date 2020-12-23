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
- [2020.12.22]
  1. **Meyers singleton(目前最推荐Ｃ++单例写法)**
  ```cpp
  #include <iostream>
  using namespace std;

  class Singleton
  {
    public:
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
  2. 