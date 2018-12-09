/*
最长公共前缀
在输入的vector里面存储多个字符串，判断这些字符串公共的前缀是什么
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution 
{
public:
    std::string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];

        int short_size=10000;
        for(int i=0;i<strs.size();i++)
        {
            
            if(strs[i].size()==0)
                return "";
            else
            {
                if(strs[i].size()<short_size)
                    short_size=strs[i].size();
            }
        }
        //std::cout<<short_size<<std::endl;
        
        for(int j=0;j<short_size;j++)
        {
            for(int i=0;i<strs.size()-1;i++)
            {
                if(strs[i][j]==strs[i+1][j])
                    continue;
                else
                    return strs[0].substr(0,j);
            }
        }
        return strs[0].substr(0,short_size);
    }
};

int main()
{
    std::vector<std::string> str_vec;
    str_vec.push_back("string");
    str_vec.push_back("strhgahs");
    str_vec.push_back("strname");
    Solution a;
    std::cout<<a.longestCommonPrefix(str_vec)<<std::endl;
    return 0;
}