/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() < 1) return 0;
        if (nums.size() == 1) return nums[0];
        int tmpMax = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmpMax + nums[i] > nums[i]) tmpMax = tmpMax + nums[i];
            else tmpMax = nums[i];
            if (max < tmpMax) max = tmpMax;
        }
        return max;
    }
};
// @lc code=end

