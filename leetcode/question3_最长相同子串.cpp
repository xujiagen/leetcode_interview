#include<iostream>
#include<string>
#include<vector>

/*
using namespace std;

class Solution
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        std::size_t substring_length=0;
        std::string str;
        for(int i=0;i<s.size();i++)
        {
            if(str.find(s[i])==-1)
            {
                str+=s[i];
                if(str.size()>substring_length)
                    substring_length=str.size();
            }
            else
            {
                //说明返回回来的是一一个值
                int num=str.find(s[i]);
                str=str.substr(num+1,str.size()-num-1);
                str+=s[i];
            }
        }
        return substring_length;
    }
};
 */
using namespace std;

class Solution{
    public:
    int lengthOfLongestSubstring(std::string s){
        std::string str;
        int sub_length=0;
        for(int i=0;i<s.size();i++)
        {
            if(str.find(s[i])==-1){
                str+=s[i];
                if(str.size()>sub_length) sub_length=str.size();
            }
            else{
                int num=str.find(s[i]);
                str=str.substr(num+1,str.size()-num-1);
                str+=s[i];
            }
        }
        return sub_length;
    }
};
