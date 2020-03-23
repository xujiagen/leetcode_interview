#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) 
    {
        if(str.size()<1)
            return str;
        int length=str.size();
        n=n%length;
        str+=str;
        return str.substr(n,length);
    }
};

int main()
{
    Solution a;
    std::string str="abcdefg";
    std::cout<<a.LeftRotateString(str,1)<<std::endl;
    return 0;
}