/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> valueCount;
        for (int i = 0; i < nums.size(); i++) {
            if (valueCount.find(nums[i]) != valueCount.end()) valueCount[nums[i]]++;
            else valueCount[nums[i]] = 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (valueCount[nums[i]] > nums.size() / 2) return nums[i];
        }
        return -1;
    }
};
// @lc code=end

