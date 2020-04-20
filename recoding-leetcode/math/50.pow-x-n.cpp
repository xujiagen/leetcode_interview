/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (34.20%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    63.8K
 * Total Submissions: 185.8K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
class Solution
{
public:
    double myPow(double x, int n)
    {
        return Pow(x, n);
    }

    double Pow(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        else if (n < 0)
            return Pow(1.0 / x, -n);
        else
        {
            double res = 1.0;
            double tmpMulti = x;
            while (n)
            {
                if (n % 2 == 1)
                    res *= tmpMulti;
                n /= 2;
                tmpMulti *= tmpMulti;
            }
            /*
            for (int i = n; i; i /= 2)
            {
                if (i % 2 > 0)
                    res *= tmpMulti;
                tmpMulti *= tmpMulti;
            }
            */
            return res;
        }
    }
};
/*
class Solution
{
public:
    double myPow(double x, int n)
    {
        // 特殊情况处理
        if (n == 0)
            return 1;
        if (x == 0)
            return 0;
        double ans = 1;
        // 因为 n 为负时最小可达-2147483648，直接取反时超过int上限，因此特殊处理
        if (n < 0)
        {
            x = 1 / x;
            ans = x;
            n = -(n + 1);
        }
        // 快速幂
        while (n > 0)
        {
            if (n % 2 > 0)
                ans *= x;
            n /= 2;
            x = x * x;
        }
        return ans;
    }
};
*/
/*
int main(int argc, char **argv)
{
    std::cout << Solution().myPow(2.0, -2147483648) << std::endl;
    return 0;
}
*/
// @lc code=end
