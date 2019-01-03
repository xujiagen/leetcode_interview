/*
翻转单词顺序列
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
  public:
    string ReverseSentence(string str)
    {
        if(str.size()<1)
            return str;
        int end=str.size()-1;
        int start=end;

        std::string new_str;
        while(start>=0)
        {
            if(str[start]==' ' && start<end)
            {
                new_str+=str.substr(start+1,end-start);
                new_str+=" ";
                if((start-1)>=0)
                {
                    start=end=start-1;
                }
            }
            start--;
        }
        new_str+=str.substr(0,end-start);
        std::cout<<new_str<<std::endl;
        return new_str;
    }
};

int main()
{
    Solution a;
    std::string str = "I am a student";
    cout << a.ReverseSentence(str) << std::endl;

    return 0;
}