#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int stack_example();
int main()
{
    stack <int, vector<int> > s;
    queue <int, vector<int> > q;

    for (int i = 1; i <10; i++)
    {
        s.emplace(i);
        q.push(i);
    }

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    // while(!q.empty())
    // {
    //     cout << q.front() << endl;
    //     q.pop();
    // }
    stack_example();
    return 0;
}

int stack_example()
{
	stack<int> stk1;    //定义一个空栈
	stack<int> stk2;
	stk1.push(2);       //向栈中添加元素
	stk1.push(9);
	stk1.emplace(3);
	stk1.emplace(39);
	stk2.push(3);
	stk2.push(4);
	stk2.swap(stk1);    //交换两个栈中的元素
	while(!stk1.empty())    //当栈不为空时，继续循环
	{
		cout << stk1.top() << endl;    //输出栈顶元素
		stk1.pop();        //将栈顶元素弹出
	}
	while(stk2.size())     //当栈中元素个数不为0时，继续循环
	{
		cout << stk2.top() << endl;
		stk2.pop();
	}
	return 0;
}