/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printList(const std::vector<int> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}
//这个函数还是存在一定的缺陷,首先创建一个存储空间,然后向这个存储空间里面添加元素
/*
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> copyNums1(m, 0);
        std::copy(nums1.begin(), nums1.begin() + m, copyNums1.begin());
        mergeList(nums1, copyNums1, nums2);
    }
    void mergeList(std::vector<int> &_FinalList, 
                   std::vector<int> &_First, 
                   std::vector<int> &_Second) {
        int firstIndex = 0, secondIndex = 0, thirdIndex = 0;
        while (firstIndex < _First.size() && secondIndex < _Second.size()) {
            if (_First[firstIndex] <= _Second[secondIndex]) _FinalList[thirdIndex++] = _First[firstIndex++]; 
            else _FinalList[thirdIndex++] = _Second[secondIndex++];
        }
        if (firstIndex == _First.size()) {
            std::copy(_Second.begin() + secondIndex, _Second.end(), _FinalList.begin() + thirdIndex);
        } else {
            std::copy(_First.begin() + firstIndex, _First.end(), _FinalList.begin() + thirdIndex);
        }
    }
};
*/
class Solution {
    public:
    void merge(std::vector<int> &nums1, int m, std::vector<int>& nums2, int n) {
        if(m == 0) {
            std::copy(nums2.begin(), nums2.end(), nums1.begin());
            return;
        } else if (n == 0) return;
        int first = m - 1, second = n - 1, third = m + n - 1;
        while (first >= 0 && second >= 0) {
            if (nums1[first] >= nums2[second]) {
                nums1[third--] = nums1[first--];
            } else {
                nums1[third--] = nums2[second--];
            }
        }
        if (first < 0) {
            std::copy(nums2.begin(), nums2.begin() + second + 1, nums1.begin());
        }
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> nums1 = {2, 0};
    std::vector<int> nums2 = {1};
    Solution().merge(nums1, 1, nums2, 1);
    printList(nums1);
    return 0;
}
*/
// @lc code=end

