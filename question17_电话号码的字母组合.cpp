/*
电话号码的字母组合
*/
#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

class Solution 
{
public:
    void addstring(std::vector<std::string>& vec_str,std::string& digits,int i,std::string s,char flag1,char flag2)
    {
        if(!digits[i+1])
        {
            for(char x=flag1;x<=flag2;x++)
            {
                std::string s1(s);
                std::string temp(1,x);
                s1.append(temp);
                vec_str.push_back(s1);
            }
        }
        else
        {
            for(char x=flag1;x<=flag2;x++)
            {
                std::string s1(s);
                std::string temp(1,x);
                s1.append(temp);
                add_flag(digits,i+1,vec_str,s1);
            }
        }
    }

    void add_flag(std::string& digits,int i,std::vector<std::string>& vec_str,std::string s)
    {
        switch(digits[i])
        {
            case '2':addstring(vec_str,digits,i,s,'a','c');break;
            case '3':addstring(vec_str,digits,i,s,'d','f');break;
            case '4':addstring(vec_str,digits,i,s,'g','i');break;
            case '5':addstring(vec_str,digits,i,s,'j','l');break;
            case '6':addstring(vec_str,digits,i,s,'m','o');break;
            case '7':addstring(vec_str,digits,i,s,'p','s');break;
            case '8':addstring(vec_str,digits,i,s,'t','v');break;
            case '9':addstring(vec_str,digits,i,s,'w','z');break;
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        std::vector<std::string> vec_str;
        int i=0;
        std::string s;
        add_flag(digits,i,vec_str,s);
        return vec_str;
    }
};

int main()
{
    Solution a;
    std::vector<std::string> vec_str;
    vec_str=a.letterCombinations("2637");
    std::vector<std::string>::iterator iter;
    for(iter=vec_str.begin();iter!=vec_str.end();iter++)
    {
        std::cout<<*iter<<std::endl;
    }
    std::cout<<pow(3,std::string("2637").size())<<std::endl;
    std::cout<<vec_str.size()<<std::endl;
    return 0;
}