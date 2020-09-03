/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
#include <iostream>
#include <string> 
#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::vector<std::string> subStrList;
        if (s.size() < 10) return subStrList;
        std::map<std::string, int> subStr;
        for (int i = 0; i < s.size() - 9; i++) {
            if (subStr.find(s.substr(i, 10)) == subStr.end()) subStr[s.substr(i, 10)] = 1;
            else subStr[s.substr(i, 10)]++;
        }
        for (std::map<std::string, int>::iterator iter = subStr.begin(); iter != subStr.end(); ++iter) {
            if (iter->second > 1) subStrList.push_back(iter->first);
        }
        return subStrList;
    }
};
/*
int main(int argc, char** argv) {
    std::string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    std::vector<std::string> res = Solution().findRepeatedDnaSequences(str);
    auto printStr = [](const std::string &str) {std::cout << str << " ";};
    std::for_each(res.begin(), res.end(), printStr);
    std::cout << std::endl; 
    return 0;
}
*/
// @lc code=end