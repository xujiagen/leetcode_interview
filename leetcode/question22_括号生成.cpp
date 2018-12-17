/*
括号生成
括号生成是输入的一个括号的对数，输出所有的可能的括号的组合的解

实现这个算法的程序一般有两种，第一种是递归
第二种是通过dp的形式来实现
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        std::vector<std::string> vec_str;
        int left=0,right=0;
        std::string s;
        add_pair(vec_str,s,0,0,n);
        return vec_str;

    }
    void add_pair(std::vector<std::string>& vec_str,std::string s,int left,int right,int n)
    {
        if(right==n)
        {
            //如果字符串里面右括号的数量和左括号的数量是相等的，说明这个时候不需要再往字符串里面添加括号了了
            vec_str.push_back(s);
        }
        if(left<n)
        {
            add_pair(vec_str,s+'(',left+1,right,n);
        }
        if(right<left)
        {
            add_pair(vec_str,s+')',left,right+1,n);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    std::vector<std::string> vec_str;
    vec_str=a.generateParenthesis(3);
    for(std::vector<std::string>::iterator iter=vec_str.begin();iter!=vec_str.end();iter++)
    {
        std::cout<<*iter<<std::endl;
    }
    return 0;
}


