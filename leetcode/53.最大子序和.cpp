/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.83%)
 * Likes:    1560
 * Dislikes: 0
 * Total Accepted:    151.3K
 * Total Submissions: 309.6K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() < 1)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int maxNum = nums[0];
        int index = 0;
        int subSum = 0;
        while (index < nums.size())
        {
            if (nums[index] > subSum && subSum < 0)
                subSum = nums[index];
            else
                subSum += nums[index];
            maxNum = subSum > maxNum ? subSum : maxNum;
            index++;
            continue;
        }
        return maxNum;
    }
};
/*
int main(int argc, char **argv)
{
    int nums[] = {1, 2};
    std::vector<int> numsVec(nums, nums + sizeof(nums) / sizeof(int));
    Solution a;
    std::cout << "sub sum: " << a.maxSubArray(numsVec) << std::endl;
    return 0;
}
*/

// @lc code=end
