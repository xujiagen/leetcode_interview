/*
栈的压入和弹出序列
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution 
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        bool flag=false;
        int point_push=0,point_pop=0;
        while(point_pop<=popV.size()-1)//0,4
        {
            //std::cout<<2<<std::endl;
            while(stack1.empty() || stack1.top()!=popV[point_pop])
            {
                //std::cout<<1<<std::endl;
                if(point_push==pushV.size())//0,4//1,4//2,4//3,4
                    break;
                stack1.push(pushV[point_push]);//1//2//3//4
                point_push++;//1//2//3//4
            }
            if(stack1.top()!=popV[point_pop])
                break;
            point_pop++;//1
            stack1.pop();//
        }
        if(stack1.empty() && point_pop==popV.size())
            flag=true;
        //std::cout<<stack1.size()<<"\t"<<point_pop<<std::endl;
        return flag;
    }
    private:
    std::stack<int> stack1;
};

int main()
{
    std::vector<int> int_vec1,int_vec2;
    int_vec1.push_back(1);
    int_vec1.push_back(2);
    int_vec1.push_back(3);
    int_vec1.push_back(4);//1
    int_vec1.push_back(5);

    int_vec2.push_back(4);
    int_vec2.push_back(5);
    int_vec2.push_back(3);
    int_vec2.push_back(2);
    int_vec2.push_back(1);

    Solution a;
    std::cout<<a.IsPopOrder(int_vec1,int_vec2)<<std::endl;
    return 0;
}