/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 *
 * https://leetcode-cn.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (31.75%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    7.9K
 * Total Submissions: 24.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord
 * 的最短转换序列。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回一个空列表。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: []
 * 
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

void printList(const std::vector<std::vector<std::string>> &_StrList)
{
    if (_StrList.size() < 1)
        return;
    for (int i = 0; i < _StrList.size(); i++)
    {
        for (int j = 0; j < _StrList[i].size(); j++)
        {
            std::cout << _StrList[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
class Solution
{
public:
    std::vector<std::vector<std::string>> findLadders(
        std::string beginWord, std::string endWord,
        std::vector<std::string> &wordList)
    {
        std::vector<std::vector<std::string>> res;
        bool beginFlag = false, endFlag = false;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == endWord)
                endFlag = true;
        }
        if (!endFlag)
            return res;
        std::vector<std::string> strList;
        strList.push_back(beginWord);
        int size = wordList.size() + 1;
        IterString(wordList, beginWord, endWord, res, strList, size);
        return res;
    }
    void IterString(std::vector<std::string> wordList,
                    std::string beginWord, std::string endWord,
                    std::vector<std::vector<std::string>> &_Res,
                    std::vector<std::string> res, int &size)
    {
        for (int i = 0; i < wordList.size(); i++)
        {
            std::vector<std::string> copyRes(res.begin(), res.end());
            if (compareString(wordList[i], beginWord))
            {
                if (wordList[i] == endWord)
                {
                    if (copyRes.size() + 1 == size)
                    {
                        copyRes.push_back(endWord);
                        _Res.push_back(copyRes);
                        continue;
                    }
                    else if (copyRes.size() + 1 < size)
                    {
                        copyRes.push_back(endWord);
                        size = copyRes.size();
                        _Res.clear();
                        _Res.push_back(copyRes);
                        continue;
                    }
                }
                else
                {
                    //res.push_back(wordList[i]);
                    copyRes.push_back(wordList[i]);
                    std::vector<std::string> copyWord(wordList.begin(), wordList.end());
                    copyWord.erase(copyWord.begin() + i);
                    IterString(copyWord, copyRes[copyRes.size() - 1], endWord, _Res, copyRes, size);
                }
            }
        }
        return;
    }
    bool compareString(std::string first, std::string second)
    {
        if (first.size() != second.size() || first.size() < 1)
            return false;
        int DiffCount = 0;
        for (int i = 0; i < first.size(); i++)
        {
            if (DiffCount > 1)
                return false;
            if (first[i] != second[i])
                DiffCount++;
        }
        if (DiffCount == 1)
            return true;
        else
            return false;
    }
};
/*
int main(int argc, char **argv)
{
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::vector<std::string>> res = Solution().findLadders(beginWord, endWord, wordList);
    printList(res);
    std::cout << res.size() << std::endl;
    return 0;
}
*/
// @lc code=end
