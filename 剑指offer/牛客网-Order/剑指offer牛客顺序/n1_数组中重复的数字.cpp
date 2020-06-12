/*
在一个长度为n的数组里面包含0-n-1范围内的数，数组中有些数字是重复的，但是不知道是重复了哪几个数字，找出任意一个重复的数字，


*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*
class Solution
{
public:
bool duplicate(int numbers[], int length, int* duplication) 
{
    for(int i=0;i<length;i++)
    {
        int index=numbers[i];
        if(index>=length) index-=length;
        if(numbers[index]>=length)
        {
            *duplication=index;
            return true;
        }
        numbers[index]=numbers[index]+length;
    }
    return false;
}
};

class Solution
{
    public:
    int duplicate(int numbers[],int length,int* duplication)
    {
        int l=1,r=numbers.size()-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            int s=0;
            for(auto x:numbers) s+=x>=l && x<=mid;
            if(s>mid-l+r) r=mid;
            else l=mid+1;
        }
    }
};
*/

class Solution
{
    public:
    int duplication(std::vector<int> nums)
    {
        int l=1,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+r>>1;
            int s=0;
            for(auto x:nums)
            {
                 s+=(x>=l && x<=mid);
                 std::cout<<"x:"<<x<<" "<<"s:"<<s<<" "<<"mid:"<<mid<<std::endl;
            }
            std::cout<<std::endl;
            
            if(s>mid-l+1) r=mid;
            else l=mid+1;
        }
        return r;
    }
};

int main()
{
    Solution a;
    int num[]={2,3,5,4,3,2,6,7};
    std::vector<int> vec_int(num,num+sizeof(num)/sizeof(int));
    int b=0;
    //std::cout<<a.duplicate(num,8,&b)<<" "<<b<<std::endl;
    std::cout<<a.duplication(vec_int)<<std::endl;
    return 0;
}
//这里使用的这个方法不好，主要是改变了之前存储的数组