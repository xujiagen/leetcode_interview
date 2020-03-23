#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int num=0;
        int great=0x80000000;
        for(int i=0;i<array.size();i++)
        {
            if(num<=0)
                num=array[i];
            else
                num+=array[i];
            if(num>great)
                great=num;
        }
        return great;
    }
};

int main()
{
    int a[]={1,-2,3,10,-4,7,2,-5};
    std::vector<int> a_vec(a,a+sizeof(a)/sizeof(int));
    Solution a1;
    std::cout<<a1.FindGreatestSumOfSubArray(a_vec)<<std::endl;
    return 0;
}