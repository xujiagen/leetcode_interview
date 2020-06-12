/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (44.10%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    42.5K
 * Total Submissions: 96.5K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::set<std::string> strSet;
        for (int i = 0; i < wordDict.size(); i++)
            strSet.insert(wordDict[i]);
        /*
        std::vector<std::vector<bool>> vecList(s.size(), std::vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (strSet.find(s.substr(i, j)) != strSet.end())
                    vecList[i][j] = true;
            }
        }
        */
        std::vector<bool> boolList(s.size(), false);
        for (int i = 1; i <= s.size(); i++)
        {
            if (strSet.find(s.substr(0, i)) != strSet.end())
            {
                boolList[i - 1] = true;
                continue;
            }
            for (int j = 1; j < i; j++)
            {
                std::cout << s.substr(i - j, j) << std::endl;
                if (boolList[i - j - 1] && strSet.find(s.substr(i - j, j)) != strSet.end())
                {
                    boolList[i - 1] = true;
                    continue;
                }
            }
        } /*
        for (int i = 0; i < boolList.size(); i++)
            std::cout << boolList[i] << " ";
        std::cout << std::endl;
        */
        return boolList[boolList.size() - 1];
    }
};
/*
int main(int argc, char **argv)
{
    std::string s("leetcode");
    std::vector<std::string> strList;
    strList.push_back("leet");
    strList.push_back("code");
    std::cout << Solution().wordBreak(s, strList) << std::endl;
    return 0;
}
*/
// @lc code=end
