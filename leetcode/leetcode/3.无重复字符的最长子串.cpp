/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() < 2) return s.size();
        maxLength = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (charSet.size() < 1 || charSet.find(s[i]) == charSet.end()) {
                charQueue.push(s[i]);
                charSet.insert(s[i]);
                maxLength = std::max(maxLength, charSet.size());
            } else {
                while (charQueue.front() != s[i]) {
                    charSet.erase(charQueue.front());
                    charQueue.pop();
                }
                charQueue.pop();
                charQueue.push(s[i]);
                maxLength = std::max(maxLength, charSet.size());
            }
        }
        return static_cast<int>(maxLength);
    }
    std::size_t maxLength;
    std::queue<char> charQueue;
    std::unordered_set<char> charSet;
};

// int main(int argc, char** argv) {
//     std::cout << Solution().lengthOfLongestSubstring("pwwkew") << std::endl;
//     return 0;
// }
// @lc code=end

