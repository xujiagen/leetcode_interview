#include<iostream>
#include<vector>

class Solution 
{
public:
    string intToRoman(int num) 
    {
        int value[]={1,5,10,50,100,500,1000};
        char value_flag[]={'I','V','X','L','C','D','M'};
        std::vector<int> value_evc(value,value+sizeof(value)/sizeof(int));
        std::vector<char> flag_vec(value_flag,value_flag+sizeof(value_flag)/sizeof(value_flag));
    }
};