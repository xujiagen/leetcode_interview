/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.size() < 2) return 0;
        int left = 0;
        while (height[left] <= 0) left++;
        int right = left;
        while (right < height.size() && height[right] > height[right + 1]) right++;
        while (right < height.size() && height[right] < height[right + 1]) right++;
        
    }
};

int main(int argc, char** argv) {

    return 0;
}
// @lc code=end

