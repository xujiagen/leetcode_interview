/*
数值的整数次方
给定一个double类型浮点数base和int类型的整数次方，有base的次方
*/
#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    double Power(double base, int exponent)
    {
        if(base==0 && exponent==0) return 1;
        else if(base==0) throw "error";
        if(exponent==0) return 1.0;
        else if(exponent<0) return 1.0/Power(base,-1*exponent);
        else if(exponent>0)
        {
            double base1=1.0;
            for(int i=0;i<exponent;i++)
                base1=base1*base;
            return base1;
        }
    }
};
*/

class Solution
{
public:
    double Power(double base, int exponent)
    {
        if (exponent == 0)
            return 1.0;
        bool positiveFlag = exponent > 0 ? true : false;
        double result = 1.0;
        if (positiveFlag)
        {
            for (int i = 0; i < exponent; i++)
            {
                result = result * base;
            }
        }
        else
        {
            for (int i = 0; i < -exponent; i++)
            {
                result = result * base;
            }
            return 1.0 / result;
        }
    }
};

int main()
{
    Solution a;
    std::cout << a.Power(3, -2) << std::endl;
    return 0;
}