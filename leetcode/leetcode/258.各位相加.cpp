/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
#include <iostream>

int addUp(int num) {
    int sum = 0;
    while (num) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            num = addUp(num);
        }
        return num;
    }
};

int main(int argc, char** argv) {
    std::cout << Solution().addDigits(38) << std::endl;
    return 0;
}
// @lc code=end