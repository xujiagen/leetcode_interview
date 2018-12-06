#include<iostream>
#include<vector>
#include<string>

class Solution
{
    public:
    int reverse(int x)
    {
        std::vector<int> int_vec;
        while(x)
        {
            int_vec.push_back(x%10);
            x=x/10;
        }
        int index=0;
        while(x)
    }
};