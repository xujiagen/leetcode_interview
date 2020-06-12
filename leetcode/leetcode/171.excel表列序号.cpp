/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (66.90%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 53.9K
 * Testcase Example:  '"A"'
 *
 * 给定一个Excel表格中的列名称，返回其相应的列序号。
 * 
 * 例如，
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: "A"
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: "AB"
 * 输出: 28
 * 
 * 
 * 示例 3:
 * 
 * 输入: "ZY"
 * 输出: 701
 * 
 * 致谢：
 * 特别感谢 @ts 添加此问题并创建所有测试用例。
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
class Solution
{
public:
    int titleToNumber(std::string s)
    {
        if (s.size() < 1)
            return 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum = sum * 26;
            sum += (s[i] - 'A' + 1);
        }
        return sum;
    }
};
// @lc code=end
