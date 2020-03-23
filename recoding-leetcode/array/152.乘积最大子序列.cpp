/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.size() < 1) return 0;
        if (nums.size() == 1) {
            if (nums[0] > 0) return nums[0];
            else return 0;
        }
        positiveMax = nums[0], negtiveMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            
        }
    }
    int positiveMax;
    int negtiveMax;
};
// @lc code=end

