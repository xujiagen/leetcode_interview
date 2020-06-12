/*
输入两个整数序列，一个序列表示栈的压入顺序，请判断第二个序列是否肯能为该栈的弹出顺序
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
class Solution
{
    public:
    bool IsPopOrder(std::vector<int> pushV,std::vector<int> popV)
    {
        if(pushV.size()!=popV.size()) return false;
        if(pushV.size()==popV.size() && pushV.size()==0) return true;
        int push_size=0,pop_size=0;
        while(push_size<pushV.size())
        {
            if(pushV[push_size]==popV[pop_size])
            {
                push_size++;
                pop_size++;
            }
            else
                stack1.push(pushV[push_size++]);
        }
        while(pop_size<pushV.size())
        {
            if(popV[pop_size]==stack1.top())
            {
                stack1.pop();
                pop_size++;
            }
            else
                break;
        }
        if(stack1.size()>0 || pop_size<pushV.size()) return false;
        else return true;
    }
    std::stack<int> stack1;
};
*/
class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int popOrder = 0;
        for (int i = 0; i < pushV.size(); i++)
        {
            if (pushV[i] == popV[popOrder])
            {
                popOrder++;
                continue;
            }
            else
                mStack.push(pushV[i]);
        }
        while (mStack.size() && mStack.top() == popV[popOrder])
        {
            mStack.pop();
            popOrder++;
        }
        if (mStack.size() > 0 || popOrder != popV.size())
            return false;
        else
            return true;
    }
    std::stack<int> mStack;
};
int main()
{
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {4, 3, 5, 2, 1};
    std::vector<int> pushList(push, push + sizeof(push) / sizeof(int));
    std::vector<int> popList(pop, pop + sizeof(pop) / sizeof(int));
    std::cout << Solution().IsPopOrder(pushList, popList) << std::endl;
    return 0;
}