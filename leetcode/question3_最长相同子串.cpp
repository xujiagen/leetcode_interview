#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (!s.size())
            return 0;
        int subLength = 0;
        std::string subString;
        for (auto &subChar : s) {
            if (subString.find(subChar) == -1) {
                subString.push_back(subChar);
                if (subString.size() > subLength)
                    subLength = subString.size();
            } else {
                std::size_t position = subString.find(subChar) + 1;
                subString = subString.substr(position, subString.size() - position);
                subString.push_back(subChar);
            }
        }
        return subLength;
    }
};

int main(int argc, char** argv) {
    std::string sentense = "dvdf";
    std::cout << "input sentense:" << sentense << std::endl;
    std::cout << "sub sentense length: " 
              << Solution().lengthOfLongestSubstring(sentense) << std::endl;

    return 0;
}

/*
#include<iostream>
#include<string>
#include<vector>

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

*/