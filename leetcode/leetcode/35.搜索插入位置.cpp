/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.size() < 1) return 0;
        if (target <= nums[0]) return 0;
        if (target > nums[nums.size() - 1]) return nums.size();
        return findPosition(nums, target);
    }
    int findPosition(const std::vector<int> &_VecList, int _Target) {
        int left = 0, right = _VecList.size() - 1;
        while (left < right) {
            if (right - left == 1) {
                if (_VecList[left] == _Target) return left;
                if (_VecList[right] >= _Target) return right;
                return right;
            }
            int middle = (left + right) >> 1;
            if (_VecList[middle] == _Target) return middle;
            else if (_VecList[middle] > _Target) right = middle;
            else if (_VecList[middle] < _Target) left = middle; 
        }
        return left;
    }
};

int main(int argc, char** argv) {
    std::vector<int> vecList = {1,3,5,6};
    std::cout << Solution().searchInsert(vecList, 2) << std::endl; 
    return 0;
}

// @lc code=end