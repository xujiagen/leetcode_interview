/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
                continue;
            }
            if (num % 3 == 0) {
                num /= 3;
                continue;
            }
            if (num % 5 == 0) {
                num /= 5;
                continue;
            }
            return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    std::cout << Solution().isUgly(14) << std::endl; 
    return 0;
}
// @lc code=end

