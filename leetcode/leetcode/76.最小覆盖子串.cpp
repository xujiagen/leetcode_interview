/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.53%)
 * Likes:    429
 * Dislikes: 0
 * Total Accepted:    34K
 * Total Submissions: 95.4K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

class Solution
{
public:
    std::string minWindow(std::string s, std::string t)
    {
        maxLength = -1;
        if (s.size() < t.size())
            return "";
        std::unordered_map<char, int> charCount;
        for (int i = 0; i < t.size(); i++)
        {
            if (charCount.find(t[i]) != charCount.end())
                charCount[t[i]]++;
            else
                charCount[t[i]] = 1;
        }
        int left = 0, right = 0;
        if (charCount.find(s[right]) != charCount.end())
        {
            charCount[s[right]]--;
        }
        right++;
        while (right <= s.size())
        {
            /*
            if (charCount.find(s[right]) != charCount.end())
            {
                charCount[s[right]]--;
            }
            */
            if (ValueCheck(charCount))
            {
                if (maxLength == -1)
                {
                    maxLength = right - left;
                    mStr = s.substr(left, maxLength);
                }
                else if (maxLength > right - left)
                {
                    maxLength = right - left;
                    mStr = s.substr(left, maxLength);
                }
                if (charCount.find(s[left]) != charCount.end())
                    ++charCount[s[left]];
                left++;
            }
            else
            {
                if (right < s.size() && charCount.find(s[right]) != charCount.end())
                {
                    charCount[s[right]]--;
                }
                right++;
            }
        }
        if (maxLength == -1)
            return "";
        else
            return mStr;
    }
    bool ValueCheck(const std::unordered_map<char, int> &_Map)
    {
        for (std::unordered_map<char, int>::const_iterator iter = _Map.begin();
             iter != _Map.end(); iter++)
        {
            if (iter->second > 0)
                return false;
        }
        return true;
    }
    int maxLength;
    std::string mStr;
};
/*
int main(int argc, char **argv)
{
    std::string S("ADOBECODEBANC"), T("ABC");
    std::cout << Solution().minWindow(S, T) << std::endl;
    return 0;
}
*/
// @lc code=end
