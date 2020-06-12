/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (57.58%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    53.5K
 * Total Submissions: 92.4K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 
 * 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到
 * 1。如果 可以变为  1，那么这个数就是快乐数。
 * 
 * 如果 n 是快乐数就返回 True ；不是，则返回 False 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

class Solution
{
public:
    bool isHappy(int n)
    {
        std::unordered_set<long long> longSet;
        long long tmpN = n;
        while (longSet.find(tmpN) == longSet.end())
        {
            longSet.insert(tmpN);
            int tmpCheck = check(tmpN);
            //std::cout << tmpCheck << std::endl;
            if (tmpCheck == 1)
                return true;
            tmpN = tmpCheck;
        }
        return false;
    }
    long long check(long long n)
    {
        std::vector<int> vecList = SquareList(n);
        return SquareSum(vecList);
    }
    std::vector<int> SquareList(long long n)
    {
        std::vector<int> res;
        while (n)
        {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }
    long long SquareSum(const std::vector<int> &_VecList)
    {
        long long sum = 0;
        for (int i = 0; i < _VecList.size(); i++)
            sum += _VecList[i] * _VecList[i];
        return sum;
    }
};
/*
int main()
{
    std::cout << Solution().isHappy(19) << std::endl;
    return 0;
}
*/
// @lc code=end
