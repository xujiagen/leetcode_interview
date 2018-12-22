#include<iostream>
#include<string>
#include<climits>

class Solution 
{
public:
    double Power(double base, int exponent) 
    {
        if(base==0.0 && exponent<0)
            return 0.0;
        if(exponent==0)
            return 1;
        if(exponent<0)
            return 1.0/Power(base,-exponent);
        else
        {
            int base1=1;
            for(int i=0;i<exponent;i++)
            {
                base1=base1*base;
                if(base1>)
            }
            return base1;
        }
    }
};