/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int reversePosition = reverseList(nums);
        if (reversePosition == 0) {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i >= reversePosition; i--) {
            if (nums[reversePosition - 1] < nums[i]) {
                std::swap(nums[reversePosition - 1], nums[i]);
                std::reverse(nums.begin() + reversePosition, nums.end());
                return;
            }
        }
    }
    int reverseList(const std::vector<int> &_VecList) {
        int i = _VecList.size() - 1;
        while (i > 0 && _VecList[i] <= _VecList[i - 1]) i--;
        return i;
    }
};

template <class T>
void printList(const typename std::vector<int> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {1, 3, 2};
    Solution().nextPermutation(vecList);
    printList<int>(vecList);
    return 0;
}
// @lc code=end

