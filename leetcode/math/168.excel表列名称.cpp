/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (37.18%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    23.2K
 * Total Submissions: 62.2K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::string convertToTitle(int n)
    {
        std::string res;
        if (n < 1)
            return res;
        char value = 'A' - 1;
        while (n)
        {
            n = n - 1;
            res.push_back('A' + n % 26);
            n = n / 26;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
/*
int main(int argc, char **argv)
{
    std::cout << Solution().convertToTitle(26) << std::endl;
    return 0;
}
*/
// @lc code=end
