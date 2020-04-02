/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (48.56%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    27.9K
 * Total Submissions: 57.6K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
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
    std::string getPermutation(int n, int k)
    {
        std::string res;
        int split = 1;
        for (int i = 1; i <= n - 1; i++)
            split = split * i;
        std::vector<char> charList;
        int realIndex = k - 1;
        for (int i = 1; i <= n; i++)
            charList.push_back('0' + i);
        for (int i = 0; i < n; i++)
        {
            int index = realIndex / split;
            res += charList[index];
            if (i == n - 1)
                continue;
            charList.erase(charList.begin() + index);
            realIndex = realIndex % split;
            split = split / (n - i - 1);
        }
        return res;
    }
};
/*
int main(int argc, char **argv)
{
    std::cout << Solution().getPermutation(4, 9) << std::endl;
    return 0;
}
*/
// @lc code=end
