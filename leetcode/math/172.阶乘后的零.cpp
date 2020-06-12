/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (39.87%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    32.8K
 * Total Submissions: 82.1K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
class Solution
{
public:
    int trailingZeroes(int n)
    {
        /*
        */
        long long value = 5;
        long long sum = 0;
        long long tmpN = n;
        while (value <= tmpN)
        {
            sum += tmpN / value;
            value *= 5;
        }
        return sum;
    }
};
/*
int main(int argc, char **argv)
{
    std::cout << Solution().trailingZeroes(30) << std::endl;
    return 0;
}
*/
// @lc code=end
