/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        if (s.size() < 2) return 0;
        std::vector<int> vecList(s.size(), 0);
        int maxLength = 0;
        for(int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                int pre = i - vecList[i - 1] - 1;
                //std::cout << pre << std::endl; 
                if (pre >= 0 && s[pre] == '(') {
                    vecList[i] = i - pre + 1 + ((pre - 1) >= 0 ? vecList[pre - 1] : 0);
                    maxLength = std::max(maxLength, vecList[i]);
                }
            }
        }
        return maxLength;
    }
};
/*
int main(int argc, char** argv) {
    std::string str(")()())");
    std::cout << Solution().longestValidParentheses(str) << std::endl;
    return 0;
}
*/
// @lc code=end

