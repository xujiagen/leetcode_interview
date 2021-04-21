/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
// class Solution {
// public:
//     int maxArea(std::vector<int>& height) {
//         if (height.size() < 2) return 0;
//         int front = 0, end = height.size() - 1;
//         int result = 0;
//         while (front < end) {
//             int tempValue = std::min(height[front], height[end]) * (end - front);
//             result = tempValue > result ? tempValue : result;
//             if (height[front] < height[end]) front++;
//             else end--;
//         }
//         return result;
//     }
// };

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        if (height.size() < 2) return 0;
        maxValue = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int miniOne = std::min(height[left], height[right]);
            maxValue = std::max(maxValue, miniOne * (right - left));
            if (height[left] == miniOne) left++;
            else right--;
        }
        return maxValue;
    }
    int maxValue;
};

int main(int argc, char** argv) {
    int vec[] = {4,3,2,1,4};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::cout << Solution().maxArea(vecList) << std::endl;
    return 0;
}
// @lc code=end

