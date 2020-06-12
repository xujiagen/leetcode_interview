/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

/*
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.size() < 1) return {-1, -1};
        if (nums.size() == 1 && nums[0] == target) return {0, 0}; 
        int left = findPosition(nums, target - 0.5);
        int right = findPosition(nums, target + 0.5);
        if (left == right) return {-1, -1};
        else return {left + 1, right};
    }
    int findPosition(const std::vector<int> &_VecList, double target) {
        int left = 0, right = _VecList.size() - 1;
        while (left < right) {
            std::cout << "left: " << left << " right: " << right << " lV: " << _VecList[left] << " rv: " << _VecList[right] << std::endl; 
            if (right - left == 1) return left;
            int middle = (left + right) >> 1;
            if (_VecList[middle] < target) left = middle;
            else right = middle;
        }
        return left;
    }
};
*/

class Solution {
    public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        if (nums.size() < 1) return {-1, -1};
        int position = findPosition(nums, target);
        if (nums[position] != target) return {-1, -1};
        int left = position, right = position;
        while (left > 0 && nums[left - 1] == target) left--;
        while (right < nums.size() - 1 && nums[right + 1] == target) right++;
        return {left, right};
    }
    int findPosition(const std::vector<int> &_VecList, int target) {
        int left = 0, right = _VecList.size() - 1;
        while (left < right) {
            std::cout << left << " " << right << std::endl; 
            if (right - left <= 1) {
                if (_VecList[left] == target) return left;
                if (_VecList[right] == target) return right;
                return left;
            }
            int middle = (left + right) >> 1;
            if (_VecList[middle] == target) return middle;
            if (_VecList[middle] < target) left = middle;
            if (_VecList[middle] > target) right = middle;
        }
        return left;
    }
};

template <class T>
void printList(const typename std::vector<T> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) std::cout << _VecList[i] << " ";
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {5,7,7,8,8,10};
    std::vector<int> vec = Solution().searchRange(vecList, 8);
    printList<int>(vec);
    return 0;
}

//先进行二分查抄，然后进行线性查找

// @lc code=end

