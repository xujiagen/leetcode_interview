/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() < 1 && nums2.size() < 1) return 0;
        else if (nums2.size() < 1) return findMedianSortedArrays(nums2, nums1);
        //std::cout << nums2.size() / 2 << std::endl; 
        if (nums1.size() == 0) {
            if (nums2.size() % 2 == 1) return double(nums2[nums2.size() / 2]);
            else return (double(nums2[nums2.size() / 2]) + double(nums2[nums2.size() / 2 - 1])) / 2;
        }
        int firstLeft = 0, firstRight = nums1.size() - 1; 
        int secondLeft = 0, secondRight = nums2.size() - 1;
        while (firstLeft < firstRight && secondLeft < secondRight) {
            int firstMid = firstLeft + (firstRight - firstLeft) / 2;
            int secondMid = secondLeft + (secondRight - secondLeft) / 2;
            if (nums1[firstMid] > nums2[secondMid]) {
                firstRight = firstMid;
                secondLeft = secondMid + 1;
            } else if (nums1[firstMid] < nums2[secondMid]) {
                firstLeft = firstMid + 1;
                secondRight = secondMid;
            } else return double(nums1[firstMid]);
        }
        std::vector<int> firstNum(nums1.begin() + firstLeft, nums1.begin() + firstRight + 1);
        std::vector<int> secondNum(nums2.begin() + secondLeft, nums2.begin() + secondRight + 1);
        firstNum.insert(firstNum.end(), secondNum.begin(), secondNum.end());
        std::sort(firstNum.begin(), firstNum.end());
        if (firstNum.size() % 2 == 1) {
            return double(firstNum[firstNum.size() / 2]);
        } else return (double(firstNum[firstNum.size() / 2]) + double(firstNum[firstNum.size() / 2 - 1])) / 2;
    }
};

int main(int argc, char** argv) {
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {-1, 3};
    std::cout << Solution().findMedianSortedArrays(nums1, nums2) << std::endl; 
    return 0;
}
// @lc code=end

