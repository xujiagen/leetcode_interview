/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.size() < 1) return true;
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            while (left < right && !IsValid(s[left])) left++;
            while (left < right && !IsValid(s[right])) right--;
            if (s[left] == s[right]) {
                left++, right--;
                continue;
            } else if (IsValidChar(s[left]) == IsValidChar(s[right])) {
                left++, right--;
                continue;
            }
            else return false;
        }
        return true;
    }
    bool IsValid(char item) {
        if (item - '0' >= 0 && item - '0' <=9) return true;
        if (item - 'a' >= 0 && item - 'a' <= 26) return true;
        if (item - 'A' >= 0 && item - 'A' <= 26) return true;
        else return false;
    }
    int IsValidChar(char item) {
        if (item - 'a' >= 0 && item - 'a' <= 26) return item - 'a';
        else if (item - 'A' >= 0 && item - 'A' <= 26) return item - 'A';
        return item - 'a';
    } 
};
/*
int main(int argc, char** argv) {
    std::string tmpString("1a2");
    std::cout << Solution().isPalindrome(tmpString) << std::endl; 
    return 0;
}
*/
// @lc code=end

