/*
1.判断一个数是不是回文数
回文数是指这个数不论是从左往右读还是从右往左读都是一样的
*/

#include<iostream>
#include<vector>
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x==0)
            return true;
        else if(x<0)
            return false;
        else
        {
            std::vector<int> int_vec;
            while(x)
            {
                int_vec.push_back(x%10);
                x=x/10;
            }
            int num=int_vec.size();
            for(int i=0;i<num/2;i++)
            {
                if(int_vec[i]==int_vec[num-1-i])
                    continue;
                else
                    return false;
            }
            return true;
        }
    }
};

int main()
{
    Solution a;
    std::cout<<a.isPalindrome(1221)<<std::endl;
    return 0;
}