/*
每一个只出现一次的字符
将这个字符存储在哈希表里面，值表示这个字符出现的次数
*/

#include<iostream>
#include<map>

using namespace std;

class Solution 
{
public:
    int FirstNotRepeatingChar(string str) 
    {
        if(str.size()<1)
            return -1;
        map<char,int> str_map;
        for(int i=0;i<str.size();i++)
        {
            //std::cout<<i<<std::endl;
            if(str_map.count(str[i])!=0)
            {
                str_map[str[i]]++;
                std::cout<<"str[i]="<<str[i]<<"\t"<<str_map[str[i]]<<std::endl;
            }
            else
                str_map[str[i]]=1;
        }

        for(int i=0;i<str.size();i++)
        {
            if(str_map[str[i]]==1)
                return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string str="hajzkbasksuhakaja";
    Solution a;
    std::cout<<a.FirstNotRepeatingChar(str)<<std::endl;
    return 0;
}
