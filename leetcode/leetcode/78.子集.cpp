/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.89%)
 * Likes:    509
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 97K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        res.push_back({});
        permuteList(res, nums, {}, 0, nums.size() - 1);
        return res;
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
/*
void printList(const std::vector<std::vector<int>> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        const std::vector<int> &vec = _VecList[i];
        for (int j = 0; j < vec.size(); j++)
        {
            std::cout << vec[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<int> vec = {1, 2, 3};
    auto vecList = Solution().subsets(vec);
    printList(vecList);
    return 0;
}
*/
// @lc code=end
