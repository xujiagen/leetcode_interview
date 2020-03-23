/*
面试题61
扑克牌中的顺子
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    bool IsContinuous( vector<int> numbers ) 
    {
        if(numbers.size()<1)
            return false;
        std::sort(numbers.begin(),numbers.end());
        int number_of_zero=0;
        int number_of_gap=0;

        for(int i=0;i<numbers.size() && numbers[i]==0;i++)
        {
            number_of_zero++;
        }
        //计算数组里面０的个数

        //计算数组里面间隔的个数
        int small=number_of_zero;
        int big=small+1;
        while(big<numbers.size())
        {
            if(numbers[small]==numbers[big])
                return false;
            number_of_gap+=numbers[big]-numbers[small]-1;
            small=big;
            big++;
        }
        return (number_of_gap>number_of_zero)?false:true;
    }
};