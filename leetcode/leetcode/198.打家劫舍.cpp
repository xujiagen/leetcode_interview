/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    long rob(std::vector<int>& nums) {
        if (nums.size() < 1) return 0;
        std::vector<int> sumValue(nums.size() + 3, 0);
        for (int i = 0; i < nums.size(); i++) {
            sumValue[i + 3] = std::max(sumValue[i], sumValue[i + 1]) + nums[i];
        }
        return std::max(sumValue[sumValue.size() - 1], sumValue[sumValue.size() - 2]);
    }
};
// @lc code=end

