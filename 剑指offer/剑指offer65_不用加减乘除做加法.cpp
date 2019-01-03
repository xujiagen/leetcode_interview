/*
不用加减乘除做加法
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum,carry;
        do
        {
            sum=num1^num2;//亦或的结果是不一样的
            carry=(num1&num2)<<1;
            num1=sum;
            num2=carry;
        }
            while(num2!=0);

            return num1;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    std::cout<<a.Add(100,99)<<std::endl;
    return 0;
}
