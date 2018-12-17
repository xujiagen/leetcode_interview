/*
三数之和
实现的思路，三数之和变成两数之和，两数之和在通过哈希表来实现
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int>& nums) 
    {
        std::sort(nums.begin(),nums.end());//将数组从小到大进行排序
        //这样的好处就是可以去除一些，无效的数据

        std::map<int,int> int_map;
        std::vector<std::vector<int> > int_vec_vec;
        for(int i=0;i<nums.size();i++)
        {
            int_map[nums[i]]=i;
            //因为第一个值才能通过哈希表来查找，第二个表只是第一个值的位置，不能通过哈希表来实现快速查找
        }
        for(int i=0;i<nums.size() && nums[i]<=0;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            //对于每一个ｉ作为下面实现的目标，下面已经找完了，所以出现重复的元素直接消除掉

            int target=-nums[i];
            for(int j=i+1;j<nums.size()-1;j++)
            {
                if(int_map.count(target-nums[j])!=0 && int_map[target-nums[j]]>j)
                //这里的判断条件是通过哈希表的形式判断一个元素出现了几次，同时第三个元素要在第二个元素后面，否则没有意义
                    {
                        std::vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(-nums[i]-nums[j]);
                        while(nums[j]==nums[j+1])
                            j++;
                       //对于每一个中间出现的元素也只需要计算一次，因为多出来的都是已经计算过了
                        int_vec_vec.push_back(temp);
                    }
            }
        }
        return int_vec_vec;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> int_vec;
    std::vector<std::vector<int> > int_vec_vec;
    for(int i=0;i<5;i++)
        int_vec.push_back(0);
    Solution a;
    int_vec_vec=a.threeSum(int_vec);
    
    for(std::vector<std::vector<int> >::iterator iter=int_vec_vec.begin();iter!=int_vec_vec.end();iter++)
    {
        for(std::vector<int>::iterator iterator=iter->begin();iterator!=iter->end();iterator++)
        {
            std::cout<<*iterator<<"\t";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    
    return 0;
}
