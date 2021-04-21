/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        value = 0;
        if (x < 0) flag = false;
        else flag = true;
        x = std::abs(x);
        while (x) {
            value = value * 10 + (x % 10);
            x = x / 10;
        }
        if (value < (- std::pow(2, 31)) || value > (std::pow(2, 31) - 1)) return 0;
        else return flag ? value : -value;
    }
    bool flag;
    long long value;
};

int main(int argc, char** argv) {
    std::cout << Solution().reverse(120) << std::endl;
    return 0;
}
// @lc code=end

