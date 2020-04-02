/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 *
 * https://leetcode-cn.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (45.84%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 17.9K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
 * 
 * 下图是字符串 s1 = "great" 的一种可能的表示形式。
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。
 * 
 * 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。
 * 
 * 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。
 * 
 * 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "great", s2 = "rgeat"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "abcde", s2 = "caebd"
 * 输出: false
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
    bool isScramble(std::string s1, std::string s2)
    {
        if (s1.size() != s2.size())
            return false;
        std::vector<int> vecList(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            vecList[s1[i] - 'a']++;
            vecList[s2[i] - 'a']--;
        }
        for (int i = 0; i < vecList.size(); i++)
        {
            if (vecList[i] != 0)
                return false;
        }
        if (TheSame(s1, s2))
            return true;
        for (int i = 1; i < s1.size(); i++)
        {
            std::cout << i << " " << s1.substr(0, s1.size()) << std::endl;
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                 isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s1.size() - i))) ||
                (isScramble(s1.substr(0, i), s2.substr(s1.size() - i, i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s1.size() - i))))
            {
                return true;
            }
        }
        return false;
    }
    bool TheSame(std::string &_First, std::string &_Second)
    {
        if (_First.size() != _Second.size())
            return false;
        for (int i = 0; i < _First.size(); i++)
        {
            if (_First[i] != _Second[i])
                return false;
        }
        return true;
    }
};
/*
int main(int argc, char **argv)
{
    std::string first("abc"), second("bca");
    std::cout << Solution().isScramble(first, second) << std::endl;
    return 0;
}
*/
// @lc code=end
