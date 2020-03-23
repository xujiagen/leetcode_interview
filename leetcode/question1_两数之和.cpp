#include <iostream>
#include <map>
#include <vector>

class Solution {
    public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> res;
        if (!nums.size())
            return res;
        std::map<int, std::size_t> numsMap;
        for (std::size_t index = 0; index < nums.size(); index++) {
            numsMap[nums[index]] = index;
        }
        for (std::size_t index = 0; index < nums.size(); index++)
        {
            if (numsMap.count(target - nums[index]) != 0 
                    && index != numsMap[target - nums[index]]) {
                res.push_back(index);
                res.push_back(numsMap[target - nums[index]]);
                break;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution a;
    int[] list = {2, 7, 11, 15};
    std::vector<int> initialList(list, list + sizeof(list) / sizeof(int));

    std::vector<int> vecList = a.twoSum(initialList, 9);
    std::cout << vecList[0] << " " << vecList[1] << std::endl;
    return 0;
}

/*
//给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

#include<iostream>
#include<vector>
using namespace std;

//我的答案
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> position;
        bool break_flag=false;
        for(std::vector<int>::iterator iter=nums.begin();iter!=nums.end()-1;iter++)
        {
            for(std::vector<int>::iterator iterator=iter+1;iterator!=nums.end();iterator++)
            {
                if(*iter+*iterator==target)
                {
                    int num1,num2;
                    num1=std::distance(nums.begin(),iter);
                    num2=std::distance(nums.begin(),iterator);
                    position.push_back(num1);
                    position.push_back(num2);
                    break_flag=true;
                    return position;
                }
                else
                    continue;
                if(break_flag==true)
                    break;
            }
        }
        
    }
};

//官方答案:
//解决方法1
class Solution{
    public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> position;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]=target-nums[i])
                {
                    position.push_back(i);
                    position.push_back(j);
                    return position;
                }
            }
        }
    }
    throw "there is no num sum as target";
};

//解决办法2
class Solution
{
    public:
    std::vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> result;
        std::map<int,int> tmpmap;
        for(int i=0;i<nums.size();i++)
        {
            tmpmap[nums[i]]=i;

        }//第一个变量是这个位置的值，第二个变量是这个值的标签

        for(int i=0;i<nums.size();i++)
        {
            if(tmpmap.count(target-nums[i])!=0 && tmpmap[target-nums[i]]!=i)
            {
                result.push_back(i);
                result.push_back(tmpmap[target-nums[i]]);
                break;
            }
        }
        return result;
    }
}


//解决办法3
//下面这种方法的时间复杂度是n,但是整体的计算方法比第二种方法更好
class Solution
{
    public:
    std::vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> result;
        map<int,int> tmpmap;
        for(int i=0;i<nums.size();i++)
        {
            if(tmpmap.count(target-nums[i])!=0)
            {
                result.push_back(tmpmap[nums[i]]);
                result.push_back(i);
                break;
            }
            tmpmap[target-nums[i]]=i;
        }
        return result;
    }
};

class Solution{
    public:
    std::vector<int> twoSum(std::vector<int>& nums,int target)
    {
        std::vector<int> vec_int;
        if(!nums.size()) return vec_int;
        std::map<int,int> tmpmap;
        for(int i=0;i<nums.size();i++)
            tmpmap[nums[i]]=i;//第一个变量表示的是这个值，第二个值表示的是这个值所在的标签
        for(int i=0;i<nums.size();i++)
        {
            if(tmpmap.count(target-nums[i])!=0 && tmpmap[target-nums[i]]!=i){
                vec_int.push_back(i);
                vec_int.push_back(tmpmap[target-nums[i]]);
                return vec_int;
            }
        }
        return vec_int;
    }
};
*/