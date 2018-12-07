/*
正则表达式匹配
１．


*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        int lens = s.length(), lenp = p.length();//记录这两个字符串的长度
        bool **dp = new bool *[lens + 2];//创建一个指向指针的指针指向一个存储指针的动态数组，这个动态数组的长度和需要匹配的字符串的长度是一样的
        for (int i = 0; i < lens + 2; i++)
            dp[i] = new bool[lenp + 2];//这个指向指针的指针的数组里面指针指向一个数组，因为这个数组里面存储的是指针，可以直接将将创建动态数组的指针放置在这个数组里面
        
        //上面是在c++里面创建二维数组

        for (int i = 0; i < lens + 2; i++)//在列方向上面是
            for (int j = 0; j < lenp + 2; j++)
                dp[i][j] = false;//将创建的c++的二维数组进行初始化，初始化为一个全是flase的数组
        dp[0][0] = true;//但是这个这个数组的头指针是true,因为这个数组因为在匹配的字符前面是空的字符串

        for (int i = 1; i < lenp; i++)
            if (p[i] == '*' && dp[0][i - 1])
                dp[0][i + 1] = true;
                //这是判断第一行，因为比较的第一个　元素是空字符串，用来判断的二维矩阵和需要判断的字符串查了一个空的字符串，相当于字符串需要向后面移动一格

        for (int i = 0; i < lens; i++)//
            for (int j = 0; j < lenp; j++)
            {
                if (s[i] == p[j] || p[j] == '.')//对应位置的数据匹配上的，这个时候就是沿用对角线上面的数据，因为之前的数据都是有效的，那么就是有效的，否则都是扯淡
                    dp[i + 1][j + 1] = dp[i][j];//如果当前判断的字符串是相等的，如果相等说明这个数组可以沿用斜对角线上面的元素
                else if (p[j] == '*')//如果当前需要匹配的字符串是'*'说明这个字符串，需要考虑下面两种情况
                {
                    if (p[j - 1] != s[i] && p[j - 1] != '.')//如果q的上一位和当前位置的元素不匹配或者上一个位置的元素是'.'可以沿用上一个位置的'.'万能匹配
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];//这个是说忽略这个位置以及上一个位置的元素
                    else
                        dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                        //这是上一行两种情况中其中一种情况匹配上了，这个时候
                        //１.这里'*'表示的是一个‘ａ’
                        //2.这里‘×’表示的是两个之前的元素
                        //3.第三个判断条件是忽略掉前面两个元素,"*"直接匹配的是前面的元素
                }
            }

        return dp[lens][lenp];
    }
};

class sotution
{
public:
    bool ismatch(string s,string p)
    {
        int s_size=s.size();//2
        int p_size=p.size();//2
        std::vector<std::vector<bool> > vec_vec_int(s_size+1,std::vector<bool>(p_size+1));//4*4
        //上面这种方式创建了一个二维数组

        //下面一开始初始化这个数组里面的元素
        for(int i=0;i<s_size+1;i++)
            for(int j=0;j<p_size+1;j++)
            {
                vec_vec_int[i][j]=false;
            }
        vec_vec_int[0][0]=true;
        for(int i=0;i<p_size;i++)
        {
            if(p[i]=='*' && vec_vec_int[0][i-1])
            {
                vec_vec_int[0][i+1]=true;
            }
            //这个元素可以消除两个元素，保持两个元素以前的状态，同时在这里的特点就是初始化的时候简单
            //下面在初始化的时候遇到“×”需要考虑三种情况，但是但是在初始化的时候只需要考虑一种情况
        }

        for(int i=0;i<s_size+1;i++)
        {
            for(int j=0;j<p_size+1;j++)
            {
                std::cout<<vec_vec_int[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }

        std::cout<<std::endl;
        //上面这种初始化的方式没有考虑一种情况那就是字符串的一开始就是'*',但是“*”这个字符串的原理就是至少从第二个元素开始

        for(int i=0;i<s_size;i++)
        {
            for(int j=0;j<p_size;j++)
            {
                if(s[i]==p[j] || p[j]=='.')//说明这个位置的元素对应上了
                {
                    vec_vec_int[i+1][j+1]=vec_vec_int[i][j];//对应位置的元素对应上了，但是字符串不一定对应上了
                }
                else if(p[j]=='*')
                {
                    if(p[j-1]!='.' || p[j-1]!=s[i])//判断上一个元素是不是万能匹配符或者上一个元素能不能对应上
                    {
                        vec_vec_int[i+1][j+1]=vec_vec_int[i+1][j-1];
                        std::cout<<"final"<<std::endl;
                    }
                    else
                    {
                        vec_vec_int[i+1][j+1]=(vec_vec_int[i+1][j]||vec_vec_int[i][j+1]||vec_vec_int[i+1][j-1]);
                    }
                }
            }
        }
        
        for(int i=0;i<s_size+1;i++)
        {
            for(int j=0;j<p_size+1;j++)
            {
                std::cout<<vec_vec_int[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }
        return vec_vec_int[s_size][p_size];
    }
};

int main()
{
    sotution a;
    std::cout<<a.ismatch("ab",".*")<<std::endl;
    return 0;
}