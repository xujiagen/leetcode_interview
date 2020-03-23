/*
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index)
    {
        std::vector<int> int_vec;
        if(index<=0)
            return false;
        if(index==1)
            return 1;
        
        int_vec.resize(index);
        int_vec[0]=1;
        int nextuglyIndex=1;
        
        int two_ugly_number=0;
        int three_ugly_number=0;
        int five_ugly_number=0;
        
        while(nextuglyIndex<index)
        {
            int min=MIN(2*int_vec[two_ugly_number],3*int_vec[three_ugly_number],5*int_vec[five_ugly_number]);
            int_vec[nextuglyIndex]=min;
            if(min==2*int_vec[two_ugly_number])
                two_ugly_number++;
            if(min==3*int_vec[three_ugly_number])
                three_ugly_number++;
            if(min==5*int_vec[five_ugly_number])
                five_ugly_number++;
            nextuglyIndex++;
        }
        return int_vec[index-1];
    }

    int MIN(int number1,int number2,int number3)
    {
        if(number1<=number2 && number1<=number3)
            return number1;
        if(number2<=number1 && number2<=number3)
            return number2;
        if(number3<=number1 && number3<=number2)
            return number3;
    }
};

int main()
{
    Solution a;
    std::cout<<a.GetUglyNumber_Solution(11)<<std::endl;
    return 0;

    return 0;
}