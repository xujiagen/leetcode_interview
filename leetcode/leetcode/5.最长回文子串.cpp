/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/*
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) return s;
        int maxLength = 1, left = 0, right =  0;
        for (int i = 0; i < s.size(); i++) {
            //std::cout << "i: " << i << std::endl;
            int diff = 1;
            while (i - diff >= 0 && i + diff < s.size() && s[i + diff] == s[i - diff]) {
                if (2 * diff + 1 > maxLength) {
                    //std::cout << "diff: " << diff << " left: " << i - diff << " right: " << i + diff << std::endl; 
                    maxLength = 2 * diff + 1;
                    left = i - diff, right = i + diff;
                }
                diff++;
            }
            diff = 1;
            //std::cout << "diff: " << diff << std::endl;
            while (i - diff >= 0 && i + diff - 1 < s.size() && s[i - diff] == s[i + diff - 1]) {
                if (2 * diff > maxLength) {
                    maxLength = 2 * diff;
                    left = i - diff, right = i + diff - 1;
                }
                diff++;
            }
        }
        return s.substr(left, maxLength);
    }
};
*/

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        longestSubString = "";
        subStrLength = 0;
        for (int i = 0; i < s.size(); i++) {
            palindrom(s, i, i);
            palindrom(s, i, i + 1);
        }
        return longestSubString;
    }

    void palindrom(const std::string &s, int first, int second) {
        int maxLength = 0;
        while (first >= 0 && second < s.size() && s[first] == s[second]) {
            maxLength = second - first + 1;
            if (maxLength > subStrLength) {
                subStrLength = maxLength;
                longestSubString = s.substr(first, second - first + 1);
            }
            first--;
            second++;
        }
    }
    std::string longestSubString;
    int subStrLength;
};

int main(int argc, char** argv) {
    std::string str("cbbd");
    std::cout << Solution().longestPalindrome(str) << std::endl; 
    return 0;
}

// @lc code=end

