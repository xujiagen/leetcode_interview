/*
首先你这个问题我最初的想法是对应括号之间的相差的是偶数倍

主要还是对栈这种先进后出的方式不是很熟悉

需要注意的问题就是比较新的c++编译器好像是没有string pop_back()这个函数的
所以这个程序编译:g++ question20_有效的括号.cpp -std=c++11
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;




class Solution1 {
public:
    bool isValid(string s) {
        if(s.size()%2!=0)    //如果是奇数个，那么一定排除
            return false;
        if(s.size()==0)    //如果等于0，那么返回true ，我自己一开始想到了，但是没有实行
            return true;
        
        string temp;//下面的程序是默认输入的是一个长度大于等于2的string，前面必须通过判断保证这一点
        temp.push_back(s[0]);
        for(int i=1;i<s.size();++i)
        {
            int k=temp.size()-1;
            if(temp[k]=='('&&s[i]==')')
                temp.pop_back();
            else if(temp[k]=='['&&s[i]==']')
                temp.pop_back();
            else if(temp[k]=='{'&&s[i]=='}')
                temp.pop_back();
            else
                temp.push_back(s[i]);
        }
        return temp.size()==0;
    }
};

int main()
{
    Solution a;
    std::cout<<a.isValid("}]}()){{)[{[(]")<<std::endl;
    Solution1 a1;
    std::cout<<a1.isValid("}]}()){{)[{[(]")<<std::endl;
    return 0;
}