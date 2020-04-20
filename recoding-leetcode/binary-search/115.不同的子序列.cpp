/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (47.40%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 22.9K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 
 * 示例 1:
 * 
 * 输入: S = "rabbbit", T = "rabbit"
 * 输出: 3
 * 解释:
 * 
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * 示例 2:
 * 
 * 输入: S = "babgbag", T = "bag"
 * 输出: 5
 * 解释:
 * 
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printList(const std::vector<std::vector<long>> &_VecList, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << _VecList[i][j] << " ";
        std::cout << std::endl;
    }
}

class Solution
{
public:
    int numDistinct(std::string s, std::string t)
    {
        std::vector<std::vector<long>> vecList(t.size() + 1,
                                               std::vector<long>(s.size() + 1, 0));
        for (std::size_t i = 0; i < s.size() + 1; i++)
            vecList[0][i] = 1;
        for (std::size_t i = 0; i < t.size(); i++)
        {
            for (std::size_t j = 0; j < s.size(); j++)
            {
                if (t[i] == s[j])
                    vecList[i + 1][j + 1] = vecList[i][j] + vecList[i + 1][j];
                else
                    vecList[i + 1][j + 1] = vecList[i + 1][j];
            }
        }
        printList(vecList, t.size() + 1, s.size() + 1);
        return vecList[t.size()][s.size()];
    }
};
/*
int main(int argc, char **argv)
{
    std::cout << Solution().numDistinct("rabbbit", "rabbit") << std::endl;
    return 0;
}
*/
// @lc code=end
