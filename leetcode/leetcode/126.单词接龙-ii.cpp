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
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// void printList(const std::vector<std::vector<std::string>> &_StrList)
// {
//     if (_StrList.size() < 1)
//         return;
//     for (int i = 0; i < _StrList.size(); i++)
//     {
//         for (int j = 0; j < _StrList[i].size(); j++)
//         {
//             std::cout << _StrList[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
// }
// // 这个算法是基于图的广度优先便利来实现的
// const int INF = 1 << 20;
// class Solution {
// public:
//     std::vector<std::vector<std::string>> findLadders(std::string beginWord, 
//                                                       std::string endWord, 
//                                                       std::vector<std::string> &_WordList) {
//         int id = 0;
//         for (const std::string &word : _WordList) {
//             if (!wordId.count(word)) {
//                 wordId[word] = id++;//vector data保存到 unordered_set里面去'
//                 idWord.push_back(word);// vector data 保存到 std::vector<std::string> idWord里面去
//             }
//         }
//         if (!wordId.count(endWord)) return {};
//         if (!wordId.count(beginWord)) {
//             wordId[beginWord] = id++;
//             idWord.push_back(beginWord);
//         }//这一步是beginWord可能不在这个序列里面,wordId里面保存这个序列,idWord里面保存beginWord
//         edges.resize(idWord.size());//edges是一个二维数组, 主要保存相互链接的两个节点
//             for (int i = 0; i < idWord.size(); i++) {
//                 for (int j = i + 1; j < idWord.size(); j++) {
//                     if (transformCheck(idWord[i], idWord[j]))
//                     {
//                         edges[i].push_back(j);
//                         edges[j].push_back(i);
//                     }
//                 }
//             }
//             const int dest = wordId[endWord];
//             std::vector<std::vector<std::string>> res;
//             std::queue<std::vector<int>> q;
//             std::vector<int> cost(id, INF);
//             q.push(std::vector<int>{wordId[beginWord]});
//             cost[wordId[beginWord]] = 0;
//             while (!q.empty()) {
//                 std::vector<int> now = q.front();
//                 q.pop();
//                 int last = now.back();
//                 if (last == dest) {
//                     std::vector<std::string> tmp;
//                     for (int index : now) {
//                         tmp.push_back(idWord[index]);
//                     }
//                     res.push_back(tmp);
//                 } else {
//                     auto &vec = edges[last];
//                     for (int i = 0; i < edges[last].size(); i++)
//                     {
//                         int to = edges[last][i];
//                         if (cost[last] + 1 <= cost[to])
//                         {
//                             cost[to] = cost[last] + 1;
//                             std::vector<int> tmp(now);
//                             tmp.push_back(to);
//                             q.push(tmp);
//                         }
//                     }
//                 }
//             }
//             return res;
//         }

//     bool transformCheck(const std::string &str1, const std::string &str2) {
//         int differents = 0;
//         for (int i = 0; i < str1.size() && differents < 2; i++) {
//             if (str1[i] != str2[i]) {
//                 differents++;
//             }
//         }
//         return differents == 1;
//     }
//     //判断两个字符串的差异是不是只差一个字符
// private: 
//     std::unordered_map<std::string, int> wordId;
//     std::vector<std::string> idWord;
//     std::vector<std::vector<int>> edges;
// };
// int main(int argc, char **argv)
// {
//     std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
//     std::string beginWord = "hit";
//     std::string endWord = "cog";
//     std::vector<std::vector<std::string>> res = Solution().findLadders(beginWord, endWord, wordList);
//     printList(res);
//     std::cout << res.size() << std::endl;
//     return 0;
// }

class Solution {
public: 
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, 
                                                      std::string endWord, 
                                                      std::vector<std::string> &_WordList) {
    int id = 0;
    for (int i = 0; i < _WordList.size(); i++) {
        if (stringMap.find(_WordList[i]) != stringMap.end()) continue;
        stringMap[_WordList[i]] = id++;
        stringList.push_back(_WordList[i]); 
    }
    if (stringMap.find(endWord) == stringMap.end()) return std::vector<std::vector<std::string>>();
    if (stringMap.find(beginWord) == stringMap.end()) {
        stringMap[beginWord] = id;
        stringList.push_back(_WordList[i]);
    }

    std::vector<std::vector<int>> matchList;
    matchList.reserve(stringMap.size());
    for (int i = 0; i < stringMap.size(); i++) {
        matchList.push_back(std::vector<int>());
    }

    for (int i = 0; i < stringList.size() - 1; i++) {
        for (int j = i + 1; j < stringList.size(); j++) {
            if (matchString(stringList[i], stringList[j])) {
                
            }
        }
    }
}

    bool matchString(const std::string &firstString, const std::string &secondString) {
        if (firstString.size() < 1 && firstString.size() !=  secondString.size()) return false;
        int diffCount = 0;
        for (int i = 0; i < firstString.size(); i++) {
            if (firstString[i] != secondString[i]) diffCount++;
            if (diffCount > 1) return false;
        }
        return diffCount == 1;
    }
std::unordered_map<std::string, int> stringMap;
std::vector<std::string> stringList;
std::vector<std::vector<int>> matchList;
std::vector<std::vector<int>> result;
}

// @lc code=end
