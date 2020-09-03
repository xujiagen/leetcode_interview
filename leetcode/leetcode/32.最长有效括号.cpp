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
/*
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

*/
class Solution {
    public:
    int longestValidParentheses(std::string s) {
        if (s.size() < 2) return 0;
        std::vector<int> value(s.size(), 0);
        int addUp = 0;
        int max = 0;
        for (int i = 1; i < s.size(); ++i) { 
            addUp = 0;
            //std::cout << "i - value[i - 1] - 1 : " << i - value[i - 1] - 1 << std::endl; 
            if (i - value[i - 1] - 1 >= 0 && s[i] ==')' && s[i - value[i - 1] - 1] == '(') {
                if (i - value[i - 1] - 2 >= 0) addUp = value[i - value[i - 1] - 2];
                value[i] = value[i - 1] + 2 + addUp;
                //std::cout << "i: " << i << " value: " << value[i] <<std::endl; 
                if (value[i] >= max) max = value[i];
            } 
        }
        /*
        for (int i = 0; i < value.size(); i++) {
            std::cout << value[i] << " ";
        }
        */
        //std::cout << std::endl; 

        return max;
    }
};
/*
int main(int argc, char** argv) {
    std::string str("())");
    std::cout << Solution().longestValidParentheses(str) << std::endl;
    return 0;
}
*/
// @lc code=end

