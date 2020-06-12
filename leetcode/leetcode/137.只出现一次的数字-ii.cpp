/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 *
 * https://leetcode-cn.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (66.13%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 42.1K
 * Testcase Example:  '[2,2,3,2]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,3,2]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 * 
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        std::unordered_set<int> vecSet(nums.begin(), nums.end());
        std::vector<int> singleVec(vecSet.begin(), vecSet.end());
        return (3 * sumList(singleVec) - sumList(nums)) / 2;
    }
    long long sumList(const std::vector<int> &_VecList)
    {
        if (_VecList.size() < 1)
            return 0;
        long long tmpValue = 0;
        for (int i = 0; i < _VecList.size(); i++)
            tmpValue += _VecList[i];
        return tmpValue;
    }
};
// @lc code=end
