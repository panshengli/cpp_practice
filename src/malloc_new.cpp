#include <iostream>
#include <cstdlib>
#include <memory>
 
class A {
public:
 
    A() {
        std::cout << "create A" << std::endl;
    }
 
    A(const A& o) {
        std::cout << "copy A" << std::endl;
    }
 
    ~A() {
        std::cout << "delete A" << std::endl;
    }
};
 
/*
 * 
 */
int main(void) {
 
    char* buf1 = (char*) malloc(10); // 
    char* buf2 = (char*) calloc(1, 10); // 效果虽然与上面一样,不同的是,calloc会将空间初始化为0.
 
    free(buf1);
    free(buf2);
 
    std::cout << "---------------------------" << std::endl;
 
    // 为什么C++中不建议使用malloc calloc realloc等C语言函数?因为:这样分配的空间,返回的指针需要通过free来释放,但free释放空间不同于delete,free不会执行析构函数!
 
    // A* ap = (A*) malloc(sizeof (class A) * 10);
    A* ap = new A;
    std::uninitialized_fill_n(ap, 10, A());
    // free(ap); // 调用1次create A ,1次delete A 10次copy A
    delete(ap);
    return 0;
}
