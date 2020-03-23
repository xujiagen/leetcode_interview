/*
正则表达式匹配
１．


*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
class Solution_2 {
public:
    bool isMatch(string s, string p) {
        int s_size=s.size();
        int p_size=p.size();
        std::vector<std::vector<bool> > vec_vec_int(s_size+1,std::vector<bool>(p_size+1,false));
        //上面是通过vector初始化的一个二维数组

        vec_vec_int[0][0]=true;
        //上面是dp二维数组初始化
        
        for(int i=0;i<p_size;i++)
        {
            if(p[i]=='*' && vec_vec_int[0][i-1])//这里主要是在一开始的时候消除一开始的*的影响
                vec_vec_int[0][i+1]=true;
        }
        //比一般的多一行因为第一行是空串，如果一开始就是*，说明程序就不是从这里开始的，应该从后面开始
        
        for(int i=0;i<s_size;i++)
        {
            for(int j=0;j<p_size;j++)
            {
                if(p[j]=='.' || p[j]==s[i])
                {
                    vec_vec_int[i+1][j+1]=vec_vec_int[i][j];//如果当前位置字符匹配上了，当前位置的状态等于之前位置的状态
                }
                else if(p[j]=='*')//下面是考虑'*'存在下的两种大情况
                {
                    if(p[j-1]!='.'&& p[j-1]!=s[i])//ｐ的上一个位置和s的当前位置和上一个位置都匹配不上
                        vec_vec_int[i+1][j+1]=vec_vec_int[i+1][j-1];//当前的位置和上上一个的位置是一样的
                    else
                        vec_vec_int[i+1][j+1]=(vec_vec_int[i][j+1]||vec_vec_int[i+1][j]||vec_vec_int[i+1][j-1]);
                        1.第一种情况：vec_vec_int[i][j+1]表示aa->a
                        2.第二种情况:vec_vec_int[i+1][j]
                        3.第三种情况本来以为不需要写，实际上是.*这种情况需要考虑进去
                }
            }
        }
        print(vec_vec_int);
        return vec_vec_int[s_size][p_size];
    }
    void print(std::vector<std::vector<bool> > vec_int)
    {
        for(int i=0;i<vec_int.size();i++)
        {
            for(int j=0;j<vec_int[0].size();j++)
                std::cout<<vec_int[i][j]<<" ";
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
};
*/
class Solution {
public:
    bool match(string str, string pattern)
    {
        int str_size=str.size();
        int pattern_size=pattern.size();//计算两个字符串的长度

        std::vector<std::vector<bool> > vec_int(str_size+1,std::vector<bool>(pattern_size+1,false));
        //上面是　初始化一个二维数组用来保存dp的标志位
        vec_int[0][0]=true;
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]=='*')
                vec_int[0][i+1]=vec_int[0][i-1];
        }
        
        for(int i=0;i<str.size();i++)
        {
            for(int j=0;j<pattern.size();j++)
            {
                if(str[i]==pattern[j] || str[j]=='.')
                {
                    vec_int[i+1][j+1]=vec_int[i][j];
                }
                else if(pattern[j]=='*')
                {
                    if(pattern[j-1]=='.' || pattern[j-1]==str[i])
                    {
                        vec_int[i+1][j+1]=vec_int[i][j+1] || vec_int[i+1][j] || vec_int[i+1][j-1];
                        /*
                        1.a*->aa
                        2.两个看成是一个aa=>a
                        3.aa->empty
                        */
                    }                   
                }
                
            }
        }
        print(vec_int);
        return vec_int[str.size()][pattern.size()];
    }
    void print(std::vector<std::vector<bool> > vec_vec_int)
    {
        for(int i=0;i<vec_vec_int.size();i++)
        {
            for(int j=0;j<vec_vec_int[0].size();j++)
            {
                std::cout<<vec_vec_int[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
};


int main()
{
    Solution c;
    std::cout<<c.match("aab","c*a*b")<<std::endl;
    return 0;
}