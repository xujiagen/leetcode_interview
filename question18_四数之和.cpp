/*
四数之和
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<set>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {

        std::sort(nums.begin(),nums.end());//首先将数组进行排序
        //for(int a:nums)
         //   std::cout<<a<<std::endl;
        if(nums.size()<4)
        {
            std::vector<std::vector<int> > a;
            return a;
        }
        std::vector<std::vector<int> > vec_vec_int;
        {
            for(int left=0;left<nums.size()-3;left++)//1
            {
                //if(left>0 && nums[left]==nums[left-1])
                //    continue;
                //这个元素如果重复出现，直接跳过，只要判断过一次，就不需要判断第二次
                for(int l=left+1;l<nums.size()-2;l++)//2
                {
                    int temp_target=target-nums[l]-nums[left];
                    int mid=l+1,right=nums.size()-1;
                    while(mid<right)
                    {
                        //std::cout<<left<<"\t"<<l<<"\t"<<mid<<"\t"<<right<<std::endl;
                        //首先这四个数满足顺序原则，先后顺序不能颠倒
                        if(nums[mid]+nums[right]==temp_target)
                        {
                            std::vector<int> vec_int;
                            int temp_left=nums[left],temp_l=nums[l],temp_mid=nums[mid],temp_right=nums[right];
                            vec_int.push_back(nums[left]);
                            vec_int.push_back(nums[l]);
                            vec_int.push_back(nums[mid]);
                            vec_int.push_back(nums[right]);
                            vec_vec_int.push_back(vec_int);
                            while(mid<right && nums[++mid]==temp_mid);
                            while(mid<right && nums[right--]==temp_right);
                        }
                        else if(nums[mid]+nums[right]<temp_target)
                            mid++;
                        else
                            right--;
                    }
                }
            }
        }
        return vec_vec_int;
    }
};

class Solution1 {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        set<vector<int> > res;
        if(nums.size() < 4)
            return vector<vector<int> >(res.begin(),res.end());
        sort(nums.begin(),nums.end());
        int l, r, sum;
        for(int i = 0; i <nums.size() - 3; i++){
            for(int j = i + 1; j < nums.size() - 2; j++){
                l = j + 1;
                r = nums.size() - 1;
                sum = target - nums[i] - nums[j];
                while(l < r){
                    if(nums[l] + nums[r] == sum){
                        vector<int> scheme = {nums[i],nums[j],nums[l],nums[r]};
                        res.insert(scheme);
                        while(l < r && nums[l + 1] == nums [l]) ++l;
                        while(l < r && nums[r - 1] == nums [r]) --r;
                        ++l;
                        --r;
                    }
                    else if(nums[l] + nums[r] < sum)
                        ++l;
                    else 
                        --r;
                }
            }
        }
        return vector<vector<int> >(res.begin(),res.end());

    }
};

int main()
{
    Solution a1;
    Solution1 a2;
    int a[] = {-3,-2,-1,0,0,1,2,3};
    std::vector<int> vec_int(a, a + sizeof(a) / sizeof(int));
    std::vector<std::vector<int> > vec_vec_int,vec_vec_vec_int;
    vec_vec_int = a1.fourSum(vec_int, 0);
    vec_vec_vec_int=a2.fourSum(vec_int,0);
    for (int i = 0; i < vec_vec_int.size(); i++)
    {
        for (int j = 0; j < vec_vec_int[i].size(); j++)
        {
            std::cout << vec_vec_int[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout<<std::endl;

    for (int i = 0; i < vec_vec_vec_int.size(); i++)
    {
        for (int j = 0; j < vec_vec_vec_int[i].size(); j++)
        {
            std::cout << vec_vec_vec_int[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}