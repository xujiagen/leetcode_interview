/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.51%)
 * Likes:    579
 * Dislikes: 0
 * Total Accepted:    95.9K
 * Total Submissions: 128.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> vecList;
        permuteList(vecList, nums, 0);
        return vecList;
    }
    void permuteList(std::vector<std::vector<int>> &vecList, std::vector<int> &nums, int index)
    {
        if (index == nums.size())
            vecList.push_back(nums);
        for (int i = index; i < nums.size(); i++)
        {
            std::swap(nums[index], nums[i]);
            permuteList(vecList, nums, index + 1);
            std::swap(nums[index], nums[i]);
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
    std::vector<std::vector<int>> vecList = Solution().permute(vec);
    printList(vecList);
    return 0;
}
*/
// @lc code=end
