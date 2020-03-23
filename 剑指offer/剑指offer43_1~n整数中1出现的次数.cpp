/*
１~n整数中一出现的次数
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ostream>
#include<istream>
#include<sstream>
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0)
            return 0;
        std::stringstream ss;
        ss<<n;
        std::string str=ss.str();
        return  caltulate(str);
    }
    int caltulate(std::string str)
    {
        if(str.size()<1)
            return 0;
        int length=str.size();//记录这个字符串的长度
        int first=str[0]-'0';//判断这个字符串的高位是什么

        if(length==1 && first==0)
            return 0;
        if(length==1 && first>0)
            return 1;
        
        //上面是递归的边界条件

        int numdigital=0;
        
        if(first>1)
            numdigital=pow(10,length-1);
        else if(first==1)
            {
                std::stringstream stream(str.substr(1,str.size()-1));
                stream>>numdigital;
                numdigital+=1;
            }
        
        int numotherdigit=first*(length-1)*pow(10,length-2);

        int numreverse=caltulate(str.substr(1,str.size()-1));

        return numdigital+numotherdigit+numreverse;
    }
};


int main()
{
    int num=10;
    Solution a;
    std::cout<<a.NumberOf1Between1AndN_Solution(num)<<std::endl;
    return 0;
}