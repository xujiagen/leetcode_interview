/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (29.93%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    29.6K
 * Total Submissions: 98K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
    {
        std::vector<int> res;
        if (words.size() < 1)
            return res;
        if (words[0].size() < 1)
            return res;
        const int &rows = words.size();
        const int &cols = words[0].size();
        if (s.size() < rows * cols)
            return res;
        //std::unordered_set<std::string> strSet(words.begin(), words.end());
        std::unordered_map<std::string, int> strMap;
        for (int i = 0; i < words.size(); i++)
        {
            if (strMap.find(words[i]) != strMap.end())
                strMap[words[i]]++;
            else
                strMap[words[i]] = 1;
        }
        /*
        for (int i = 0; i < s.size() - rows * cols; i++)
        {
            if (strSet.find(s.substr(i, cols)) != strSet.end())
            {
                if (judge(s.substr(i, cols * rows), rows, cols, strSet))
                    res.push_back(i);
            }
        }
        */
        for (int i = 0; i <= s.size() - rows * cols; i++)
        {
            if (strMap.find(s.substr(i, cols)) != strMap.end())
            {
                if (judge(s.substr(i, cols * rows), rows, cols, strMap, words))
                    res.push_back(i);
            }
        }
        return res;
    }
    /*
    bool judge(std::string str, int rows, int cols, std::unordered_set<std::string> _StrSet)
    {
        for (int i = 0; i < str.size(); i += cols)
        {
            if (_StrSet.find(str.substr(i, cols)) == _StrSet.end())
                return false;
            else
                _StrSet.erase(str.substr(i, cols));
        }
        return true;
    }
    */
    bool judge(std::string str, int rows, int cols, std::unordered_map<std::string, int> _StrMap, std::vector<std::string> &_StrList)
    {
        for (int i = 0; i < str.size(); i += cols)
        {
            if (_StrMap.find(str.substr(i, cols)) == _StrMap.end())
                return false;
            else
                _StrMap[str.substr(i, cols)]--;
        }
        for (int i = 0; i < _StrList.size(); i++)
        {
            if (_StrMap[_StrList[i]] != 0)
                return false;
        }
        return true;
    }
};
/*
void printList(std::vector<int> vecList)
{
    for (int i = 0; i < vecList.size(); i++)
    {
        std::cout << vecList[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::string s("wordgoodgoodgoodbestword");
    std::vector<std::string> strList;
    strList.push_back("word");
    strList.push_back("good");
    strList.push_back("best");
    strList.push_back("good");
    std::vector<int> vecList = Solution().findSubstring(s, strList);
    printList(vecList);
    return 0;
}
*/
// @lc code=end
