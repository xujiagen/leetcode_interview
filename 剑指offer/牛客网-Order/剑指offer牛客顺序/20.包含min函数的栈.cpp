/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
class Solution
{
    public:
    void push(int value)
    {
        stack1.push(value);
        if(!stack1.size()) stack2.push(value);
        else stack2.push(min(value,stack1.top()));
    }

    void pop()
    {
        if(!stack1.size()) throw"error";
        else
        {
            stack1.pop();
            stack2.pop();
        }
    }

    int top()
    {
        if(!stack1.size()) throw "error";
        else return stack1.top(); 
    }

    int min()
    {
        if(!stack1.size()) throw"error";
        else return stack2.top();
    }
    std::stack<int> stack1;
    std::stack<int> stack2;
};
*/
class Solution
{
public:
    void push(int value)
    {
        mOrigin.push(value);
        if (mMin.size() < 1)
            mMin.push(value);
        else
            mMin.push(std::min(value, mMin.top()));
    }
    void pop()
    {
        if (mOrigin.size() > 0)
        {
            mOrigin.pop();
            mMin.pop();
        }
        else
            return;
    }
    int top()
    {
        if (mOrigin.size() > 0)
            return mOrigin.top();
    }
    int min()
    {
        if (mMin.size() > 0)
            return mMin.top();
    }
    std::stack<int> mOrigin;
    std::stack<int> mMin;
};