#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
    std::string longestPalindrome(std::string s)
    {
        if(s.size()<=1)
           return s;
        std::pair<int,int> pair_vec;
        int max=0;
        std::pair<int,int> int_pair(0,1);
        std::vector<std::vector<int> > int_vec_vec(s.size()+1);
        for(std::vector<std::vector<int> >::iterator iter=int_vec_vec.begin();iter!=int_vec_vec.end();iter++)
            iter->resize(s.size()+1);
        for(int i=0;i<s.size();i++)
            int_vec_vec[i][i]=1;
        for(int i=0;i<s.size()-1;i++)
            int_vec_vec[i][i+1]=1;    
        for(int distance=2;distance<=s.size();distance++)
        {
            for(int i=0;i<s.size();i++)
            {
                if(i<s.size() && (i+distance)<=s.size())
                {
                    if(s[i]==s[i+distance-1] && int_vec_vec[i+1][i+distance-1])
                    {
                        int_vec_vec[i][i+distance]=1;
                        if(distance>max)
                        {
                            int_pair.first=i;
                            int_pair.second=distance;
                        }
                    }
                    else
                        int_vec_vec[i][i+distance]=0;
                }
            }
        }
        return s.substr(int_pair.first,int_pair.second);
    }
};

class solution
{
    public:
    std::string long(std::string s)
    {
        if(s.size()<=1)
            return s;
        //下面开始初始化一二维数组
        std::vector<std::vector<int> > int_vec_vec(s.size()+1);
        for(std::vector<std::vector<int> >::iterator iter=int_vec_vec.begin();iter!=int_vec_vec.end();iter++)
        {
            iter->resize(s.size()+1);
        }
        for(int i=0;i<s.size()+1;i++)
        {
            for(int j=0;j<s.size()+1;j++)
            {
                int_vec_vec[i][j]=
            }
        }

    }
};