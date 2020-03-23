/*
用两个栈实现队列
用两个栈来实现一个队列，完成队列的push和pop操作，队列中的元素为int类型
*/

/*
#include<iostream>
#include<vector>
#include<queue>
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
        if(stack2.size()>0 || stack1.size()>0)
        {
            if(stack2.size()==0)
            {
                //for(std::size_t i=0;i<stack1.size();i++)
                while(stack1.size())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            int number=stack2.top();
            stack2.pop();
            return number;
        }
        else
        {
            throw "error";
        }
        
    }
    std::stack<int> stack1;
    std::stack<int> stack2;
};

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    std::vector<int> vec_int(a,a+sizeof(a)/sizeof(int));
    Solution a;
    for(int i=0;i<vec_int.size();i++)
    {
        a.
    }
    Solution a;
    return 0;
}
*/

#include <algorithm>
#include <iostream>
#include <stack>

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
        if (stack2.size() > 0)
        {
            int num = stack2.top();
            stack2.pop();
            return num;
        }
        else if (stack1.size() > 0)
        {
            while (stack1.size() > 0)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int num = stack2.top();
            stack2.pop();
            return num;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char **argv)
{
    int vec[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    for ()
        return 0;
}