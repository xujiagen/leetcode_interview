/*
输入两个整数序列，一个序列表示栈的压入顺序，请判断第二个序列是否肯能为该栈的弹出顺序
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

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

int main()
{
    Solution a;
    return 0;
}