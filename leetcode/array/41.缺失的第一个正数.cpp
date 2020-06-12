/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        if (nums.size() < 1) return 1;
        std::set<int> setList;
        int minPositive = 1;
        for (int i = 0; i < nums.size(); i++) {
            setList.insert(nums[i]);
        }
        while (setList.find(minPositive) != setList.end()) {
            minPositive++;
        }
        return minPositive;
    }
};
// @lc code=end

