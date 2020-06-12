/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (65.17%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    36.3K
 * Total Submissions: 55.7K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int numTrees(int n)
    {
        if (n < 3)
            return n;
        std::vector<int> vecList(n + 1, 0);
        vecList[0] = 1, vecList[1] = 1, vecList[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            int tmpValue = 0;
            for (int j = 0; j < i; j++)
            {
                tmpValue += vecList[j] * vecList[i - 1 - j];
            }
            vecList[i] = tmpValue;
        }
        return vecList[vecList.size() - 1];
    }
};
/*
int main(int argc, char **argv)
{
    std::cout << Solution().numTrees(3) << std::endl;
    return 0;
}
*/
// @lc code=end
