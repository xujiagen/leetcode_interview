/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.27%)
 * Likes:    1689
 * Dislikes: 0
 * Total Accepted:    173.8K
 * Total Submissions: 614.6K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start

#include <iostream>
#include <string>

using namespace std;

// 暴力破解，　时间复杂度太高了！

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        int palindromeSize = 0;
        std::string palindromeStr;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (j - i < palindromeSize)
                    continue;
                if (isPalindrome(s, i, j))
                {
                    palindromeSize = j - i + 1;
                    palindromeStr = s.substr(i, j - i + 1);
                }
            }
        }
        return palindromeStr;
    }

    bool isPalindrome(std::string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

// 动态规划的解法，这种方法的时间复杂度是O(n2)
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.size() < 2)
            return s;
        int palindromeLength = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int tmpLength = max(palindromeSize(s, i, i), palindromeSize(s, i, i + 1));
            if (tmpLength > palindromeLength)
            {
                palindromeLength = tmpLength;
                start = i - (palindromeLength - 1) / 2;
            }
        }
        return s.substr(start, palindromeLength);
    }

    int palindromeSize(std::string _Str, int _Left, int _Right)
    {
        while (_Left >= 0 && _Right < _Str.size() && _Str[_Left] == _Str[_Right])
        {
            _Left--;
            _Right++;
        }
        return _Right - _Left - 1;
    }
};

// @lc code=end
