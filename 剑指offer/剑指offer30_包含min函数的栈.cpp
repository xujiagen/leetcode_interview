/*
返回一个包含栈中最小元素的栈,实践复杂度是O(1)
*/
#include<iostream>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

class Solution 
{
public:
    void push(int value) 
    {
        stack1.push(value);
        if(stack2.size()<1)
            stack2.push(value);
        else
        {
            if(stack2.top()>value)
                stack2.push(value);
            else
                stack2.push(stack2.top());
        }
    }
    void pop() 
    {
        if(stack1.size()<1)
            return;
        else
        {
            stack1.pop();
            stack2.pop();
        }
    }
    int top() 
    {
        if(stack1.size()<1)
            throw "error";
        else
            return stack1.top();   
    }
    int min() 
    {
        if(stack2.size()<1)
            throw "error";
        else
            return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
