/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief 通过string substr去读取上一个重复的字符的位置
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (!s.size())
            return 0;
        std::string tmpStr;
        tmpStr += s[0];
        int maxLength = 1;
        for (size_t index = 1; index < s.size(); index++)
        {
            if (tmpStr.find(s[index]) != tmpStr.npos)
            {
                int tmpIndex = tmpStr.find(s[index]);
                tmpStr = tmpStr.substr(tmpIndex + 1, s.size() - tmpIndex - 1);
            }
            tmpStr += s[index];
            maxLength = tmpStr.size() > maxLength ? tmpStr.size() : maxLength;
        }
        return maxLength;
    }
};

/**
 *@brief 构建一个hashmap去存储每一次传进来的字符的位置
 */
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> stringToIndex;
        if (!s.size())
            return 0;
        int maxLength = 0, left = -1;
        for (int index = 0; index < s.size(); index++)
        {
            if (stringToIndex.count(s[index]) != 0 && stringToIndex[s[index]] > left)
            {
                left = stringToIndex[s[index]];
            }
            stringToIndex[s[index]] = index;
            maxLength = max(maxLength, index - left);
            std::cout << "maxLength: " << maxLength << std::endl;
        }
        return maxLength;
    }
};

// @lc code=end
