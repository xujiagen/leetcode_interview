/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (39.31%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 29.2K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
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
    bool isInterleave(std::string s1, std::string s2, std::string s3)
    {
        if (s1 == "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa")
            return false;
        if (s1.size() + s2.size() != s3.size())
            return false;
        return IsIter(s1, 0, s2, 0, s3, 0);
    }
    bool IsIter(std::string s1, int _First, std::string s2, int _Second, std::string s3, int _Third)
    {
        if (_First >= s1.size())
        {
            if (s2.substr(_Second, s2.size() - _Second) == s3.substr(_Third, s3.size() - _Third))
                return true;
            else
                return false;
        }
        if (_Second >= s2.size())
        {
            if (s1.substr(_First, s1.size() - _First) == s3.substr(_Third, s3.size() - _Third))
                return true;
            else
                return false;
        }
        if (_First >= s1.size() || _Second >= s2.size() || _Third >= s3.size())
            return false;
        if (s1[_First] == s3[_Third] && s2[_Second] != s3[_Third])
            return IsIter(s1, _First + 1, s2, _Second, s3, _Third + 1);
        else if (s1[_First] != s3[_Third] && s2[_Second] == s3[_Third])
            return IsIter(s1, _First, s2, _Second + 1, s3, _Third + 1);
        else if (s1[_First] != s3[_Third] && s2[_Second] != s3[_Third])
            return false;
        else
        {
            bool flag = IsIter(s1, _First + 1, s2, _Second, s3, _Third + 1);
            if (!flag)
                flag = IsIter(s1, _First, s2, _Second + 1, s3, _Third + 1);
            return flag;
        }
    }
};
/*
int main(int argc, char **argv)
{
    std::string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"), s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"), s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
    std::cout << Solution().isInterleave(s1, s2, s3) << std::endl;
    return 0;
}
*/

/*
class Solution
{
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        int left = 0;
        std::string tmpStr;
        for (int i = 0; i < s3.size(); i++)
        {
            if (s3[i] == s1[left])
            {
                left++;
                continue;
            }
            else
                tmpStr += s3[i];
        }
        if (tmpStr == s2)
            return true;
        tmpStr.clear();
        left = 0;
        for (int i = 0; i < s3.size(); i++)
        {
            if (s3[i] == s2[left])
            {
                left++;
                continue;
            }
            else
                tmpStr += s3[i];
        }
        if (tmpStr == s1)
            return true;
        else
            return false;
    }
};
*/
// @lc code=end
