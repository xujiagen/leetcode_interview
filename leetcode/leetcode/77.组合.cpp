/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.35%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    42.1K
 * Total Submissions: 57.3K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
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
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> vecList;
        permuteList(vecList, {}, 1, n, k);
        return vecList;
    }
    void permuteList(std::vector<std::vector<int>> &_VecList, std::vector<int> vecList, int left, int right, int k)
    {
        if (k == 0)
        {
            _VecList.push_back(vecList);
            return;
        }
        if (right - left + 1 < k)
            return;
        for (int i = left; i <= right; i++)
        {
            std::vector<int> tmpVec(vecList.begin(), vecList.end());
            tmpVec.push_back(i);
            permuteList(_VecList, tmpVec, i + 1, right, k - 1);
        }
    }
};
/*
class Solution
{
public:
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> vecList;
        for (int i = 1; i <= n; i++)
            vecList.push_back(i);
        permuteList(res, vecList, {}, n, k);
        return res;
    }
    void permuteList(std::vector<std::vector<int>> &_Res,
                     std::vector<int> vecList, std::vector<int> vec, int n, int k)
    {
        if (k <= 0)
        {
            _Res.push_back(vec);
            return;
        }
        for (int i = 0; i < vecList.size(); i++)
        {
            std::vector<int> tmpVec(vec.begin(), vec.end());
            tmpVec.push_back(vecList[i]);
            std::vector<int> tmpList(vecList.begin(), vecList.end());
            tmpList.erase(tmpList.begin() + i);
            permuteList(_Res, tmpList, tmpVec, n, k - 1);
        }
    }
};
*/

/*
void printList(std::vector<std::vector<int>> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        const std::vector<int> &vec = _VecList[i];
        for (int j = 0; j < vec.size(); j++)
            std::cout << vec[j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    auto vecList = Solution().combine(4, 2);
    printList(vecList);
    return 0;
}
*/
// @lc code=end
