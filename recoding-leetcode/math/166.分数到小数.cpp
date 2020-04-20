/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (25.83%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 38.1K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 示例 1:
 * 
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 * 
 * 
 * 示例 2:
 * 
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 * 
 * 示例 3:
 * 
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::string fractionToDecimal(int numerator, int denominator)
    {
        std::string res;
        if (numerator == 0)
        {
            res += "0";
            return res;
        }
        long long tmpFirst = numerator, tmpSecond = denominator;
        if ((tmpFirst < 0 && tmpSecond > 0) || (tmpFirst > 0 && tmpSecond < 0))
        {
            res += "-";
            tmpFirst = tmpFirst > 0 ? tmpFirst : -tmpFirst;
            tmpSecond = tmpSecond > 0 ? tmpSecond : -tmpSecond;
        }
        if (tmpFirst < 0 && tmpSecond < 0)
        {
            tmpFirst = -tmpFirst;
            tmpSecond = -tmpSecond;
        }
        if (tmpFirst > tmpSecond)
        {
            res += std::to_string(tmpFirst / tmpSecond);
            tmpFirst = tmpFirst % tmpSecond;
            if (!tmpFirst)
                return res;
        }
        else
            res += "0";
        res += ".";
        int lastFirst = 0;
        std::unordered_map<long long, int> valueIndex;
        while (tmpFirst)
        {
            if (valueIndex.find(tmpFirst) != valueIndex.end())
            {
                std::string tmpLoop = std::string(res.begin() + valueIndex[tmpFirst], res.end());
                res = std::string(res.begin(), res.begin() + valueIndex[tmpFirst]) + "(" + tmpLoop + ")";
                return res;
            }
            valueIndex[tmpFirst] = res.size();
            tmpFirst = tmpFirst * 10;
            res += std::to_string(tmpFirst / tmpSecond);
            tmpFirst = tmpFirst % tmpSecond;
        }
        return res;
    }
};
/*
int main(int argc, char **argv)
{
    std::cout << Solution().fractionToDecimal(4, 333) << std::endl;
    return 0;
}
*/
// @lc code=end
