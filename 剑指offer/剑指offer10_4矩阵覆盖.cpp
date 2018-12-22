/*
使用2*1的小矩阵横着或者竖着覆盖更大的矩阵，请问用n个2*1的矩阵无重复的覆盖２×N大矩阵，总共有多少种方法
*/
#include<iostream>
#include<string>
#include<vector>

class Solution 
{
public:
    int rectCover(int number) 
    {
        if(number==0)
            return 0;
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        int num1=1;
        int num2=2;
        int number1;
        for(int i=2;i<number;i++)
        {
            number1=num1+num2;
            num1=num2;
            num2=number1;
        }
        return number1;
    }
};