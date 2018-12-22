/*
用两个栈完成一个队列
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;
class Solution
{
public:
    void push(int node) 
    {
        stack1.push(node);     
    }
    int pop() 
    {
        if(stack2.size()<=0)
        {
            while(stack1.size())
            {
                int number=stack1.top();
                stack2.push(number);
                stack1.pop();
            }
        }
        if(stack2.size()==0)
        {
            throw "队列里面没有元素！";
        }
        int num=stack2.top();
        stack2.pop();
        return num;
    } 

private:
    stack<int> stack1;//用来添加元素
    stack<int> stack2;//用来删除元素
};

int main()
{
    Solution a;
    a.push(1);
    a.push(2);
    std::cout<<a.pop()<<std::endl;
    std::cout<<a.pop()<<std::endl;
    return 0;
}