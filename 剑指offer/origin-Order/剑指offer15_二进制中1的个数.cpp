#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
     int  NumberOf1(int n) 
     {
         int count=0;
         unsigned int flag=1;
         while(flag)
         {
             if(flag&n)
                 count++;
             flag=flag<<1;
         }
         return count;
     }
};