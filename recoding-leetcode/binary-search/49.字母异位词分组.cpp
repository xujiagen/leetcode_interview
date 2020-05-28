/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (61.17%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    69.6K
 * Total Submissions: 113.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

void printList(const std::vector<std::vector<std::string>> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        const std::vector<std::string> &vec = _VecList[i];
        for (int j = 0; j < vec.size(); j++)
            std::cout << vec[j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::vector<std::string> tmpVec(strs.begin(), strs.end());
        for (int i = 0; i < tmpVec.size(); i++)
            std::sort(tmpVec[i].begin(), tmpVec[i].end());
        std::unordered_map<std::string, int> strMap;
        int count = 0;
        for (int i = 0; i < tmpVec.size(); i++)
        {
            if (strMap.find(tmpVec[i]) != strMap.end())
                continue;
            strMap[tmpVec[i]] = count++;
        }
        std::vector<std::vector<std::string>> vecList(count, std::vector<std::string>());
        for (int i = 0; i < tmpVec.size(); i++)
            //vecList[i].push_back(strs[strMap[tmpVec[i]]]);
            vecList[strMap[tmpVec[i]]].push_back(strs[i]);
        return vecList;
    }
};
/*
int main(int argc, char **argv)
{
    std::vector<std::string> vecList = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto vec = Solution().groupAnagrams(vecList);
    printList(vec);
    return 0;
}
*/
// @lc code=end
