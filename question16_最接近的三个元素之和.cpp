/*
最接近的三个元素之和
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        std::sort(nums.begin(),nums.end());//0,1,1,1
        if(nums.size()<3)
            return 0;
        int min=nums[0]+nums[1]+nums[2];//2

        int mid,right;

        for(int i=0;i<nums.size()-2;i++)//i
        {
            mid=i+1,right=nums.size()-1;//2,3
            int temp_target=target-nums[i];//99
            std::cout<<i<<"\t"<<std::endl;
            while(mid<right)
            {
                if(std::abs(temp_target-nums[mid]-nums[right])<std::abs(target-min))
                {
                    min=nums[i]+nums[mid]+nums[right];
                    std::cout<<i<<"\t"<<temp_target<<"\t"<<nums[mid]<<"\t"<<nums[right]<<std::endl;
                }
                if(nums[mid]+nums[right]==temp_target)
                    return target;
                else
                {
                    if(nums[mid]+nums[right]<temp_target)
                        mid++;
                    else
                        right--;
                }
            }
        }
        return min;
    }
};

int main()
{
    Solution a;
    std::vector<int> int_vec;
    int_vec.push_back(0);
    int_vec.push_back(1);
    int_vec.push_back(1);
    int_vec.push_back(1);
    std::cout<<a.threeSumClosest(int_vec,100)<<std::endl;
    return 0;
}