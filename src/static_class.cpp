#include <iostream>
class Widget
{
    public:
        Widget()
        {
            count++;
        }
        ~Widget()
        {
            --count;
        }
        static int num()
        {
            return count;
        }
    private:
        static int count;
};
int Widget::count = 0;
int main()
{
    Widget x,y;
    std::cout << "The num is: " << Widget::num() << std::endl;
    if(Widget::num()>1)
    {
        Widget x,y,z;
        std::cout << "The num is: " << Widget::num() << std::endl;
    }
    Widget z;
    std::cout << "The num is: " << Widget::num() << std::endl;
    return 0;
}