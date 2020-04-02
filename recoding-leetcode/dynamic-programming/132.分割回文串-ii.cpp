/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (42.59%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 21K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回符合要求的最少分割次数。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class Solution
{
public:
    int minCut(std::string s)
    {
        if (s.size() < 2)
            return 0;
        std::vector<std::vector<bool>> boolList(s.size(), std::vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (s[i] == s[j] && (i - j <= 2 || boolList[j + 1][i - 1]))
                    boolList[j][i] = true;
            }
        }
        /*
        std::cout << "boolList: " << std::endl;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
                std::cout << boolList[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        */
        std::vector<int> vecList(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
            vecList[i] = i;
        for (int i = 0; i < s.size(); i++)
        {
            if (boolList[0][i] == true)
            {
                vecList[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++)
            {
                if (boolList[j + 1][i])
                    vecList[i] = std::min(vecList[i], vecList[j] + 1);
            }
        }
        return vecList[vecList.size() - 1];
    }
};
/*
int main(int argc, char **argv)
{
    std::cout << Solution().minCut("aab") << std::endl;
    return 0;
}
*/
// @lc code=end
