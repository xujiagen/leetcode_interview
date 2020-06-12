/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.46%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    27.5K
 * Total Submissions: 46.2K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        res.push_back({});
        permuteList(res, nums, {}, 0, nums.size() - 1);
        std::set<std::vector<int>> setList(res.begin(), res.end());
        return std::vector<std::vector<int>>(setList.begin(), setList.end());
    }
    void permuteList(std::vector<std::vector<int>> &_VecList,
                     std::vector<int> nums, std::vector<int> vec, int left, int right)
    {
        if (left > right)
            return;
        for (int i = left; i <= right; i++)
        {
            std::vector<int> tmpVec(vec.begin(), vec.end());
            tmpVec.push_back(nums[i]);
            _VecList.push_back(tmpVec);
            permuteList(_VecList, nums, tmpVec, i + 1, right);
        }
    }
};
// @lc code=end
