/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (57.77%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    47.6K
 * Total Submissions: 82.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> vecList;
        permuteList(vecList, nums, 0);
        std::set<std::vector<int>> setList(vecList.begin(), vecList.end());
        return std::vector<std::vector<int>>(setList.begin(), setList.end());
    }
    void permuteList(std::vector<std::vector<int>> &_VecList, std::vector<int> &_Nums, int Index)
    {
        if (Index == _Nums.size())
        {
            _VecList.push_back(_Nums);
            return;
        }
        for (int i = Index; i < _Nums.size(); i++)
        {
            /*
            if (_Nums[i] == _Nums[Index])
                continue;
                */
            std::swap(_Nums[i], _Nums[Index]);
            permuteList(_VecList, _Nums, Index + 1);
            std::swap(_Nums[i], _Nums[Index]);
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
    std::vector<int> vec = {1, 1, 2};
    std::vector<std::vector<int>> vecList = Solution().permuteUnique(vec);
    printList(vecList);
    return 0;
}
*/
// @lc code=end
