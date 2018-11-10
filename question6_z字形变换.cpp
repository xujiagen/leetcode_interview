#include<iostream>
#include<string>
#include<vector>

class Solution
{
    public:
    Solution(){}
    std::string convert(std::string s,int numRows)
    {
        if(numRows<=1 || numRows>s.size())
            return s;
        std::vector<std::string> str_vec(numRows);
        std::size_t index;
        for(std::size_t i=0;i<s.size();i++)
        {
            index=(i)%(2*numRows-2);
            index=index<numRows?index:(2*numRows-index-2);
            str_vec[index]+=s[i];
        }
        std::string str;
        for(int i=0;i<numRows;i++)
        {
            std::cout<<str_vec[i]<<std::endl;
            str+=str_vec[i];
        }
        return str;  
    }
};

int main()
{
    Solution name;
    std::string str="PAYPALISHIRING";
    std::cout<<"显示结果:"<<name.convert(str,3)<<std::endl;
}