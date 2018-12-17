/*
字符串转换整数的一些约定
1、前面是空格的话，去除空格
2.前面是负号或者数组保留数组
3.字符串后面的字符串如果是一些字符串去除这些字符串
4.如果溢出了返回的是溢出的最大值
*/
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
class Solution 
{
public:
    int myAtoi(string str) 
    {
        int num=str.size();
        bool minus=true;
        bool space=true;
        long long number=0;
        int shuzi;
        bool value=true;
        for(int i=0;i<=num;i++)
        {
            if(i==num)
                return number;
            if(str[i]=='-')
            {
                minus=false;
                if(value==true)
                    {
                        value=false;
                        continue;
                    }
                else
                    return 0;
            }
            else if(str[i]=='+')
            {
                minus=true;
                if(value==true)
                {
                    value=false;
                    continue;
                }
                else
                return 0;
            }
            else if(space && str[i]==' ')
            {
                if(value==true)
                    continue;
                else
                    return 0;
            }
            else if(str[i]>='0' && str[i]<='9')
            {
                shuzi=str[i]-'0'; 
                std::cout<<shuzi<<"\t"<<minus;
                value=false;
                if(minus==true)
                {
                    number=number*10+shuzi;
                    if(number>INT_MAX)
                        return INT_MAX;
                }
                else
                {
                    number=number*10-shuzi;
                    if(number<INT_MIN)
                        return INT_MIN;
                }
                std::cout<<"\t"<<number<<std::endl;
            }
            else
            {
                if(number!=0)
                {
                    std::cout<<"final"<<number<<std::endl;
                    return number;
                    
                }
                else
                    return 0;
            }
        }
    }
};

int main()
{
    Solution a;
    std::cout<<a.myAtoi("   +12122 is num");
}