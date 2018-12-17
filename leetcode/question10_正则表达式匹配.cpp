/*
正则表达式匹配
１．


*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution_2 {
public:
    bool isMatch(string s, string p) {
        int s_size=s.size();
        int p_size=p.size();
        std::vector<std::vector<bool> > vec_vec_int(s_size+1,std::vector<bool>(p_size+1));
        //上面是通过vector初始化的一个二维数组
        
        //下面是dp数组的初始化
        for(int i=0;i<s_size+1;i++)
        {
            for(int j=0;j<p_size+1;j++)
            {
                vec_vec_int[i][j]=false;
            }
        }
        vec_vec_int[0][0]=true;
        //上面是dp二维数组初始化
        
        for(int i=0;i<p_size;i++)
        {
            if(p[i]=='*' && vec_vec_int[0][i-1])
                vec_vec_int[0][i+1]=true;
        }
        //上面是计算好了第一行
        
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
                        /*
                        1.第一种情况：vec_vec_int[i][j+1]表示aa->a
                        2.第二种情况:vec_vec_int[i+1][j]
                        3.第三种情况本来以为不需要写，实际上是.*这种情况需要考虑进去
                        */
                }
            }
        }
        return vec_vec_int[s_size][p_size];
    }
};
//

int main()
{
    Solution_2 c;
    c.isMatch("aab","c*a*b");
    return 0;
}