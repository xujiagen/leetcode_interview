/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() < 1) return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int middle = (left + right) >> 1;
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;
            if (nums[middle] == target) return middle;
            if (nums[left] < nums[middle] ) 
        }
    }
};

int main(int argc, char** argv) {

}
// @lc code=end

