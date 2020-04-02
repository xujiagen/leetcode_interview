/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (37.65%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 34.7K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 * 
 * 说明：
 * 
 * 
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
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
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::vector<std::string> strList;
        if (wordDict.size() < 1)
            return strList;
        std::set<std::string> strSet(wordDict.begin(), wordDict.end());
        IterWord(s, strSet, s.size() - 1, "", strList);
        return strList;
    }
    void IterWord(std::string s, std::set<std::string> &_StrSet, int Index, std::string str, std::vector<std::string> &_VecList)
    {
        if (Index < 0)
        {
            _VecList.push_back(str);
            return;
        }
        for (int i = 1; i <= Index + 1; i++)
        {
            //std::cout << "index: " << Index << " substr: " << s.substr(Index - i + 1, i) << std::endl;
            if (_StrSet.find(s.substr(Index - i + 1, i)) != _StrSet.end())
            {
                if (str.size() > 0)
                    IterWord(s, _StrSet, Index - i, s.substr(Index - i + 1, i) + " " + str, _VecList);
                else
                    IterWord(s, _StrSet, Index - i, s.substr(Index - i + 1, i), _VecList);
            }
        }
        return;
    }
};
/*
void printList(const std::vector<std::string> &_StrList)
{
    if (_StrList.size() < 1)
        return;
    for (int i = 0; i < _StrList.size(); i++)
        std::cout << _StrList[i] << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::string s("catsanddog");
    std::vector<std::string> strList;
    strList.push_back("cat");
    strList.push_back("cats");
    strList.push_back("and");
    strList.push_back("sand");
    strList.push_back("dog");
    auto vecList = Solution().wordBreak(s, strList);
    printList(vecList);
    return 0;
}
*/
// @lc code=end
