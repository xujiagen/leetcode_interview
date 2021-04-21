/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

// class Solution {
// public:
//     double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
//         if (nums1.size() < 1 && nums2.size() < 1) return 0;
//         else if (nums2.size() < 1) return findMedianSortedArrays(nums2, nums1);
//         //std::cout << nums2.size() / 2 << std::endl; 
//         if (nums1.size() == 0) {
//             if (nums2.size() % 2 == 1) return double(nums2[nums2.size() / 2]);
//             else return (double(nums2[nums2.size() / 2]) + double(nums2[nums2.size() / 2 - 1])) / 2;
//         }
//         int firstLeft = 0, firstRight = nums1.size() - 1; 
//         int secondLeft = 0, secondRight = nums2.size() - 1;
//         while (firstLeft < firstRight && secondLeft < secondRight) {
//             int firstMid = firstLeft + (firstRight - firstLeft) / 2;
//             int secondMid = secondLeft + (secondRight - secondLeft) / 2;
//             if (nums1[firstMid] > nums2[secondMid]) {
//                 firstRight = firstMid;
//                 secondLeft = secondMid + 1;
//             } else if (nums1[firstMid] < nums2[secondMid]) {
//                 firstLeft = firstMid + 1;
//                 secondRight = secondMid;
//             } else return double(nums1[firstMid]);
//         }
//         std::vector<int> firstNum(nums1.begin() + firstLeft, nums1.begin() + firstRight + 1);
//         std::vector<int> secondNum(nums2.begin() + secondLeft, nums2.begin() + secondRight + 1);
//         firstNum.insert(firstNum.end(), secondNum.begin(), secondNum.end());
//         std::sort(firstNum.begin(), firstNum.end());
//         if (firstNum.size() % 2 == 1) {
//             return double(firstNum[firstNum.size() / 2]);
//         } else return (double(firstNum[firstNum.size() / 2]) + double(firstNum[firstNum.size() / 2 - 1])) / 2;
//     }
// };

// class Solution {
// public:
//     double middleValueOfList(const std::vector<int> &inputList) {
//         if (inputList.size() % 2 == 1) return inputList[inputList.size() / 2];
//         else return (double(inputList[inputList.size() / 2 - 1]) + double(inputList[inputList.size() / 2])) / 2;
//     }
//     double findMedianSortedArrays(std::vector<int>& num1,  std::vector<int> &num2) {
//         if (num1.size() < num2.size()) return findMedianSortedArrays(num2, num1);
//         int firstLeft = 0, firstRight = num1.size() - 1, secondLeft = 0, secondRight = num2.size() - 1;
//         while (firstLeft < firstRight && secondLeft < secondRight) {
//             int firstMiddle = (firstLeft + firstRight) >> 2;
//             int secondMiddle = (secondLeft + secondRight) >> 2; 
//             if (num1[firstMiddle] < num2[secondMiddle]) {
//                 firstRight = firstMiddle;
//                 secondLeft = secondMiddle;
//             } else if (num1[firstMiddle] > num2[secondMiddle]) {
//                 firstLeft = firstMiddle;
//                 secondRight = secondMiddle;
//             } else return ((double(num1[firstMiddle]) + double(num2[secondMiddle])) / 2);
//         }
//         std::vector<int> firstMiddleList(num1.begin() + firstLeft , num1.begin() + firstRight + 1);
//         std::vector<int> secondMiddleList(num2.begin() + secondLeft, num2.begin() + secondLeft + 1);
//         firstMiddleList.insert(firstMiddleList.end(), secondMiddleList.begin(), secondMiddleList.end());
//         std::sort(firstMiddleList.begin(), firstMiddleList.end());
//         return middleValueOfList(firstMiddleList);
//     }
// };

// class Solution {
// public:
//     int getKElement(const std::vector<int> &nums1, const std::vector<int> &nums2, int k) {
//         int m = nums1.size();
//         int n = nums2.size();
//         int index1 = 0, index2 = 0;
//         while (true) {
//             //边界情况
//             if (index1 == m) return nums2[index2 + k - 1];
//             if (index2 == n) return nums1[index1 + k - 1];
//             if (k == 1) return std::min(nums1[index1], nums2[index2]);

//             //正常情况
//             int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
//             int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
//             int pivot1 = nums1[newIndex1];
//             int pivot2 = nums2[newIndex2];
//             if (pivot1 <= pivot2) {
//                 k -= newIndex1 - index1 + 1;
//                 index1 = newIndex1 + 1;
//             } else {
//                 k -= newIndex2 -  index2 + 1;
//                 index2 = newIndex2  + 1;
//             }
//         }
//     }
//     double findMiddleSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
//         int totalLength = nums1.size() + nums2.size();
//         if (totalLength % 2 == 1) return getKthElement(nums1, nums2, (totalLength + 1) / 2);
//         else return (getKElement(nums1, nums2, totalLength / 2) + getKElement(nums1, num2, totalLength / 2 + 1)) / 2.0;
//     }
// };

class Solution {
public:
    int getKElement(const std::vector<int> &nums1, const std::vector<int> &nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            if (index1 == m) return nums2[index2 + k - 1];
            if (index2 == n) return nums1[index1 + k - 1];
            if (k == 1) return std::min(nums1[index1], nums2[index2]);

            int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMiddleSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) return getKElement(nums1, nums2, (totalLength + 1) / 2);
        else return (double(getKElement(nums1, nums2, totalLength / 2)) + double(getKElement(nums1, nums2, totalLength / 2 + 1))) / 2.0;
    }
};



int main(int argc, char** argv) {
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {-1, 3};
    //std::cout << Solution().findMedianSortedArrays(nums1, nums2) << std::endl;
    std::cout << Solution().findMiddleSortedArrays(nums1, nums2) << std::endl; 
    return 0;
}
// @lc code=end

