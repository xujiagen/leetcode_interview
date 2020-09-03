/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        if (nums.size() < 0) return -1;
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
/*
int main(int argc, char *argv[]) {
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << Solution().findPeakElement(nums) << std::endl; 
    return 0;
}
*/
// @lc code=end

